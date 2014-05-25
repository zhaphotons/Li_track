#ifndef DRIFT
#define DRIFT

#include"Element.h"


class Drift: public Element
{
public:	
	Drift(){}
	Drift(double L): Element(L){}

	Herd* track(Herd* herd);
	
};


#endif