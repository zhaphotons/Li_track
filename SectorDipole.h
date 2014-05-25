#ifndef SECTORDIPOLE
#define SECTORDIPOLE


#include"Element.h"
#include"Herd.h"
#include<cmath>


class SectorDipole : public Element
{

public:

	double angle, E1, E2;
	double Fint, Hgap;
	int chips;

	double h, rho;
	double E1b, E2b;

	SectorDipole(){}
	SectorDipole(double L, double angle, double E1, double E2, double Fint, double Hgap, int chips):
	Element(L)
	{
		this->angle = angle; this->E1 = E1; this->E2 = E2;
		this->Fint = Fint; this->Hgap = Hgap;
		this->chips = chips;

		rho = L/angle; h = 1./rho;
		
		E1b = E1 - h*2*Hgap*Fint*(1+pow(sin(E1),2));
		E2b = E2 - h*2*Hgap*Fint*(1+pow(sin(E2),2));
	}

	Herd* track(Herd* herd);
};





#endif