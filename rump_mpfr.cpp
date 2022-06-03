#include <iostream>
#include <stdio.h>
#include <mpreal.h>
using namespace std;
using namespace mpfr;

int main(int argc, char **argv){
    //Timer t;
	mpfr_set_default_prec(512);
    cout.precision(57);
	cout << "точность = " << mpfr_get_default_prec() << endl;
	mpreal a = 77617;
	mpreal b = 33096;
	mpreal c = 11 * pow(a,2) * pow(b,2) - pow(b,6) - 121*pow(b,4) - 2;
	mpreal f = 333.75 * pow(b,6) + pow(a,2) * c + 5.5 * pow(b,8) + a/(2*b);
	cout.precision(64);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "f = " << f << endl;
    //cout << "Время =  " << t.elapsed() << endl;
	
	return 0;
}
