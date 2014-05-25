#ifndef BEAMLINE
#define BEAMLINE

#include<vector>

#include"Element.h"
#include"Herd.h"

#include<iostream>
using namespace std;

class Beamline
{
public:

	int size;

	double L;

	vector< Element* > beamline;

	Beamline(){}
	Beamline(vector< Element* > beamline)
	{
		this->beamline = beamline;

		size = beamline.size();
		L = 0;

		for(int i=0; i<size; i++)
		{
			L += beamline[i]->L;
		}
	}

	Herd* track(Herd* herd);
	Herd* track(Herd* herd, int n);
};


#endif