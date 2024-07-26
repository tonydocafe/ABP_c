#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

ABP *iniciarABP() {
    ABP *arvore = (ABP *)malloc(sizeof(ABP));
    if (arvore!=NULL) {
        arvore->pai = NULL;
        arvore->total = 0;
    }
    return arvore;
}

void inserirnaABP(No **pai, Aluno info) {
    if (*pai == NULL) {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->info = info;
        novoNo->filhoesquerda = NULL;
        novoNo->filhodireita = NULL;
        *pai = novoNo;
    } else {
        int comparar = strcmp(info.nome, (*pai)->info.nome);
        if (comparar < 0) {
            inserirnaABP(&((*pai)->filhoesquerda), info);
        } else {
            inserirnaABP(&((*pai)->filhodireita), info);
        }
    }
}


Aluno buscarAluno(No *pai, char nome[]) {
    if (pai == NULL) {
        Aluno NaoEncontrado;
        strcpy(NaoEncontrado.nome, "");
        NaoEncontrado.matricula = 0;
        NaoEncontrado.nota = 0.0;
        return NaoEncontrado;
    }
    int comparar = strcmp(nome, pai->info.nome);
    if (comparar == 0) {
        return pai->info;
    }
    if (comparar < 0) {
        return buscarAluno(pai->filhoesquerda, nome);
    }
    return buscarAluno(pai->filhodireita, nome);
}

Aluno encontrarMaiorNota(No *pai) {
    if (pai->filhodireita == NULL) {
        return pai->info;
    }
    return encontrarMaiorNota(pai->filhodireita);
}


Aluno encontrarMenorNota(No *pai) {
    if (pai->filhoesquerda == NULL) {
        return pai->info;
    }
    return encontrarMenorNota(pai->filhoesquerda);
}

No *removerdaABP(No *pai, char nome[]) {
    if (pai == NULL) {
        return pai;
    }
    int comparar = strcmp(nome, pai->info.nome);
    if (comparar < 0) {
        pai->filhoesquerda = removerdaABP(pai->filhoesquerda, nome);
    } else if (comparar > 0) {
        pai->filhodireita = removerdaABP(pai->filhodireita, nome);
    } else {
        if (pai->filhoesquerda == NULL) {
            No *temp = pai->filhodireita;
            free(pai);
            return temp;
        } else if (pai->filhodireita == NULL) {
            No *temp = pai->filhoesquerda;
            free(pai);
            return temp;
        }
        No *temp = pai->filhodireita;
        while (temp->filhoesquerda != NULL) {
            temp = temp->filhoesquerda;
        }
        pai->info = temp->info;
        pai->filhodireita = removerdaABP(pai->filhodireita, temp->info.nome);
    }
     
    return pai;
}

void ABPordem(No *pai) {
    if (pai) {
        ABPordem(pai->filhoesquerda);
        printf("Nome: %s, Matrícula: %d, Nota: %.2f\n", pai->info.nome, pai->info.matricula, pai->info.nota);
        ABPordem(pai->filhodireita);
    }
}

void destruirABP(No *pai) {
    if (pai != NULL) {
        destruirABP(pai->filhoesquerda);
        destruirABP(pai->filhodireita);
        free(pai);
    }
}
