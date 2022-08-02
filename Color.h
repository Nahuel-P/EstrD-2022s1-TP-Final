#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

struct ColorStr;
typedef ColorStr* Color; // INV.REP.: nunca es NULL

Color rgb(int r, int g, int b); 
        // PRECOND: 0<=r<=255, 0<=g<=255, 0<=b<=255, 
bool  equalColor(Color c1, Color c2);		
void  RenderColor(Color c, int minLen); 
		// OBS: 
		//  El ancho esperado está entre 10 y 16. 
		//  Si minLen es menor que el ancho esperado, se obtiene ese ancho.
		//  Si es mayor o igual, se obtiene minLen.
int expectedColorLength(Color c);

static Color black  = rgb(  0,   0,   0);
static Color white  = rgb(255, 255, 255);
static Color red    = rgb(255,   0,   0);
static Color green  = rgb(  0, 255,   0);
static Color blue   = rgb(  0,   0, 255);
static Color yellow = rgb(255, 255,   0);
static Color orange = rgb(255, 180,   0);
static Color purple = rgb(180,   0, 255);
static Color pink   = rgb(255,   0, 255);
static Color cyan   = rgb(  0, 255, 255);
static Color brown  = rgb(120,  60,  60); 
static Color green1 = rgb(  0, 129,   0);
static Color green2 = rgb(  0, 166,   0);
static Color green3 = rgb(  0, 194,   0);
static Color green4 = rgb(170, 212,   0);
static Color brown1 = rgb(170,  83,   0);
static Color brown2 = rgb(170, 136,   0);

#endif