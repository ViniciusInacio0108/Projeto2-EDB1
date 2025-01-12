#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void push(No **topo, int valor){
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->dado = valor;
  novo_no->proximo = *topo;
  *topo = novo_no;
}

int pop(No **topo){
  if(*topo != NULL){
    No *temp = *topo;
    int valor = temp->dado;
    *topo = (*topo)->proximo;
        
    free(temp);
        
    return valor;
  }

  printf("Erro: Pilha vazia!\n");
 
  return -1; 
}

int esta_vazia(No *topo){
  return topo == NULL;
}

int peek(No *topo){
  if(topo != NULL)
    return topo->dado;

  printf("Erro: Pilha vazia!\n");
    
  return -1;
}
