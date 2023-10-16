typedef struct pixel Pixel;
typedef struct imagem Imagem;

// struct pixel{
//     int valor, x, y;
// };

// struct imagem{
//     Pixel *pixels;
//     int largura, altura;
// };

Imagem *criarImagem(int largura, int altura);
void preencherImagem(Imagem *img);
void imprimirImagem(Imagem *img);
void liberarImagem(Imagem *img);
void setPixelValue(Imagem *img, int y, int x, int valor);
int getPixelValue(Imagem *img, int y, int x);
