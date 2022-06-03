//генерация матрицы размерности N x N 
//заполненную элементами из интервала [-3, 3]

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <iomanip>
 
using namespace std;
	
int main(){
	string s1, s2;
	ofstream f1, f2;	
	int n = 5000;
    int **arr= new int*[n];
    int **arr2 = new int*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
        arr2[i] = new int[n];
    }
    srand(time(0));    
    //первая матрица
    for(int i = 0; i < n; i++ ){
	    for(int j = 0;  j < n;  j++ ){
		    arr[i][j] = rand() % 7 - 3; //[-3;3]
		}
	}  
	cout << "Размерность" << endl;
	cout << n << " x " << n << endl;
	//запись в файл
	s1 = "matrixx1";
	f1.open(s1);
    if (f1.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i=0;i< n;i++){
			for(int j=0;j< n;j++){
				f1<< setw(5)<< arr[i][j];
				cout << setw(5)<< arr[i][j];
				}
			f1<< endl;
			cout << endl;
		}
	}
	f1.close();
	//вторую матрицу генерирую отдельно
	//потому как иначе рандомайзер выдаёт одинаковые значения 
	cout << endl;
	sleep(1);
	srand(time(0));
	//вторая матрица
	for(int i = 0; i < n; i++ ){
	    for(int j = 0;  j < n;  j++ ){
		    arr2[i][j] = rand() % 7 - 3;
		}
	}  
	s2 = "matrixx2";
	f2.open(s2);
    if (f2.fail()) {
		cout<<"\n Ошибка открытия файла"<<endl;
		}
	else {
		for(int i=0;i< n;i++){
			for(int j=0;j< n;j++){
				cout << setw(5)<< arr2[i][j];
				f2<< setw(5)<< arr2[i][j];
				}
			f2<< endl;
			cout << endl;
		}
	}
	f2.close();
	return 0;
	}
