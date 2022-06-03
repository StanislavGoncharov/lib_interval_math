//произведение матриц
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
using namespace std;
	
int main(){
	string s1, s2;
	ifstream f1, f2;
	ofstream frez;	
	int n = 1000;
	mpf_t tmpmul;
	mpf_init(tmpmul);
	cout << mpf_get_default_prec() << endl;
	//объявляем указатели	
    mpf_t **a= new mpf_t *[n];
    mpf_t **b = new mpf_t *[n];
    mpf_t **c = new mpf_t *[n];    
    for (int i = 0; i < n; i++){
        a[i] = new mpf_t [n];
        b[i] = new mpf_t [n];
        c[i] = new mpf_t [n];
    }
    //инициализируем матрицы нулями
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
				mpf_init(a[i][j]);
				mpf_init(b[i][j]);
				mpf_init(c[i][j]);
			}
	}
	cout << "Размерность" << endl;
	cout << n << " x " << n << endl;

	s1 = "mx1";
	s2 = "mx2";
	//чтение
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
    
//проверяем корректность считывания матриц из файла
//первая матрица
/*
	for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(5)<< a[i][j];
        }
        cout << endl;
    }
    cout << endl;
    //вторая матрица
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(5)<< b[i][j];
        }
        cout << endl;
    }
*/
    cout << "Вычисляю..." << endl;
    double t1=omp_get_wtime();
    //#pragma omp parallel for shared (a,b,c) num_threads(4)
		for (int i=0; i< n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++){
					//умножаем элементы матриц
					mpf_mul(tmpmul, a[i][k], b[k][j]);
					//прибавляем результат умножения к c[i][j]
					mpf_add(c[i][j], c[i][j], tmpmul);
					}			
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	//записываем результат в файл
	s1 = "mult_rez_mpf";
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
	for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++){
				mpf_clear(a[i][j]);
				mpf_clear(b[i][j]);
				mpf_clear(c[i][j]);
	}
	mpf_clear(tmpmul); 
	
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
