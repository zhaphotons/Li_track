#ifndef HERD
#define HERD

#include"Syn_par.h"
#include<iostream>

using namespace std;


class Herd
{

public:

	//粒子有关参数
	Syn_par syn_par;

	//粒子数
	int Pnum;

	//粒子丢失信息
	int* Lose_flag;

	//粒子坐标
	double *x, *px, *y, *py, *t, *pt;

	Herd() {}
	Herd(Syn_par syn_par, int Pnum,
	     double* x, double* px, double* y, double* py, double* t, double* pt)
	{
		this->syn_par = syn_par;
		this->Pnum = Pnum;

		this->Lose_flag = new int[Pnum];

		this->x  = new double[Pnum];
		this->px = new double[Pnum];
		this->y  = new double[Pnum];
		this->py = new double[Pnum];
		this->t  = new double[Pnum];
		this->pt = new double[Pnum];


		for(int i=0; i<Pnum; i++)
		{
			this->Lose_flag[i] = 0;
		}

		memcpy(this->x, x, Pnum*sizeof(double));
		memcpy(this->px, px, Pnum*sizeof(double));
		memcpy(this->y, y, Pnum*sizeof(double));
		memcpy(this->py, py, Pnum*sizeof(double));
		memcpy(this->t, t, Pnum*sizeof(double));
		memcpy(this->pt, pt, Pnum*sizeof(double));
	}

	~Herd()
	{
		delete [] Lose_flag;
		delete [] x;
		delete [] px;
		delete [] y;
		delete [] py;
		delete [] t;
		delete [] pt;
	}

};



ostream& operator<<(ostream& out, const Herd& herd);



#endif HERD