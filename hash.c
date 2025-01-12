#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hash.h"

int funcao_hash(char chave)
{
  chave = tolower(chave);

  if (chave >= 'a' && chave <= 'z')
  {
    return chave - 'a';
  }
  if (chave >= '0' && chave <= '9')
  {
    return chave - '0' + 26;
  }
  switch (chave)
  {
  case ',':
    return 36;
  case ' ':
    return 37;
  case '.':
    return 38;
  case '?':
    return 39;
  case ':':
    return 40;
  }
}

CaractereDetalhe *criar_caractere(char chave, int quantidade)
{
  CaractereDetalhe *novo_caractere = (CaractereDetalhe *)malloc(sizeof(CaractereDetalhe));
  if (novo_caractere)
  {
    novo_caractere->caractere = chave;
    novo_caractere->quantidade = quantidade;
  }

  return novo_caractere;
}

void inicializar_tabela(tabela_hash *tabela)
{
  for (int i = 0; i < TAMANHO; i++)
  {
    tabela->caracteres[i] = NULL;
  }
}

void inserir(tabela_hash *tabela, char chave)
{
  int indice = funcao_hash(chave);

  if (tabela->caracteres[indice] == NULL)
  {
    CaractereDetalhe *novo_caractere = criar_caractere(chave, 0);
    tabela->caracteres[indice] = novo_caractere;
  }
  else
  {
    CaractereDetalhe *novo_caractere = criar_caractere(chave, tabela->caracteres[indice]->quantidade++);
    tabela->caracteres[indice] = novo_caractere;
  }
}

CaractereDetalhe *buscar(tabela_hash *tabela, char chave)
{
  int indice = funcao_hash(chave);
  CaractereDetalhe *atual = tabela->caracteres[indice];

  return atual;
}

void imprimir_tabela(tabela_hash *tabela)
{
  for (int i = 0; i < TAMANHO; i++)
  {
    printf("Índice %d: \n", i);
    CaractereDetalhe *atual = tabela->caracteres[i];
    printf("Caractere: %c \n", atual->caractere);
    printf("Quantidade: %d \n", atual->quantidade);
  }
}