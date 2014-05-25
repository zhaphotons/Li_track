#include"Beamline.h"
#include"Herd.h"
#include"Element.h"


Herd* Beamline::track(Herd* herd)
{

	herd->syn_par.n += 1;

	for(int i=0; i<size; i++)
	{
		beamline[i]->track(herd);	
	}

	return herd;
}

Herd* Beamline::track(Herd* herd, int n)
{
	for(int turn=0; turn<n; turn++)
	{
		this->track(herd);
	}

	return herd;
}