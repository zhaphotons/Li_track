#include<iostream>
#include<iomanip>

#include"Syn_par.h"
#include"Herd.h"

using namespace std;

ostream& operator<<(ostream& out, const Herd& herd)
{
	//cout << "==============================================================" << endl;
	//cout << "# Syn_par info" << endl;
	//cout << "==============================================================" << endl;
	out << herd.syn_par;

	out << endl;
	//cout << "==============================================================" << endl;
	
	int pre(8), w(20);

	for(int i=0; i<herd.Pnum; i++)
	{
		out 
			 << setprecision(0) << setw(w) << left
			 << herd.Lose_flag[i]

			 << setprecision(pre) << setw(w) << left
			 << herd.x[i]

			 << setprecision(pre) << setw(w) << left
			 << herd.px[i]

			 << setprecision(pre) << setw(w) << left
			 << herd.y[i]

			 << setprecision(pre) << setw(w) << left
			 << herd.py[i]

			 << setprecision(pre) << setw(w) << left
			 << herd.t[i]

			 << setprecision(pre) << setw(w) << left
			 << herd.pt[i] << endl;
	}
	
	return out;
}
