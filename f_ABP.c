#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

ABP *iniciarABP() {
    ABP *arvore = (ABP *)malloc(sizeof(ABP));
    if (arvore!=NULL) {
        arvore->pai = NULL;
        arvore->total = 0;
    }
    return arvore;
}

void inserirnaABP(No **pai, int info) {
    if (*pai == NULL) {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->info = info;
        novoNo->filhoesquerda = NULL;
        novoNo->filhodireita = NULL;
        *pai = novoNo;
    } else {
        if (info < (*pai)->info) {
            inserirnaABP(&((*pai)->filhoesquerda), info);
        } else {
            inserirnaABP(&((*pai)->filhodireita), info);
        }
    }
}


No *buscarnaABP(No *pai, int info) {
    if (pai == NULL || pai->info == info) {
        return pai;
    }
    if (info < pai->info) {
        return buscarnaABP(pai->filhoesquerda, info);
    }
    return buscarnaABP(pai->filhodireita, info);
}

No *MinimoABP(No *no) {
    while (no->filhoesquerda != NULL) {
        no = no->filhoesquerda;
    }
    return no;
}


No *removerdaABP(No *pai, int info) {
    if (pai == NULL) {
        return pai;
    }
    if (info < pai->info) {
        pai->filhoesquerda = removerdaABP(pai->filhoesquerda, info);
    } else if (info > pai->info) {
        pai->filhodireita = removerdaABP(pai->filhodireita, info);
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
        No *temp = MinimoABP(pai->filhodireita);
        pai->info = temp->info;
        pai->filhodireita = removerdaABP(pai->filhodireita, temp->info);
    }
    return pai;
}

void ABPordem(No *pai) {
    if (pai) {
        ABPordem(pai->filhoesquerda);
        printf("%d ", pai->info);
        ABPordem(pai->filhodireita);
    }
}

void ABPpreordem(No *pai) {
    if (pai) {
        printf("%d ", pai->info);
        ABPpreordem(pai->filhoesquerda);
        ABPpreordem(pai->filhodireita);
    }
}

void ABPposordem(No *pai) {
    if (pai) {
        ABPposordem(pai->filhoesquerda);
        ABPposordem(pai->filhodireita);
        printf("%d ", pai->info);
    }
}

int ContarNosABP(No *pai) {
    if (pai == NULL) {
        return 0;
    }
    return 1 + ContarNosABP(pai->filhoesquerda) + ContarNosABP(pai->filhodireita);
}

void destruirABP(No *pai) {
    if (pai) {
        destruirABP(pai->filhoesquerda);
        destruirABP(pai->filhodireita);
        free(pai);
    }
}
