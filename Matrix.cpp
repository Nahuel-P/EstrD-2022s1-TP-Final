#include <iostream>
//using namespace std;

#include "Matrix.h"

struct MatrixStr {
   int width;
   int height;
   Color** elements;
};

Matrix M_new(int w, int h, Color c) {
  Color** elems = new Color*[w];
  for(int i=0;i<w;i++) {
    elems[i] = new Color[h];
    for(int j=0;j<h;j++) {
      elems[i][j] = c;
    } 
  }
  return M_load(elems,w,h);
}

void M_delete(Matrix m) {
  for(int i=0;i<m->width;i++) { delete m->elements[i]; }
  delete m->elements;
  delete m;
}

Matrix M_load  (Color** source, int w, int h) {
  MatrixStr* newM = new MatrixStr;
  newM->width    = w;
  newM->height   = h;
  newM->elements = source;
  return newM;
}

int M_width (Matrix m) { return(m->width);  }
int M_height(Matrix m) { return(m->height); }

// PRECOND: 0<i<=M_width(m), 0<j<=M_height(m) 
Color M_getAt (Matrix m, int i, int j) {
  return m->elements[i-1][j-1];
}

// PRECOND: 0<i<=M_width(m), 0<j<=M_height(m) 
void M_setAt (Matrix m, int i, int j, Color c) {
  m->elements[i-1][j-1] = c;
}

int expectedColumnLength(Matrix m, int i) {
  int currentMax = expectedColorLength(M_getAt(m,i,1));
  for(int j=2;j<=m->height;j++) { 
    currentMax = max(currentMax, expectedColorLength(M_getAt(m,i,j))); 
  }
  return(currentMax);
}

int* expectedColumnsLengths(Matrix m) {
  int* colLen = new int[m->width+1];
  for(int i=1;i<=m->height;i++) {
    colLen[i] = expectedColumnLength(m, i);
  }
  return colLen;
}

void RenderRow(Matrix m, int j, string sep, int* colLen) {
  cout << sep; 
  RenderColor(M_getAt(m,1,j),colLen[1]);
  for(int i=2;i<=m->width;i++) { 
    cout << ", "; 
    RenderColor(M_getAt(m,i,j),colLen[i]); 
  }
  cout << endl;
}

void M_render(Matrix m) {
 cout << "Matrix m = [" << endl;
  int* colLen = expectedColumnsLengths(m);
  RenderRow(m,1,"  ",colLen);
  for(int j=2;j<=m->height;j++) { 
    RenderRow(m,j,", ",colLen); 
  }
  cout << "]" << endl;
  delete(colLen);
}  