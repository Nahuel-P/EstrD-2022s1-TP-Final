#include <iostream>
using namespace std;

#include "Color.h"

struct ColorStr { 
  // INV.REP.: 0<=red<=255, 0<=green<=255, 0<=blue<=255, 
  int red;
  int green;
  int blue;
};

// PRECOND: 0<=r<=255, 0<=g<=255, 0<=b<=255, 
Color rgb(int r, int g, int b) {
  ColorStr* c = new ColorStr;
  c->red   = r;
  c->green = g;
  c->blue  = b;
  return c;
}

bool equalColor(Color c1, Color c2) {
  return(c1->red  ==c2->red
      && c1->green==c2->green
      && c1->blue ==c2->blue);
}

void renderChannel(int c) {
  //if (c<10)  { cout << " "; }
  //if (c<100) { cout << " "; }
  cout << c;
}

int expectedChannelLength(int c) { return (c<10?1:(c<100?2:3)); }
int expectedColorLength(Color c) {
  return (7 + expectedChannelLength(c->red)
            + expectedChannelLength(c->green)
            + expectedChannelLength(c->blue));
}

void renderBlanks(int n) {
  for(int i=1;i<=n;i++) { cout << " "; }
}

void RenderColor(Color c, int minLen) {
	// OBS: 
	//  El ancho esperado está entre 10 y 16. 
	//  Si minLen es menor que el ancho esperado, se obtiene ese ancho.
	//  Si es mayor o igual, se obtiene minLen.
  cout << "rgb(";
  renderChannel(c->red);
  cout << ","; 
  renderChannel(c->green);
  cout << ",";
  renderChannel(c->blue);
  cout << ")";
  renderBlanks(max(0,minLen-expectedColorLength(c)));
}
