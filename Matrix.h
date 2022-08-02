#include <iostream>
using namespace std;

#include "Color.h"

struct MatrixStr;
typedef MatrixStr* Matrix; // INV.REP.: nunca es NULL

Matrix M_new   (int w, int h, Color c);
void   M_delete(Matrix m);
Matrix M_load  (Color** source, int w, int h);
int    M_width (Matrix m);
int    M_height(Matrix m);
Color  M_getAt (Matrix m, int i, int j);          // PRECOND: 0<i<=M_width(m), 0<j<=M_height(m)
void   M_setAt (Matrix m, int i, int j, Color c); // PRECOND: 0<i<=M_width(m), 0<j<=M_height(m)
void   M_render(Matrix m);