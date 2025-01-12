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
  case '.':
    return 36;
  case '?':
    return 37;
  case ':':
    return 38;
  case ';':
    return 39;
  }
}

No *criar_no(char chave)
{
  No *novo_no = (No *)malloc(sizeof(No));
  if (novo_no)
  {
    novo_no->chave = chave;
    novo_no->proximo = NULL;
  }
  return novo_no;
}

void inicializar_tabela(tabela_hash *tabela)
{
  for (int i = 0; i < TAMANHO; i++)
  {
    tabela->tabela[i] = NULL;
  }
}

void inserir(tabela_hash *tabela, char chave)
{
  int indice = funcao_hash(chave);
  No *novo_no = criar_no(chave);

  if (tabela->tabela[indice] == NULL)
  {
    tabela->tabela[indice] = novo_no;
  }
  else
  {
    novo_no->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novo_no;
  }
}

int buscar(tabela_hash *tabela, char chave)
{
  int indice = funcao_hash(chave);
  No *atual = tabela->tabela[indice];

  while (atual != NULL)
  {
    if (atual->chave == chave)
    {
      return 1;
    }
    atual = atual->proximo;
  }

  return 0;
}

void remover(tabela_hash *tabela, char chave)
{
  int indice = funcao_hash(chave);
  No *atual = tabela->tabela[indice];
  No *anterior = NULL;

  while (atual != NULL)
  {
    if (atual->chave == chave)
    {
      if (anterior == NULL)
      {
        tabela->tabela[indice] = atual->proximo;
      }
      else
      {
        anterior->proximo = atual->proximo;
      }
      free(atual);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }
  printf("Chave %c não encontrada para remoção.\n", chave);
}

void imprimir_tabela(tabela_hash *tabela)
{
  for (int i = 0; i < TAMANHO; i++)
  {
    printf("Índice %d: ", i);
    No *atual = tabela->tabela[i];
    while (atual != NULL)
    {
      printf("%c -> ", atual->chave);
      atual = atual->proximo;
    }
    printf("NULL\n");
  }
}