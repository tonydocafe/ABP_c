#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"


int main() {
    ABP *arvore = NULL;
    int decisao;
    char nome[100];

    do {
        printf("\n Escolha uma opção:\n");
        printf("1 * Criar uma árvore (binária de pesquisa)\n");
        printf("2 * Adcionar um aluno na árvore\n");
        printf("3 * Buscar um aluno pelo nome e imprimir seus dados\n");
        printf("4 * Remover um aluno \n");
        printf("5 * Imprimir a árvore em ordem\n");
        printf("6 * Imprimir os dados do aluno com a maior nota\n");
        printf("7 * Imprimir os dados do aluno com a menor nota\n");
        printf("8 * Destruir a árvore\n");
        printf("9 * Sair\n");
        printf("Escolha uma opção: ");
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
                    Aluno aluno;
                    printf("Digite o nome do aluno: ");
                    scanf("%s", aluno.nome);
                    printf("Digite a matrícula do aluno: ");
                    scanf("%d", &aluno.matricula);
                    printf("Digite a nota do aluno: ");
                    scanf("%lf", &aluno.nota);
                    inserirnaABP(&(arvore->pai), aluno);
                    printf("aluno inserido com sucesso!\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 3:
                if (arvore!=NULL) {
                    printf("Digite o nome do aluno a ser buscado: ");
                    scanf("%s", nome);
                    Aluno alunoEncontrado = buscarAluno(arvore->pai, nome);
                    if (strcmp(alunoEncontrado.nome, "") != 0) {
                        printf("Dados do aluno encontrado:\n");
                        printf("Nome: %s, Matrícula: %d, Nota: %.2f\n", alunoEncontrado.nome, alunoEncontrado.matricula, alunoEncontrado.nota);
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 4:
                if (arvore!=NULL) {
                    printf("Digite o nome do aluno a ser removido: ");
                    scanf("%s", nome);
                    arvore->pai = removerdaABP(arvore->pai, nome);
                    printf("Aluno removido!\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 5:
                if (arvore!=NULL) {
                    printf("Árvore em ordem:\n");
                    ABPordem(arvore->pai);
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 6:
                if (arvore!=NULL) {
                    Aluno alunoMaiorNota = encontrarMaiorNota(arvore->pai);
                    printf("Aluno com a maior nota:\n");
                    printf("Nome: %s, Matrícula: %d, Nota: %.2f\n", alunoMaiorNota.nome, alunoMaiorNota.matricula, alunoMaiorNota.nota);
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 7:
                if (arvore!=NULL) {
                    Aluno alunoMenorNota = encontrarMenorNota(arvore->pai);
                    printf("Aluno com a menor nota:\n");
                    printf("Nome: %s, Matrícula: %d, Nota: %.2f\n", alunoMenorNota.nome, alunoMenorNota.matricula, alunoMenorNota.nota);
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 8:
                if (arvore!=NULL) {
                    destruirABP(arvore->pai);
                    free(arvore);
                    arvore = NULL;
                    printf("Árvore destruída.\n");
                } else {
                    printf("Crie uma árvore antes.\n");
                }
                break;

            case 9:
                if (arvore!=NULL) {
                    destruirABP(arvore->pai);
                    free(arvore);
                }
                printf("Fechando!\n");
                break;

            default:
                printf("Tente novamente.\n");
        }

    } while (decisao != 9);

    return 0;
}