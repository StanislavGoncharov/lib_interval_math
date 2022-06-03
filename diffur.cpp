#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <iomanip>
#include <typeinfo>
#include <gmpxx.h>
#include <stdlib.h>
#include <omp.h>
#include <cmath>
#include <boost/numeric/interval/interval.hpp>
#include <boost/numeric/interval/io.hpp>   
#include <boost/numeric/interval/rounded_arith.hpp> 
#include <boost/numeric/interval/checking.hpp>      
#include <boost/numeric/interval/arith.hpp>         
#include <boost/numeric/interval/policies.hpp>
#include <boost/numeric/interval/transc.hpp>   

#include "matrix.h"
#include "diffur.h"

ostream& operator<<(ostream& os, const Interval& r) {
  os << r.lower() << " " << r.upper();
  return os;
}
			
Interval Isin(Interval a){
	
	double l,u;
	
	l = a.lower();
	u = a.upper();
	Interval res(sin(l), sin(u));
	
	return res;
}

Interval Icos(Interval a){
	
	double l,u;
	
	l = a.lower();
	u = a.upper();
	Interval res(cos(l), cos(u));
	
	return res;
}

Interval Itan(Interval a){
	
	double l,u;
	
	l = a.lower();
	u = a.upper();
	Interval res(tan(l), tan(u));
	
	return res;
}

Interval Iexp(Interval a){
	
	double l,u;
	
	l = a.lower();
	u = a.upper();
	Interval res(exp(l), exp(u));
	
	return res;
}   


void Eiler(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval x0){
	
	Interval *X= new Interval[n];
	Interval *Y= new Interval[n];
	Interval *YR= new Interval[n];
	
	Interval h=(b-a)/(Interval)n;
	Y[0]=x0;
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i < n; i++){
		X[i]=a+ (Interval)i * h;	
	}
	for(int i=1; i < n; i++){
		
		Y[i]=Y[i-1]+h*Fn(X[i-1],Y[i-1]);
	}
	for(int i=0; i < n; i++){
			cout << "X["<<i<<"]="<<X[i] <<" " << endl;
	}
	cout << endl;
	for(int i=0; i < n; i++){
			cout << "Y["<<i<<"]="<<Y[i] << " " << endl;
	}	
	delete X;
	delete Y;
	delete YR;
}

void Eiler_m(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0){
	
	Interval *X= new Interval[n];
	Interval *Y= new Interval[n];
	Interval *YR= new Interval[n];
	Interval xp, yp;
	
	Interval h=(b-a)/(Interval)n;
	Y[0]=y0;
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i < n; i++){
		X[i]= a + (Interval)i * h;	
	}
	for(int i=1; i < n; i++){
		xp = X[i-1] + h/2.0;
		yp = Y[i-1] + h/2.0 * Fn(X[i-1],Y[i-1]);
		Y[i]=Y[i-1] + h * Fn(xp,yp);
	}
	for(int i=0; i < n; i++){
			cout << "X["<<i<<"]="<<X[i] << endl;
	}
	cout << endl;
	for(int i=0; i < n; i++){
			cout << "Y["<<i<<"]="<<Y[i] << endl;
	}	
	delete X;
	delete Y;
	delete YR;
}
/*
void Runge_Kut(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0, Interval* X,Interval* Y){
	

	Interval k1,k2,k3,k4,delt;
	
	Interval h=(b-a)/(Interval)n;
	Y[0]=y0;
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i < n; i++){
		X[i]= a + (Interval)i * h;	
	}
	for(int i=1; i < n; i++){
		k1 = Fn(X[i-1],Y[i-1]);
		k2 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k1);
		k3 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k2);
		k4 = Fn(X[i-1] + h, Y[i-1] + h*k3);
		delt = h/6.0*(k1+2.0*k2+2.0*k3+k4);
		Y[i] = Y[i-1] + delt;
	}
	for(int i=0; i < n; i++){
			cout << "X["<<i<<"]="<<X[i] << endl;
	}
	cout << endl;
	for(int i=0; i < n; i++){
			cout << "Y["<<i<<"]="<<Y[i] << endl;
	}
}
*/
void Runge_Kut(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0, Interval* X,Interval* Y){
	

	Interval k1,k2,k3,k4,delt;
	
	Interval h=(b-a)/(Interval)n;
	Y[0]=y0;
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i <= n; i++){
		X[i]= a + (Interval)i * h;	
	}
	for(int i=1; i <= n; i++){
		k1 = Fn(X[i-1],Y[i-1]);
		k2 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k1);
		k3 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k2);
		k4 = Fn(X[i-1] + h, Y[i-1] + h*k3);
		delt = h/6.0*(k1+2.0*k2+2.0*k3+k4);
		Y[i] = Y[i-1] + delt;
	}
	for(int i=0; i <= n; i++){
			cout << "X["<<i<<"]="<<X[i] << endl;
	}
	cout << endl;
	for(int i=0; i <= n; i++){
			cout << "Y["<<i<<"]="<<Y[i] << endl;
	}
}

void Runge_Kut_DB(double (*Fn)(double, double), double a,double b, int n, double y0, double* X,double* Y){
	
	double k1,k2,k3,k4,delt;
	
	double h=(b-a)/n;
	Y[0]=y0;
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i <= n; i++){
		X[i]= a + i * h;	
	}
	for(int i=1; i <= n; i++){
		k1 = Fn(X[i-1],Y[i-1]);
		k2 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k1);
		k3 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k2);
		k4 = Fn(X[i-1] + h, Y[i-1] + h*k3);
		delt = h/6.0*(k1+2.0*k2+2.0*k3+k4);
		Y[i] = Y[i-1] + delt;
	}
	/*
	for(int i=0; i < n; i++){
		cout << "X["<<i<<"]="<<X[i] << endl;
	}*/
	cout << endl;
	for(int i=0; i <= n; i++){
		cout << "X["<<i<<"]="<<X[i] << "\t\t" << "Y["<<i<<"]="<<Y[i] << endl;
	}
}


void Kut_Merson(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0, Interval eps=0.001){
	
	Interval *X= new Interval[n];
	Interval *Y= new Interval[n];
	Interval *YR= new Interval[n];
	Interval k1,k2,k3,k4,k5,R,Y1,Y2;
	int i,j;
	
	Interval h=(b-a)/(Interval)n;
	Y[0]=y0;
	X[0] = a;
	i = 1;
	while (X[i-1] + h <= b){
		R = 3.0*eps;
	
		while (R>eps){
			k1 = Fn(X[i-1],Y[i-1]);
			k2 = Fn(X[i-1] + h/3.0, Y[i-1] + h/3.0*k1);
			k3 = Fn(X[i-1] + h/3.0, Y[i-1] + h/6.0*k1 + h/6.0*k2);
			k4 = Fn(X[i-1] + h/2.0, Y[i-1] + h/8.0*k1 + 3.0*h/8.0*k2);
			k5 = Fn(X[i-1] + h, Y[i-1] + h/2.0*k1 - 3.0*h/2.0*k3 + 2.0*h*k4);
			
			Y1 = Y[i-1] + h/2.0*(k1-3.0*k3+4.0*k4);
			Y2 = Y[i-1] + h/6.0*(k1+4.0*k4+k5);
			
			R = 0.2*abs(Y1 - Y2);
			if (R > eps){
				h = h/2.0;
			}
			else{
				X[i] = X[i-1]+h;
				Y[i] = Y2;
				i = i+1;
				
				if (R <= eps /64.0){
					if (X[i-1] + 2.0*h <= b){
						h = 2.0*h;
					}
				}		
			}
		}
	}
	j = i - 1;
	
	cout << "j= " << j << endl;
	for(int jj=0; jj < i; jj++){
			cout << "X["<<jj<<"]="<<X[jj] << endl;
	}
	cout << endl;
	for(int jj=0; jj < i; jj++){
			cout << "Y["<<jj<<"]="<<Y[jj] << endl;
	}
	/*delete X;
	delete Y;
	delete YR;*/	
}

void Adams(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0){
	
	Interval *X= new Interval[n];
	Interval *Y= new Interval[n];
	Interval *YR= new Interval[n];
	Interval k1,k2,k3,k4,delt,yp;
	
	Interval h=(b-a)/(Interval)n;
	Y[0]=y0;
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i < n; i++){
		X[i]= a + (Interval)i * h;	
	}
	for(int i=1; i < n; i++){
		k1 = Fn(X[i-1],Y[i-1]);
		k2 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k1);
		k3 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k2);
		k4 = Fn(X[i-1] + h, Y[i-1] + h*k3);
		delt = h/6.0*(k1+2.0*k2+2.0*k3+k4);
		Y[i] = Y[i-1] + delt;
	}
	
	for(int i=3; i < n-1; i++){
		yp = Y[i]+h/24.0*(-9.0*Fn(X[i-3],Y[i-3])+37.0*Fn(X[i-2],Y[i-2])-59.0*Fn(X[i-1],Y[i-1]) + 55.0*Fn(X[i],Y[i]));
		Y[i+1] = Y[i] + h/24.0*(Fn(X[i-2],Y[i-2])-5.0*Fn(X[i-1],Y[i-1]) + 19.0*Fn(X[i],Y[i]) + 9.0*Fn(X[i+1],yp));
	}
	
	for(int i=0; i < n; i++){
		cout << "X["<<i<<"]="<<X[i] << endl;
	}
	cout << endl;
	for(int i=0; i < n; i++){
		cout << "Y["<<i<<"]="<<Y[i] << endl;
	}
	delete X;
	delete Y;
	delete YR;	
}

void Miln_m(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0){
	
	Interval *X= new Interval[n];
	Interval *Y= new Interval[n];
	Interval *yp= new Interval[n];
	Interval k1,k2,k3,k4,delt,m;
	
	Interval h=(b-a)/(Interval)n;
	Y[0] = y0;
	yp[0] = Y[0];
	
	//cout << M_PI << endl;
	//cout << pi_hlf << endl;
	//cout << b << endl;
	for(int i=0; i < 4; i++){
		X[i]= a + (Interval)i * h;	
	}
	for(int i=1; i < 5; i++){
		k1 = Fn(X[i-1],Y[i-1]);
		k2 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k1);
		k3 = Fn(X[i-1] + h/2.0, Y[i-1] + h/2.0*k2);
		k4 = Fn(X[i-1] + h, Y[i-1] + h*k3);
		delt = h/6.0*(k1+2.0*k2+2.0*k3+k4);
		Y[i] = Y[i-1] + delt;
		yp[i] = Y[i];
	}
	
	for(int i=3; i < n-1; i++){
		yp[i+1] = Y[i-3] + 4.0*h/3.0*(2.0*Fn(X[i-2],Y[i-2]) - Fn(X[i-1],Y[i-1]) + Fn(X[i],Y[i]));
		m = yp[i+1] + 28.0/29.0*(Y[i]-yp[i]);
		Y[i+1] = Y[i-1] + h/3.0*(Fn(X[i-1],Y[i-1])) + 4.0 * Fn(X[i],Y[i]) + Fn(X[i+1],m);
	}
	
	for(int i=0; i < n; i++){
			cout << "X["<<i<<"]="<<X[i] << endl;
	}
	cout << endl;
	for(int i=0; i < n; i++){
			cout << "Y["<<i<<"]="<<Y[i] << endl;
	}
	delete X;
	delete Y;
	delete yp;
		
}



