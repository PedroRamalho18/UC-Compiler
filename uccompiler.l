%{
	#include <stdio.h>
	#include <string.h>
	
	int row = 1, column = 0, error=0;
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
RESERVED "["|"]"|"++"|"--"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"bool"|"complex"|"imaginary"
IGNORE " "|"\t"|"\n"|"\r"|"\f,|"\\"|"\"

error .


%%

"/*"                            { BEGIN(COMMENT); }
<COMMENT>\n|\r|\r\n                {row += 1;
                                 column = 0;}
                                 
<COMMENT>"*/"                    { BEGIN(INITIAL); }
<COMMENT>.                        {;}

"//"                            {BEGIN(COMMENTLINE);}                                                          
<COMMENTLINE>\r|\n|\r\n            {BEGIN(INITIAL);
                                row += 1;
                                column = 0;
                                }
<COMMENTLINE>.                    {;}
                    

{IGNORE}                {   
                            if (*yytext == '\n'){
                                row += 1;
                                column = 0;
                            }
                        }

{NATURAL}+              { printf("NATURAL\n"); }
{DECIMAL}               { printf("DECIMAL %s\n",yytext); }

\"                                    { BEGIN(CHRLIT); 
                                      strcpy(palavra,"\0");}
<CHRLIT>"\n"                            { printf("error.. \n");
                                      BEGIN(INITIAL);}
<CHRLIT>\"[^\"]                        { BEGIN(INITIAL);
                                      if(error <= 1) printf("CHARLIT (\'%s')\n",palavra);
                                      else printf("error.. \n");
                                      error = 0;}
<CHRLIT>\\[0-7]{0,3}                    { strcpy(palavra, yytext); error += 1;}
<CHRLIT>\\[^\"'nt\\]                    { error = 2;}
<CHRLIT>\\[\"'nt\\]                    { strcpy(palavra, yytext); error += 1;}
<CHRLIT>.                                { strcpy(palavra, yytext); error += 1;}

{CHAR}                  { printf("CHAR\n");}
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
{RESERVED}              { printf("RESERVED\n");}



{IDENTIFIER}            { printf("IDENTIFIER (%s)\n",yytext);}
{error}                 { printf("Unrecognized character '%s' (line %d, column %d)\n", yytext, row, column); }

%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}

