#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *filhoesquerda;
    struct No *filhodireita;
} No;


typedef struct ABP {
    No *pai;
    int total;
} ABP;

ABP *iniciarABP(); 
void inserirnaABP(No **pai, int info); 

No *buscarnaABP(No *pai, int info); 

No *MinimoABP(No *no); 

No *removerdaABP(No *pai, int info); 

void ABPordem(No *pai); 

void ABPpreordem(No *pai); 

void ABPposordem(No *pai);

int ContarNosABP(No *pai); 

void destruirABP(No *pai); 
#endif
