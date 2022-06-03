#include <iostream>
#include <typeinfo>
#include <gmpxx.h>
#include <omp.h>
using namespace std;
	
int main(){
	const char *tmpx[6] = {"1e20",  "1e18", "1223", "1e15", "3", "-1e12"};
	const char *tmpy[6] = {"1e20",  "-1e22", "2", "1e13", "2111", "1e16"};
	mpf_t x[6];
	mpf_t y[6];
	mpf_t tmpmul;
	mpf_t res;
	mpf_init(tmpmul); mpf_init(res);
	mpf_set_default_prec(256);
	cout << mpf_get_default_prec() << endl;
	for (int i = 0; i < 6; i++){
		mpf_init_set_str(x[i], tmpx[i], 10);
		mpf_init_set_str(y[i], tmpy[i], 10);
	}
    cout << "Вычисляю..." << endl;
    double t1=omp_get_wtime();
	for (int i=0; i<6; i++){
		mpf_mul(tmpmul, x[i], y[i]);
		cout << "itog["<<i<<"]="<< tmpmul << endl;
		mpf_add(res, res, tmpmul);
		cout << "Результат     " << res << endl;
	}
	double t2=omp_get_wtime();
	printf("\nВремя счёта %lfc.\n",t2-t1);
	return 0;
	}
