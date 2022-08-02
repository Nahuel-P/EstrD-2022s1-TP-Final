#include <iostream>
using namespace std;
#include <string.h>

#include "Color.h"
#include "Matrix.h"
#include "Img.h"

Matrix Source2() {
  Matrix source2 = M_new(8,8, green4);
  for(int i=1;i<=8;i++) { for(int j=1;j<=4;j++) { M_setAt(source2,i,j,cyan); } }
  M_setAt(source2,3,2,green1);  M_setAt(source2,2,3,green1);
  M_setAt(source2,3,3,green1);  M_setAt(source2,2,4,green1);
  M_setAt(source2,3,5,green1);
  M_setAt(source2,3,4,green2);  M_setAt(source2,6,4,green2);
  M_setAt(source2,4,3,green2);  M_setAt(source2,4,4,green2);
  M_setAt(source2,4,5,green2);  M_setAt(source2,5,3,green2);
  M_setAt(source2,5,4,green2);  M_setAt(source2,5,5,green2);
  M_setAt(source2,4,2,green3);  M_setAt(source2,5,2,green3);
  M_setAt(source2,6,2,green3);  M_setAt(source2,6,3,green3);
  M_setAt(source2,7,3,green3);  M_setAt(source2,6,5,green3);
  M_setAt(source2,7,4,green3);
  M_setAt(source2,4,6,brown1);  M_setAt(source2,4,7,brown1);
  M_setAt(source2,5,6,brown2);  M_setAt(source2,5,7,brown2);
  return(source2);
}

int main(int argc, char** args){
  if(argc >= 2) {
    if (strcmp(args[1],"1") == 0) {
      Matrix source1 = M_new(2, 2, red);
      M_setAt(source1,2,2,blue);
      Img img1 = createImg(source1, 2);
      if (argc >= 3 && strcmp(args[2],"-c") == 0) {
        CompressImg(img1);
      }
      RenderImg(img1);
    }
    if (strcmp(args[1],"2") == 0) {
      Matrix source2 = Source2(); 
      Img img2 = createImg(source2,8);
      if (argc >= 3 && strcmp(args[2],"-c") == 0) {
        CompressImg(img2);
      }
      RenderImg(img2);
    }
  } else {
    cout << "Para usarlo, indicar como primer argumento el ejemplo deseado (1 o 2), y opcionalmente como segundo argumento -c para imágenes comprimidas.";
  }
  return(0);
}

