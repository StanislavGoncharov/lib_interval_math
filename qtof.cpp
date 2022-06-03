#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <gmpxx.h>
#include <omp.h>
using namespace std;

void mpq_to_mpf(mpf_t tmpfloat, mpq_t tmpdrob, int precision){
	//разбираем дробь на числитель и знаменатель
	string s, sR, s2;
	mpz_t num;
	mpz_t den;
	mpz_init(num);
	mpz_init(den);
	mpq_get_num(num, tmpdrob);
	mpq_get_den(den, tmpdrob);
	cout << "Разбираем дробь..." << endl;
	cout << "Числитель дроби" << endl;
	mpz_out_str(stdout, 10, num);
	cout << endl;
	cout << "Знаменатель дроби" << endl;
	mpz_out_str(stdout, 10, den);
	cout << endl;
	mpz_t q; mpz_t r; mpz_t tmpq; mpz_t tmpr; mpz_t num1;
	mpz_init(q); mpz_init(r); mpz_init(tmpq); mpz_init(tmpr); mpz_init(num1);
	
	if (mpz_cmp_ui(num, 0) < 0){
		mpz_mul_si(num1, num, -1);
		s = s + "-";
		}
	else{
		mpz_set(num1, num);
		}
	mpz_fdiv_q(q, num1, den); //целая часть 
	mpz_fdiv_r(r, num1, den); //остаток
	const char *charQ;
	const char *charR;
	charQ = mpz_get_str(NULL, 10, q);
	charR= mpz_get_str(NULL, 10, r);
	s = s + string(charQ) + ".";
	sR = string(charR) + "0";
	mpz_t num2; // временнный числитель
	mpz_init(num2);
	charR = sR.c_str();
	mpz_set_str(num2, charR, 10);
	//#pragma omp parallel for num_threads(4)
		for (int i = 0; i <= precision; i++){
			mpz_fdiv_q(q, num2, den); // целая часть
			mpz_fdiv_r(r, num2, den); //остаток
			charQ = mpz_get_str(NULL, 10, q);
			charR= mpz_get_str(NULL, 10, r);
			s = s + string(charQ);
			sR = string(charR) + "0";
			charR = sR.c_str();
			mpz_set_str(num2, charR, 10);
			}
	const char *charS;
	charS = s.c_str();
	mpf_set_str(tmpfloat, charS, 10);
	}

int main(){
	//для теста сохраним числитель и знаменатель в char
	const char *cnum= "-54767";
	const char *cden= "66192";
	//переведём char в mpz
	mpz_t tmpnum;
	mpz_t tmpden;
	mpz_init(tmpnum);
	mpz_init(tmpden);
	mpz_set_str(tmpnum, cnum, 10);
	mpz_set_str(tmpden, cden, 10);
	//соберём дробь
	mpq_t tmpdrob;
	mpq_init(tmpdrob);
	mpq_set_num(tmpdrob, tmpnum);
	mpq_set_den(tmpdrob, tmpden);
	cout << "Переводим дробь\n " << tmpdrob << endl;  //дробь
	
	mpf_t tmpfloat;
	mpf_init(tmpfloat);
	mpf_set_default_prec(512);
	mpq_to_mpf(tmpfloat, tmpdrob, 25);
	cout << "Итоговое вещественное число" << endl;
	mpf_out_str(stdout, 10,0,tmpfloat);
	cout<<endl;
	
	return 0;
	}
