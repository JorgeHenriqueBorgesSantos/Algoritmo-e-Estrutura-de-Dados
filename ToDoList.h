#define MAX 80

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;

struct no
{
    char tarefa[MAX];
    No* prox;
};

typedef struct descritor
{
	int quant;
	No* prim;
    No* ult;
} Descritor;


Descritor* criar()
{
    Descritor* d;

	d = (Descritor *)malloc( sizeof( Descritor ) );
    d->prim = NULL;
    d->quant = 0;
    d->ult = NULL;
    return d;
}

void Insert(Descritor* Lista[7], int ind){
    No *temp;
    int x;
    char texto[MAX];

    temp = (No *)malloc( sizeof( No ) );
    scanf("%s", texto);

    for(x=0; x < strlen(texto); x++){
        temp->tarefa[x] = texto[x];
    }
    temp->tarefa[x] = '\0';
    temp->prox = NULL;

    if (Lista[ind]->prim == NULL){
        Lista[ind]->prim = temp;
        Lista[ind]->ult = temp;
        temp = NULL;
        Lista[ind]->quant++;
    }
    else{
        Lista[ind]->ult->prox = temp;
        Lista[ind]->ult = temp;
        temp = NULL;
        Lista[ind]->quant++;
    }
}

void Pop(Descritor* Lista[7], int ind){
    No* temp;
    temp = Lista[ind]->prim;

    Lista[ind]->prim = temp->prox;
    if(temp->prox == NULL){
        Lista[ind]->ult = NULL;
    }
    free(temp);
    Lista[ind]->quant--;
}

void Printar(Descritor* Lista[7]){
    int x, k, v;
    No* temp;
    char dias[7][3] = { {"Dom"}, {"Seg"}, {"Ter"}, {"Qua"}, {"Qui"}, {"Sex"}, {"Sab"}};

    for(k=0; k<7; k++){
        temp = Lista[k]->prim;
        for (v = 0; v < 3; v++)
        {
            printf("%c", dias[k][v]);
        }
        printf(": ");

        for(x=0; x < Lista[k]->quant; x++){
            printf("%s", temp->tarefa);
            printf(", ");
            temp = temp->prox;
        }
        printf("\n");
    }
}
