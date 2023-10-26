%{
	#include <stdio.h>
	#include <string.h>
	
	int row = 1, column = 0;
	char palavra[100];
	#define YY_USER_ACTION {column += yyleng;}
%}

%X COMMENT WORD

digit   [0-9]
identifier [a-z][a-z0-9]*
keywords "integer"|"double"|"if"|"then"|"else"
ignore " "|"\t"|"\n"|"\r"|"\f,|"\\"|"\"
punctuation [()=,*/+-]
error .


%%

"/*"			{BEGIN(COMMENT);}
<COMMENT>.		{ECHO;}
<COMMENT>\r|\n|\r\n {
                        row += 1;
                        column = 0;
                    }		
                                                                       
<COMMENT>"*/"		{BEGIN(INITIAL);}

\"									{ BEGIN(WORD); }
<WORD>\\+[^fnrt\"]+					{ printf("error.. \n");
									  BEGIN(INITIAL);
									  strcpy(palavra,"\0");}
<WORD>\"							{ BEGIN(INITIAL);
									  printf("STRLIT (\"%s\")\n",palavra);
									  strcpy(palavra,"\0"); }
<WORD>"\n"							{ printf("error.. \n");
									  BEGIN(INITIAL);
									  strcpy(palavra,"\0"); }
<WORD>.								{ strcat(palavra,yytext); }


{ignore}                {   
                            if (*yytext == '\n'){
                                row += 1;
                                column = 0;
                            }
                        }
{punctuation}           { printf("%s\n",yytext);}
{digit}+                { printf("NATURAL %s\n",yytext); }
{digit}*"."{digit}+     { printf("DECIMAL  %s\n",yytext); }
{keywords}              { printf("%s\n",yytext);}
{identifier}            { printf("IDENTIFIER %s\n",yytext);}
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
