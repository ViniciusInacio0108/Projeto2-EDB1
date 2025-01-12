#define TAMANHO 41
#define VALID_CHARS "abcdefghijklmnopqrstuvwxyz0123456789, .?:"

typedef struct No
{
  char chave;
  struct No *proximo;
} No;

typedef struct tabela_hash
{
  No *tabela[TAMANHO];
} tabela_hash;

int funcao_hash(char chave);
No *criar_no(char chave);
void inicializar_tabela(tabela_hash *tabela);
void inserir(tabela_hash *tabela, char chave);
int buscar(tabela_hash *tabela, char chave);
void remover(tabela_hash *tabela, char chave);
void imprimir_tabela(tabela_hash *tabela);