#include <unistd.h>
typedef struct pilha Pilha;

struct pilha
{
    Pilha *prox;
    int i;
    int j;
};

Pilha *criar_pilha()
{
    return NULL;
}

Pilha *adicionar_pilha(int i, int j, Pilha *p)
{
    Pilha *p_temp;
    p_temp = (Pilha *)malloc(sizeof(Pilha));
    p_temp->prox = p;
    p_temp->i = i;
    p_temp->j = j;

    return p_temp;
}

Pilha *remover_pilha(Pilha *p)
{
    Pilha *p_temp;
    p_temp = (Pilha *)malloc(sizeof(Pilha));
    p_temp = p;
    p = p_temp->prox;
    p_temp = NULL;
    free(p_temp);

    return p;
}

void ler_arquivo(int array_inteiro[][10], int n)
{
    int i, j, lin = n, col = n;
    char array[lin][col][2];
    char verif[2];

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            fgets(verif, 2, stdin);

            if (strcmp(verif, "\n\0") != 0 && strcmp(verif, "\r\0") != 0)
            {
                // printf("copying...\n");
                //printf("%s\n", verif);
                strcpy(array[i][j], verif);
                array_inteiro[i][j] = atoi(array[i][j]);
                ;
            }
            else
                j--;
        }
    }
}

void print_array(int array[][10], int n)
{
    int i, j, lin = n, col = lin;

    printf("\n");
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void copiar_matriz(int mat[][10], int mat_copia[][10], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat_copia[i][j] = mat[i][j];
        }
    }
}

/*
0 - espaço em branco
1 - parede
2 - caminho percorrido
3 - caminho correto (resposta final)
4 - beco sem saída
*/

/*
direita array[i][j+1]
baixo array[i+1][j]
esquerda array[i][j-1]
cima array[i-1][j]
*/

Pilha *achar_caminho(int array[][10], int n, Pilha *p)
{
    int i = 1, j = 0, final = 0;

    while (final == 0 || p!=NULL)
    {

        // se direita
        if (array[i][j + 1] == 0 || (i == n - 2 && j + 1 == n - 1))
        {
            j++;
            array[i][j] = 2;
            p = adicionar_pilha(i, j, p);
        }
        // baixo
        else
        {
            if (array[i + 1][j] == 0 || (i == n - 2 && j + 1 == n - 1))
            {
                i++;
                array[i][j] = 2;
                p = adicionar_pilha(i, j, p);
            }
            else
            {
                // esquerda
                if (array[i][j - 1] == 0)
                {
                    j--;
                    array[i][j] = 2;
                    p = adicionar_pilha(i, j, p);
                }

                else
                {
                    // cima
                    if (array[i - 1][j] == 0)
                    {
                        i--;
                        array[i][j] = 2;
                        p = adicionar_pilha(i, j, p);
                    }
                    // Tudo bloqueado
                    else
                    {
                        // para direita
                        if (array[i][j + 1] == 2)
                        {
                            array[i][j] = 4;
                            p = remover_pilha(p);
                            i = p->i;
                            j = p->j;
                        }
                        else
                        {
                            // para baixo
                            if (array[i + 1][j] == 2)
                            {
                                array[i][j] = 4;
                                p = remover_pilha(p);
                                i = p->i;
                                j = p->j;
                            }
                            else
                            {
                                // para esquerda
                                if (array[i][j - 1] == 2)
                                {
                                    array[i][j] = 4;
                                    p = remover_pilha(p);
                                    i = p->i;
                                    j = p->j;
                                }
                                else
                                {
                                    // para cima
                                    if (array[i - 1][j] == 2)
                                    {
                                        array[i][j] = 4;
                                        p = remover_pilha(p);
                                        i = p->i;
                                        j = p->j;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        sleep(1);
        print_array(array, n);

        if (p->i == n - 2 && p->j == n - 1)
        {
            printf("\n\n\n\n\n\n\nChegou no finalll\n\n\n\n\n\n");
            final = 1;
        }
        if(p==NULL)
        printf("\nSem saída!\n");
    }
    return p;
}

void mostrar_caminho_final(Pilha *p, int mat[][10])
{
    Pilha *p_temp;
    p_temp = (Pilha *)malloc(sizeof(Pilha));
    p_temp = p;

    while (p_temp != NULL)
    {
        mat[p_temp->i][p_temp->j] = 3;
        p_temp = p_temp->prox;
    }
    
    print_array(mat, 10);
}
