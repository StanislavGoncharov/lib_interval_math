/*#include <iostream>
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

#include <iostream>
//#include <mpreal.h>
*/

using namespace std;
using namespace boost::numeric;
//using namespace mpfr;


typedef interval<double> Interval;

//typedef interval<mpreal> Interval;
//typedef boost::numeric::interval<double> Doublerval;								

ostream& operator<<(ostream& os, const Interval& r);

										
Interval Isqrt(Interval a);
															
/*----------------------------------------------------------------------------------------------------------------PRINT*/
															
//--------------------------------------------------------------------------------
void Print_Matrix(Interval **a, int row, int col, int setwp);
//--------------------------------------------------------------------------------
void Print_Vector(Interval *a, int row, int setwp);

//--------------------------------------------------------------------------------
void Print_Matrix(double **a, int row, int col, int setwp);

//--------------------------------------------------------------------------------
void Print_Vector(double *a, int row, int setwp);


/*----------------------------------------------------------------------------------------------------------------EXPORT*/													
														
//--------------------------------------------------------------------------------
void FExport_Matrix(double **a, int row, int col, string fname, int setwprec);
//--------------------------------------------------------------------------------
void FExport_Vector(double *a, int row, string fname, int setwprec);
//--------------------------------------------------------------------------------
void FExport_Matrix(Interval **a, int row, int col, string fname, int setwprec);
//--------------------------------------------------------------------------------
void FExport_Vector(Interval *a, int row, string fname, int setwprec);

/*----------------------------------------------------------------------------------------------------------------READ*/
//--------------------------------------------------------------------------------
void FRead_Double(double **a, int row, int col, string fname);

//--------------------------------------------------------------------------------
void FRead_Double(double *a, int row, string fname);

//--------------------------------------------------------------------------------
int FRead_Interval(Interval **a, int row, int col, string fname);

//--------------------------------------------------------------------------------
int FRead_Interval(Interval *a, int row, string fname);

/*----------------------------------------------------------------------------------------------------------------CONVERT*/

Interval Cnv_Double_To_Interval(double a);

//--------------------------------------------------------------------------------
Interval** Cnv_Matrix_To_Interval(double **a, int row, int col);

//--------------------------------------------------------------------------------
Interval* Cnv_Vector_To_Interval(double *a, int row);

/*------------------------------------------------------------------------------------------------------------ARITHMETIC*/

//--------------------------------------------------------------------------------
Interval** Sum_Matrix(Interval **a, Interval **b, int row, int col);

//--------------------------------------------------------------------------------
Interval** Difference_Matrix(Interval **a, Interval **b, int row, int col);
//--------------------------------------------------------------------------------
Interval** Mult_Matrix(Interval **a, int row1, int col1, Interval **b, int row2, int col2);
//--------------------------------------------------------------------------------
Interval* Mult_Matrix(Interval **a, int row1, int col1, Interval *b, int row2);

//--------------------------------------------------------------------------------
Interval** Mult_Matrix_By_Elements(Interval **a, Interval **b, int row, int col);

//--------------------------------------------------------------------------------
Interval** Mult_Matrix_on_Number(Interval **a, int row, int col, Interval Number);

//--------------------------------------------------------------------------------
Interval** Transpose(Interval **a, int row, int col);

//--------------------------------------------------------------------------------
Interval Determinant_Matrix(Interval **a, int n);



//--------------------------------------------------------------------------------
Interval* Gauss(Interval **a, Interval *b, int n, int prec);
//--------------------------------------------------------------------------------
Interval* Gauss_Jourdan(Interval **a, Interval *b, int n, int prec);

//--------------------------------------------------------------------------------
void LU(Interval **a, Interval **L, Interval **U, int n);


//--------------------------------------------------------------------------------
Interval* SLAU_LU(Interval **a, Interval *b, int n, int prec);

Interval Norm(Interval *a, int n);

Interval ScalarProd(Interval *x, Interval *y, int n);

int QR_GShmidth(Interval **a, Interval **Q, Interval **R, int n);
//--------------------------------------------------------------------------------
Interval** Inverse_Matrix(Interval **a, int n);
