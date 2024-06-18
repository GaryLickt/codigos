#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum {
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_CHAR,
  TYPE_BOOL,
  TYPE_VOID,
  ID,
  NUM_INT,
  NUM_FLOAT,
  NUM_DOUBLE,
  TEXT,
  OP_ASSIGN,
  OP_PLUS_ASSIGN,
  OP_MINUS_ASSIGN,
  OP_TIMES_ASSIGN,
  OP_DIVIDE_ASSIGN,
  OP_MODULO_ASSIGN,
  OP_AND_ASSIGN,
  OP_OR_ASSIGN,
  OP_LOGICAL_AND,
  OP_LOGICAL_OR,
  OP_NOT,
  OP_GREATER_THAN,
  OP_GREATER_EQUAL,
  OP_LESS_THAN,
  OP_LESS_EQUAL,
  OP_NOT_EQUAL,
  OP_EQUAL,
  OP_PLUS,
  OP_MINUS,
  OP_TIMES,
  OP_DIVIDE,
  OP_MODULO,
  OP_INCREMENT,
  OP_DECREMENT,
  OP_DOT,
  OP_ARROW,
  KW_IF,
  KW_ELSE,
  KW_WHILE,
  KW_FOR,
  KW_SWITCH,
  KW_CASE,
  KW_DEFAULT,
  KW_BREAK,
  KW_CONTINUE,
  KW_RETURN,
  KW_STRUCT,
  SEMICOLON,
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  COMMA,
  COMMENT_LINE,
  COMMENT_BLOCK,
  OP_DOT_DOT_DOT,
  END_OF_FILE,
  UNKNOWN,
  ERROR
} TokenType;

// Token structure
typedef struct {
  TokenType type;
  char *lexeme;
} Token;

// Function prototypes
void syntaxError();
Token *getNextToken();
void match(int linha, TokenType expectedToken);
void Program();
void Declaracao();
void DeclaracaoVariavel();
void DeclaracaoFuncao();
void Parametros();
void Parametro();
void Bloco();
void Comentario();
void Expressao();
void Atribuicao();
void EstruturaControle();
void CaseLista();
void CaseDecl();
void DeclaracaoEstrutura();
void Array();
void ArrayInicializacao();
void ExpressaoLogica();
void ExpressaoRelacional();
void ExpressaoAritmetica();
void ExpressaoMultiplicativa();
void ExpressaoUnaria();
void ExpressaoPostfix();
void ExpressaoLista();
void Argumentos();
void Primaria();

// Global variables
Token *currentToken;
char input[1024];
int currentPosition = 0;
int inputLength = 0;
int linhaTamanho = 0;

int main() {
  // Inicialização
  FILE *arq = fopen("input.txt", "r");

  if (arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  } else {
    // Lê a primeira linha inteira do arquivo
    while ((inputLength = fgets(input, sizeof(input), arq)) != NULL) {
      // Verifica se a linha termina com `;` seguido de `\n`
      linhaTamanho = strlen(input);
      if ((input[linhaTamanho - 2] == ';' && input[linhaTamanho - 1] == '\n') ||
          (input[linhaTamanho - 2] == '}' && input[linhaTamanho - 1] == '\n')) {
        // Se sim, substitui `\n` por `\0`
        input[linhaTamanho - 1] = '\0';
        linhaTamanho -= 1;
      }

      printf("===============\nAnalisando linha:\n \"%s\"\n\n", input);
      currentPosition = 0;
      currentToken = getNextToken();
      Program();

      // Verifica o final do arquivo
      if (currentToken->type != END_OF_FILE) {
        printf("Erro: Final Arquivo\n");
        syntaxError();
      }

      printf("\nParsing successful.\n\n");
    }
  }

  // Libera a memória alocada para o último token
  free(currentToken);
  fclose(arq);

  return 0;
}

// Functions for parsing each production rule

void Program() {
  while (currentToken->type != END_OF_FILE) {
    Declaracao();
    // Liberar o token atual antes de obter o próximo
    free(currentToken);
    currentToken = getNextToken();
    if (currentToken->type == END_OF_FILE || currentToken->type == UNKNOWN) {
      break;
    }
  }
}

void Declaracao() {
  // Verifica se o token atual é um comentário e trata adequadamente
  if (currentToken->type == COMMENT_LINE ||
      currentToken->type == COMMENT_BLOCK) {
    Comentario();
  }
  // Verifica se o token atual é um tipo
  else if (currentToken->type == TYPE_INT || currentToken->type == TYPE_FLOAT ||
           currentToken->type == TYPE_DOUBLE ||
           currentToken->type == TYPE_CHAR || currentToken->type == TYPE_BOOL ||
           currentToken->type == TYPE_VOID) {
    // Avança para o próximo token
    Token *nextToken = getNextToken();
    // Verifica se o próximo token é um ID, o que indicaria uma declaração de
    // variável
    if (nextToken->type == ID) {
      free(nextToken);
      nextToken = getNextToken();
      if (nextToken->type == OP_ASSIGN) {
        // Trata a declaração de variável
        DeclaracaoVariavel();
      } else if (nextToken->type == LEFT_PAREN) {
        free(nextToken);
        // Como o próximo token é um '(', trata como uma declaração de função
        DeclaracaoFuncao();
      }
    }
    // Se não for nem um ID nem um '(', pode ser uma declaração inválida
    else {
      free(nextToken);
      // Emitir erro de sintaxe
      printf("Erro: Declaração Invalida\n");
      syntaxError();
    }
  }
  // Verifica se o token atual é a palavra-chave 'struct'
  else if (currentToken->type == KW_STRUCT) {
    // Trata a declaração de estrutura
    DeclaracaoEstrutura();
  } else if (currentToken->type == ID) {
    // Trata a atribuição
    Atribuicao();
  } else if (currentToken->type == KW_IF || currentToken->type == KW_FOR ||
             currentToken->type == KW_WHILE ||
             currentToken->type == KW_SWITCH ||
             currentToken->type == KW_RETURN ||
             currentToken->type == KW_BREAK ||
             currentToken->type == KW_CONTINUE ||
             currentToken->type == KW_DEFAULT) {
    EstruturaControle();
  } else if (currentToken->type == LEFT_BRACKET ||
             currentToken->type == LEFT_PAREN ||
             currentToken->type == LEFT_BRACE ||
             currentToken->type == SEMICOLON ||
     currentToken->type == RIGHT_BRACE ||
     currentToken->type == RIGHT_PAREN ||
     currentToken->type == RIGHT_BRACKET) {
    match(__LINE__, currentToken->type);
  }
  // Se não for nenhum dos casos acima, trata como uma declaração inválida
  else {
    // Emitir erro de sintaxe
    printf("Erro: Erro de Sintaxe\n");
    syntaxError();
  }
}

void DeclaracaoVariavel() {
  // DeclaracaoVariavel → Tipo ID ; | Tipo ID = Expressao ;
  if (currentToken->type == TYPE_INT || currentToken->type == TYPE_FLOAT ||
      currentToken->type == TYPE_DOUBLE || currentToken->type == TYPE_CHAR ||
      currentToken->type == TYPE_BOOL) {
    // Match Tipo
    match(__LINE__, currentToken->type);
    // Match ID
    if (currentToken->type == ID) {
      match(__LINE__, ID);
    } else if (currentToken->type == NUM_INT ||
               currentToken->type == NUM_FLOAT) {
      match(__LINE__, currentToken->type);
    }
    // Verifica se há atribuição
    if (currentToken->type == OP_ASSIGN) {
      // Match =
      match(__LINE__, OP_ASSIGN);
      // Chamada para Expressao
      Expressao();
    }
    // Match ; (after expression, if any)
    match(__LINE__, SEMICOLON);
  } else {
    printf("Erro: Declaração Variavel\n");
    syntaxError();
  }
}

void DeclaracaoFuncao() {
  // DeclaracaoFuncao → Tipo ID ( Parametros ) Bloco
  // DeclaracaoFuncao → Tipo ID ( ) Bloco
  // DeclaracaoFuncao → Tipo ID ( Parametros ) ;
  // DeclaracaoFuncao → Tipo ID ( ) ;

  if (currentToken->type == TYPE_INT || currentToken->type == TYPE_FLOAT ||
      currentToken->type == TYPE_DOUBLE || currentToken->type == TYPE_CHAR ||
      currentToken->type == TYPE_BOOL || currentToken->type == TYPE_VOID) {
    // Match Tipo
    match(__LINE__, currentToken->type);

    if (currentToken->type == ID) {
      // Match ID
      match(__LINE__, ID);
    } else {
      match(__LINE__, currentToken->type);
    }

    if (currentToken->type == LEFT_PAREN) {
      // Match (
      match(__LINE__, LEFT_PAREN);
      if (currentToken->type != RIGHT_PAREN) {
        // Chamada para Parametros
        Parametros();
      }
    } else {
      match(__LINE__, currentToken->type);
    }

    if (currentToken->type == RIGHT_PAREN) {
      // Match )
      match(__LINE__, RIGHT_PAREN);
      if (currentToken->type == LEFT_BRACE) {
        // DeclaracaoFuncao → Tipo ID ( Parametros ) Bloco
        // DeclaracaoFuncao → Tipo ID ( ) Bloco
        // Chamada para Bloco
        Bloco();
      } else if (currentToken->type == SEMICOLON) {
        // DeclaracaoFuncao → Tipo ID ( Parametros ) ;
        // DeclaracaoFuncao → Tipo ID ( ) ;
        // Match ;
        match(__LINE__, SEMICOLON);
      } else {
        printf("Erro: Declaração Função - Função incorreta\n");
        syntaxError();
      }
    } else {
      match(__LINE__, currentToken->type);
    }
  } else {
    printf("Erro: Declaração Função - Tipo invalido\n");
    syntaxError();
  }
}

void DeclaracaoEstrutura() {
  // DeclaracaoEstrutura → struct ID { DeclaracaoVariavel* } ;
  if (currentToken->type == KW_STRUCT) {
    // Match struct
    match(__LINE__, KW_STRUCT);
    // Match ID
    match(__LINE__, ID);
    // Match {
    match(__LINE__, LEFT_BRACE);
    // Loop para DeclaracaoVariavel*
    while (currentToken->type == TYPE_INT || currentToken->type == TYPE_FLOAT ||
           currentToken->type == TYPE_DOUBLE ||
           currentToken->type == TYPE_CHAR || currentToken->type == TYPE_BOOL) {
      DeclaracaoVariavel();
    }
    // Match }
    match(__LINE__, RIGHT_BRACE);
    // Match ;
    match(__LINE__, SEMICOLON);
  } else {
    printf("Erro: Declaração Estrutura\n");
    syntaxError();
  }
}

void Expressao() {
  // Expressao → Atribuicao | ExpressaoLogica
  if (currentToken->type == ID) {
    // Se o próximo token for um ID, então é uma atribuição
    Atribuicao();
  } else {
    // Caso contrário, é uma expressão lógica
    ExpressaoLogica();
  }
}

void Bloco() {
  // Bloco → { Declaracao* }
  // Match {
  match(__LINE__, LEFT_BRACE);
  // Loop para Declaracao*
  while (currentToken->type != RIGHT_BRACE) {
    Declaracao();
  }
  // Match }
  match(__LINE__, RIGHT_BRACE);
}

void Argumentos() {
  // Argumentos → ExpressaoLista
  ExpressaoLista();
}

void Atribuicao() {
  if (currentToken->type == ID) {
    match(__LINE__, ID); // Corresponde ao ID
    if (currentToken->type == LEFT_BRACKET) {
      match(__LINE__, LEFT_BRACKET);
      if (currentToken->type == NUM_INT || currentToken->type == NUM_FLOAT ||
          currentToken->type == ID) {
        match(__LINE__, currentToken->type);
      }
      match(__LINE__, RIGHT_BRACKET);
    }

    if (currentToken->type == OP_ASSIGN ||
        currentToken->type == OP_PLUS_ASSIGN ||
        currentToken->type == OP_MINUS_ASSIGN ||
        currentToken->type == OP_TIMES_ASSIGN ||
        currentToken->type == OP_DIVIDE_ASSIGN ||
        currentToken->type == OP_MODULO_ASSIGN ||
        currentToken->type == OP_AND_ASSIGN ||
        currentToken->type == OP_OR_ASSIGN || currentToken->type == OP_PLUS ||
        currentToken->type == OP_MINUS || currentToken->type == OP_TIMES ||
        currentToken->type == OP_DIVIDE || currentToken->type == OP_MODULO) {
      match(__LINE__,
            currentToken->type); // Corresponde ao operador de atribuição

      Expressao();
    } else if (currentToken->type == OP_LESS_THAN ||
               currentToken->type == OP_LESS_EQUAL ||
               currentToken->type == OP_GREATER_THAN ||
               currentToken->type == OP_GREATER_EQUAL ||
               currentToken->type == OP_EQUAL ||
               currentToken->type == OP_NOT_EQUAL) {
      match(__LINE__, currentToken->type);
      Expressao();
    } else if (currentToken->type == OP_INCREMENT ||
               currentToken->type == OP_DECREMENT) {
      match(__LINE__, currentToken->type);
    } else if (currentToken->type == RIGHT_PAREN ||
               currentToken->type == RIGHT_BRACE) {
      // não trata ) ou } NESSA função
    } else if (currentToken->type == SEMICOLON) {
      match(__LINE__, SEMICOLON); // Corresponde ao ;
    } else {
      printf("Erro: Operador de atribuição inválido ou ponto e vírgula "
             "esperado\n");
      syntaxError();
    }
  } else {
    printf("Erro: Atribuicao\n");
    syntaxError();
  }
}

void Primaria() {
  // Primaria → ID | NUM_INT | NUM_DEC | TEXT | ( Expressao )
  if (currentToken->type == ID || currentToken->type == NUM_INT ||
      currentToken->type == NUM_FLOAT || currentToken->type == NUM_DOUBLE ||
      currentToken->type == TEXT) {
    // Match ID, NUM_INT, NUM_DEC, TEXT
    match(__LINE__, currentToken->type);
  } else if (currentToken->type == LEFT_PAREN) {
    // Match (
    match(__LINE__, LEFT_PAREN);
    // Chamada recursiva para Expressao
    Expressao();
    // Match )
    match(__LINE__, RIGHT_PAREN);
  } else {
    printf("Erro: Primaria\n");
    syntaxError();
  }
}

void Parametro() {
  // Parametro → Tipo ID | Tipo ID [] | Tipo ... ID
  if (currentToken->type == TYPE_INT || currentToken->type == TYPE_FLOAT ||
      currentToken->type == TYPE_DOUBLE || currentToken->type == TYPE_CHAR ||
      currentToken->type == TYPE_BOOL) {
    // Match Tipo
    match(__LINE__, currentToken->type);
    // Match ID
    match(__LINE__, ID);
    // Verifica se é um array
    if (currentToken->type == LEFT_BRACKET) {
      // Match [
      match(__LINE__, LEFT_BRACKET);
      if (currentToken->type == NUM_INT){
        match(__LINE__, NUM_INT);
      }
      // Match ]
      match(__LINE__, RIGHT_BRACKET);
      
      // Verifica se não é uma matriz
      if (currentToken->type == LEFT_BRACKET) {
        // Match [
        match(__LINE__, LEFT_BRACKET);
        if (currentToken->type == NUM_INT){
          match(__LINE__, NUM_INT);
        }
        // Match ]
        match(__LINE__, RIGHT_BRACKET);
      }
    }
    // Verifica se é um parâmetro varargs
    if (currentToken->type == OP_DOT_DOT_DOT) {
      // Match ...
      match(__LINE__, OP_DOT_DOT_DOT);
      // Match ID
      match(__LINE__, ID);
    }
  } else {
    printf("Erro: Parametro\n");
    syntaxError();
  }
}

void Parametros() {
  // Caso base: Verifica se não há parâmetros (Parametros → ε)
  if (currentToken->type != RIGHT_PAREN) {
    // Caso 1: Parametros → Parametro
    Parametro();

    // Caso 2: Parametros → Parametro , Parametros
    while (currentToken->type == COMMA) {
      // Match , (consome a vírgula)
      match(__LINE__, COMMA);

      // Chama Parametro para o próximo parâmetro na lista
      Parametros();
    }
  }
  // Caso 3: Parametros → ε é tratado implicitamente quando currentToken->type
  // == RIGHT_PAREN
}

void Comentario() {
  // Comentario → // Qualquer texto até o final da linha
  if (currentToken->type == COMMENT_LINE) {
    // Match Comment Line
    match(__LINE__, COMMENT_LINE);
  }
  // Comentario → /* Qualquer texto até */
  else if (currentToken->type == COMMENT_BLOCK) {
    // Match Comment Block
    match(__LINE__, COMMENT_BLOCK);
  } else {
    printf("Erro: Comentario\n");
    syntaxError();
  }
}

void EstruturaControle() {
  // EstruturaControle → if ( Expressao ) Bloco
  // EstruturaControle → if ( Expressao ) Bloco else Bloco
  // EstruturaControle → while ( Expressao ) Bloco
  // EstruturaControle → for ( Expressao ; Expressao ; Expressao ) Bloco
  // EstruturaControle → switch ( Expressao ) CaseLista
  // EstruturaControle → break ;
  // EstruturaControle → continue ;
  // EstruturaControle → return Expressao ;

  switch (currentToken->type) {
  case KW_IF:
    match(__LINE__, KW_IF);
    match(__LINE__, LEFT_PAREN);
    Expressao();
    match(__LINE__, RIGHT_PAREN);
    Bloco();
    if (currentToken->type == KW_ELSE) {
      match(__LINE__, KW_ELSE);
      Bloco();
    }
    break;
  case KW_WHILE:
    match(__LINE__, KW_WHILE);
    match(__LINE__, LEFT_PAREN);
    Expressao();
    match(__LINE__, RIGHT_PAREN);
    Bloco();
    break;
  case KW_FOR:
    match(__LINE__, KW_FOR);
    match(__LINE__, LEFT_PAREN);
    Expressao();
    match(__LINE__, SEMICOLON);
    Expressao();
    match(__LINE__, SEMICOLON);
    Expressao();
    match(__LINE__, RIGHT_PAREN);
    Bloco();
    break;
  case KW_SWITCH:
    match(__LINE__, KW_SWITCH);
    match(__LINE__, LEFT_PAREN);
    Expressao();
    match(__LINE__, RIGHT_PAREN);
    CaseLista();
    break;
  case KW_BREAK:
  case KW_CONTINUE:
    match(__LINE__, currentToken->type);
    match(__LINE__, SEMICOLON);
    break;
  case KW_RETURN:
    match(__LINE__, KW_RETURN);
    Expressao();
    match(__LINE__, SEMICOLON);
    break;
  default:
    printf("Erro: Estrutura Controle\n");
    syntaxError();
  }
}

void CaseLista() {
  // CaseLista → CaseDecl*
  while (currentToken->type == KW_CASE || currentToken->type == KW_DEFAULT) {
    CaseDecl();
  }
}

void CaseDecl() {
  // CaseDecl → case Expressao : Bloco
  // CaseDecl → default : Bloco
  switch (currentToken->type) {
  case KW_CASE:
    match(__LINE__, KW_CASE);
    Expressao();
    match(__LINE__, SEMICOLON);
    Bloco();
    break;
  case KW_DEFAULT:
    match(__LINE__, KW_DEFAULT);
    match(__LINE__, SEMICOLON);
    Bloco();
    break;
  default:
    printf("Erro: CaseDecl\n");
    syntaxError();
  }
}

void ExpressaoLista() {
  // ExpressaoLista → Expressao
  Expressao();
  // ExpressaoLista → ExpressaoLista , Expressao
  while (currentToken->type == COMMA) {
    match(__LINE__, COMMA);
    Expressao();
  }
}

void ExpressaoLogica() {
  // ExpressaoLogica → ExpressaoRelacional
  // ExpressaoLogica → ExpressaoLogica && ExpressaoRelacional
  // ExpressaoLogica → ExpressaoLogica || ExpressaoRelacional
  // ExpressaoLogica → ! ExpressaoRelacional

  if (currentToken->type == OP_NOT) {
    match(__LINE__, OP_NOT);
    ExpressaoRelacional();
  } else {
    ExpressaoRelacional();
    while (currentToken->type == OP_LOGICAL_AND ||
           currentToken->type == OP_LOGICAL_OR) {
      match(__LINE__, currentToken->type);
      ExpressaoRelacional();
    }
  }
}

void ExpressaoRelacional() {
  // ExpressaoRelacional → ExpressaoAritmetica
  // ExpressaoRelacional → ExpressaoAritmetica > ExpressaoAritmetica
  // ExpressaoRelacional → ExpressaoAritmetica >= ExpressaoAritmetica
  // ExpressaoRelacional → ExpressaoAritmetica < ExpressaoAritmetica
  // ExpressaoRelacional → ExpressaoAritmetica <= ExpressaoAritmetica
  // ExpressaoRelacional → ExpressaoAritmetica != ExpressaoAritmetica
  // ExpressaoRelacional → ExpressaoAritmetica == ExpressaoAritmetica

  ExpressaoAritmetica();
  if (currentToken->type == OP_GREATER_THAN ||
      currentToken->type == OP_GREATER_EQUAL ||
      currentToken->type == OP_LESS_THAN ||
      currentToken->type == OP_LESS_EQUAL ||
      currentToken->type == OP_NOT_EQUAL || currentToken->type == OP_EQUAL) {
    match(__LINE__, currentToken->type);
    ExpressaoAritmetica();
  }
}

void ExpressaoAritmetica() {
  // ExpressaoAritmetica → ExpressaoMultiplicativa
  // ExpressaoAritmetica → ExpressaoAritmetica + ExpressaoMultiplicativa
  // ExpressaoAritmetica → ExpressaoAritmetica - ExpressaoMultiplicativa

  ExpressaoMultiplicativa();
  while (currentToken->type == OP_PLUS || currentToken->type == OP_MINUS) {
    match(__LINE__, currentToken->type);
    ExpressaoMultiplicativa();
  }
}

void ExpressaoMultiplicativa() {
  // ExpressaoMultiplicativa → ExpressaoUnaria
  // ExpressaoMultiplicativa → ExpressaoMultiplicativa * ExpressaoUnaria
  // ExpressaoMultiplicativa → ExpressaoMultiplicativa / ExpressaoUnaria
  // ExpressaoMultiplicativa → ExpressaoMultiplicativa % ExpressaoUnaria

  ExpressaoUnaria();
  while (currentToken->type == OP_TIMES || currentToken->type == OP_DIVIDE ||
         currentToken->type == OP_MODULO) {
    match(__LINE__, currentToken->type);
    ExpressaoUnaria();
  }
}

void ExpressaoUnaria() {
  // ExpressaoUnaria → ExpressaoPostfix
  // ExpressaoUnaria → - ExpressaoUnaria
  // ExpressaoUnaria → ++ ExpressaoPostfix
  // ExpressaoUnaria → -- ExpressaoPostfix

  if (currentToken->type == OP_MINUS || currentToken->type == OP_INCREMENT ||
      currentToken->type == OP_DECREMENT) {
    match(__LINE__, currentToken->type);
    ExpressaoUnaria(); // Chamada recursiva para tratar múltiplos operadores
                       // unários consecutivos
  } else {
    ExpressaoPostfix();
  }
}

void ExpressaoPostfix() {
  // ExpressaoPostfix → Primaria
  // ExpressaoPostfix → Primaria [ Expressao ]
  // ExpressaoPostfix → Primaria ( Argumentos )
  // ExpressaoPostfix → Primaria . ID
  // ExpressaoPostfix → Primaria -> ID

  Primaria();
  while (currentToken->type == LEFT_BRACKET ||
         currentToken->type == LEFT_PAREN || currentToken->type == OP_DOT ||
         currentToken->type == OP_ARROW) {
    if (currentToken->type == LEFT_BRACKET) {
      match(__LINE__, LEFT_BRACKET);
      Expressao();
      match(__LINE__, RIGHT_BRACKET);
    } else if (currentToken->type == LEFT_PAREN) {
      match(__LINE__, LEFT_PAREN);
      Argumentos();
      match(__LINE__, RIGHT_PAREN);
    } else {
      match(__LINE__, currentToken->type);
      match(__LINE__, ID);
    }
  }
}

void Array() {
  // Array → [ NUM_INT ] | [ ]
  if (currentToken->type == LEFT_BRACKET) {
    match(__LINE__, LEFT_BRACKET);
    if (currentToken->type == NUM_INT) {
      match(__LINE__, NUM_INT);
    }
    match(__LINE__, RIGHT_BRACKET);
  } else {
    printf("Erro: Array\n");
    syntaxError();
  }
}

void ArrayInicializacao() {
  // ArrayInicializacao → { ExpressaoLista }
  match(__LINE__, LEFT_BRACE);
  ExpressaoLista();
  match(__LINE__, RIGHT_BRACE);
}

void printTokenType(TokenType type) {
  switch (type) {
  case TYPE_INT:
    printf("TYPE_INT");
    break;
  case TYPE_FLOAT:
    printf("TYPE_FLOAT");
    break;
  case TYPE_DOUBLE:
    printf("TYPE_DOUBLE");
    break;
  case TYPE_CHAR:
    printf("TYPE_CHAR");
    break;
  case TYPE_BOOL:
    printf("TYPE_BOOL");
    break;
  case TYPE_VOID:
    printf("TYPE_VOID");
    break;
  case ID:
    printf("ID");
    break;
  case NUM_INT:
    printf("NUM_INT");
    break;
  case NUM_FLOAT:
    printf("NUM_FLOAT");
    break;
  case NUM_DOUBLE:
    printf("NUM_DOUBLE");
    break;
  case TEXT:
    printf("TEXT");
    break;
  case OP_ASSIGN:
    printf("OP_ASSIGN");
    break;
  case OP_PLUS_ASSIGN:
    printf("OP_PLUS_ASSIGN");
    break;
  case OP_MINUS_ASSIGN:
    printf("OP_MINUS_ASSIGN");
    break;
  case OP_TIMES_ASSIGN:
    printf("OP_TIMES_ASSIGN");
    break;
  case OP_DIVIDE_ASSIGN:
    printf("OP_DIVIDE_ASSIGN");
    break;
  case OP_MODULO_ASSIGN:
    printf("OP_MODULO_ASSIGN");
    break;
  case OP_AND_ASSIGN:
    printf("OP_AND_ASSIGN");
    break;
  case OP_OR_ASSIGN:
    printf("OP_OR_ASSIGN");
    break;
  case OP_LOGICAL_AND:
    printf("OP_LOGICAL_AND");
    break;
  case OP_LOGICAL_OR:
    printf("OP_LOGICAL_OR");
    break;
  case OP_NOT:
    printf("OP_NOT");
    break;
  case OP_GREATER_THAN:
    printf("OP_GREATER_THAN");
    break;
  case OP_GREATER_EQUAL:
    printf("OP_GREATER_EQUAL");
    break;
  case OP_LESS_THAN:
    printf("OP_LESS_THAN");
    break;
  case OP_LESS_EQUAL:
    printf("OP_LESS_EQUAL");
    break;
  case OP_NOT_EQUAL:
    printf("OP_NOT_EQUAL");
    break;
  case OP_EQUAL:
    printf("OP_EQUAL");
    break;
  case OP_PLUS:
    printf("OP_PLUS");
    break;
  case OP_MINUS:
    printf("OP_MINUS");
    break;
  case OP_TIMES:
    printf("OP_TIMES");
    break;
  case OP_DIVIDE:
    printf("OP_DIVIDE");
    break;
  case OP_MODULO:
    printf("OP_MODULO");
    break;
  case OP_INCREMENT:
    printf("OP_INCREMENT");
    break;
  case OP_DECREMENT:
    printf("OP_DECREMENT");
    break;
  case OP_DOT:
    printf("OP_DOT");
    break;
  case OP_ARROW:
    printf("OP_ARROW");
    break;
  case KW_IF:
    printf("KW_IF");
    break;
  case KW_ELSE:
    printf("KW_ELSE");
    break;
  case KW_WHILE:
    printf("KW_WHILE");
    break;
  case KW_FOR:
    printf("KW_FOR");
    break;
  case KW_SWITCH:
    printf("KW_SWITCH");
    break;
  case KW_CASE:
    printf("KW_CASE");
    break;
  case KW_DEFAULT:
    printf("KW_DEFAULT");
    break;
  case KW_BREAK:
    printf("KW_BREAK");
    break;
  case KW_CONTINUE:
    printf("KW_CONTINUE");
    break;
  case KW_RETURN:
    printf("KW_RETURN");
    break;
  case KW_STRUCT:
    printf("KW_STRUCT");
    break;
  case SEMICOLON:
    printf("SEMICOLON");
    break;
  case LEFT_BRACE:
    printf("LEFT_BRACE");
    break;
  case RIGHT_BRACE:
    printf("RIGHT_BRACE");
    break;
  case LEFT_PAREN:
    printf("LEFT_PAREN");
    break;
  case RIGHT_PAREN:
    printf("RIGHT_PAREN");
    break;
  case LEFT_BRACKET:
    printf("LEFT_BRACKET");
    break;
  case RIGHT_BRACKET:
    printf("RIGHT_BRACKET");
    break;
  case COMMA:
    printf("COMMA");
    break;
  case COMMENT_LINE:
    printf("COMMENT_LINE");
    break;
  case COMMENT_BLOCK:
    printf("COMMENT_BLOCK");
    break;
  case OP_DOT_DOT_DOT:
    printf("OP_DOT_DOT_DOT");
    break;
  case END_OF_FILE:
    printf("END_OF_FILE");
    break;
  case UNKNOWN:
    printf("UNKNOWN");
    break;
  case ERROR:
    printf("ERROR");
    break;
  }
}

void syntaxError() {
  // Contagem de linhas e colunas até a posição atual
  int line = 1, column = 0;
  for (int i = 0; i < currentPosition; i++) {
    if (input[i] == '\n') {
      line++;
      column = 0;
    } else {
      column++;
    }
  }

  // Exibindo a linha do erro
  printf("Erro de sintaxe na linha %d, coluna %d:\n", line, column);

  // Exibindo o token onde ocorreu o erro
  printf("Erro ao processar o token: ");
  switch (currentToken->type) {
  case ID:
    printf("Identificador\n");
    break;
  case NUM_INT:
    printf("Número inteiro\n");
    break;
  case NUM_FLOAT:
    printf("Número decimal\n");
    break;
  case OP_ASSIGN:
    printf("Operador de atribuição '='\n");
    break;
  case SEMICOLON:
    printf("Ponto e Vírgula\n");
    break;
  case END_OF_FILE:
    printf("Final de Arquivo inesperado\n");
    break;
  default:
    printf("Token não identificado\n");
    break;
  }

  exit(1);
}

Token *getNextToken() {
  // Ignorar espaços em branco e caracteres de quebra de linha
  while (isspace(input[currentPosition])) {
    currentPosition++;
  }

  // Verificar o final da string de entrada
  if (currentPosition >= linhaTamanho) {
    Token *token = (Token *)malloc(sizeof(Token));
    token->type = END_OF_FILE;
    token->lexeme = NULL;
    return token;
  }

  // Identificação de números
  if (isdigit(input[currentPosition])) {
    int start = currentPosition;
    while (isdigit(input[currentPosition])) {
      currentPosition++;
    }
    if (input[currentPosition] == '.') { // Check for float or double
      currentPosition++;
      while (isdigit(input[currentPosition])) {
        currentPosition++;
      }
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = NUM_FLOAT; // Assuming float for simplicity
      token->lexeme = strndup(input + start, currentPosition - start);
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);
      printf("\n");
      return token;
    } else {
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = NUM_INT;
      token->lexeme = strndup(input + start, currentPosition - start);
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);
      printf("\n");
      return token;
    }
  }

  // Identificação de textos
  if (input[currentPosition] == '"' || input[currentPosition] == '\'') {
    char quoteType = input[currentPosition];
    currentPosition++;
    int start = currentPosition;
    while (input[currentPosition] != quoteType &&
           currentPosition < linhaTamanho) {
      currentPosition++;
    }
    if (currentPosition < linhaTamanho) {
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TEXT;
      token->lexeme = strndup(input + start, currentPosition - start);
      currentPosition++; // Avançar após a aspas de fechamento
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);
      printf("\n");
      return token;
    } else {
      // String não fechada
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = ERROR;
      token->lexeme = strndup(input + start, currentPosition - start);
      printf("token: %s (incompleta)\n", token->lexeme);
      return token;
    }
  }

  // Identificação de identificadores e palavras-chave
  if (isalpha(input[currentPosition])) {
    int start = currentPosition;
    while (isalnum(input[currentPosition]) || input[currentPosition] == '_') {
      currentPosition++;
    }
    char *lexeme = strndup(input + start, currentPosition - start);

    // Check for keywords
    if (strcmp(lexeme, "int") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TYPE_INT;
      token->lexeme = strdup("int");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "float") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TYPE_FLOAT;
      token->lexeme = strdup("float");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "double") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TYPE_DOUBLE;
      token->lexeme = strdup("double");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "char") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TYPE_CHAR;
      token->lexeme = strdup("char");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "bool") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TYPE_BOOL;
      token->lexeme = strdup("bool");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "void") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = TYPE_VOID;
      token->lexeme = strdup("void");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "if") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_IF;
      token->lexeme = strdup("if");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "else") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_ELSE;
      token->lexeme = strdup("else");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "for") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_FOR;
      token->lexeme = strdup("for");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "case") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_CASE;
      token->lexeme = strdup("case");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "break") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_BREAK;
      token->lexeme = strdup("break");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "while") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_WHILE;
      token->lexeme = strdup("while");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "return") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_RETURN;
      token->lexeme = strdup("return");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "switch") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_SWITCH;
      token->lexeme = strdup("switch");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "default") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_DEFAULT;
      token->lexeme = strdup("default");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    if (strcmp(lexeme, "continue") == 0) {
      free(lexeme);
      Token *token = (Token *)malloc(sizeof(Token));
      token->type = KW_CONTINUE;
      token->lexeme = strdup("continue");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }

    // If no keyword matches, it is an identifier
    Token *token = (Token *)malloc(sizeof(Token));
    token->type = ID;
    token->lexeme = lexeme;
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  }

  // Identificação de operadores e pontuação
  Token *token;
  switch (input[currentPosition]) {
  case '=':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_EQUAL;
      token->lexeme = strdup("==");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_ASSIGN;
    token->lexeme = strdup("=");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '+':
    currentPosition++;
    if (input[currentPosition] == '+') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_INCREMENT;
      token->lexeme = strdup("++");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    } else if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_PLUS_ASSIGN;
      token->lexeme = strdup("+=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_PLUS;
    token->lexeme = strdup("+");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '-':
    currentPosition++;
    if (input[currentPosition] == '-') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_DECREMENT;
      token->lexeme = strdup("--");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    } else if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_MINUS_ASSIGN;
      token->lexeme = strdup("-=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_MINUS;
    token->lexeme = strdup("-");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '*':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_TIMES_ASSIGN;
      token->lexeme = strdup("*=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_TIMES;
    token->lexeme = strdup("*");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '/':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_DIVIDE_ASSIGN;
      token->lexeme = strdup("/=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    } else if (input[currentPosition] == '/') {
      // Comment line
      while (input[currentPosition] != '\n' && currentPosition < linhaTamanho) {
        currentPosition++;
      }
      token = (Token *)malloc(sizeof(Token));
      token->type = COMMENT_LINE;
      token->lexeme = strdup("//");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    } else if (input[currentPosition] == '*') {
      // Comment block
      currentPosition++;
      while (!(input[currentPosition] == '*' &&
               input[currentPosition + 1] == '/') &&
             currentPosition < linhaTamanho) {
        currentPosition++;
      }
      if (currentPosition < linhaTamanho) {
        currentPosition += 2;
      }
      token = (Token *)malloc(sizeof(Token));
      token->type = COMMENT_BLOCK;
      token->lexeme = strdup("/* */");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_DIVIDE;
    token->lexeme = strdup("/");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '%':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_MODULO_ASSIGN;
      token->lexeme = strdup("%=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_MODULO;
    token->lexeme = strdup("%");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case ';':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = SEMICOLON;
    token->lexeme = strdup(";");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '{':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = LEFT_BRACE;
    token->lexeme = strdup("{");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '}':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = RIGHT_BRACE;
    token->lexeme = strdup("}");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '(':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = LEFT_PAREN;
    token->lexeme = strdup("(");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case ')':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = RIGHT_PAREN;
    token->lexeme = strdup(")");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '[':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = LEFT_BRACKET;
    token->lexeme = strdup("[");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case ']':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = RIGHT_BRACKET;
    token->lexeme = strdup("]");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case ',':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = COMMA;
    token->lexeme = strdup(",");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '.':
    currentPosition++;
    if (input[currentPosition] == '.') {
      currentPosition++;
      if (input[currentPosition] == '.') {
        currentPosition++;
        token = (Token *)malloc(sizeof(Token));
        token->type = OP_DOT_DOT_DOT;
        token->lexeme = strdup("...");
        printf("-> token: %s\ntipo: ", token->lexeme);
        printTokenType(token->type);
        return token;
        printf("\n");
      }
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_DOT;
    token->lexeme = strdup(".");
    return token;
  case '!':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_NOT_EQUAL;
      token->lexeme = strdup("!=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_NOT;
    token->lexeme = strdup("!");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '&':
    currentPosition++;
    if (input[currentPosition] == '&') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_AND_ASSIGN;
      token->lexeme = strdup("&&");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    } else if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_AND_ASSIGN;
      token->lexeme = strdup("&=");
      printf("-> token: %s\ntipo: ", token->lexeme);

      printTokenType(token->type);
      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_AND_ASSIGN;
    token->lexeme = strdup("&");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);

    printf("\n");
    return token;
  case '|':
    currentPosition++;
    if (input[currentPosition] == '|') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_OR_ASSIGN;
      token->lexeme = strdup("||");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);

      printf("\n");
      return token;
    } else if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_OR_ASSIGN;
      token->lexeme = strdup("|=");
      printf("-> token: %s\ntipo: ", token->lexeme);

      printTokenType(token->type);
      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_OR_ASSIGN;
    token->lexeme = strdup("|");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);
    return token;
    printf("\n");

  case '~':
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_NOT;
    token->lexeme = strdup("~");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);
    return token;
    printf("\n");

  case '>':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_GREATER_EQUAL;
      token->lexeme = strdup(">=");
      printf("-> token: %s\ntipo: ", token->lexeme);

      printTokenType(token->type);
      printf("\n");
      return token;
    } else if (input[currentPosition] == '>') {
      currentPosition++;
      if (input[currentPosition] == '=') {
        currentPosition++;
        token = (Token *)malloc(sizeof(Token));
        token->type = OP_GREATER_EQUAL;
        token->lexeme = strdup(">>=");
        printf("-> token: %s\ntipo: ", token->lexeme);
        printTokenType(token->type);
        return token;
        printf("\n");
      }
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_GREATER_EQUAL;
      token->lexeme = strdup(">>");
      printf("-> token: %s\ntipo: ", token->lexeme);

      printTokenType(token->type);
      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_GREATER_THAN;
    token->lexeme = strdup(">");
    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);
    return token;
    printf("\n");

  case '<':
    currentPosition++;
    if (input[currentPosition] == '=') {
      currentPosition++;
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_LESS_EQUAL;
      token->lexeme = strdup("<=");
      printf("-> token: %s\ntipo: ", token->lexeme);
      printTokenType(token->type);
      printf("\n");
      return token;
    } else if (input[currentPosition] == '<') {
      currentPosition++;
      if (input[currentPosition] == '=') {
        currentPosition++;
        token = (Token *)malloc(sizeof(Token));
        token->type = OP_LESS_EQUAL;
        token->lexeme = strdup("<<=");
        printf("-> token: %s\ntipo: ", token->lexeme);
        printTokenType(token->type);
        printf("\n");
        return token;
      }
      token = (Token *)malloc(sizeof(Token));
      token->type = OP_LESS_EQUAL;
      token->lexeme = strdup("<<");
      printf("-> token: %s\ntipo: ", token->lexeme);

      printTokenType(token->type);
      printf("\n");
      return token;
    }
    token = (Token *)malloc(sizeof(Token));
    token->type = OP_LESS_THAN;
    token->lexeme = strdup("<");

    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);
    printf("\n");
    return token;
  default:
    currentPosition++;
    token = (Token *)malloc(sizeof(Token));
    token->type = UNKNOWN;
    token->lexeme = strndup(input + currentPosition - 1, 1);

    printf("-> token: %s\ntipo: ", token->lexeme);
    printTokenType(token->type);
    printf("\n");
    return token;
  }
}

void match(int linha, TokenType expectedToken) {
  if (currentToken->type == expectedToken) {
    free(currentToken);
    currentToken = getNextToken();
    if (currentToken == NULL) {
      printf("Error: Unexpected end of file\nLine: %d\n", linha);
      syntaxError();
    }
  } else {
    printf("\nError: Token mismatch\nLine: %d\nExpected: ", linha);
    printTokenType(expectedToken);
    printf("\nFound: ");
    printTokenType(currentToken->type);
    printf("\n\n");
    syntaxError();
  }
}