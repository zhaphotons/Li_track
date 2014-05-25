#include"Catcher.h"

#include<vector>
#include<iostream>
#include<iomanip>

using namespace std;


Herd* Catcher::track(Herd* herd)
{
	for(int i=0; i<herd->Pnum; i++)
	{
		if(herd->Lose_flag[i] == 0)
		{
			if(herd->x[i]>d)
			{
				cout << "Catch!" << endl;
				turn_l.push_back(herd->syn_par.n);
				x_l.push_back(herd->x[i]);
				px_l.push_back(herd->px[i]);
				y_l.push_back(herd->y[i]);
				py_l.push_back(herd->py[i]);
				t_l.push_back(herd->t[i]);
				pt_l.push_back(herd->pt[i]);

				herd->Lose_flag[i] = 1;
				herd->x[i] = 0;
				herd->px[i] = 0;
				herd->y[i] = 0;
				herd->py[i] = 0;
				herd->t[i] = 0;
				herd->pt[i] = 0;
			}
		}
	}

	return herd;
}


ostream& operator<<(ostream& out, Catcher* catcher)
{
	out << "Lose_infomation" << endl;
	
	int pre(8), w(20);

	for(int i=0; i<catcher->turn_l.size(); i++)
	{
		out 
			 << setprecision(0) << setw(w) << left
			 << catcher->turn_l[i]

			 << setprecision(pre) << setw(w) << left
			 << catcher->x_l[i]

			 << setprecision(pre) << setw(w) << left
			 << catcher->px_l[i]

			 << setprecision(pre) << setw(w) << left
			 << catcher->y_l[i]

			 << setprecision(pre) << setw(w) << left
			 << catcher->py_l[i]

			 << setprecision(pre) << setw(w) << left
			 << catcher->t_l[i]

			 << setprecision(pre) << setw(w) << left
			 << catcher->pt_l[i] << endl;
	}

	return out;

}