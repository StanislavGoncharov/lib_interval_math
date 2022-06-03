#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <gmpxx.h>
#include <omp.h>
using namespace std;

void mpf_to_mpq(mpq_t tmpdrob, mpf_t tmpfloat){
	string s, s1, s2;
	//разбиваем mpf на мантиссу и порядок, чтобы перевести в строку
	char *stfloat;
	mp_exp_t exponent;
	stfloat = mpf_get_str(NULL, &exponent, 10, 0, tmpfloat); //преобразуем mpf в мантису и порядок
	//cout << stfloat << endl;
	//cout << exponent << endl;
	s = string(stfloat); //записываем мантиссу в строку
	if (exponent == 0){
		s = "0." + s;
	}
	else{
		s.insert(exponent, ".");
		}
	//cout << "Строка из длинного вещественного\n "<<  s << endl;
	
	mpz_t a, denum, numer;
	const char *chrs1;
	mpz_init_set_ui(a, 10);
	mpz_init(denum);
	mpz_init(numer);
	remove_copy(s.begin(), s.end(), back_inserter(s1), '.'); //число без точки
	remove_copy(s.begin()+s.find('.'), s.end(), back_inserter(s2), '.'); //дробная часть
	long long int n = s2.length();
	mpz_pow_ui(denum, a, n);
	chrs1 = s1.c_str();
	mpz_set_str(numer, chrs1, 10);
	mpq_set_num(tmpdrob, numer);
	mpq_set_den(tmpdrob, denum);
	
	mpz_clear(a);
	mpz_clear(numer);
	mpz_clear(denum);
	}


int main(){
	
	//для теста сохраним число в char
	const char *chrs = "1.33";
	//переведём char в mpf
	mpf_t tmpfloat;
	mpf_init(tmpfloat);
	mpf_set_str(tmpfloat, chrs,10);
	cout << "Исходное число" << endl;
	mpf_out_str(stdout, 10, 60, tmpfloat);
	cout << endl;
	
	mpq_t tmpdrob;
	mpq_init(tmpdrob);
	mpf_to_mpq(tmpdrob, tmpfloat);
	cout << "Итоговая дробь\n " << tmpdrob << endl;  //дробь
	
	mpq_t tmpdrob3;
	mpq_init(tmpdrob3);
	mpq_set_f(tmpdrob3, tmpfloat);
	cout << "Результат встроенной функции преобразования\n "<< tmpdrob3 << endl;
		
	mpq_clear(tmpdrob);
	mpf_clear(tmpfloat);
	//delete[] chrs1;
	return 0;
	}
