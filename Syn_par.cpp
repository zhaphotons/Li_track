#include<iostream>

#include"Syn_par.h"


using namespace std;

ostream& operator<<(ostream& out, const Syn_par& syn_par)
{
	cout << "turn, E0, K, gamma, beta" << endl;

	cout << syn_par.n << " "
		 << syn_par.E0 << " "
		 << syn_par.K << " "
		 << syn_par.gamma << " "
		 << syn_par.beta << endl;

	return out;

}