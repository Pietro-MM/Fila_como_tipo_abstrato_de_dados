/*
    NOME: PIETRO MINGHINI MORALLES
    RA: 792238
    DISCIPLINA: Algoritmos e Estruturas de Dados 1
    EXERCICIO: F3 - TAD Fila: implementação, teste e aplicação.
    DESCRIÇÃO: ATIVIDADE PARA IMPLEMENTAR E TESTAR O TAD FILA SEM REALOCAÇÃO DOS ELEMENTOS
*/
#include "Fila_TAD.h"
#include <stdio.h>

void imprimirPrimeiro(Fila *f);
void imprimeFila(Fila *f);

int main() {
    int op = 10, valor;
    bool resultado;
    Fila fila1;
    Cria(&fila1);

    while (op != 0){
        printf("(1) Cheia -- (2) Vazia -- (3) Insere -- (4) Remove -- (5) Imprime Primeiro -- (6) Imprime Fila: ");
        scanf("%d", &op);
        if(op == 1){
            resultado = Cheia(&fila1);
            if(resultado){
                printf("Fila cheia\n");
            }
            else{
                printf("N cheia\n");
            }
        }
        else if(op == 2){
            resultado = Vazia(&fila1);
            if(resultado){
                printf("Fila vazia\n");
            }
            else{
                printf("N vazia\n");
            }
        }
        else if(op == 3){
            scanf("%d", &valor);
            Insere(&fila1, valor, &resultado);
            if(resultado){
                printf("Inserido %d\n", valor);
            }
            else{
                printf("Fila cheia\n");
            }
        }
        else if(op == 4){
            Retira(&fila1, &valor, &resultado);
            if(resultado){
                printf("Retirou %d\n", valor);
            }
            else{
                printf("Fila vazia\n");
            }
        }
        else if(op == 5){
            imprimirPrimeiro(&fila1);
        }
        else if(op == 6){
            imprimeFila(&fila1);
        }
    }
    return 0;
}

void imprimirPrimeiro(Fila *f){
    Fila aux;
    Cria(&aux);
    int x, qtdVz = 0;
    bool resultado;

    if(Vazia(f)){
        printf("Fila vazia\n");
    }
    else{
        while(!Vazia(f)) {
            if(qtdVz == 0) {
                Retira(f, &x, &resultado);
                printf("O primeiro elemento eh: %d\n", x);
                Insere(&aux, x, &resultado);
                qtdVz++;
            }
            else{
                Retira(f, &x, &resultado);
                Insere(&aux, x, &resultado);
            }
        }
        while (!Vazia(&aux)){
            Retira(&aux, &x, &resultado);
            Insere(f, x, &resultado);
        }
    }
};

void imprimeFila(Fila *f){
    Fila aux;
    Cria(&aux);
    int x;
    bool resultado;

    if(Vazia(f)){
        printf("Fila vazia\n");
    }
    else{
        while (!Vazia(f)){
            Retira(f, &x, &resultado);
            Insere(&aux, x, &resultado);
        }
        printf("Inicio -----> ");
        while (!Vazia(&aux)){
            Retira(&aux, &x, &resultado);
            printf("%d ", x);
            Insere(f, x, &resultado);
        }
        printf("\n");
    }
}