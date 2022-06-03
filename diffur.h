using namespace std;
using namespace boost::numeric;
//using namespace mpfr;


typedef interval<double> Interval;

//typedef interval<mpreal> Interval;
//typedef boost::numeric::interval<double> Doublerval;								

ostream& operator<<(ostream& os, const Interval& r);
			
Interval Isin(Interval a);

Interval Icos(Interval a);

Interval Itan(Interval a);

Interval Iexp(Interval a);

void Eiler(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval x0);

void Eiler_m(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0);

void Runge_Kut(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0, Interval* X,Interval* Y);

void Runge_Kut_DB(double (*Fn)(double, double), double a,double b, int n, double y0, double* X,double* Y);

void Kut_Merson(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0, Interval eps);
void Adams(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0);

void Miln_m(Interval (*Fn)(Interval, Interval), Interval a,Interval b, int n, Interval y0);



