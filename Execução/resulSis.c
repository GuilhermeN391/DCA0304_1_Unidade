#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "resulSis.h"

struct matrizes gauss(struct matrizes a, struct matrizes b, struct matrizes c){
    float valor=0;
    int i, j, l=0, co=0, nc, p=0, s=0;
    printf("Informe qual a precisao n que voce quer na aproximacao: ");
    scanf("%d", &s);
    do{
      l = 0;
      co = 0;
      for(i=0; i<b.nlinhas; i++){
            for(j=0; j<b.ncolunas; j++){
                for(nc=0; nc<a.nlinhas; nc++){
                    valor -=  a.m[i][nc] * b.m[nc][j];
                }
                valor = valor + c.m[i][j] + a.m[l][co]*b.m[i][j];
                b.m[i][j]= valor/a.m[l][co];
                l++;
                co++;
                valor=0;
            }
        }
        p++;
    }while(p < s);
        printf("\n u = \n");
        imprimir(b);
        return b;
};

float senh(float a){

    float r;
    r = (exp(a) - exp(-a))/2;

    return r;
}

float pi(){
    int i;
    float r;
    for(i=1,r=1;i<=1000000;i++){
           r += pow(-1,i) / (2*i+1);
           }
           r = 4*r;
  return r;

}
float ana(int n, float coorX, float coorY){

    float u=0, Cn=0, p=0;
    int i;
    p = pi();
    for (i=1; i<n; i++){
        Cn = 4/(i * p * sinh(3*i*p/2));
        u += Cn*sinh(i*p*coorY)*sin(i*p*coorX);
    }
        u = 100*u;
        return u;
    }


/// Essa função faz a analise do potencial em todos os pontos da matriz
/// Para gerar os dados, tem que se informar os limites da malha e o
/// Passo do sistema, considerando que a matriz a ser trabalhada será
/// quadrada, ou seja, a distancia entre os pontos será sempre igual.
struct matrizes multiana(int an){
    struct matrizes u;
    float i, j, pa, lyi, lys, lxe, lxd;
    int l, n;
    printf(" Insira o limite x esquerdo do sistema: ");
    scanf("%f", &lxe);
    printf(" Insira o limite x direito do sistema: ");
    scanf("%f", &lxd);
    printf(" Insira o limite y inferior do sistema: ");
    scanf("%f", &lyi);
    printf(" Insira o limite y superior do sistema: ");
    scanf("%f", &lys);
    printf(" Insira o passo do sistema: ");
    scanf("%f", &pa);
    float coorX = (lxe + pa), coorY = (lyi + pa);
    u.nlinhas = ((lys - lyi)/pa) - 1;
    u.ncolunas = ((lxd - lxe)/pa) - 1;
    for(i=coorY, l=0; i<lys, l<u.nlinhas; i=i+pa, l++){
        for(j=coorX, n=0; j<lxd, n<u.ncolunas; j=j+pa, n++){
                u.m[l][n] = ana(an, j, i);
    }
    }
    printf("A matriz resultante da analise eh:\n");
    imprimir(u);
    return u;
    }
/// Essa função vai fornecer uma matriz com as dimenções da
/// matriz formada pela malha, onde a partir do elemento
/// [0][0] é o resultado no 1° ponto e seguindo gradativamente
/// tendo a leitura das colunas e depois as linhas como ordem.
/// Foi considerado 20 como o número de iterações para a analise
/// podendo ser mudado no main.c.




