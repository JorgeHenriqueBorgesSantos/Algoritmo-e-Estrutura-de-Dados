#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

int main(int argc, char *argv[]){
    int n=10;
    int mat[n][n], mat_copia[n][n];
    int i, j;
    Pilha* pilha;

    pilha = criar_pilha();


    ler_arquivo(mat, n);
    print_array(mat, n);
    copiar_matriz(mat, mat_copia, n);

    pilha=achar_caminho(mat, n, pilha);
    printf("Caminho achado!\n");
    print_array(mat_copia, n);
    print_array(mat, n);


}