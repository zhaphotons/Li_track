#include"Sextupole.h"
#include"Herd.h"

Herd* Sextupole::track(Herd* herd)
{
	double gamma(herd->syn_par.gamma), beta(herd->syn_par.beta);
	double O1;

	double step(L/chips);

	for(int i=0; i<herd->Pnum; i++)
	{
		for(int j=0; j<chips; j++)
		{
			double s;

			//Kick 1
			s = c1*step;
			double x(herd->x[i]), px(herd->px[i]), y(herd->y[i]), py(herd->py[i]),t(herd->t[i]), pt(herd->pt[i]);

			herd->px[i] = px - K2/2.*(x*x-y*y)*s;
			herd->py[i] = py + K2*x*y*s;
			herd->pt[i] = pt;


			//Drift 1
			s = d1*step;
			x = herd->x[i]; px = herd->px[i]; y = herd->y[i]; py = herd->py[i]; t = herd->t[i]; pt = herd->pt[i];
			O1 = pow(px,2)+pow(py,2)+pow(pt/beta/gamma,2);
		
			herd->x[i] = x + s*(px - pt*px/beta);
			herd->y[i] = y + s*(py - pt*py/beta);
			herd->t[i] = t + s*(pt/pow(beta,2)/pow(gamma,2) - 1./2./beta*O1 - pow(pt,2)/pow(beta,3)/pow(gamma,2));
		
		 
			//Kick 2
			s = c2*step;
			x = herd->x[i]; px = herd->px[i]; y = herd->y[i]; py = herd->py[i]; t = herd->t[i]; pt = herd->pt[i];
		
			herd->px[i] = px - K2/2.*(x*x-y*y)*s;
			herd->py[i] = py + K2*x*y*s;
			herd->pt[i] = pt;

			//Drift 2
			s = d2*step;
			x = herd->x[i]; px = herd->px[i]; y = herd->y[i]; py = herd->py[i]; t = herd->t[i]; pt = herd->pt[i];
			O1 = pow(px,2)+pow(py,2)+pow(pt/beta/gamma,2);
		
			herd->x[i] = x + s*(px - pt*px/beta);
			herd->y[i] = y + s*(py - pt*py/beta);
			herd->t[i] = t + s*(pt/pow(beta,2)/pow(gamma,2) - 1./2./beta*O1 - pow(pt,2)/pow(beta,3)/pow(gamma,2));
		
			//Kick 3
			s = c3*step;
			x = herd->x[i]; px = herd->px[i]; y = herd->y[i]; py = herd->py[i]; t = herd->t[i]; pt = herd->pt[i];
		
			herd->px[i] = px - K2/2.*(x*x-y*y)*s;
			herd->py[i] = py + K2*x*y*s;
			herd->pt[i] = pt;

			//Drift 3
			s = d3*step;
			x = herd->x[i]; px = herd->px[i]; y = herd->y[i]; py = herd->py[i]; t = herd->t[i]; pt = herd->pt[i];
			O1 = pow(px,2)+pow(py,2)+pow(pt/beta/gamma,2);
		
			herd->x[i] = x + s*(px - pt*px/beta);
			herd->y[i] = y + s*(py - pt*py/beta);
			herd->t[i] = t + s*(pt/pow(beta,2)/pow(gamma,2) - 1./2./beta*O1 - pow(pt,2)/pow(beta,3)/pow(gamma,2));
		
			//Kick 4
			s = c4*step;
			x = herd->x[i]; px = herd->px[i]; y = herd->y[i]; py = herd->py[i]; t = herd->t[i]; pt = herd->pt[i];
		
			herd->px[i] = px - K2/2.*(x*x-y*y)*s;
			herd->py[i] = py + K2*x*y*s;
			herd->pt[i] = pt;
		}
	}

	return herd;

}