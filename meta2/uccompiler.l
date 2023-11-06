    /*Pedro Tiago Gomes Ramalho 2019248594
    André Rodrigues Costa Pinto 2021213497 */

%{
	#include <stdio.h>
	#include <string.h>
	
    int row = 1, row_comment = 0, column_comment = 0, column = 0, column_chr = 0, error=0, current_state_char =0 , current_state_comment = 0,flag=0;	
    char palavra[100];
	#define YY_USER_ACTION {column += yyleng;}

%}

%X COMMENT CHRLIT COMMENTLINE
NATURAL   [0-9]
RESERVED "["|"]"|"++"|"--"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inrow"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"bool"|"complex"|"imaginary"|"_Bool"|"_Complex"|"_Imaginary"|"inline"
IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
DECIMAL (\.[0-9]+([eE][-+]?[0-9]+)?)|([0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?)
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
BITWISEXOR "^"
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
IGNORE " "|"\t"|"\n"|"\r"|"\f,|"\\"|"\"
erro .


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
                                        if(error == 1){
                                            if(flag==1) printf("CHRLIT('%s')\n",palavra);
                                        }
                                        else printf("Line %d, column %d: invalid char constant ('%s')\n",row, column_chr, palavra); 
                                        current_state_char = 0;}
<CHRLIT>.                             { strcat(palavra, yytext); error += 1; }

{IGNORE}                {   
                            if (*yytext == '\n'){
                                row += 1;
                                column = 0;
                            }
                        }

{NATURAL}+              { if(flag==1) printf("NATURAL(%s)\n",yytext); }
{DECIMAL}               { if(flag==1) printf("DECIMAL(%s)\n",yytext); }


{CHAR}                  {if(flag==1)   printf("CHAR\n");}
{ELSE}                  {if(flag==1)   printf("ELSE\n");}
{WHILE}                 {if(flag==1)   printf("WHILE\n");}
{IF}                    {if(flag==1)   printf("IF\n");}
{INT}                   {if(flag==1)   printf("INT\n");}
{SHORT}                 {if(flag==1)   printf("SHORT\n");}
{DOUBLE}                {if(flag==1)   printf("DOUBLE\n");}
{RETURN}                {if(flag==1)   printf("RETURN\n");}
{VOID}                  {if(flag==1)   printf("VOID\n");}
{BITWISEAND}            {if(flag==1)   printf("BITWISEAND\n");}
{BITWISEOR}             {if(flag==1)   printf("BITWISEOR\n");}
{BITWISEXOR}            {if(flag==1)   printf("BITWISEXOR\n");}
{AND}                   {if(flag==1)   printf("AND\n");}
{ASSIGN}                {if(flag==1)   printf("ASSIGN\n");}
{MUL}                   {if(flag==1)   printf("MUL\n");}
{COMMA}                 {if(flag==1)   printf("COMMA\n");}
{DIV}                   {if(flag==1)   printf("DIV\n");}
{EQ}                    {if(flag==1)   printf("EQ\n");}
{GE}                    {if(flag==1)   printf("GE\n");}
{GT}                    {if(flag==1)   printf("GT\n");}
{LBRACE}                {if(flag==1)   printf("LBRACE\n");}
{LE}                    {if(flag==1)   printf("LE\n");}
{LPAR}                  {if(flag==1)   printf("LPAR\n");}
{LT}                    {if(flag==1)   printf("LT\n");}
{MINUS}                 {if(flag==1)   printf("MINUS\n");}
{MOD}                   {if(flag==1)   printf("MOD\n");}
{NE}                    {if(flag==1)   printf("NE\n");}
{NOT}                   {if(flag==1)   printf("NOT\n");}
{OR}                    {if(flag==1)   printf("OR\n");}
{PLUS}                  {if(flag==1)   printf("PLUS\n");}
{RBRACE}                {if(flag==1)   printf("RBRACE\n");}
{RPAR}                  {if(flag==1)   printf("RPAR\n");}
{SEMI}                  {if(flag==1)   printf("SEMI\n");}
{RESERVED}              {if(flag==1)   printf("RESERVED(%s)\n",yytext);}
{IDENTIFIER}            {if(flag==1)   printf("IDENTIFIER(%s)\n",yytext);}
{erro}                  { printf("Line %d, column %d: unrecognized character (%s)\n",row, column, yytext); }

%%
extern int yylex();
int main(int argc, char* argv[]) {
    if((argc >1) && (strcmp(argv[1],"-l")==0 )){
        flag=1;
    }
    
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    if (current_state_char == 1) printf("Line %d, column %d: unterminated char constant\n",row, column_chr);
    if (current_state_comment == 1) printf("Line %d, column %d: unterminated comment\n",row_comment, column_comment);
    return 1;
}