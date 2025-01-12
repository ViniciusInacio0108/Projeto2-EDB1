#define TAMANHO 1000000

typedef struct No{
  int chave;
  struct No *proximo;
} No;

typedef struct tabela_hash{
  No *tabela[TAMANHO];
}tabela_hash;

int funcao_hash(int chave);
No *criar_no(int chave);
void inicializar_tabela(tabela_hash *tabela);
void inserir(tabela_hash *tabela, int chave);
int buscar(tabela_hash *tabela, int chave);
void remover(tabela_hash *tabela, int chave);
void imprimir_tabela(tabela_hash* tabela);