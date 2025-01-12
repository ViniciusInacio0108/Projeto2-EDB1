#define TAM_MAX 1000000

typedef struct {
    int itens[TAM_MAX];
    int topo;
}Pilha;

void push(Pilha* p, int valor);
int esta_vazia(Pilha *p);
int pop(Pilha *p);
int peek(Pilha *p);