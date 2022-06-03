//произведение матриц (сишный дабл)

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
#include <time.h>
using namespace std;
	
int main(){
	string s1, s2;
	ifstream f1, f2;
	ofstream frez;	
	int n = 5000;
    double **a= new double *[n];
    double **b = new double *[n];
    double **c = new double *[n];
    for (int i = 0; i < n; i++){
        a[i] = new double [n];
        b[i] = new double [n];
        c[i] = new double [n];
    } 
	cout << "Размерность" << endl;
	cout << n << " x " << n << endl;
	/*s1 = "matrixx1";
	s2 = "matrixx2";

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
    f2.close();*/

//вывод исходных матриц на экран
    /*for (int i = 0; i < n; i++){
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
    }*/
    
    for(int i = 0; i < n; i++ ){
	    for(int j = 0;  j < n;  j++ ){
		    a[i][j] = rand() % 7 - 3; //[-3;3]
		}
	}  
	
		sleep(1);
	srand(time(0));
	//вторая матрица
	for(int i = 0; i < n; i++ ){
	    for(int j = 0;  j < n;  j++ ){
		    b[i][j] = rand() % 7 - 3;
		}
	}  
    
    cout << "Вычисляю..." << endl;	
    double t1=omp_get_wtime();
    #pragma omp parallel for shared (a,b,c) num_threads(4)
		for (int i=0; i< n; i++)
			for (int j = 0; j < n; j++){
				//c[i][j] = 0;
				//for (int k = 0; k < n; k++)
				//	c[i][j]  = (a[i][k] * b[k][j]);
				c[i][j] = (a[i][j] * b[i][j]);
				}
	double t2=omp_get_wtime();
	printf("Время счёта %lfc.\n",t2-t1);
	
	//записываем результат в файл
/*	s1 = "mult_double1111111111";
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
*/
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
