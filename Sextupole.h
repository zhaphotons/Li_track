#ifndef SEXTUPOLE
#define SEXTUPOLE


#include"Element.h"
#include"Herd.h"
#include<cmath>


class Sextupole : public Element
{
public:
	
	//Basic parameters
	double K2;
	int chips;

	//For 4th order tracking
	double c1,d1,c2,d2,c3,d3,c4;

	Sextupole(){}
	Sextupole(double L, double K2, int chips)
	: Element(L)
	{
		this->K2 = K2;
		this->chips = chips;

		c1 = 1./2./(2.-pow(2.,1./3.)); c4 = c1;
		c2 = (1.-pow(2.,1./3.))/2./(2.-pow(2.,1./3.)); c3 = c2;
		d1 = 1./(2.-pow(2.,1./3.)); d3 = d1;
		d2 = -pow(2.,1./3.)/(2.-pow(2.,1./3.));
	}

	Herd* track(Herd* herd);  //4th order

};



#endif