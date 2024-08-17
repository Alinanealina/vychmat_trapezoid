#include <iostream>
using namespace std;
const int N = 5;

double funct(double x)
{
	return (1 / x);
}

double perv(double x)
{
	return (log(x));
}

double pr2(double x)
{
	return (2 / pow(x, 3));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1, j;
	double a = 1, b = 2, x0, x1, Ih, Ih2 = 0, I = perv(b) - perv(a), h = (b - a) / N, eps = pow(10, -8), eps2, M;
	cout << " a = " << a << ", b = " << b << ", h = " << h << ", Iточн = " << I << ", e = " << eps << endl;
	do
	{
		cout << " Шаг " << i << ":";
		Ih = Ih2;
		Ih2 = 0;
		M = 0;
		if (i == 1)
		{
			for (j = 0, x0 = a, x1 = a + h; j < N; j++, x0 = x1, x1 += h)
				Ih += h * (funct(x0) + funct(x1)) / 2;
		}
		h /= 2;
		for (j = 0, x0 = a, x1 = a + h; j < pow(2, i) * N; j++, x0 = x1, x1 += h)
			Ih2 += h * (funct(x0) + funct(x1)) / 2;
		cout << " I_h = " << Ih << ", I_h/2 = " << Ih2;

		for (j = 0, x0 = a; j < pow(2, (i - 1)) * N; j++, x0 += h)
		{
			eps2 = abs(pr2(x0));
			if (M < eps2)
				M = eps2;
		}
		eps2 = pow(h, 2) * (b - a) * M / 12;
		cout << ", eps_усеч = " << eps2 << endl;
		i++;
	} while (!(abs(Ih2 - I) < eps));
	cout << " h = " << h;
	return 0;
}