%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbol and Scope Structures
typedef struct Symbol {
    char *name;
    char *type;
    struct Symbol *next;
} Symbol;

typedef struct Scope {
    Symbol *symbols;
    struct Scope *parent;
} Scope;

Scope *current_scope = NULL;
void enter_scope();
void leave_scope();
int add_symbol(const char *name, const char *type);
Symbol* check_symbol(const char *name);
Symbol* find_symbol_in_scope(const char *name, Scope *scope);
int main_defined = 0;

void enter_scope() {
    Scope *new_scope = (Scope *)malloc(sizeof(Scope));
    if (!new_scope) {
        fprintf(stderr, "Error: malloc failed in enter_scope\n");
        exit(EXIT_FAILURE);
    }
    new_scope->symbols = NULL;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void leave_scope() {
    Scope *old_scope = current_scope;
    current_scope = current_scope->parent;
    free(old_scope);
}

int add_symbol(const char *name, const char *type) {
    if (find_symbol_in_scope(name, current_scope) != NULL) {
        return 0;
    }

    Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
    if (!new_symbol) {
        fprintf(stderr, "Error: malloc failed in add_symbol\n");
        exit(EXIT_FAILURE);
    }
    new_symbol->name = strdup(name);
    if (!new_symbol->name) {
        fprintf(stderr, "Error: strdup failed in add_symbol\n");
        exit(EXIT_FAILURE);
    }
    new_symbol->type = strdup(type);
    if (!new_symbol->type) {
        fprintf(stderr, "Error: strdup failed in add_symbol\n");
        exit(EXIT_FAILURE);
    }
    new_symbol->next = current_scope->symbols;
    current_scope->symbols = new_symbol;
    return 1;
}

Symbol* check_symbol(const char *name) {
    Scope *scope = current_scope;
    while (scope != NULL) {
        Symbol *symbol = find_symbol_in_scope(name, scope);
        if (symbol != NULL) {
            return symbol;
        }
        scope = scope->parent;
    }
    return NULL;
}

Symbol* find_symbol_in_scope(const char *name, Scope *scope) {
    Symbol *symbol = scope->symbols;
    while (symbol != NULL) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol;
        }
        symbol = symbol->next;
    }
    return NULL;
}

extern int yylineno;
extern char* yytext;

int yyerror(char* e) {
    fflush(stdout);
    fprintf(stderr, "Error: %s at line %d\n", e, yylineno);
    fprintf(stderr, "Last token: %s\n", yytext);
    return 0;
}

void print_error(const char* error_message) {
    fprintf(stderr, "Semantic Error: %s at line %d\n", error_message, yylineno);
}

typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
} node;

node* mkleaf(char* token) {
    node* newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        fprintf(stderr, "Error: malloc failed in mkleaf\n");
        exit(EXIT_FAILURE);
    }
    newnode->token = strdup(token);
    if (!newnode->token) {
        fprintf(stderr, "Error: strdup failed in mkleaf\n");
        exit(EXIT_FAILURE);
    }
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

PROGRAM
    : CODE { printtree($1); }
    ;

CODE
    : FUNCTIONS { $$ = mknode("CODE", $1, NULL); }
    ;

FUNCTIONS
    : FUNCTION FUNCTIONS { $$ = mknode("FUNCTIONS", $1, $2); }
    | FUNCTION { $$ = mknode("FUNCTIONS", $1, NULL); }
    ;

FUNCTION
    : PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' {
          enter_scope();
          if (strcmp($3, "main") == 0) {
              if (main_defined) {
                  print_error("Multiple definitions of 'main'");
              } else {
                  if (strcmp($2, "void") != 0 || strcmp($7, "STATIC") != 0 || $5 != NULL) {
                      print_error("'main' function must be public, static, void, and have no parameters");
                  }
                  main_defined = 1;
              }
          }
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9)));
          leave_scope();
      }
    | PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' {
          enter_scope();
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9)));
          leave_scope();
      }
    | PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' '{' FUNCTION_BODY '}' {
          enter_scope();
          if (strcmp($3, "main") == 0) {
              if (main_defined) {
                  print_error("Multiple definitions of 'main'");
              } else {
                  if (strcmp($2, "void") != 0 || $5 != NULL) {
                      print_error("'main' function must be public, static, void, and have no parameters");
                  }
                  main_defined = 1;
              }
          }
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", NULL, $8)));
          leave_scope();
      }
    | PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' '{' FUNCTION_BODY '}' {
          enter_scope();
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", NULL, $8)));
          leave_scope();
      }
    | PUBLIC FUNCTION_TYPE IDENTIFIER '(' ')' FUNCTION_MOD '{' FUNCTION_BODY '}' {
          enter_scope();
          if (strcmp($3, "main") == 0) {
              if (main_defined) {
                  print_error("Multiple definitions of 'main'");
              } else {
                  if (strcmp($2, "void") != 0 || strcmp($6, "STATIC") != 0) {
                      print_error("'main' function must be public, static, void, and have no parameters");
                  }
                  main_defined = 1;
              }
          }
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", NULL, mknode("BODY", $6, $8)));
          leave_scope();
      }
    | PRIVATE FUNCTION_TYPE IDENTIFIER '(' ')' FUNCTION_MOD '{' FUNCTION_BODY '}' {
          enter_scope();
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", NULL, mknode("BODY", $6, $8)));
          leave_scope();
      }
    | PUBLIC FUNCTION_TYPE IDENTIFIER '(' ')' '{' FUNCTION_BODY '}' {
          enter_scope();
          if (strcmp($3, "main") == 0) {
              if (main_defined) {
                  print_error("Multiple definitions of 'main'");
              } else {
                  if (strcmp($2, "void") != 0) {
                      print_error("'main' function must be public, static, void, and have no parameters");
                  }
                  main_defined = 1;
              }
          }
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("BODY", NULL, $7));
          leave_scope();
      }
    | PRIVATE FUNCTION_TYPE IDENTIFIER '(' ')' '{' FUNCTION_BODY '}' {
          enter_scope();
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("BODY", NULL, $7));
          leave_scope();
      }
    ;

HAS_PARAMS
    : ARGS PARAMETER_LIST { $$ = mknode("ARGS", $2, NULL); }
    | { $$ = NULL; }
    ;

FUNCTION_MOD
    : ':' STATIC { $$ = mkleaf("STATIC"); }
    | { $$ = mkleaf("NON-STATIC"); }
    ;

PARAMETER_LIST
    : PARAMETER { $$ = $1; }
    | PARAMETER ';' PARAMETER_LIST { $$ = mknode(",", $1, $3); }
    ;

PARAMETER
    : PARAMETER_TYPE ':' IDENTIFIERS {
          $$ = mknode("", $1, $3);
          // Add each identifier in the parameter list to the symbol table
          struct node* ids = $3;
          while (ids) {
              if (!add_symbol(ids->token, $1->token)) {
                  print_error("Redeclaration of parameter");
              }
              ids = ids->right;
          }
      }
    ;

IDENTIFIERS
    : IDENTIFIER ',' IDENTIFIERS { $$ = mknode("", mkleaf($1), $3); }
    | IDENTIFIER { $$ = mkleaf($1); }
    ;

PARAMETER_TYPE
    : INT { $$ = mkleaf("int"); }
    | FLOAT { $$ = mkleaf("float"); }
    | DOUBLE { $$ = mkleaf("double"); }
    | CHAR { $$ = mkleaf("char"); }
    | INT_POINTER { $$ = mkleaf("int*"); }         
    | CHAR_POINTER { $$ = mkleaf("char*"); }      
    | REAL_POINTER { $$ = mkleaf("double*"); }     
    | FLOAT_POINTER { $$ = mkleaf("float*"); }
    ;

FUNCTION_TYPE
    : VOID { $$ = mkleaf("void"); }
    | INT { $$ = mkleaf("int"); }
    | FLOAT { $$ = mkleaf("float"); }
    | DOUBLE { $$ = mkleaf("double"); }
    | CHAR { $$ = mkleaf("char"); }
    | INT_POINTER { $$ = mkleaf("int*"); }         
    | CHAR_POINTER { $$ = mkleaf("char*"); }       
    | REAL_POINTER { $$ = mkleaf("double*"); }     
    | BOOL { $$ = mkleaf("bool"); }
    ;

FUNCTION_BODY
    : DECLARATIONS STATEMENTS { $$ = mknode("BODY", $1, $2); }
    | STATEMENTS { $$ = mknode("BODY", NULL, $1); }
    | { $$ = mknode("BODY", NULL, NULL); }
    ;

DECLARATIONS
    : VAR_DECLARATION DECLARATIONS { $$ = mknode("", $1, $2); }
    | NESTED_FUNCTIONS DECLARATIONS { $$ = mknode("", $1, $2); }
    | STRING_DECLARATION DECLARATIONS { $$ = mknode("", $1, $2); }
    | VAR_DECLARATION { $$ = mknode("", $1, NULL); }
    | NESTED_FUNCTIONS { $$ = mknode("", $1, NULL); }
    | STRING_DECLARATION { $$ = mknode("", $1, NULL); }
    ;

STATEMENTS
    : STATEMENT STATEMENTS { $$ = mknode("", $1, $2); }
    | STATEMENT { $$ = mknode("", $1, NULL); }
    ;

NESTED_FUNCTIONS
    : PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' {
          enter_scope();
          if (strcmp($3, "main") == 0) {
              if (main_defined) {
                  print_error("Multiple definitions of 'main'");
              } else {
                  if (strcmp($2, "void") != 0 || strcmp($7, "STATIC") != 0 || $5 != NULL) {
                      print_error("'main' function must be public, static, void, and have no parameters");
                  }
                  main_defined = 1;
              }
          }
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PUBLIC", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9)));
          leave_scope();
      }
    | PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}' {
          enter_scope();
          if (!add_symbol($3, $2)) {
              print_error("Redeclaration of function");
          }
          $$ = mknode("FUNC", mknode("PRIVATE", mkleaf($3), NULL), mknode("PARAMS", $5, mknode("BODY", $7, $9)));
          leave_scope();
      }
    ;

STATEMENT
    : IF '(' EXPR ')' '{' FUNCTION_BODY '}' {
          if (strcmp($3->token, "bool") != 0) {
              print_error("Condition in if statement must be of type bool");
          }
          $$ = mknode("IF", $3, $6);
      }
    | IF '(' EXPR ')' '{' FUNCTION_BODY '}' ELSE '{' FUNCTION_BODY '}' {
          if (strcmp($3->token, "bool") != 0) {
              print_error("Condition in if statement must be of type bool");
          }
          $$ = mknode("IF-ELSE", mknode("IF", $3, $6), $10);
      }
    | WHILE '(' EXPR ')' '{' FUNCTION_BODY '}' {
          if (strcmp($3->token, "bool") != 0) {
              print_error("Condition in while statement must be of type bool");
          }
          $$ = mknode("WHILE", $3, $6);
      }
    | FOR '(' STATEMENT EXPR ';' STATEMENT ')' '{' FUNCTION_BODY '}' {
          if (strcmp($4->token, "bool") != 0) {
              print_error("Condition in for statement must be of type bool");
          }
          $$ = mknode("FOR", $3, mknode("", $4, mknode("", $6, $9)));
      }
    | RETURN EXPR ';' { $$ = mknode("RETURN", $2, NULL); }
    | IDENTIFIER ASSIGN EXPR ';' {
          Symbol* sym = check_symbol($1);
          if (!sym) {
              print_error("Undeclared variable");
          } else if (strcmp(sym->type, $3->token) != 0) {
              print_error("Type mismatch in assignment");
          }
          $$ = mknode("ASSIGN", mkleaf($1), $3);
      }
    | DECLARATION ASSIGN EXPR ';' {
          if (strcmp($1->token, $3->token) != 0) {
              print_error("Type mismatch in assignment");
          }
          $$ = mknode("DECL-ASSIGN", $1, $3);
      }
    | VAR_DECLARATION { $$ = $1; }
    | STRING_DECLARATION { $$ = $1; }
    | EXPR ';' { $$ = $1; }
    ;

DECLARATION
    : PARAMETER_TYPE IDENTIFIER {
          if (!add_symbol($2, $1->token)) {
              print_error("Redeclaration of variable");
          }
          $$ = mknode("DECLARATION", $1, mkleaf($2));
      }
    ;

VAR_DECLARATION
    : VAR PARAMETER_TYPE ':' VAR_ASSIGN_LIST ';' {
          node* list = $4;
          while (list) {
              if (list->left && !add_symbol(list->left->token, $2->token)) {
                  print_error("Redeclaration of variable");
              }
              list = list->right;
          }
          $$ = mknode("VAR_DECLARATION", $2, $4);
      }
    ;

VAR_ASSIGN_LIST
    : IDENTIFIER ASSIGN EXPR { $$ = mknode("VAR_ASSIGN", mkleaf($1), $3); }
    | IDENTIFIER ASSIGN EXPR ',' VAR_ASSIGN_LIST { $$ = mknode("VAR_ASSIGN_LIST", mknode("VAR_ASSIGN", mkleaf($1), $3), $5); }
    | IDENTIFIER { $$ = mkleaf($1); }
    | IDENTIFIER ',' VAR_ASSIGN_LIST { $$ = mknode("VAR_ASSIGN_LIST", mkleaf($1), $3); }
    ;

STRING_DECLARATION
    : STRING STRING_DECL_LIST ';' { $$ = mknode("STRING_DECLARATION", $2, NULL); }
    ;

STRING_DECL_LIST
    : STRING_DECL_ELEM ',' STRING_DECL_LIST { $$ = mknode("STRING_DECL_LIST", $1, $3); }
    | STRING_DECL_ELEM { $$ = $1; }
    ;

STRING_DECL_ELEM
    : IDENTIFIER '[' INTEGER ']' ASSIGN STRING_LITERAL {
          $$ = mknode("STRING_ASSIGN", mkleaf($1), mknode("ARRAY", mkleaf($3), mkleaf($6)));
      }
    | IDENTIFIER '[' INTEGER ']' { $$ = mknode("ARRAY_DECL", mkleaf($1), mkleaf($3)); }
    ;

EXPR
    : EXPR '+' EXPR { $$ = mknode("+", $1, $3); }
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
    | IDENTIFIER {
          if (!check_symbol($1)) {
              print_error("Undeclared variable");
          }
          $$ = mkleaf($1);
      }
    | INTEGER { $$ = mkleaf($1); }
    | FLOAT_LITERAL { $$ = mkleaf($1); }
    | CHAR_LITERAL { $$ = mkleaf($1); }
    | STRING_LITERAL { $$ = mkleaf($1); }
    | BOOL_TRUE { $$ = mkleaf("TRUE"); }
    | BOOL_FALSE { $$ = mkleaf("FALSE"); }
    | '(' EXPR ')' { $$ = $2; }
    ;

%%

int main() {
    yyparse();
    return 0;
}
