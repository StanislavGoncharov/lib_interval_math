#include <iostream>
#include <stdio.h>
#include <mpreal.h>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <iomanip>
#include <typeinfo>
#include <stdlib.h>
#include <omp.h>
using namespace std;
using namespace mpfr;

int main(){
	string s1, s2;
	ifstream f1, f2;
	ofstream frez;
	int n = 1000;
	mpfr_set_default_prec(32);
	cout << "precision = " << mpfr_get_default_prec() << endl;
	//объявляем указатели
	mpreal **a= new mpreal *[n];
    mpreal **b = new mpreal *[n];
    mpreal **c = new mpreal *[n];
    for (int i = 0; i < n; i++){
        a[i] = new mpreal [n];
        b[i] = new mpreal [n];
        c[i] = new mpreal [n];
    }
     
	//читаем из файлов исходые матрицы
	s1 = "mx1";
	s2 = "mx2";
    f1.open(s1);
    f2.open(s2);
    if (!f1.is_open() || !f2.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                f1 >> a[i][j];
                f2 >> b[i][j];
            }
        }
        cout << "Матрицы считаны" << endl;
    }
    f1.close();
    f2.close();

	cout << "Вычисляю..." << endl;	
	double t1=omp_get_wtime();
	//#pragma omp parallel for shared (a,b,c) num_threads(4)
		for (int i=0; i< n; i++)
			for (int j = 0; j < n; j++){
				c[i][j] = 0;
				for (int k = 0; k < n; k++)
					c[i][j] += (a[i][k] * b[k][j]);
			}
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	//записываем результ в файл
	s1 = "mult_rez_mpfr";
	frez.open(s1);
    if (frez.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i=0;i< n;i++){
			for(int j=0;j< n;j++){
				frez<< setw(5)<< c[i][j];
				//cout << setw(5)<< c[i][j];
				}
			frez<< endl;
			//cout << endl;
		}
	}
	frez.close();
	
	//очищаем память
	for (int i =0; i < n; i++){
		delete[] a[i];
		delete[] b[i];
		delete[] c[i];
	}
	delete[] a;
	delete[] b;
	delete[] c;
	 
	 //чтобы знать, что программа отработала до конца
	cout << "я тут был"<< endl;
	return 0;
	
}
