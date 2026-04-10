#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmat.h"

struct matrizes arquivos(void){
    struct matrizes n;
    int i, j;
    char a[100];
    FILE *file;
    a[0]=0;
    printf("Digite a localizacao do arquivo: ");
///Deve-se digitar a localizacao exata do arquivo, senao nao ira ler//
    while(strlen(a) < 2){
        fgets(a, 100, stdin);
    }
    a[strlen(a)-1]= 0;
    file = fopen(a, "r");
    fscanf(file,"%d %d", &n.nlinhas, &n.ncolunas);
    for(i=0; i<n.nlinhas; i++){
        for( j=0; j<n.ncolunas; j++){
            fscanf(file, "%f", &n.m[i][j]);
        }
    }
    return n;
}

struct matrizes imprimir (struct matrizes m){
    int i, j;
    for (i=0;i<m.nlinhas;i++) {
        for (j=0;j<m.ncolunas;j++) {
            printf("%.1f ", m.m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return m;
}

struct matrizes multiplicar(struct matrizes a, struct matrizes b){
    int i, j, nc;
    float valor=0;
    struct matrizes c;
    if(a.ncolunas == b.nlinhas){
        c.ncolunas = b.ncolunas;
        c.nlinhas = a.nlinhas;
        for(i=0; i<c.nlinhas; i++){
            for(j=0; j<c.ncolunas; j++){
                c.m[i][j] =0;
                for(nc=0; nc<a.nlinhas; nc++){
                    valor +=  a.m[i][nc] * b.m[nc][j];
                }
                c.m[i][j]=valor;
                valor=0;
            }
        }
    }
    else {
        {
                c.ncolunas = 0;
                c.nlinhas = 0;
                printf("\nNao eh possivel multiplicar as matrizes\n");
            }
    }
    return c;
}

struct matrizes impArquivos(struct matrizes m){
    int i, j;
    char a[100];
    FILE *fileout;
    a[0]=0;
    printf("Digite a localizacao de destino do arquivo: ");
    while(strlen(a) < 2){
        fgets(a, 100, stdin);
    }
    a[strlen(a)-1]= 0;
    fileout = fopen(a, "w");
    fprintf(fileout,"%d %d\n", m.nlinhas, m.ncolunas);
    for(i=0; i<m.nlinhas; i++){
        for( j=0; j<m.ncolunas; j++){
            fprintf(fileout, "%.1f ", m.m[i][j]);
        }
        fprintf(fileout, "\n");
    }
    fclose(fileout);
}

