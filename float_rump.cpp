#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	float a = 77617;
	float b = 33096;
	float c = 11 * pow(a,2) * pow(b,2) - pow(b,6) - 121*pow(b,4) - 2;
	float f = 333.75 * pow(b,6) + pow(a,2) * c + 5.5 * pow(b,8) + a/(2*b);
	cout << "f = " << f << endl;
	
	return 0;
}
