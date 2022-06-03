#include <iostream>
#include <typeinfo>
#include <gmpxx.h>
using namespace std;

int main(){
	mpf_set_default_prec(256);
	//mpf_set_default_prec(512);
    mpf_t muller[100];
    for (int i =0; i < 100; i++)
		mpf_init(muller[i]);
    cout << "точность = " << mpf_get_default_prec() << endl;
    mpf_t a, b, c;
    mpf_init_set_d(a,108.0);
    mpf_init_set_d(b,815.0);
    mpf_init_set_d(c,1500.0);
    mpf_set_d(muller[0], 4.00);
    mpf_set_d(muller[1], 4.25);
    mpf_t t1, t2, t3;
    mpf_init(t1);
    mpf_init(t2);
    mpf_init(t3);
	for (int i = 2; i<100; i++){
		mpf_div(t1, c, muller[i-2]);
		mpf_sub(t2, b, t1);
		mpf_div(t3, t2, muller[i-1]);
		mpf_sub(muller[i], a, t3);
	}
	for (int i = 0; i<100; i++){
		cout << i << " " << muller[i] << endl;
	}
	return 0;
}
