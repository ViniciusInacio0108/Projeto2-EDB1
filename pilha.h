#define MAX_CHAR 1000000

typedef struct Pilha
{
    char *valor[MAX_CHAR];
    int topo;
};

void init_pilha(Pilha *p);
int pilha_empty(Pilha *p);
int pilha_full(Pilha *p);
void pile(Pilha *p, const char *newValue);
void depile(Pilha *p);