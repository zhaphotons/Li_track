#include<iostream>
#include"Syn_par.h"
#include"Herd.h"
#include"Element.h"
#include"Drift.h"
#include"Quadrupole.h"
#include"SectorDipole.h"
#include"Sextupole.h"
#include"Beamline.h"

#include<time.h>
#include<vector>


using namespace std;


#define pi 3.141592653589793

int main()
{
	Syn_par a(938.27, 60);

	//Herd b(a, 5);

	double x[5] = {1e-3,2e-3,3e-3,4e-3,5e-3};
	double px[5] = {1e-3,-2e-3,3e-3,-4e-3,5e-3};
	double temp[5] = {0,0,0,0,0};
	double temp2[1] = {1e-4};

	Herd* b;
	b = new Herd(a, 1, x, px, x, px, x, px);

	//cout << a;
	cout << *b;

	//Element c(0.35);
	
	//cout << b.x[0] << b.px[4] << endl;

	//cout << sizeof(x);

	Drift* D;
	D = new Drift(0.001);

	Quadrupole *QF, *QD;
	QF = new Quadrupole(0.1, 10, 2);
	QD = new Quadrupole(0.1, -10, 2);

	SectorDipole* SB;
	SB = new SectorDipole(1.60, 60./180.*pi, 23.*pi/180., 23.*pi/180, 0.5, 0.05/2, 1);

	Sextupole* SEA;
	SEA = new Sextupole(0.1, 10, 2);


	vector< Element* > line;

	//line.push_back(D);
	line.push_back(QF);
	line.push_back(SEA);
	line.push_back(QD);
	//line.push_back(SB);
	
	
	Beamline Main(line);


	clock_t start, finish;
	double dur;

	start = clock();
	for(int i=0; i<100; i++)
	{
		if(i%1000 == 0) cout<<i<<endl;
		Main.track(b);
	}
	finish = clock();
	cout << *b;
	cout << (double)(finish - start)/CLOCKS_PER_SEC << endl;

	//cout << tan(SB->E1) <<endl;
}