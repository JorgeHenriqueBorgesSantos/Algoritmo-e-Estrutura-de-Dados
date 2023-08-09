#include <unistd.h>
typedef struct pilha Pilha;

struct pilha
{
    Pilha* prox;
    int i;
    int j;
};

Pilha* criar_pilha()
{   
    return NULL;
}

Pilha* adicionar_pilha(int i, int j, Pilha *p)
{
    Pilha *p_temp;
    p_temp= (Pilha *)malloc(sizeof(Pilha));
    p_temp->prox=p;
    p_temp->i=i;
    p_temp->j=j;

    return p_temp;   
}

Pilha* remover_pilha(Pilha *p)
{
    Pilha *p_temp;
    p_temp= (Pilha *)malloc(sizeof(Pilha));
    p_temp=p;
    p=p_temp->prox;
    p_temp=NULL;
    free(p_temp);
    
    return p;
}

void ler_arquivo(int array_inteiro[][10], int n)
{
    int i, j, lin=n, col=n;
    char array[lin][col][2];
    char verif[2];

    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            fgets(verif, 2, stdin);

                if (strcmp(verif,"\n\0")!=0 && strcmp(verif,"\r\0")!=0)
                {
                    //printf("copying...\n");
                    printf("%s\n", verif);
                    strcpy(array[i][j], verif);
                    array_inteiro[i][j]=atoi(array[i][j]);;
                }
                else
                    j--;
        }
    }

}


/*
void ler_arquivo(int array_inteiro[][10], int n)
{
    int i, j, lin=n, col=n;
    char array_char[lin][col];
    char *num = malloc(2*sizeof(char));

    printf("Insert numbers: ");
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            array_char[i][j] = getchar();
            if(isspace(array_char[i][j]))
                j--;
            else
            {
            num[0]=array_char[i][j];
            num[1]="\0";
            array_inteiro[i][j]=atoi(num);
            }
        }
    }

}
*/


void print_array(int array[][10], int n)
{
    int i, j, lin=n, col=lin;
    
    printf("Print do array\n");
     for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }


}

void copiar_matriz(int mat[][10], int mat_copia[][10], int n)
{
    int i, j;

    for (i=0; i<n; i++){
        for(j=0; j<n; j++){
            mat_copia[i][j]=mat[i][j];
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
Pilha* apagar_caminho(Pilha * p){
    Pilha * p_temp;
    p_temp = (Pilha *)malloc(sizeof(Pilha));
    p_temp=p;
    while(p_temp->prox != NULL){
        p_temp=remover_pilha(p_temp);
    }
    printf("O primeiro passo Foi %d  %d\n", p->i, p->j);
    return p_temp;
}

Pilha * achar_caminho(int array[][10], int n, Pilha* p ){
    int i=1, j=0, final=0, tentativas=0;

    while(final==0){
        
        //se direita
        tentativas++;
         if(array[i][j+1]==0 || (i==n-2 && j+1==n-1)){      
            tentativas=0;
            j++;
            array[i][j]=2;
            p = adicionar_pilha(i, j, p);
            printf("Pra direita!\n");         
        }
        //baixo
        else{
            tentativas++;
            if(array[i+1][j]==0 || (i==n-2 && j+1==n-1) )
            {     
                        tentativas=0;
                        i++;
                        array[i][j]=2;
                        p = adicionar_pilha(i, j, p);
                        printf("Pra baixo\n");
                    

                 
            }
            else{
                //esquerda
                tentativas++;
                if(array[i][j-1]==0 )
                {            
                      
                            tentativas=0;
                            j--;
                            array[i][j]=2;
                            p = adicionar_pilha(i, j, p);
                            printf("Pra esquerda!\n");
                }
                   
                
                else
                {   
                    tentativas++;                       
                            //cima    
                            if(array[i-1][j]==0 )
                            {
                                tentativas=0;
                                i--;
                                array[i][j]=2;
                                p = adicionar_pilha(i, j, p);
                                printf("Pra cima!\n");
                            }
                            //Tudo bloqueado
                            else{
                                // para direita
                                if(array[i][j-1] != 0 && array[i+1][j]!=0 && array[i-1][j]!=0){
                                printf("repetindo\n");
                                array[i][j]=4;
                                i=p->i;
                                j=p->j;
                                p=remover_pilha(p);
                                
                                }
                                //para cima
                                if(array[i+1][j]!=0 && array[i][j+1]!=0 && array[i][j-1]!=0){
                                    printf("repetindo\n");
                                    array[i][j]=4;
                                    i=p->i;
                                    j=p->j; 
                                    p=remover_pilha(p);
                                      
                                }
                                //para esquerda
                                if(array[i][j+1]!=0 && array[i+1][j]!=0 && array[i-1][j]!=0){
                                    printf("repetindo\n");
                                    array[i][j]=4;
                                    i=p->i;
                                    j=p->j;
                                    p=remover_pilha(p);
                                    
                                }
                                //para baixo
                                if(array[i-1][j]!=0 && array[i][j+1]!=0 && array[i][j-1]!=0){
                                    printf("repetindo\n");
                                    array[i][j]=4;
                                    i=p->i;
                                    j=p->j;
                                    p=remover_pilha(p);
                                    
                                }
                            
                            }
                    }
                }

                }
            

            sleep(2);
            print_array(array, n);
            printf("linha %d  coluna %d\n", p->i, p->j);

            if (p->i==n-2 && p->j==n-1){
            printf("\n\n\nChegou no finalll\n\n\n");
            final=1; 
            }  
        }
        return p;
    }

void mostrar_caminho_final(Pilha* p, int mat[][10]){
        printf(" %d %d" , p->i, p->j);
        Pilha * p_temp;
        p_temp = (Pilha *)malloc(sizeof(Pilha));
        int cont=0;
        p_temp=p;
        printf(" %d %d" , p_temp->i, p_temp->j);

        while(p_temp->prox!=NULL){
            mat[p_temp->i][p_temp->j]=3;
            cont++;
            p_temp=p_temp->prox;
        }
        printf("Matrix final obteve %d passos", cont);
        print_array(mat, 10);
}
    

