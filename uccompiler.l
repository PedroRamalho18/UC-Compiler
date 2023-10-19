%{
	#include <stdio.h>
	#include <string.h>
	
	int row = 1, column = 0, column_chr = 0, error=0, current_state_char =0 , current_state_comment = 0;
	char palavra[100];
	#define YY_USER_ACTION {column += yyleng;}
%}

%X COMMENT CHRLIT COMMENTLINE

NATURAL   [0-9]
IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
DECIMAL ([0-9]+(\.[0-9]*)*|\.[0-9]+)([eE][-+]?[0-9]+)?

CHAR "char"
ELSE "else"
WHILE "while"
IF "if"
INT "int"
SHORT "short"
DOUBLE "double"
RETURN "return"
VOID "void"
BITWISEAND "&"
BITWISEOR "|"
BITWISEXOR "ˆ"
AND "&&"
ASSIGN "="
MUL "*"
COMMA ","
DIV "/"
EQ "=="
GE ">="
GT ">"
LBRACE "{"
LE "<="
LPAR "("
LT "<"
MINUS "-"
MOD "%"
NE "!="
NOT "!"
OR "||"
PLUS "+"
RBRACE "}"
RPAR ")"
SEMI ";"
RESERVED "["|"]"|"++"|"--"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inrow"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"bool"|"complex"|"imaginary"
IGNORE " "|"\t"|"\n"|"\r"|"\f,|"\\"|"\"

erro .


%%

"/*"                            { BEGIN(COMMENT); 
                                  current_state_comment = 1;}
<COMMENT>\n|\r|\r\n             {row += 1;
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
                    

\'                                    { BEGIN(CHRLIT); 
                                        strcpy(palavra,"\0");
                                        error = 0;
                                        column_chr = column;
                                        current_state_char = 1;}
<CHRLIT>\\*"\n"                       { printf("Line %d, column %d: unterminated char constant\n",row, column_chr);
                                        row += 1;
                                        column = 0;
                                        BEGIN(INITIAL);
                                        current_state_char = 0;}
<CHRLIT>\\[0-7]{0,3}                  { strcat(palavra, yytext); error += 1;}
<CHRLIT>\\[^\"'nt\\]                  { strcat(palavra, yytext); error = 2;}
<CHRLIT>\\[\"'nt\\]                   { strcat(palavra, yytext); error += 1;}
<CHRLIT>\'                            { BEGIN(INITIAL);
                                        if(error == 1) printf("CHRLIT('%s')\n",palavra);
                                        else printf("Line %d, column %d: invalid char constant ('%s')\n",row, column_chr, palavra); 
                                        current_state_char = 0;}
<CHRLIT>.                             { strcat(palavra, yytext); error += 1; }

{IGNORE}                {   
                            if (*yytext == '\n'){
                                row += 1;
                                column = 0;
                            }
                        }

{NATURAL}+              { printf("NATURAL(%s)\n",yytext); }
{DECIMAL}               { printf("DECIMAL(%s)\n",yytext); }


{CHAR}                  { printf("CHAR\n");}
{ELSE}                  { printf("ELSE\n");}
{WHILE}                 { printf("WHILE\n");}
{IF}                    { printf("IF\n");}
{INT}                   { printf("INT\n");}
{SHORT}                 { printf("SHORT\n");}
{DOUBLE}                { printf("DOUBLE\n");}
{RETURN}                { printf("RETURN\n");}
{VOID}                  { printf("VOID\n");}
{BITWISEAND}            { printf("BITWISEAND\n");}
{BITWISEOR}             { printf("BITWISEOR\n");}
{BITWISEXOR}            { printf("BITWISEXOR\n");}
{AND}                   { printf("AND\n");}
{ASSIGN}                { printf("ASSIGN\n");}
{MUL}                   { printf("MUL\n");}
{COMMA}                 { printf("COMMA\n");}
{DIV}                   { printf("DIV\n");}
{EQ}                    { printf("EQ\n");}
{GE}                    { printf("GE\n");}
{GT}                    { printf("GT\n");}
{LBRACE}                { printf("LBRACE\n");}
{LE}                    { printf("LE\n");}
{LPAR}                  { printf("LPAR\n");}
{LT}                    { printf("LT\n");}
{MINUS}                 { printf("MINUS\n");}
{MOD}                   { printf("MOD\n");}
{NE}                    { printf("NE\n");}
{NOT}                   { printf("NOT\n");}
{OR}                    { printf("OR\n");}
{PLUS}                  { printf("PLUS\n");}
{RBRACE}                { printf("RBRACE\n");}
{RPAR}                  { printf("RPAR\n");}
{SEMI}                  { printf("SEMI\n");}
{RESERVED}              { printf("RESERVED(%s)\n",yytext);}



{IDENTIFIER}            { printf("IDENTIFIER(%s)\n",yytext);}
{erro}                  { printf("Line %d, column %d: unrecognized character (%s)\n",row, column, yytext); }

%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    if (current_state_char == 1) printf("Line %d, column %d: unterminated char constant\n",row, column_chr);
    if (current_state_comment == 1) printf("Line %d, column %d: unterminated comment\n",row, column_chr);
    return 1;
}