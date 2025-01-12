#define MAX 1000

typedef struct Pilha
{
    char *valor[MAX];
    int topo;
};

void init_pilha(Pilha *p);
int pilha_empty(Pilha *p);
int pilha_full(Pilha *p);
Pilha get_pilha(Pilha *p, const char *value);
void pile(Pilha *p, const char *newValue);
void depile(Pilha *p);