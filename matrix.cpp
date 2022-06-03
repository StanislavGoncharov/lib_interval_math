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



ostream& operator<<(ostream& os, const Interval& r) {
  os << r.lower() << " " << r.upper();
  return os;
}													

Interval Isqrt(Interval a){
	if (a >=0){
		double l,u;
		
		l = a.lower();
		u = a.upper();
		Interval res(sqrt(l), sqrt(u));
		
		return res;
	}
	cout << "Ошибка! Квадратный корень из отрицательного числа!" << endl;
	return nan("1");

}

															
/*----------------------------------------------------------------------------------------------------------------PRINT*/
															
//--------------------------------------------------------------------------------
void Print_Matrix(Interval **a, int row, int col, int setwp = 10){
		
	cout << "---------------Print_Interval_Matrix---------------" << endl;
	for(int i = 0; i < row; i++){
		for(int j = 0;j < col; j++){
			cout << setw(setwp)<< a[i][j];
		}
		cout << endl;
	}
	cout << "------------------------------------------\n\n\n" << endl;
}

//--------------------------------------------------------------------------------
void Print_Vector(Interval *a, int row, int setwp = 10){
	
	cout << "---------------Print_Interval_Vector---------------" << endl;
	for(int i = 0; i < row; i++){
		cout << setw(setwp)<< a[i] << endl;	
	}
	cout << "------------------------------------------\n\n\n" << endl;
}

//--------------------------------------------------------------------------------
void Print_Matrix(double **a, int row, int col, int setwp = 10){
		
	cout << "---------------Print_Matrix---------------" << endl;
	for(int i = 0; i < row; i++){
		for(int j = 0;j < col; j++){
			cout << setw(setwp)<< a[i][j];
		}
		cout << endl;
	}
	cout << "------------------------------------------\n\n\n" << endl;
}

//--------------------------------------------------------------------------------
void Print_Vector(double *a, int row, int setwp = 10){
	
	cout << "---------------Print_Vector---------------" << endl;
	for(int i = 0; i < row; i++){
		cout << setw(setwp)<< a[i] << endl;	
	}
	cout << "------------------------------------------\n\n\n" << endl;
}


/*----------------------------------------------------------------------------------------------------------------EXPORT*/
															
															
//--------------------------------------------------------------------------------
void FExport_Matrix(double **a, int row, int col, string fname = "fout", int setwprec=10){
	
	ofstream frez;
	cout << "-------------Export_Matrix_on_" << fname << "-------------" << endl;
	
	frez.open(fname);
    if (frez.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i = 0; i < row;i++){
			for(int j = 0; j < col; j++){
				frez<< setw(setwprec)<< a[i][j] << endl;
				}
			//frez<< endl;
		}
	}
	frez.close();
	cout << "-------------Export_Matrix_END-------------\n\n\n" << endl;
}

//--------------------------------------------------------------------------------
void FExport_Vector(double *a, int row, string fname = "fout", int setwprec=10){
	
	ofstream frez;
	cout << "-------------Export_Vector_on_" << fname << "-------------" << endl;
	
	frez.open(fname);
    if (frez.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i = 0; i < row;i++){
				frez<< setw(setwprec)<< a[i] << endl;
		}
	}
	frez.close();
	cout << "-------------Export_Vector_END-------------\n\n\n" << endl;
}


//--------------------------------------------------------------------------------
void FExport_Matrix(Interval **a, int row, int col, string fname = "fout", int setwprec=10){
	
	ofstream frez;
	cout << "-------------Export_Matrix_on_" << fname << "-------------" << endl;
	
	frez.open(fname);
    if (frez.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i = 0; i < row;i++){
			for(int j = 0; j < col; j++){
				frez<< setw(setwprec)<< a[i][j] << endl;
				}
			//frez<< endl;
		}
	}
	frez.close();
	cout << "-------------Export_Matrix_END-------------\n\n\n" << endl;
}

//--------------------------------------------------------------------------------
void FExport_Vector(Interval *a, int row, string fname = "fout", int setwprec=10){
	
	ofstream frez;
	cout << "-------------Export_Vector_on_" << fname << "-------------" << endl;
	
	frez.open(fname);
    if (frez.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i = 0; i < row;i++){
				frez<< setw(setwprec)<< a[i] << endl;
		}
	}
	frez.close();
	cout << "-------------Export_Vector_END-------------\n\n\n" << endl;
}


/*----------------------------------------------------------------------------------------------------------------READ*/
															

//--------------------------------------------------------------------------------
void FRead_Double(double **a, int row, int col, string fname = "fin"){
	
	cout << "-------------Read_Double_Matrix_from_" << fname << "-------------" << endl;
	ifstream f1;	
     
	cout << "Размерность матрицы" << endl;
	cout << row << " x " << col << endl;
    f1.open(fname);
    if (!f1.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                f1 >> a[i][j];
            }
        }
        cout << "Матрица считана" << endl;
    }
    f1.close();
	
	cout << "-------------Read_Double_Matrix_END-------------\n\n\n" << endl;
}

//--------------------------------------------------------------------------------
void FRead_Double(double *a, int row, string fname = "fin"){
	
	cout << "-------------Read_Double_Vector_from_" << fname << "-------------" << endl;
	ifstream f1;	
     
	cout << "Размерность вектора" << row << endl;
    f1.open(fname);
    if (!f1.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < row; i++)
        {
                f1 >> a[i];
        }
        cout << "Вектор считан" << endl;
    }
    f1.close();
	
	cout << "-------------Read_Double_Vector_END-------------\n\n\n" << endl;
}


//--------------------------------------------------------------------------------
int FRead_Interval(Interval **a, int row, int col, string fname = "fin"){
	/*есть баг, если начало интервала больше конца, то вылетаем на компиляции*/
	
	cout << "-------------Read_Interval_Matrix_from_" << fname << "-------------" << endl;
	ifstream f1;
	double tmpa, tmpb;	
     
	cout << "Размерность матрицы" << endl;
	cout << row << " x " << col << endl;
    f1.open(fname);
    if (!f1.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                f1 >> tmpa;
                f1 >> tmpb;
                if (tmpa > tmpb){
					cout << endl;
					cout << tmpa << " " << tmpb << endl;
					cout << "Ошибка! Начало интервала больше конца интервала!" << endl;
					cout << "Чтение завершено с ошибкой!" << endl;
					cout << endl;
					return -1;
				}
                //cout << tmpa << " " << tmpb << endl;
                Interval tmpi(tmpa, tmpb);
				a[i][j] = tmpi;
            }
        }
        cout << "Матрица считана" << endl;
    }
    f1.close();
	
	cout << "-------------Read_Interval_Matrix_END-------------\n\n\n" << endl;
	return 0;
}

//--------------------------------------------------------------------------------
int FRead_Interval(Interval *a, int row, string fname = "fin"){
	
	cout << "-------------Read_Interval_Vector_from_" << fname << "-------------" << endl;
	ifstream f1;
	double tmpa, tmpb;		
     
	cout << "Размерность вектора" << row << endl;
    f1.open(fname);
    if (!f1.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < row; i++)
        {
			f1 >> tmpa;
			f1 >> tmpb;
			if (tmpa > tmpb){
				cout << endl;
				cout << tmpa << " " << tmpb << endl;
				cout << "Ошибка! Начало интервала больше конца интервала!" << endl;
				cout << "Чтение завершено с ошибкой!" << endl;
				cout << endl;
				return -1;
			}
			Interval tmpi(tmpa, tmpb);
			a[i] = tmpi;
        }
        cout << "Вектор считан" << endl;
    }
    f1.close();
	
	cout << "-------------Read_Interval_Vector_END-------------\n\n\n" << endl;
	return 0;
}


/*----------------------------------------------------------------------------------------------------------------CONVERT*/

Interval Cnv_Double_To_Interval(double a){
	
	double l,u;
	
	l = a  - 0.00000001;
	u = a  + 0.00000001;
	Interval tmp(l,u); 
	return tmp;
}


//--------------------------------------------------------------------------------
Interval** Cnv_Matrix_To_Interval(double **a, int row, int col){
	
	Interval tmp;
	Interval **ITMP= new Interval*[row];
    for (int i = 0; i < row; i++)
        ITMP[i] = new Interval[col];
     
	for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++){
			tmp = Cnv_Double_To_Interval(a[i][j]);
            //ITMP[i][j] = a[i][j];
			ITMP[i][j] = tmp;
		}
			
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval* Cnv_Vector_To_Interval(double *a, int row){
	
	Interval *ITMP= new Interval [row];
    Interval tmp; 
	for (int i = 0; i < row; i++){
			tmp = Cnv_Double_To_Interval(a[i]);
            //ITMP[i] = a[i];
			ITMP[i] = tmp;
        }
	return ITMP;
}

/*------------------------------------------------------------------------------------------------------------ARITHMETIC*/

//--------------------------------------------------------------------------------
Interval** Sum_Matrix(Interval **a, Interval **b, int row, int col){
	
	if (row != col)
	{
		cout << "Поэлементное сложение невозможно!";
		return 0;
	}
	
	Interval **ITMP= new Interval*[row];
    for (int i = 0; i < row; i++)
        ITMP[i] = new Interval[col];	
	
	cout << "Произвожу поэлементное сложение матриц. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    #pragma omp parallel for shared (a,b,ITMP) num_threads(4)
		for (int i=0; i< row; i++)
			for (int j = 0; j < col; j++)
				    ITMP[i][j] = a[i][j] + b[i][j];  
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval** Difference_Matrix(Interval **a, Interval **b, int row, int col){
	
	if (row != col)
	{
		cout << "Поэлементное вычитание невозможно!";
		return 0;
	}
	
	Interval **ITMP= new Interval*[row];
    for (int i = 0; i < row; i++)
        ITMP[i] = new Interval[col];	
	
	cout << "Произвожу поэлементное вычитание матриц. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    //#pragma omp parallel for shared (a,b,c) num_threads(2)
		for (int i=0; i< row; i++)
			for (int j = 0; j < col; j++)
				    ITMP[i][j] = a[i][j] - b[i][j];   
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval** Mult_Matrix(Interval **a, int row1, int col1, Interval **b, int row2, int col2){
	
	if (col1 != row2)
	{
		cout << "Умножение невозможно!";
		return 0;
	}
	
	Interval **ITMP= new Interval*[row1];
    for (int i = 0; i < row1; i++)
        ITMP[i] = new Interval[col2];
	
	cout << "Произвожу умножение матриц. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    #pragma omp parallel for shared (a,b,ITMP) num_threads(4)
		for (int i=0; i < row1; i++)
			for (int j = 0; j < col2; j++)
				for (int k = 0; k < col1; k++)
				    ITMP[i][j] += a[i][k] * b[k][j];				
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval* Mult_Matrix(Interval **a, int row1, int col1, Interval *b, int row2){
	
	if (col1 != row2)
	{
		cout << "Умножение невозможно!";
		return 0;
	}
	
	Interval *ITMP= new Interval[row1];

	
	cout << "Произвожу умножение матриц. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    //#pragma omp parallel num_threads(2)
		for (int i=0; i< row1; i++)
				for (int k = 0; k < col1; k++)
				    ITMP[i]+= a[i][k] * b[k];				
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval** Mult_Matrix_By_Elements(Interval **a, Interval **b, int row, int col){
	
	if (row != col)
	{
		cout << "Поэлементное умножение невозможно!";
		return 0;
	}
	
	Interval **ITMP= new Interval*[row];
    for (int i = 0; i < row; i++)
        ITMP[i] = new Interval[col];
	
	cout << "Произвожу поэлементное умножение матриц. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    #pragma omp parallel for shared (a,b,ITMP) num_threads(4)
		for (int i=0; i< row; i++)
			for (int j = 0; j < col; j++)
				    ITMP[i][j] = a[i][j] * b[i][j];  
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval** Mult_Matrix_on_Number(Interval **a, int row, int col, Interval Number){
	
	Interval **ITMP= new Interval*[row];
    for (int i = 0; i < row; i++)
        ITMP[i] = new Interval[col];
	
	cout << "Произвожу умножение матрицы на число. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    //#pragma omp parallel for shared (a,b,c) num_threads(2)
		for (int i=0; i< row; i++)
			for (int j = 0; j < col; j++)
				    ITMP[i][j] = Number * a[i][j];				
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval** Transpose(Interval **a, int row, int col){
	
	Interval **ITMP= new Interval*[row];
    for (int i = 0; i < row; i++)
        ITMP[i] = new Interval[col];
        
	cout << "Произвожу транспонирование матрицы. Ожидайте..." << endl;
    double t1=omp_get_wtime();
    //#pragma omp parallel for shared (a,b,c) num_threads(2)
		for (int i=0; i< row; i++)
			for (int j = 0; j < col; j++)
				    ITMP[i][j] = a[j][i];  
				
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	return ITMP;
}

//--------------------------------------------------------------------------------
Interval Determinant_Matrix(Interval **a, int n){
	
	Interval det;
	//double s;
	Interval s;
	int tmp_j;
	Interval **TMP;    // Субматрица как набор ссылок на исходную матрицу
	
	
	
	switch (n){
		case 1:
			return a[0][0];
		case 2:
			return a[0][0] * a[1][1] - a[0][1] * a[1][0];
		default:
			if (n < 1){ 
				cout << "Вычисление определителя невозможно" << endl;
				return nan("1");  // Некорректная матрица
			}	
			TMP = new Interval*[n-1];  // Массив ссылок на столбцы субматрицы
			det = 0;
			s = 1;        
			for (int i = 0; i < n; i++)  
			{
				tmp_j = 0;
				for (int j = 0; j < n; j++)
					if (i != j)     
						TMP[tmp_j++] = a[j] + 1;  

				det = det + s * a[i][0] * Determinant_Matrix(TMP, n-1);
				s = -s;
			}
			delete[] TMP;
			return det;
	}
}


//--------------------------------------------------------------------------------
Interval* Gauss(Interval **a, Interval *b, int n, int prec = 8) {
	int k, r;
	Interval temp, max, M, S;
	Interval *x = new Interval [n];
	
	cout<< "\n\n\n---Вычисляю решение СЛАУ методом Гаусса---" << endl;
	
	cout<< setprecision(prec)<< fixed;
	//mpfr_set_default_prec(prec);
	Interval **TMPA= new Interval *[n];
	Interval *TMPB = new Interval [n];
	for (int i = 0; i < n; i++){
        TMPA[i] = new Interval [n];
        x[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			TMPA[i][j] = a[i][j];
		}
    }
    for (int i = 0; i < n; i++){
			TMPB[i] = b[i];
    }    
	
	
	for (int k = 0; k < n - 1; k++) {
		max = abs(TMPA[k][k]);
		r = k;
		for (int i = k + 1; i < n; i++) {
			if (abs(TMPA[i][k]) > max) {
				max = abs(TMPA[i][k]);
				r = i;
			}
		}
		if (r != k) {
			temp = TMPB[k];
			TMPB[k] = TMPB[r];
			TMPB[r] = temp;
			for (int j = 0; j < n; j++) {
				temp = TMPA[k][j];
				TMPA[k][j] = TMPA[r][j];
				TMPA[r][j] = temp;
			}
		}
		for (int i = k + 1; i < n; ++i) {
			M = TMPA[i][k] / TMPA[k][k];
			for (int j = k; j < n; ++j) {
				TMPA[i][j] = TMPA[i][j] - M*TMPA[k][j];
			}
			TMPB[i] = TMPB[i] - M*TMPB[k];
		}
	}
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			if (j != n){
				cout << setw(20)<< TMPA[i][j];
			}
			else{
				cout << setw(20)<< TMPB[i];
			}
		}
		cout << endl;
	}
	cout << endl;	
	
	for (int i = n-1; i >= 0; i--) {
		S = 0;
		for (int j = i + 1; j < n; ++j) {
			S = S + TMPA[i][j]*x[j];
		}
		x[i] = (TMPB[i]-S)/ TMPA[i][i];
	}
	
	delete[] TMPA;
	delete TMPB;
	return x;
}

//--------------------------------------------------------------------------------
Interval* Gauss_Jourdan(Interval **a, Interval *b, int n, int prec = 8) {
	
	int i,j,k;
	Interval tmp;
	int m = n + 1;
	Interval zero=0;
	
	cout<< "\n\n\n---Вычисляю решение СЛАУ методом Жордана-Гаусса---" << endl;
	cout<< setprecision(prec)<< fixed;
	Interval *x= new Interval [n];
	Interval **Z= new Interval *[n];
	for (int i = 0; i < n; i++)
	{
		Z[i] = new Interval [m];
		x[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j != n){
				Z[i][j] = a[i][j];
			}
			else{
				Z[i][j] = b[i];
			}
		}
	}
	
	//Print_Matrix(Z,n,m);
	 
	for(i = 0; i < n; i++)
	{
		if(Z[i][i] == zero)
		{
			cout<<"Mathematical Error!";
			exit(0);
		}
		for(j = 0; j < n; j++)
		{
			//cout << " [ " << i << " ] "<< " [ " << j << " ] "<< Z[i][j] << endl;
			if(i != j)
			{
				tmp = Z[j][i]/Z[i][i];
				for(k = 0; k < m; k++)
				{
					Z[j][k] = Z[j][k] - tmp*Z[i][k];
				}
			}
		}
	}
	
	Print_Matrix(Z,n,m,15);
	
	for(i = 0; i < n; i++)
	{
		x[i] = Z[i][n]/Z[i][i];
		//cout << " [ " << i << " ] "<<  x[i] << endl;
	}

	delete[] Z;
	return x;
}

//--------------------------------------------------------------------------------
void LU(Interval **a, Interval **L, Interval **U, int n) {
	
    Interval det = Determinant_Matrix(a,n);
    Interval zero = 0;
    if (det != zero){
		
			Interval **A= new Interval *[n];
			for (int i = 0; i < n; i++)
				A[i] = new Interval [n];
			
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				A[i][j] = a[i][j];
		 
		//инициализация матриц L и U
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) L[i][j]=1;
				else L[i][j]=0;
				U[i][j]=0;
			}
		}
		//непосредственно разложение
		for(int k=0;k<n;k++)
		{
			U[k][k]=A[k][k];
			for(int i=k+1;i<n;i++)
			{
				L[i][k]=A[i][k]/U[k][k];
				U[k][i]=A[k][i];
			}
			for(int i=k+1;i<n;i++)
			{
				for(int j=k+1;j<n;j++) 
					A[i][j]=A[i][j]-L[i][k]*U[k][j];
			}

		}
		cout <<"\nL - матрица"<< endl;			
		Print_Matrix(L,n,n,20);
		cout <<"U - матрица"<< endl;
		Print_Matrix(U,n,n,20);
		
		delete[] A;
		
	}
	else{
		cout << "Определитель матрицы равен нулю" << endl;
		cout << "Разложение невозможно!" << endl;
	}
}


//--------------------------------------------------------------------------------
Interval* SLAU_LU(Interval **a, Interval *b, int n, int prec = 8) {
	
	
	
	cout<< "\n\n\n---Вычисляю решение СЛАУ методом LU-разложения---" << endl;
	cout<< setprecision(prec)<< fixed;
	Interval *x= new Interval [n];
	Interval *y= new Interval [n];
	Interval **L= new Interval *[n];
	Interval **U= new Interval *[n];
	Interval S = 0;
	for (int i = 0; i < n; i++)
	{
		L[i] = new Interval [n];
		U[i] = new Interval [n];
		x[i] = 0;
		y[i] = 0;
	}
	
	LU(a,L,U,n);
	y[0] = b[0];
	
	for (int i=0; i < n; i++){
		S = 0;
		for (int k=0; k < i; k++){
			S = S + L[i][k]*y[k];
		}
		y[i]=b[i]-S;
	}
	x[n-1]=y[n-1]/U[n-1][n-1];
	
	for (int i=n-1; i >= 0; i--){
		S = 0;
		for (int k=i+1; k < n; k++){
			S = S + U[i][k]*x[k];
		}
		x[i]=(y[i]-S)/U[i][i];
	}
	
	delete[] L;
	delete[] U;
	delete y;
	return x;
}

Interval Norm(Interval *a, int n)//нормирование
{
	Interval s = 0;
	for (int i = 0; i < n; i++)
		s += a[i] * a[i];
	return Isqrt(s);
}

Interval ScalarProd(Interval *x, Interval *y, int n)
{
	Interval s = 0;
	for (int i = 0; i < n; i++)
		s += x[i] * y[i];
	return s;
}

int QR_GShmidth(Interval **a, Interval **Q, Interval **R, int n)
{
	
	Interval **A= new Interval *[n];
	Interval *q_= new Interval [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new Interval [n];
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			Q[i][j] = 0;
			R[i][j] = 0;
		}
	
	A = Transpose(a,n,n);	
	
	for (int j = 0; j < n; j++)
	{
	
		q_ = A[j];
		Q[j] = q_;
	
		for (int i = 0; i < n-1; i++)
		{
	
			R[i][j] = ScalarProd(Q[i], A[j],n);
	
			for (int k = 0; k < n; k++)
				Q[j][k] = Q[j][k]-R[i][j] * Q[i][k];
		}
	
		R[j][j] = Norm(Q[j],n);
		if (R[j][j] == 0)
		{
			cout << "ошибка" << endl;
			return -1;
		}
	
		for (int k = 0; k < n; k++)
			Q[j][k] = Q[j][k] / R[j][j];
	}
	cout <<"\nQ - матрица"<< endl;				
	Print_Matrix(Q,n,n,25);
	cout <<"R - матрица"<< endl;
	Print_Matrix(R,n,n,25);
	
	return 0;
}
/*
int QR_GShmidthModified(Interval **a, Interval **Q, Interval **R, int n)
{
	
	Matrix A = Transpose(A1);
	
	Result.R = InitZero(A.size());
	int m = A.size();
	for (int j = 0; j < m; j++)
	{
		
		Vector q_ = A[j];
		Result.Q.push_back(q_);
		
		for (int i = 0; i < Result.Q.size() - 1; i++)
		{
		
			Result.R[i][j] = ScalarProd(Result.Q[i], Result.Q[j]);
		
			for (int k = 0; k < Result.Q[j].size(); k++)
				Result.Q[j][k] = Result.Q[j][k] - Result.R[i][j] * Result.Q[i][k];
		}
		
		Result.R[j][j] = Norm(Result.Q[j]);
		if (Result.R[j][j] == 0)
		{
			return -1;
		}
		
		for (int k = 0; k < Result.Q[j].size(); k++)
			Result.Q[j][k] = (double)Result.Q[j][k] / Result.R[j][j];
	}
	return 0;
}

*/
//--------------------------------------------------------------------------------
Interval** Inverse_Matrix(Interval **a, int n){
	
	Interval det = Determinant_Matrix(a,n);
	
	Interval zero=0;
 	
	if (det!=zero){
		cout << "Det= " << det << endl;
		cout << "Определитель не равен нулю!" << endl;
		
		Interval **ITMP= new Interval*[n];
		Interval *B= new Interval [n];
		Interval *itr;
		for (int i = 0; i < n; i++)
			ITMP[i] = new Interval[n];

		
		double t1=omp_get_wtime();
		//#pragma omp parallel for shared (a,b,c) num_threads(2)

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					B[j] = 1;
				}
				else
				{
					B[j] = 0;
				}
			}
			itr = Gauss_Jourdan(a,B,n);
			for (int k = 0; k < n; k++)
			{
				ITMP[k][i] = itr[k];
			}
		}

		double t2=omp_get_wtime();
		printf("Время счёта %lfc.\n",t2-t1);

		return ITMP;
			
	}
	
	cout << "Det= " << det << endl;
	cout << "Определитель равен НУЛЮ!" << endl;
	cout << "Обратной матрицы не существует!" << endl;
	return 0;
}
