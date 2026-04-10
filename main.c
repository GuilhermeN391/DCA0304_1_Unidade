#include "funcoesMat.c"
#include "resulSis.c"

int main()
{
    struct matrizes a, b, c, u;
    a = arquivos();
    b = arquivos();
    c = arquivos();
    b = gauss(a,b,c);
    u = multiana(20);
    impArquivos(b);
    impArquivos(u);
    return 0;
}
