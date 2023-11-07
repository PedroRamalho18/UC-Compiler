 /*Pedro Tiago Gomes Ramalho 2019248594
    AndrÃ© Rodrigues Costa Pinto 2021213497 */

%{
    #include "y.tab.h"
    #include "ast.h"
	#include <stdio.h>
	#include <string.h>
    #define YY_USER_ACTION {column += yyleng;}
    #define PASS_TOKEN() yylval.token = strdup(yytext);

    int row = 1, row_comment = 0, column_comment = 0, column = 0, column_chr = 0, error=0, current_state_char =0 , current_state_comment = 0,flag=0;	
    char palavra[100];

    int yyparse(void);
    void yyerror(char *);

    extern struct node *program;


%}



%X COMMENT chrlit COMMENTLINE

%%

"/*"                            { BEGIN(COMMENT); 
                                  current_state_comment = 1;
                                  row_comment = row;
                                  column_comment = column - 1;}
<COMMENT>\n|\r|\r\n             { row += 1;
                                  column = 0;}
                                 
<COMMENT>"*/"                   { BEGIN(INITIAL); 
                                  current_state_comment = 0;}
<COMMENT>.                      {;}

"//"                            {BEGIN(COMMENTLINE);}                                                          
<COMMENTLINE>\r|\n|\r\n         {BEGIN(INITIAL);
                                row += 1;
                                column = 0;
                                }
<COMMENTLINE>.                  {;}
                    

\'                                    { BEGIN(chrlit); 
                                        strcpy(palavra,"\0");
                                        error = 0;
                                        column_chr = column;
                                        current_state_char = 1;}
<chrlit>\\*"\n"                       { printf("Line %d, column %d: unterminated char constant\n",row, column_chr);
                                        row += 1;
                                        column = 0;
                                        BEGIN(INITIAL);
                                        current_state_char = 0;}
<chrlit>\\[0-7]{0,3}                  { strcat(palavra, yytext); error += 1;}
<chrlit>\\[^\"'nt\\]                  { strcat(palavra, yytext); error = 2;}
<chrlit>\\[\"'nt\\]                   { strcat(palavra, yytext); error += 1;}
<chrlit>\'                            { BEGIN(INITIAL);
                                        if(error == 1){
                                            if(flag==1) printf("CHRLIT('%s')\n",palavra);PASS_TOKEN();return CHRLIT;
                                        }
                                        else printf("Line %d, column %d: invalid char constant ('%s')\n",row, column_chr, palavra); 
                                        current_state_char = 0;}
<chrlit>.                             { strcat(palavra, yytext); error += 1; }

[ \t\n\r\f\\]+   {
                    if (*yytext == '\n') {
                        row += 1;
                        column = 0;
                    }
                }

[0-9]+              { if(flag==1)  printf("NATURAL(%s)\n",yytext);PASS_TOKEN();return NATURAL; }
(\.[0-9]+([eE][-+]?[0-9]+)?)|([0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?) {
                    if(flag==1)  printf("DECIMAL(%s)\n",yytext);PASS_TOKEN();return DECIMAL;
                }
"char"              { if(flag==1)  printf("CHAR\n"); return CHAR; }
"else"              { if(flag==1)  printf("ELSE\n"); return ELSE; }
"while"             { if(flag==1)  printf("WHILE\n"); return WHILE; }
"if"                { if(flag==1)  printf("IF\n"); return IF; }
"int"               { if(flag==1)  printf("INT\n"); return INT; }
"short"             { if(flag==1)  printf("SHORT\n"); return SHORT; }
"double"            { if(flag==1)  printf("DOUBLE\n"); return DOUBLE; }
"return"            { if(flag==1)  printf("RETURN\n"); return RETURN; }
"void"              { if(flag==1)  printf("VOID\n"); return VOID; }
"&"                 { if(flag==1)  printf("BITWISEAND\n"); return BITWISEAND; }
"|"                 { if(flag==1)  printf("BITWISEOR\n"); return BITWISEOR; }
"^"                 { if(flag==1)  printf("BITWISEXOR\n"); return BITWISEXOR; }
"&&"                { if(flag==1)  printf("AND\n"); return AND; }
"="                 { if(flag==1)  printf("ASSIGN\n"); return ASSIGN; }
"*"                 { if(flag==1)  printf("MUL\n"); return MUL; }
","                 { if(flag==1)  printf("COMMA\n"); return COMMA; }
"/"                 { if(flag==1)  printf("DIV\n"); return DIV; }
"=="                { if(flag==1)  printf("EQ\n"); return EQ; }
">="                { if(flag==1)  printf("GE\n"); return GE; }
">"                 { if(flag==1)  printf("GT\n"); return GT; }
"{"                 { if(flag==1)  printf("LBRACE\n"); return LBRACE; }
"<="                { if(flag==1)  printf("LE\n"); return LE; }
"("                 { if(flag==1)  printf("LPAR\n"); return LPAR; }
"<"                 { if(flag==1)  printf("LT\n"); return LT; }
"-"                 { if(flag==1)  printf("MINUS\n"); return MINUS; }
"%"                 { if(flag==1)  printf("MOD\n"); return MOD; }
"!="                { if(flag==1)  printf("NE\n"); return NE; }
"!"                 { if(flag==1)  printf("NOT\n"); return NOT; }
"||"                { if(flag==1)  printf("OR\n"); return OR; }
"+"                 { if(flag==1)  printf("PLUS\n"); return PLUS; }
"}"                 { if(flag==1)  printf("RBRACE\n"); return RBRACE; }
")"                 { if(flag==1)  printf("RPAR\n"); return RPAR; }
";"                 { if(flag==1)  printf("SEMI\n"); return SEMI; }
"++"|"--"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inrow"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"bool"|"complex"|"imaginary"|"_Bool"|"_Complex"|"_Imaginary"|"_inline" {
                    if(flag==1)  printf("RESERVED(%s)\n",yytext);PASS_TOKEN();return RESERVED;
                }
[a-zA-Z_][a-zA-Z_0-9]* {
                    if(flag==1)  printf("IDENTIFIER(%s)\n",yytext);PASS_TOKEN();return IDENTIFIER;
                }
.                   { printf("Line %d, column %d: unrecognized character (%s)\n",row, column, yytext); }


%%
extern int yylex();

int main(int argc, char* argv[]) {
    if((argc >1) && (strcmp(argv[1],"-l")==0 )){
        flag=1;
    }
    
    yyparse();    /* run the lexical analysis automaton */
    return 0;
}

int yywrap() {  /* called on EOF, return 1 to terminate */
    if (current_state_char == 1) printf("Line %d, column %d: unterminated char constant\n",row, column_chr);
    if (current_state_comment == 1) printf("Line %d, column %d: unterminated comment\n",row_comment, column_comment);
    return 1;
}