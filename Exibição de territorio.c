#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Cada território terá: nome, cor do exército e quantidade de tropas
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor de 5 territórios
    Territorio territorios[5];

    printf("=== Cadastro de Territórios ===\n");

    // Cadastro dos 5 territórios usando um laço for
    for (int i = 0; i < 5; i++) {
        printf("\n--- Território %d ---\n", i + 1);

        printf("Digite o nome do território: ");
        scanf(" %[^\n]", territorios[i].nome); // lê string com espaços

        printf("Digite a cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor); // lê string com espaços

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territórios Registrados ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
