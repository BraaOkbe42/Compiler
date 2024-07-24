%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
} node;

node* mkleaf(char* token);
node* mknode(char* token, node* left, node* right);
void printtree(node* tree);
extern int yylineno;
extern char* yytext;

int yyerror(char* e);

%}

%union {
  char* string; 
  struct node* node;
}

%type <node> PROGRAM CODE FUNCTIONS FUNCTION PARAMETER_LIST PARAMETER_TYPE PARAMETER FUNCTION_BODY STATEMENT EXPR HAS_PARAMS DECLARATION VAR_DECLARATION NESTED_FUNCTIONS STRING_DECLARATION
%type <node> IDENTIFIERS STATEMENTS DECLARATIONS STRING_DECL_ELEM
%type <string> FUNCTION_TYPE FUNCTION_MOD VAR_ASSIGN_LIST STRING_DECL_LIST
%token <string> BOOL CHAR INT STRING FLOAT DOUBLE VOID IF BOOL_TRUE BOOL_FALSE ELSE WHILE FOR VAR MAIN RETURN NULL_ DO PUBLIC PRIVATE STATIC ARGS
%token <string> IDENTIFIER INTEGER FLOAT_LITERAL CHAR_LITERAL STRING_LITERAL
%token <string> INT_POINTER CHAR_POINTER REAL_POINTER FLOAT_POINTER
%token <string> AND OR EQ NE GE LE ASSIGN

%start PROGRAM

%%

PROGRAM         : CODE { printtree($1); }
                ;

CODE            : FUNCTIONS { $$ = mknode("CODE", $1, NULL); }
                ;

FUNCTIONS       : FUNCTION FUNCTIONS { $$ = mknode("FUNCTIONS", $1, $2); }
                | FUNCTION { $$ = mknode("FUNCTIONS", $1, NULL); }
                ;

FUNCTION        : PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9))); }
                | PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9))); }
                | PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", NULL, $8))); }
                | PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", NULL, $8))); }
                | PUBLIC FUNCTION_TYPE IDENTIFIER '(' ')' '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("BODY", NULL, $7)); }
                | PRIVATE FUNCTION_TYPE IDENTIFIER '(' ')' '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("BODY", NULL, $7)); }
                ;
                
HAS_PARAMS      : ARGS PARAMETER_LIST { $$ = mknode("ARGS", $2, NULL); }
                | { $$ = NULL; };

FUNCTION_MOD    : ':' STATIC { $$ = mkleaf("STATIC"); }
                | { $$ = mkleaf("NON-STATIC"); };

PARAMETER_LIST  : PARAMETER { $$ = $1; }
                | PARAMETER ';' PARAMETER_LIST { $$ = mknode(",", $1, $3); }
                ;

PARAMETER       : PARAMETER_TYPE ':' IDENTIFIERS { $$ = mknode("", $1, $3); }
                ;
                
IDENTIFIERS     : IDENTIFIER ',' IDENTIFIERS { $$ = mknode("", mkleaf($1), $3); }
                | IDENTIFIER { $$ = mkleaf($1); }
                ;

PARAMETER_TYPE  : INT { $$ = mkleaf("int"); }
                | FLOAT { $$ = mkleaf("float"); }
                | DOUBLE { $$ = mkleaf("double"); }
                | CHAR { $$ = mkleaf("char"); }
                | INT_POINTER { $$ = mkleaf("int*"); }         
                | CHAR_POINTER { $$ = mkleaf("char*"); }      
                | REAL_POINTER { $$ = mkleaf("double*"); }     
                | FLOAT_POINTER { $$ = mkleaf("float*"); }
                ;

FUNCTION_TYPE   : VOID { $$ = mkleaf("void"); }
                | INT { $$ = mkleaf("int"); }
                | FLOAT { $$ = mkleaf("float"); }
                | DOUBLE { $$ = mkleaf("double"); }
                | CHAR { $$ = mkleaf("char"); }
                | INT_POINTER { $$ = mkleaf("int*"); }         
                | CHAR_POINTER { $$ = mkleaf("char*"); }       
                | REAL_POINTER { $$ = mkleaf("double*"); }     
                | BOOL { $$ = mkleaf("bool"); }  /* Added BOOL type */
                ;

FUNCTION_BODY   : DECLARATIONS STATEMENTS { $$ = mknode("BODY", $1, $2); }
                | STATEMENTS { $$ = mknode("BODY", NULL, $1); }
                | { $$ = mknode("BODY", NULL, NULL); }
                ;

DECLARATIONS    : VAR_DECLARATION DECLARATIONS { $$ = mknode("", $1, $2); }
                | NESTED_FUNCTIONS DECLARATIONS { $$ = mknode("", $1, $2); }
                | STRING_DECLARATION DECLARATIONS { $$ = mknode("", $1, $2); }
                | VAR_DECLARATION { $$ = mknode("", $1, NULL); }
                | NESTED_FUNCTIONS { $$ = mknode("", $1, NULL); }
                | STRING_DECLARATION { $$ = mknode("", $1, NULL); }
                ;

STATEMENTS      : STATEMENT STATEMENTS { $$ = mknode("", $1, $2); }
                | STATEMENT { $$ = mknode("", $1, NULL); }
                ;

NESTED_FUNCTIONS: PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9))); }
                | PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' { $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9))); }
                ;
                
STATEMENT       : IF '(' EXPR ')' '{' FUNCTION_BODY '}' { $$ = mknode("IF", $3, $6); }
                | IF '(' EXPR ')' '{' FUNCTION_BODY '}' ELSE '{' FUNCTION_BODY '}' { $$ = mknode("IF-ELSE", mknode("IF", $3, $6), $10); }
                | WHILE '(' EXPR ')' '{' FUNCTION_BODY '}' { $$ = mknode("WHILE", $3, $6); }
                | FOR '(' STATEMENT EXPR ';' STATEMENT ')' '{' FUNCTION_BODY '}' { $$ = mknode("FOR", $3, mknode("", $4, mknode("", $6, $9))); }
                | RETURN EXPR ';' { $$ = mknode("RETURN", $2, NULL); }
                | IDENTIFIER ASSIGN EXPR ';' { $$ = mknode("ASSIGN", mkleaf($1), $3); }
                | DECLARATION ASSIGN EXPR ';' { $$ = mknode("DECL-ASSIGN", $1, $3); }
                | VAR_DECLARATION { $$ = $1; }
                | STRING_DECLARATION { $$ = $1; }
                | EXPR ';' { $$ = $1; }
                ;

DECLARATION     : PARAMETER_TYPE IDENTIFIER { $$ = mknode("DECLARATION", $1, mkleaf($2)); }
                ;

VAR_DECLARATION : VAR PARAMETER_TYPE ':' VAR_ASSIGN_LIST ';' { $$ = mknode("VAR_DECLARATION", $2, $4); }
                ;

VAR_ASSIGN_LIST : IDENTIFIER ASSIGN EXPR { $$ = mknode("VAR_ASSIGN", mkleaf($1), $3); }
                | IDENTIFIER ASSIGN EXPR ',' VAR_ASSIGN_LIST { $$ = mknode("VAR_ASSIGN_LIST", mknode("VAR_ASSIGN", mkleaf($1), $3), $5); }
                | IDENTIFIER { $$ = mkleaf($1); }
                | IDENTIFIER ',' VAR_ASSIGN_LIST { $$ = mknode("VAR_ASSIGN_LIST", mkleaf($1), $3); }
                ;

STRING_DECLARATION : STRING STRING_DECL_LIST ';' { $$ = mknode("STRING_DECLARATION", $2, NULL); }
                   ;

STRING_DECL_LIST : STRING_DECL_ELEM ',' STRING_DECL_LIST { $$ = mknode("STRING_DECL_LIST", $1, $3); }
                 | STRING_DECL_ELEM { $$ = $1; }
                 ;

STRING_DECL_ELEM : IDENTIFIER '[' INTEGER ']' ASSIGN STRING_LITERAL { $$ = mknode("STRING_ASSIGN", mkleaf($1), mknode("ARRAY", mkleaf($3), mkleaf($6))); }
                 | IDENTIFIER '[' INTEGER ']' { $$ = mknode("ARRAY_DECL", mkleaf($1), mkleaf($3)); }
                 ;

EXPR            : EXPR '+' EXPR { $$ = mknode("+", $1, $3); }
                | EXPR '-' EXPR { $$ = mknode("-", $1, $3); }
                | EXPR '*' EXPR { $$ = mknode("*", $1, $3); }
                | EXPR '/' EXPR { $$ = mknode("/", $1, $3); }
                | EXPR EQ EXPR { $$ = mknode("==", $1, $3); }
                | EXPR NE EXPR { $$ = mknode("!=", $1, $3); }
                | EXPR GE EXPR { $$ = mknode(">=", $1, $3); }
                | EXPR LE EXPR { $$ = mknode("<=", $1, $3); }
                | EXPR '>' EXPR { $$ = mknode(">", $1, $3); }
                | EXPR '<' EXPR { $$ = mknode("<", $1, $3); }
                | EXPR AND EXPR { $$ = mknode("&&", $1, $3); }
                | EXPR OR EXPR { $$ = mknode("||", $1, $3); }
                | IDENTIFIER { $$ = mkleaf($1); }
                | INTEGER { $$ = mkleaf($1); }
                | FLOAT_LITERAL { $$ = mkleaf($1); }
                | CHAR_LITERAL { $$ = mkleaf($1); }
                | STRING_LITERAL { $$ = mkleaf($1); }
                | BOOL_TRUE { $$ = mkleaf("TRUE"); }
                | BOOL_FALSE { $$ = mkleaf("FALSE"); }
                | '(' EXPR ')' { $$ = $2; }
                ;

%%

node* mkleaf(char* token) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->token = strdup(token);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* mknode(char* token, node* left, node* right) {
    node* newnode = mkleaf(token);
    newnode->left = left;
    newnode->right = right;
    return newnode;
}

void printtree(node* tree) {
    if (tree == NULL) return;
    static int depth = 0;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%s\n", tree->token);
    depth++;
    printtree(tree->left);
    printtree(tree->right);
    depth--;
}

int yyerror(char* e) {
    fflush(stdout);
    fprintf(stderr, "Error: %s at line %d\n", e, yylineno);
    fprintf(stderr, "Last token: %s\n", yytext);
    return 0;
}

int main() {
    yyparse();
    return 0;
}
