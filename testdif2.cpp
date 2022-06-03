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

#include "diffur.h"

Interval G(Interval x){
        return Icos(x)*(100.0*(2.0*x*Isin(x)-(square(x)-2.0)*Icos(x))-200.0);
}


Interval F(Interval x, Interval y){
        return 100.0*square(x) * square(Icos(x)) - y * Itan(x) ;
}

Interval FF(Interval x, Interval y){
	/*работает*/
        return (2.0 / square(x)) - square(y);
}

Interval FFF(Interval x, Interval y){
	Interval epSs = 0.01;
	
        return (1.0 + x - (1.0 + x)* y)/epSs;
}

double FDD(double x, double y){
	double eps = 0.01;
	
        return (1.0 + x - (1.0 + x)* y)/eps;
}

double GDD(double x){
	double eps = 0.01;
        return 1.0 - exp(-1.0*(2.0*x+x*x)/(2.0*eps));
}

Interval GGG(Interval x){
	Interval eps = 0.01;
        return 1.0 - Iexp(-1.0*(2.0*x+square(x))/(2.0*eps));
}


int main() {
        double pi_hlf = M_PI;
        
        /*
        Interval a=0;
        Interval b=pi_hlf/2;
        int n=10;
        Interval x0 = 0;
        */
        /*
        Interval a=1;
        Interval b=3;
        int n=15;
        Interval x0 = 0;
        Interval eps = 0.001;
        */
        /*
        Interval a=0;
        Interval b=2;
        int n=150;
        Interval y0=0;
        Interval eps = 0.1;
        Interval *Test= new Interval[n];
        Interval *X= new Interval[n];
        Interval *XX= new Interval[n];
        Interval *YY= new Interval[n];
        Interval h=(b-a)/(Interval)n;
		for(int i=0; i < n; i++){
			X[i] = a + (Interval)i * h;	
		}
		*/
		double a=0;
        double b=2;
        int n=150;
        double y0=0;
        
        double *Test= new double[n];
        double *X= new double[n];
        double *XX= new double[n];
        double *YY= new double[n];
        double h=(b-a)/n;
		
		for(int i=0; i < n; i++){
			X[i] = a + i * h;	
		}

        for(int i=0; i < n; i++){
			Test[i] = GDD(X[i]);	
		}
		
		/*for(int i=0; i < n; i++){
			cout << "X["<<i<<"]="<<X[i] << endl;
		}
		cout << endl;
		*/
		for(int i=0; i < n; i++){
			cout << "X["<<i<<"]="<<X[i] << "\t\t" << "Test["<<i<<"]="<<Test[i] << endl;
		}
		
		
        Runge_Kut_DB(FDD,a,b,n,y0,XX,YY);
 
        /*Interval Err;
        for (int i = 0; i < n; i++){
			Err += square(Test[i]-YY[i]);
		}
		cout << "Err=" << Err << endl;
        */
        
        /*cout << endl;
        cout << endl;
        cout << endl;
        Eiler(FFF,a,b,n,y0);
        cout << endl;
        cout << endl;
        cout << endl;
        Eiler_m(FFF,a,b,n,y0);
        cout << endl;
        cout << endl;
        cout << endl;*/
        //Kut_Merson(FFF,a,b,n,y0,eps);	
        /*cout << endl;
        cout << endl;
        cout << endl;
		Adams(FFF,a,b,n,y0);
		cout << endl;
        cout << endl;
        cout << endl;
        Miln_m(FFF,a,b,5,y0);
		cout << endl;
        cout << endl;
        cout << endl;*/
			
        return 0;
}
