#include"Headers.h"

#include<fstream>



void main()
{

	SectorDipole *SB;

	Quadrupole *QF, *QD;

	Sextupole *SEQ1, *SEQ2, *SEA1, *SEA2;

	Drift *D1,
		  *D21, *D22, *D23, *D24,
		  *D31, *D32, *D33, *D34, *D35, *D36,
		  *D41, *D42,
		  *D51, *D52, *D53, *D54,
		  *D61, *D62, *D63, *D64,
		  *D7;

	Catcher *Ca;

	QF = new Quadrupole(0.25, 2.2632, 3);
	QD = new Quadrupole(0.20, -1.0, 3);

	SEQ1 = new Sextupole(0.15, -7, 1);
	SEQ2 = new Sextupole(0.15, -7, 1);

	SEA1 = new Sextupole(0.15, -10, 1);
	SEA2 = new Sextupole(0.15, 10, 1);

	SB = new SectorDipole(1.60, pi/3, 23.0*pi/180, 23.0*pi/180, 0.5, 0.052/2, 1);

	D1 = new Drift(1.45);
	
	D21 = new Drift(0.275); D22 = new Drift(0.45); D23 = new Drift(1.325); D24 = new Drift(0.25);

	D31 = new Drift(0.25); D32 = new Drift(0.25); D33 = new Drift(0.8); D34 = new Drift(0.275);  D35 = new Drift(0.45); D36 = new Drift(0.275);
	
	D41 = new Drift(1.0); D42 = new Drift(1.9);

	D51 = new Drift(0.2755); D52 = new Drift(0.45); D53 = new Drift(1.325); D54 = new Drift(0.25);
	
	D61 = new Drift(0.25); D62 = new Drift(1.325); D63 = new Drift(0.45); D64 = new Drift(0.275);

	D7 = new Drift(1.45);

	Ca = new Catcher(30e-3);
	
	Element* line[] = {Ca,
					   D1,
					   SB,
					   D21, SEQ1, D22, QF, D23, QD, D24,
					   SB,
					   D31, QD, D32, D33, D34, QF, D35, SEA1, D36,
					   SB,
					   D41, D42,
					   SB,
					   D51, SEQ2, D52, QF, D53, QD, D54,
					   SB,
					   D61, QD, D62, QF, D63, SEA2, D64, 
					   SB,
					   D7};
	
	
	//Element* line[] = {D1};

	vector<Element*> line_v(line, line+sizeof(line)/sizeof(Element*));

	Beamline Main(line_v);



	Syn_par a(938.27, 100);

	//Herd b(a, 5);

	double x[10] = {-1.4e-3+1.7e-3,2e-3,3e-3,4e-3,5e-3,1e-3,2e-3,3e-3,4e-3,5e-3};
	double px[10] = {-5e-4,-2e-4,3e-4,-4e-4,5e-4,1e-4,-2e-4,3e-4,-4e-4,5e-4};
	double temp[5] = {0,0,0,0,0};
	double temp2[1] = {1e-4};

	Herd* b;
	b = new Herd(a, 1, x,px,px,px,px, px);
	//cout << *b;

	vector<double> x_l, px_l;

	clock_t start, finish;
	double dur;

	start = clock();
	for(int i=0; i<100000; i++)
	{
		if(i%1000 == 0) cout<<i<<endl;
		x_l.push_back(b->t[0]);
		px_l.push_back(b->pt[0]);
		Main.track(b);
	}
	finish = clock();
	cout << *b;
	cout << (double)(finish - start)/CLOCKS_PER_SEC << endl;

	ofstream out;
	out.open("shit.txt", ios::out);
	//for(int i=0; i<x_l.size(); i++)
	//{
	//	out << x_l[i] <<"  " << px_l[i] << endl;
	//}
}