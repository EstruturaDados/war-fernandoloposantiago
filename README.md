#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10   // capacidade máxima da mochila

// ---------- Estrutura do Item ----------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ---------- Protótipos das Funções ----------
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

// ---------- Função Principal ----------
int main() {
    Item mochila[MAX_ITENS];  // vetor de structs
    int total = 0;            // quantidade atual de itens
    int opcao;

    do {
        printf("\n=== MOCHILA DO AVENTUREIRO ===\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // consumir o \n deixado pelo scanf

        switch(opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}

// ---------- Implementação das Funções ----------

// Inserir um novo item na mochila
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("Nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove \n

    printf("Tipo (arma, municao, cura...): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar();

    mochila[*total] = novo; // adiciona ao vetor
    (*total)++;

    printf("Item adicionado com sucesso!\n");
}

// Remover item pelo nome
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("Mochila vazia! Nenhum item para remover.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a remover: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            // sobrescreve com o próximo item
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }

    printf("Item nao encontrado.\n");
}

// Listar todos os itens
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    printf("\n--- Itens na mochila ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Buscar item pelo nome
void buscarItem(Item mochila[], int total) {
    if (total == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado.\n");
}
