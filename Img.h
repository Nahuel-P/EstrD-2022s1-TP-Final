#include "Color.h"
#include "Matrix.h"

struct ImgSt;
typedef ImgSt* Img; // INV.REP.: el puntero no es NULL

Img createImg(Matrix m, int w); // PRECOND: w es potencia de 2, m es de w*w
int sizeImg(Img img);
void CompressImg(Img img);
void RenderImg(Img img);
