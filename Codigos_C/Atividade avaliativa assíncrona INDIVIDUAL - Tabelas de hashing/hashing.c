#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 53

typedef struct carro {
    char placa[8];
    char marca[15];
    char modelo[15];
    char cor[15];
    int status;
} CARRO;

typedef struct noTabela {
    char placa[8];
    int posicao;
    struct noTabela* prox;
} NO;

FILE* prepararArquivo(char nome[]);
void fecharArquivo(FILE* arq);
int buscar(NO* tabelaHashing[], char placa[]);
void cadastrar(FILE* arq, NO* tabelaHashing[]);
void consultar(FILE* arq, NO* tabelaHashing[]);
void alterar(FILE* arq, NO* tabelaHashing[]);
void remover(FILE* arq, NO* tabelaHashing[]);
void exibirCadastro(FILE* arq, NO* tabelaHashing[]);
void criarIndice(FILE* arq, NO* tabelaHashing[]);
void inserirTabelaHash(NO* tabelaHashing[], char placa[], int pos);
int hashing(char placa[]);
void desalocarIndice(NO* tabelaHashing[]);
void exibirOpcoes();
int isEmpty(NO* tabelaHashing[]);

int main() {
    char nomeArq[] = "carros.dat";
    int op;
    FILE* cadastro;
    NO* tabelaHashing[N];
    cadastro = prepararArquivo(nomeArq);
    if (cadastro == NULL)
        printf("Erro ao abrir o arquivo.\n");
    else {
        criarIndice(cadastro, tabelaHashing);
        do {
            exibirOpcoes();
            scanf("%d",&op); fflush(stdin);
            switch (op) {
            case 1: cadastrar(cadastro, tabelaHashing);
                break;
            case 2: consultar(cadastro, tabelaHashing);
                break;
            case 3: alterar(cadastro, tabelaHashing);
                break;
            case 4: remover(cadastro, tabelaHashing);
                break;
            case 5: exibirCadastro(cadastro, tabelaHashing);
                break;
            case 0: fecharArquivo(cadastro);
                desalocarIndice(tabelaHashing);
                break;
            default: printf("Opção invalida \n");
            }
        } while (op != 0);
    }
    return 0;
}

void exibirOpcoes() {
    printf("Opções \n");
    printf("1 - Cadastrar um carro \n");
    printf("2 - Consultar carro \n");
    printf("3 - Alterar dados do carro \n");
    printf("4 - Remover carro \n");
    printf("5 - Exibir carros cadastrados \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a Opção: ");
}

int isEmpty(NO* tabelaHashing[]) {
    for (int i = 0; i < N; i++) {
        if (tabelaHashing[i] != NULL) {
            return 0;
        }
    }
    return 1;
}


FILE* prepararArquivo(char nome[]) {
    FILE* aux;
    aux = fopen(nome, "r+b");
    if (aux == NULL)
        aux = fopen(nome, "w+b");
    return aux;
}

void fecharArquivo(FILE* arq) {
    FILE* novoArq;
    CARRO carro;

    novoArq = fopen("temp.dat", "w+b");

    if (novoArq == NULL) {
        printf("Erro na criação de arquivo temporário.\n");
        exit(1);
    }

    rewind(arq);

    while (fread(&carro, sizeof(CARRO), 1, arq) == 1) {
        if (carro.status == 1) {
            fwrite(&carro, sizeof(CARRO), 1, novoArq);
        }
    }

    fclose(arq);
    fclose(novoArq);

    remove("carros.dat");
    rename("temp.dat", "carros.dat");
}


void criarIndice(FILE* arq, NO* tabelaHashing[]) {
    CARRO carro;
    int posicao = 0;

    rewind(arq);

    while (fread(&carro, sizeof(CARRO), 1, arq) == 1) {
        if (carro.status == 1) {
            int posHash = hashing(carro.placa);
            inserirTabelaHash(tabelaHashing, carro.placa, posicao);
        }
        posicao++;
    }
}

void desalocarIndice(NO* tabelaHashing[]) {
    for (int i = 0; i < N; i++) {
        NO* atual = tabelaHashing[i];
        NO* proximo;

        while (atual != NULL) {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }

        tabelaHashing[i] = NULL;
    }
}

int buscar(NO* tabelaHashing[], char placa[]) {
    int posHash = hashing(placa);

    NO* atual = tabelaHashing[posHash];

    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0) {
            return atual->posicao;
        }
        atual = atual->prox;
    }

    return -1;
}

void inserirTabelaHash(NO* tabelaHashing[], char placa[], int pos) {
    int posHash = hashing(placa);

    NO* novoNo = (NO*)malloc(sizeof(NO));
    if (novoNo == NULL) {
        printf("Erro no alocamento de memória de um novo nó.\n");
        return;
    }

    strcpy(novoNo->placa, placa);
    novoNo->posicao = pos;
    novoNo->prox = NULL;

    if (tabelaHashing[posHash] == NULL) {
        tabelaHashing[posHash] = novoNo;
    } else {
        NO* atual = tabelaHashing[posHash];
        NO* anterior = NULL;

        while (atual != NULL && strcmp(atual->placa, placa) < 0) {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) {
            novoNo->prox = tabelaHashing[posHash];
            tabelaHashing[posHash] = novoNo;
        } else {
            novoNo->prox = atual;
            anterior->prox = novoNo;
        }
    }
}

void removerTabelaHash(NO* tabelaHashing[], char placa[], int posTabela) {
    int posHash = hashing(placa);

    NO* atual = tabelaHashing[posHash];
    NO* anterior = NULL;

    while (atual != NULL && strcmp(atual->placa, placa) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            tabelaHashing[posHash] = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }

        free(atual);
    } else {
        printf("Placa não registrada.\n");
    }
}

int hashing(char placa[]) {
    int soma, i, tam;

    soma = 0;
    i = 0;
    tam = strlen(placa);

    for (i = 0; i < tam; i++) {
        soma += placa[i];
    }

    return soma % N;
}

void cadastrar(FILE* arq, NO* tabelaHashing[]) {
    CARRO novoCarro;
    int posicao;
    char idknmr;

    printf("Digite a placa do carro a ser cadastrado: ");
    scanf("%s", &novoCarro.placa);
    fflush(stdin);

    posicao = buscar(tabelaHashing, novoCarro.placa);

    if (posicao != -1) {
        printf("Carro com a placa %s já está cadastrado.\n", novoCarro.placa);
        return;
    }

    printf("Digite a marca do carro: ");
    scanf("%s", &novoCarro.marca);
    printf("Digite o modelo do carro: ");
    scanf("%s", &novoCarro.modelo);
    printf("Digite a cor do carro: ");
    scanf("%s", &novoCarro.cor);

    fseek(arq, 0, SEEK_END);
    fwrite(&novoCarro, sizeof(CARRO), 1, arq);

    posicao = (ftell(arq) / sizeof(CARRO)) - 1;

    inserirTabelaHash(tabelaHashing, novoCarro.placa, posicao);

    printf("Carro cadastrado com sucesso.\n");
}

void consultar(FILE* arq, NO* tabelaHashing[]) {

    if (isEmpty(tabelaHashing) == 1){
        printf("Não há nenhum carro cadastrado.\n");
    }
    else{
        char placa[8];
        int posicao;

        printf("Digite a placa do carro a ser consultado: ");
        scanf("%s", &placa);
        fflush(stdin);

        posicao = buscar(tabelaHashing, placa);

        if (posicao != -1) {
            fseek(arq, (posicao - 1) * sizeof(CARRO), SEEK_SET);
            CARRO carro;
            fread(&carro, sizeof(CARRO), 1, arq);
            printf("Placa: %s\nMarca: %s\nModelo: %s\nCor: %s\n", carro.placa, carro.marca, carro.modelo, carro.cor);
        } else {
            printf("Carro com a placa %s não encontrado.\n", placa);
        }
    }
}

void alterar(FILE* arq, NO* tabelaHashing[]) {
    char placa[8];
    int posicao;

    printf("Digite a placa do carro a ser alterado: ");
    scanf("%s", &placa);
    fflush(stdin);

    posicao = buscar(tabelaHashing, placa);

    if (posicao != -1) {
        fseek(arq, (posicao - 1) * sizeof(CARRO), SEEK_SET);
        CARRO carro;
        fread(&carro, sizeof(CARRO), 1, arq);

        printf("Digite a nova marca do carro: ");
        scanf("%s", &carro.marca);
        printf("Digite o novo modelo do carro: ");
        scanf("%s", &carro.modelo);
        printf("Digite a nova cor do carro: ");
        scanf("%s", &carro.cor);

        fseek(arq, -sizeof(CARRO), SEEK_CUR);
        fwrite(&carro, sizeof(CARRO), 1, arq);

        printf("Dados do carro alterados com sucesso.\n");
    } else {
        printf("Carro com a placa %s não encontrado.\n", placa);
    }
}

void remover(FILE* arq, NO* tabelaHashing[]) {
    char placa[8];
    int posicao;

    printf("Digite a placa do carro a ser removido: ");
    scanf("%s", &placa);
    fflush(stdin);

    posicao = buscar(tabelaHashing, placa);

    if (posicao != -1) {
        fseek(arq, (posicao - 1) * sizeof(CARRO), SEEK_SET);
        CARRO carro;
        fread(&carro, sizeof(CARRO), 1, arq);

        printf("Deseja realmente remover o carro com a placa %s? (S/N): ", placa);
        char resposta;
        scanf(" %c", &resposta);
        fflush(stdin);

        if (resposta == 'S' || resposta == 's') {
            carro.status = 0;
            fseek(arq, -sizeof(CARRO), SEEK_CUR);
            fwrite(&carro, sizeof(CARRO), 1, arq);

            removerTabelaHash(tabelaHashing, placa, posicao);

            printf("Carro removido com sucesso.\n");
        } else {
            printf("Remoção cancelada.\n");
        }
    } else {
        printf("Carro com a placa %s não encontrado.\n", placa);
    }
}


void exibirCadastro(FILE* arq, NO* tabelaHashing[]) {
    if (isEmpty(tabelaHashing) == 1){
        printf("Não há nenhum carro cadastrado.\n");
    }
    else{
        rewind(arq);

        CARRO carro;

        printf("Carros cadastrados:\n");

        while (fread(&carro, sizeof(CARRO), 1, arq) == 1) {
            if (carro.status == 1) {
                printf("Placa: %s\nMarca: %s\nModelo: %s\nCor: %s\n\n", carro.placa, carro.marca, carro.modelo, carro.cor);
            }
        }
    }
}