#ifndef CATCHER
#define CATCHER

#include"Element.h"

#include<vector>
#include<iostream>

using namespace std;


class Catcher : public Element
{
public:
	
	double d;
	vector<double> turn_l, x_l, px_l, y_l, py_l, t_l, pt_l;

	Catcher(){}
	Catcher(double d)
	:Element(0)
	{
		this->d = d;
	}

	Herd* track(Herd* herd);
};

ostream& operator<<(ostream& out, Catcher* catcher);

#endif