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
	//char *tempstr;
	ifstream f1, f2;
	ofstream frez;	
	int n = 1000;
	mpq_t tmpmul; 
	//объявляем указатели	
    mpq_t **a= new mpq_t *[n];
    mpq_t **b = new mpq_t *[n];
    mpq_t **c = new mpq_t *[n];
    for (int i = 0; i < n; i++){
        a[i] = new mpq_t [n];
        b[i] = new mpq_t [n];
        c[i] = new mpq_t [n];
    }
    //инициализируем матрицы нулями
    for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
				mpq_init(a[i][j]);
				mpq_init(b[i][j]);
				mpq_init(c[i][j]);
			}
	}
	cout << "Размерность" << endl;
	cout << n << " x " << n << endl;
	//чтение
	s1 = "mx1";
	s2 = "mx2";
    f1.open(s1);
    f2.open(s2);
    if (!f1.is_open() || !f2.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
				f1 >> a[i][j];
				f2 >> b[i][j];
            }
        }
        cout << "Матрицы считаны" << endl;
    }
    f1.close();
    f2.close();
    
//проверяем корректность считывания матриц из файла
//вывод исходных матриц на экран
//первая матрица
/* 
   for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(5)<< a[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(5)<< b[i][j];
        }
        cout << endl;
    }
*/
	cout << "Вычисляю..." << endl;
    double t1=omp_get_wtime();
    #pragma omp parallel for shared (a,b,c) num_threads(4)
		for (int i=0; i< n; i++)
			for (int j = 0; j < n; j++){
				//очищаю на всякий случай (иногда неверно считает результирующую матрицу)
				//грешу на грязную память
				mpq_init(c[i][j]);
				mpq_init(tmpmul);
				mpq_set_ui(c[i][j], 0,1); //присваиваю значение вида 0/1
				for (int k = 0; k < n; k++){
					//умножаем элементы матриц
					mpq_mul(tmpmul, a[i][k], b[k][j]);
					//прибавляем результат умножения к c[i][j]
					mpq_add(c[i][j], c[i][j], tmpmul);
					}
				}			 
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n", t2-t1);
	
	//записываем результат в файл
	s1 = "mult_rez_mpq";
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
		cout << "Результат записан в файл" << endl;
	}
	frez.close();
	
	//очищаем память
	for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++){
				mpq_clear(a[i][j]);
				mpq_clear(b[i][j]);
				mpq_clear(c[i][j]);
	}	
	mpq_clear(tmpmul);
		
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
