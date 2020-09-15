%%
AVERAGE        printf("AVERAGE\n");
FOR            printf("FOR\n");
WHILE          printf("WHILE\n");
TO             printf("TO\n");
ARRAY          printf("ARRAY\n");
NOOPTIMIZE     printf("NOOPTIMIZE\n");
ALL            printf("ALL\n");
NEXT           printf("NEXT\n");
RECORD         printf("RECORD\n");
REST           printf("REST\n");
","            printf("COMMA\n");
"+"            printf("PLUS\n");
"-"            printf("MINUS\n");
"*"            printf("MULTIPLY\n");
"/"            printf("DIVIDE\n");
"<="           printf("LEQ\n");
">="           printf("GEQ\n");
"<>"|"#"|"!="  printf("NEQ\n");
"=="           printf("STR_EQ\n");
"="            printf("EQUAL\n");
"<"            printf("LESS\n");
">"            printf("GREATER\n");
AND            printf("AND\n");
OR             printf("OR\n");
NOT            printf("NOT\n");
"("            printf("OP\n");
")"            printf("CP\n");
[a-zA-Z][a-zA-Z0-9]* printf("IDENTIFIER\n");
[1-9][0-9]*          printf("NUMBER\n");
[ \t]           {/*ignore whitespace*/}
%%
