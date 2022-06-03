#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int i;
	float x[6] = {1e20, 1223, 1e18, 1e15, 3, -1e12};
	float y[6] = {1e20, 2, -1e22, 1e13, 2111, 1e16};
	float z[6];
	float res;
	
	for (i=0; i<6; i++){
		z[i]=x[i]*y[i];
		cout << "itog["<<i<<"]="<< x[i]*y[i]<< endl;
		res+=z[i];
	}
	cout <<"res = " << res << endl;
	return 0;
	
}
