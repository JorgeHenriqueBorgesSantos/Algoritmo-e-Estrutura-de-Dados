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
    printf("\n\nMaze\n\n")
    print_array(mat_copia, n);
    printf("Caminho percorrido");
    print_array(mat, n);
    printf("\n\nCaminho final\n\n");
    mostrar_caminho_final(pilha, mat);

    return 0;
}
