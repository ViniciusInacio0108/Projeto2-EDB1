typedef struct no{
    int dado;
    struct no *proximo;
}No;

void push(No **topo, int valor);
int pop(No **topo);
int esta_vazia(No *topo);
int peek(No *topo);