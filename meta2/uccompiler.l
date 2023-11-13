 /*Pedro Tiago Gomes Ramalho 2019248594
    André Rodrigues Costa Pinto 2021213497 */

%{
    #include "y.tab.h"
    #include "ast.h"
	#include <stdio.h>
	#include <string.h>
    #define YY_USER_ACTION {column += yyleng;}
    #define PASS_TOKEN() yylval.token = strdup(yytext);
    
    int row = 1, row_comment = 0;
    int column = 0, column_comment = 0, column_chr = 0;
    int error=0;
    int flag1=0, flag2=0;

    char palavra[100];

    int yyparse();

    extern struct node *program;


%}


%X COMMENT chrlit COMMENTLINE

%%

"/*"                            { BEGIN(COMMENT);
                                  row_comment = row;
                                  column_comment = column - 1;}
<COMMENT>\n|\r|\r\n             { row += 1;
                                  column = 0;}
                                 
<COMMENT>"*/"                   { BEGIN(INITIAL); }
<COMMENT><<EOF>>                { BEGIN(INITIAL); printf("Line %d, column %d: unterminated comment\n",row_comment, column_comment);}
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
                                        column_chr = column;}
<chrlit>\\*"\n"                       { printf("Line %d, column %d: unterminated char constant\n",row, column_chr);
                                        row += 1;
                                        column = 0;
                                        BEGIN(INITIAL);}
<chrlit>\\[0-7]{0,3}                  { strcat(palavra, yytext); error += 1;}
<chrlit>\\[^\"'nt\\]                  { strcat(palavra, yytext); error = 2;}
<chrlit>\\[\"'nt\\]                   { strcat(palavra, yytext); error += 1;}
<chrlit>\'                            { BEGIN(INITIAL);
                                        if(error == 1){
                                            if(flag1==1) printf("CHRLIT('%s')\n",palavra);PASS_TOKEN();if(flag2==1) return CHRLIT;
                                        }
                                        else printf("Line %d, column %d: invalid char constant ('%s')\n",row, column_chr, palavra);}
<chrlit><<EOF>>                       { BEGIN(INITIAL); printf("Line %d, column %d: unterminated char constant\n",row, column_chr);}
<chrlit>.                             { strcat(palavra, yytext); error += 1; }

[ \t\n\r\f\\]   {
                    if (*yytext == '\n') {
                        row += 1;
                        column = 0;
                    }
                }

[0-9]+              { if(flag1==1)  printf("NATURAL(%s)\n",yytext);PASS_TOKEN();if(flag2==1) return NATURAL; }
(\.[0-9]+([eE][-+]?[0-9]+)?)|([0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?) {
                    if(flag1==1)  printf("DECIMAL(%s)\n",yytext);PASS_TOKEN();if(flag2==1) return DECIMAL;
                }
"char"              { if(flag1==1)  printf("CHAR\n");if(flag2==1) return CHAR; }
"else"              { if(flag1==1)  printf("ELSE\n");if(flag2==1) return ELSE; }
"while"             { if(flag1==1)  printf("WHILE\n");if(flag2==1) return WHILE; }
"if"                { if(flag1==1)  printf("IF\n");if(flag2==1) return IF; }
"int"               { if(flag1==1)  printf("INT\n");if(flag2==1) return INT; }
"short"             { if(flag1==1)  printf("SHORT\n");if(flag2==1) return SHORT; }
"double"            { if(flag1==1)  printf("DOUBLE\n");if(flag2==1) return DOUBLE; }
"return"            { if(flag1==1)  printf("RETURN\n");if(flag2==1) return RETURN; }
"void"              { if(flag1==1)  printf("VOID\n");if(flag2==1) return VOID; }
"&"                 { if(flag1==1)  printf("BITWISEAND\n");if(flag2==1) return BITWISEAND; }
"|"                 { if(flag1==1)  printf("BITWISEOR\n");if(flag2==1) return BITWISEOR; }
"^"                 { if(flag1==1)  printf("BITWISEXOR\n");if(flag2==1) return BITWISEXOR; }
"&&"                { if(flag1==1)  printf("AND\n");if(flag2==1) return AND; }
"="                 { if(flag1==1)  printf("ASSIGN\n");if(flag2==1) return ASSIGN; }
"*"                 { if(flag1==1)  printf("MUL\n");if(flag2==1) return MUL; }
","                 { if(flag1==1)  printf("COMMA\n");if(flag2==1) return COMMA; }
"/"                 { if(flag1==1)  printf("DIV\n");if(flag2==1) return DIV; }
"=="                { if(flag1==1)  printf("EQ\n");if(flag2==1) return EQ; }
">="                { if(flag1==1)  printf("GE\n");if(flag2==1) return GE; }
">"                 { if(flag1==1)  printf("GT\n");if(flag2==1) return GT; }
"{"                 { if(flag1==1)  printf("LBRACE\n");if(flag2==1) return LBRACE; }
"<="                { if(flag1==1)  printf("LE\n");if(flag2==1) return LE; }
"("                 { if(flag1==1)  printf("LPAR\n");if(flag2==1) return LPAR; }
"<"                 { if(flag1==1)  printf("LT\n");if(flag2==1) return LT; }
"-"                 { if(flag1==1)  printf("MINUS\n");if(flag2==1) return MINUS; }
"%"                 { if(flag1==1)  printf("MOD\n");if(flag2==1) return MOD; }
"!="                { if(flag1==1)  printf("NE\n");if(flag2==1) return NE; }
"!"                 { if(flag1==1)  printf("NOT\n");if(flag2==1) return NOT; }
"||"                { if(flag1==1)  printf("OR\n");if(flag2==1) return OR; }
"+"                 { if(flag1==1)  printf("PLUS\n");if(flag2==1) return PLUS; }
"}"                 { if(flag1==1)  printf("RBRACE\n");if(flag2==1) return RBRACE; }
")"                 { if(flag1==1)  printf("RPAR\n");if(flag2==1) return RPAR; }
";"                 { if(flag1==1)  printf("SEMI\n");if(flag2==1) return SEMI; }
"++"|"--"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inrow"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"bool"|"complex"|"imaginary"|"_Bool"|"_Complex"|"_Imaginary"|"_inline" {
                    if(flag1==1)  printf("RESERVED(%s)\n",yytext);PASS_TOKEN();if(flag2==1) return RESERVED;
                }
[a-zA-Z_][a-zA-Z_0-9]* {
                    if(flag1==1)  printf("IDENTIFIER(%s)\n",yytext);PASS_TOKEN();if(flag2==1) return IDENTIFIER;
                }
.                   { printf("Line %d, column %d: unrecognized character (%s)\n",row, column, yytext); }


%%

int main(int argc, char* argv[]) {
    if (argc > 1){
        if(strcmp(argv[1],"-l")==0 ){
            flag1=1;
            yylex();
        }
        if(strcmp(argv[1],"-t")==0 ){
            yyparse();
            flag2=1;
        }
    } else{
        flag2=1;
        yyparse(); /* run the lexical analysis automaton */
        yylex_destroy();
    }

    return 0;
}

int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}

void yyerror (const char * s ) {
    printf("Line %d, column %d: %s: %s\n", row, (int)(column-strlen(yytext)+1), s, yytext);
}