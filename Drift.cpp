#include"Drift.h"
#include<cmath>


Herd* Drift::track(Herd* herd)
{
	for(int i=0; i<herd->Pnum; i++)
	{
		double x(herd->x[i]), px(herd->px[i]), y(herd->y[i]), py(herd->py[i]),t(herd->t[i]), pt(herd->pt[i]);

		double beta(herd->syn_par.beta), gamma(herd->syn_par.gamma);

		double Value_tmp = px*px + py*py + pow(pt/beta/gamma, 2);
		double O1 = sqrt( pow(1+pt/beta,2) - Value_tmp );

		herd->x[i] = x + L*px/O1;
		herd->y[i] = y + L*py/O1;
		herd->t[i] = t + L*(1./beta - (1./beta+pt)/O1);

	}

	return herd;
}