#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

    double muller[100];
    double a, b, c;
    a = 108.0;
    b = 815.0;
    c = 1500.0;
	muller[0] = 4.00;
	muller[1] = 4.25;
	for (int i = 2; i<100; i++){
		muller[i] = a - (b - c/muller[i-2])/muller[i-1];
	}
	for (int i = 0; i<100; i++){
		cout << i << " " << muller[i] << endl;
	}
	return 0;
}
