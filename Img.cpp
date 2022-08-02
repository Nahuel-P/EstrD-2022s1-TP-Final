#include "Img.h"

#define DIR        int
#define HOJA       99
#define HORIZONTAL 42
#define VERTICAL   17

struct ITreeSt {     
    DIR      division;    
    Color    color;       
    ITreeSt* first;    
    ITreeSt* second;
};
 /* INV.REP.
    En division
      *Este valor solamente puede tener los valores HOJA, HORIZONTAL y VERTICAL.
      *Cuando es HORIZONTAL, sus hijos (first y second) son VERTICAL u HOJA.
      *Cuando es VERTICAL, sus hijos (first y second) son HORIZONTAL u HOJA.
      *Cuando es COLOR, sus hijos (first y second) son NULL.
      *Solo debe tener el atributo COLOR si y solo si 'division' es HOJA.
      *Cuando es HORIZONTAL o VERTICAL, su color es NULL.
      *El primer nodo del arbol siempre es HORIZONTAL.
    OBS: si division es
      - HOJA, entonces color es el color del bloque representado  
      - HORIZONTAL, entonces first es la parte izquierda y second la derecha
      - VERTICAL, entonces first es la parte superior y second la inferior
 */

struct ImgSt {
    int width;
    int height;
    int size;
    ITreeSt* itree ;
};
 /* INV.REP.
    *size = sizeTree itree
    *size tiene que ser menor o igual que width*height
    *width y height es potencia de 2 
    *width y height son iguales
    OBS:
    size en este caso es la cantidad de hojas que tiene el árbol
 */

//---------------------------------------------------------
// sizeImg
//---------------------------------------------------------
int sizeImg(Img img) {
  return (img -> size);
};

int size(ITreeSt* it){
  if (it -> division == HOJA){
    return 1;
  }
  else{
    return size(it -> first) + size ( it -> second);
  }
};

//---------------------------------------------------------
// createImg
//---------------------------------------------------------
//AUX
int half (int num){
  return (num/2);
};

//----------------------------------------
ITreeSt* loadIT(int iw, int ih
               ,int fw, int fh
               ,int n, Matrix m, DIR d) {
  ITreeSt* itree = new ITreeSt;
  if (n==1){
    itree -> division = HOJA;
    itree -> color = M_getAt(m, iw, ih);
    itree -> first = NULL;
    itree -> second = NULL;
    return itree;
  }
  else if(d == HORIZONTAL){
    itree -> division = HORIZONTAL;
    itree -> color = NULL;
    itree -> first = loadIT(iw, ih, fw, half(fh), half(n), m, VERTICAL);
    itree -> second = loadIT(iw, (ih+half (fh)), fw, half(fh), half(n), m, VERTICAL);
    return itree;
  }
  else { //Decidí no poner otro IF(d==VERTICAL) ya que no hay otros casos. En caso contrario, rompe el INV.REP
    itree -> division = VERTICAL;
    itree -> color = NULL;
    itree -> first = loadIT(iw, ih, half(fw), fh,half(n), m, HORIZONTAL);
    itree -> second = loadIT(iw+half(fw), ih, half(fw), fh, half(n), m, HORIZONTAL);
    return itree;
  };
};

// PRECOND: w es potencia de 2, m es de w*w
Img createImg(Matrix m, int w) {
  ImgSt* img = new ImgSt;
  img -> width = w;
  img -> height = w;
  img -> itree = loadIT(1,1,w,w,(w*w),m, HORIZONTAL);
  img -> size = size(img -> itree);
  return img;
};

//---------------------------------------------------------
// CompressImg
//---------------------------------------------------------
// AUXILIAR SUGERIDA
// OBS: el int retornado es la cantidad final de hojas del t luego de modificarlo
int CompressIT(ITreeSt* t) {
  if(t->division==HOJA){
    return 1;
  }
  int sizeTree = CompressIT(t->first) + CompressIT(t->second);
  if(t->first->division == HOJA && t->second->division == HOJA && t->first->color == t->second->color){
    t->division = HOJA;
    t->color  = t -> first -> color;
    delete t -> first;
    delete t -> second;
    t->first  = NULL;
    t->second = NULL;
  }
  return sizeTree;
};

void CompressImg(Img img) {
  img -> size = CompressIT(img->itree);
};

//---------------------------------------------------------
// RenderImg
//---------------------------------------------------------
int renderSize(int x){
  return x*50;
};

void AddSVGTagAtBeginning (int w, int h){
  cout << "<svg height=\"" << renderSize(h) << "\"" 
       << " width=\""  << renderSize(w) << "\">";
};

void AddSVGCloseTag(){
  cout << "\n</svg>";
};

void RenderBlock(int x, int y, int w, int h, Color color){
  cout <<  "\n<rect" 
        << " x=\""      << renderSize(x) <<  "\"" 
        << " y=\""      << renderSize(y) << "\""
        << " width=\""  << renderSize(w)  <<"\""
        << " height=\"" << renderSize(h)  <<"\""
        << " style=\"fill:";
        RenderColor(color,0);
        cout << ";stroke-width:3;stroke:rgb(0,0,0)\"/>";
};

void RenderIT(int x, int y, int w, int h, ITreeSt* t) {
  if (t -> division == HOJA){
    RenderBlock(x,y,w,h,t->color);
  }
  else if (t -> division == HORIZONTAL){
    RenderIT(x, y, w, half(h), t->first);
    RenderIT(x, y+half(h), w, half(h), t->second);
  }
  else if(t-> division == VERTICAL){
    RenderIT(x,y,half(w),h, t->first);
    RenderIT(x+half(w),y,half(w),h, t->second);
  }
};

void RenderImg(Img img) {
  AddSVGTagAtBeginning(img -> width, img -> height);
  RenderIT(0,0, img -> width, img -> height, img -> itree);
  AddSVGCloseTag();
};