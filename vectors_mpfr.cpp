#include <iostream>
#include <stdio.h>
#include <mpreal.h>
using namespace std;
using namespace mpfr;

int main(int argc, char **argv){
	int i;
	mpfr_set_default_prec(256);
	cout << "precision = " << mpfr_get_default_prec() << endl;
	mpreal x[6] = {1e20, 1223, 1e18, 1e15, 3, -1e12};
	mpreal y[6] = {1e20, 2, -1e22, 1e13, 2111, 1e16};
	mpreal z[6];
	mpreal res;
	
	for (i=0; i<6; i++){
		z[i]=x[i]*y[i];
		cout << "itog["<<i<<"]="<< x[i]*y[i]<< endl;
		res+=z[i];
	}
	cout <<"res = " << res << endl;
	return 0;
	
}
