#include "matrix.h"
#include <omp.h>
//--------------------------------------------------------------------------------
int main() {
	string s1, s2;
	ifstream f1, f2;	

	const int n = 5000;

    double **a= new double*[n];
    double **b = new double *[n];
    for (int i = 0; i < n; i++){
        a[i] = new double [n];
        b[i] = new double [n];
    }
    
    Interval **Ia= new Interval*[n];
    Interval **Ib= new Interval*[n];
    Interval **Ic= new Interval*[n];


    for (int i = 0; i < n; i++){
        Ia[i] = new Interval[n];
        Ib[i] = new Interval[n];
        Ic[i] = new Interval[n];

        
    } 
	
	
	
	FRead_Double(a,n,n,"mat1");
	FRead_Double(b,n,n,"mat2");
	
	Ia = Cnv_Matrix_To_Interval(a,n,n);
	Ib = Cnv_Matrix_To_Interval(b,n,n);
	
	Ic = Mult_Matrix_By_Elements(Ia,Ib,n,n);
	
	//FExport_Matrix(Ic,n,n,"multmx");
	
	
	
	
	
	/*
	FRead_Double(a,n,n,"./test/koefA");
	FRead_Double(b,n,"./test/koefB");
	
	Ia = Cnv_Matrix_To_Interval(a,n,n);
	Ib = Cnv_Vector_To_Interval(b,n);
	
	FExport_Matrix(Ia, n, n, "test/koefAA", 15);
	FExport_Vector(Ib, n, "test/koefBB", 15);
	
	Print_Matrix(Ia,n,n,20);
	Print_Vector(Ib,n,20);
		
	res1 = Gauss_Jourdan(Ia,Ib,n,5);
	Print_Vector(res1,n,20);
	
	res2 = SLAU_LU(Ia,Ib,n,5);
	Print_Vector(res2,n,20);
	*/
			
}
