#include "ToDoList.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    Descritor* Semana[7];
    int h, y, t;

    for (h = 0; h < 7; h++)
    {
        Semana[h] = criar();
    }

    h=0;
    while(0<=h<7)
    {
        scanf("%d", &h);
        if(h>6||h<0)
        {
            break;
        }
        Insert(Semana, h);
    }
    printf("\n");

    Printar(Semana);

    printf("\n");
    
    for (h = 0; h < 7; h++)
    {
        y = Semana[h]->quant;
        for (t=0; t < y; t++)
        {
            Pop(Semana, h);
        }
    }

    printf("Tarefas da semana concluidas(Lista vazia)");
}
