/*
    NOME: PIETRO MINGHINI MORALLES
    RA: 792238
    DISCIPLINA: Algoritmos e Estruturas de Dados 1
    EXERCICIO: F3 - TAD Fila: implementação, teste e aplicação.
    DESCRIÇÃO: IMPLEMENTAÇÃO DAS FUNÇÕES TAD FILA
*/

#include "Fila_TAD.h"

void Cria(Fila *F){
    F->ultimo = -1;
};

bool Vazia(Fila *F){
    if(F->ultimo == -1){
        return true;
    }
    else{
        return false;
    }
};

bool Cheia(Fila *F){
    if(F->ultimo == MAX - 1){
        return true;
    }
    else{
        return false;
    }
};

void Insere(Fila *F, int x, bool *result){
    if(Cheia(F) == false) {
        F->elementos[F->ultimo + 1] = x;
        F->ultimo += 1;
        *result = true;
    }
    else{
        *result = false;
    }
};

void Retira(Fila *F, int *x, bool *result){
    if(Vazia(F) == false){
        *x = F->elementos[0];
        for(int i = 0; i < F->ultimo; i++){
            F->elementos[i] = F->elementos[i+1];
        }
        F->ultimo = F->ultimo - 1;
        *result = true;
    }
    else{
        *result = false;
    }
};

