#ifndef ELEMENT
#define ELEMENT

#include"Herd.h"

class Element
{
public:

	double L;

	Element(){}
	Element(double L){this->L = L;}

	virtual Herd* track(Herd* herd){return herd;};

};


#endif