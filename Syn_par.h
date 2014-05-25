#ifndef SYN_PAR
#define SYN_PAR


#include<cmath>
#include<iostream>

using namespace std;


class Syn_par
{

public:

	double E0, K;

	double gamma, beta;

	int n;           //turn of track

	Syn_par() {}
	Syn_par(double E0, double K)
	{
		this->E0 = E0;
		this->K  = K;

		this->gamma = (E0+K)/E0;
		this->beta  = sqrt(1.-1./gamma/gamma);

		n = 0;
	}
};


ostream& operator<<(ostream& out, const Syn_par& syn_par);



#endif