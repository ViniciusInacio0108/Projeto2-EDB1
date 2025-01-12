#include <stdio.h>
#include "pilha.h"

void push(Pilha* p, int valor) {
  if(p->topo < TAM_MAX-1){
    p->itens[++p->topo] = valor;
  }else{
    printf("Erro: Pilha cheia!\n");
  }
}

int esta_vazia(Pilha *p){
  return p->topo == -1;
}

int pop(Pilha *p){
  if(!esta_vazia(p)){
    return p->itens[p->topo--];
  }

  printf("Erro: Pilha vazia!\n");
  
  return -1;
}

int peek(Pilha *p){
  if(p->topo >= 0){
    return p->itens[p->topo];
  }

  printf("Erro: Pilha vazia!\n");
    
  return -1;
}
