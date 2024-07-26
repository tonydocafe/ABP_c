#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"


int main() {
    ABP *arvore = NULL;
    int decisao, info;

    do {
        printf("\n Escolha uma opção:\n");
        printf("1 * Criar uma árvore (binária de pesquisa)\n");
        printf("2 * Adcionar um elemento na árvore \n");
        printf("3 * Buscar um elemento na árvore\n");
        printf("4 * Remover um elemento na árvore\n");
        printf("5 * Imprimir a árvore em ordem\n");
        printf("6 * Imprimir a árvore em pre ordem\n");
        printf("7 * Imprimir a árvore em pos ordem\n");
        printf("8 * Mostrar a total de nós da árvore\n");
        printf("9 * Destruir a abp\n");
        printf("10 * Fechar\n");
        scanf("%d", &decisao);

        switch (decisao) {
            case 1:
                if (arvore == NULL) {
                    arvore = iniciarABP();
                    printf("A foi árvore criada !\n");
                } else {
                    printf("A árvore já existe.\n");
                }
                break;

            case 2:
                if (arvore!=NULL) {
                    printf("Digite o elemento a ser inserido: ");
                    scanf("%d", &info);
                    inserirnaABP(&(arvore->pai), info);
                    printf("Elemento inserido!\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 3:
                if (arvore!=NULL) {
                    printf("Digite a busca: ");
                    scanf("%d", &info);
                    No *resultado = buscarnaABP(arvore->pai, info);
                    if (resultado) {
                        printf("Elemento encontrado.\n");
                    } else {
                        printf("Elemento não encontrado.\n");
                    }
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 4:
                if (arvore!=NULL) {
                    printf("Digite o elemento a ser removido: ");
                    scanf("%d", &info);
                    arvore->pai = removerdaABP(arvore->pai, info);
                    printf("Elemento removido!\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 5:
                if (arvore!=NULL) {
                    printf("Árvore Binária de Pesquisa em ordem: ");
                    ABPordem(arvore->pai);
                    printf("\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 6:
                if (arvore!=NULL) {
                    printf("Árvore Binária de Pesquisa em pré-ordem: ");
                    ABPpreordem(arvore->pai);
                    printf("\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 7:
                if (arvore!=NULL) {
                    printf("Árvore Binária de Pesquisa em pós-ordem: ");
                    ABPposordem(arvore->pai);
                    printf("\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 8:
                if (arvore!=NULL) {
                    int totalNos = ContarNosABP(arvore->pai);
                    printf("A total de nós na ABP é: %d\n", totalNos);
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 9:
                if (arvore!=NULL) {
                    destruirABP(arvore->pai);
                    free(arvore);
                    arvore = NULL;
                    printf("ABP destruída.\n");
                } else {
                    printf("A ABP não foi criada: Crie uma ABP primeiro.\n");
                }
                break;

            case 10:
                if (arvore!=NULL) {
                    destruirABP(arvore->pai);
                    free(arvore);
                }
                printf("Saindo do programa. Obrigado!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (decisao != 10);

    return 0;
}