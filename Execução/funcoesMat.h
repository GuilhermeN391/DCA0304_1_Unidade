
struct matrizes {
    int nlinhas;
    int ncolunas;
    float m[100][100];
};
///Função de imprimir no console as marizes.
struct matrizes imprimir (struct matrizes m);
/// Função de ler os arquivos com as matrizes iniciais
/// Para não precisar digitar as matrizes no console.
struct matrizes arquivos(void);
/// Função para multiplicar as matrizes, operação essa que é
/// bem requisitada nesse projeto.
struct matrizes multiplicar(struct matrizes a, struct matrizes b);
/// Função de imprimir as matrizes em um arquivo .txt para ter
/// o seu registro não apenas no console.
struct matrizes impArquivos(struct matrizes m);
/// Lembrando que esse programa não lê matriz no console para uma
/// melhor experiencia do opetador.
/// Nas operações de leitura e impressão de arquivos, a escrita
/// do arquivo referente deve ser a seguinte:
/// c:(ou d: se for o caso)/users/nome do usuario/pasta do arquivo/nome_do_arquivo.txt
