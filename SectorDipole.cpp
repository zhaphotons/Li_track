#include<cmath>

#include"SectorDipole.h"
#include"Herd.h"

Herd* SectorDipole::track(Herd* herd)
{

	double gamma(herd->syn_par.gamma), beta(herd->syn_par.beta);
	
	//E1
	for(int i=0; i<herd->Pnum; i++)
	{
		herd->px[i] += h*tan(E1)*herd->x[i];
		herd->py[i] += -h*tan(E1b)*herd->y[i];
	}
	

	//Body
	double b1(h);

	for(int i=0; i<herd->Pnum; i++)
	{
		double x(herd->x[i]), px(herd->px[i]), y(herd->y[i]), py(herd->py[i]),t(herd->t[i]), pt(herd->pt[i]);
		double A = sqrt( pow(1.+pt/beta,2) - py*py - pow(pt/beta/gamma,2));
		herd->px[i] = px*cos(h*L) + ( sqrt(pow(A,2)-px*px) - b1*(rho+x) )*sin(h*L);
		double dpx_ds = -h*px*sin(h*L) + ( sqrt(pow(A,2)-px*px) - b1*(rho+x) )*h*cos(h*L);
		
		herd->x[i] = rho/b1*( h*sqrt(pow(A,2)-pow(herd->px[i],2)) - dpx_ds - b1 );

		herd->y[i] = y + py/b1/rho*L + py/b1*( asin(px/A) - asin(herd->px[i]/A) );

		herd->t[i] = t + (1./beta - h/b1*(1./beta+pt))*L - (1./beta+pt)/b1*( asin(px/A) - asin(herd->px[i]/A) );
	}


	//E2
	for(int i=0; i<herd->Pnum; i++)
	{
		herd->px[i] += h*tan(E2)*herd->x[i];
		herd->py[i] += -h*tan(E2b)*herd->y[i];
	}
	
	return herd;
}