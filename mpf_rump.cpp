#include <iostream> 
#include <gmpxx.h>
using namespace std;

int main(){
	mpf_t a, b, c, result, a11,a2, b2, b6, b4, res1, res2,res3, res4,koef1,koef2, b8, res5, res6, res7, res8, res9, res10, res11;
	mpf_inits(a,b,c, result, a11, a2, b2, b6, b4, res1, res2,res3, res4, koef1, koef2, b8, res5, res6, res7, res8, res9, res10, res11);
	mpf_set_d(a, 77617);
	mpf_set_d(b, 33096);
	mpf_set_d(koef1, 333.75);
	mpf_set_d(koef2, 5.5);
	
	mpf_pow_ui(a2, a, 2); //a^2
	mpf_pow_ui(b2, b, 2); //b^2
	mpf_pow_ui(b6, b, 6); //b^6
	mpf_pow_ui(b4, b, 4); //b^4
	mpf_pow_ui(b8, b, 8); //b^8
	mpf_mul_ui(a11, a2, 11);
	mpf_mul(res1, a11 , b2); //11*a^2*b^2
	mpf_sub(res2, res1, b6); //11*a^2*b^2 - b^6
	mpf_mul_ui(res3, b4, 121); //121*b^4
	mpf_sub(res4, res2, res3); //
	mpf_sub_ui(c, res4, 2);
	//mpf_out_str(stdout, 10, 57, c); //вывод строки
	cout << " Результат "<< endl;
	mpf_mul(res5, koef1, b6); //333.75 * b^6
	mpf_mul(res6, a2, c); // c * a^2
	mpf_mul(res7, koef2, b8); // 5.5*b^8
	mpf_mul_ui(res8, b, 2); // 2 * b
	mpf_div(res9, a, res8);
	mpf_add(res10, res5, res6);
	mpf_add(res11, res10, res7);
	mpf_add(result, res11, res9); 
	
	mpf_out_str(stdout, 10, 60, result); //вывод строки
	
	//mpf_clears(c, result, a11, a2, b2, b6, b4, res1, res2,res3, res4);
	cout << endl;
	cout << " КОНЕЦ" << endl;
	return 0;
}
