#define TAMANHO 41
#define VALID_CHARS "abcdefghijklmnopqrstuvwxyz0123456789, .?:"

typedef struct CaractereDetalhe
{
  char caractere;
  int quantidade;
} CaractereDetalhe;

typedef struct tabela_hash
{
  CaractereDetalhe *caracteres[TAMANHO];
} tabela_hash;

int funcao_hash(char chave);
CaractereDetalhe *criar_caractere(char chave, CaractereDetalhe *antigoDetalhe);
void inicializar_tabela(tabela_hash *tabela);
void inserir(tabela_hash *tabela, char chave);
CaractereDetalhe *buscar(tabela_hash *tabela, char chave);
void imprimir_tabela(tabela_hash *tabela);