//Построить таблицу приближенных значений функции sinx+x*chx на отрезке [-1,0] с шагом 0.1  
//и точностью eps = 0.0001. Результат вывести в виде таблицы
#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double eps)
{
	double Sin = 0, Ch = 1, n, i = 1;
	n = x;
	while (fabs(n) >= eps)
	{
		Sin += n;
		n *= (x * x * (-1)) / ((2 * i) * (2 * i + 1));
		++i;
	}
	n = 1;
	i = 1;
	while (fabs(n) >= eps)
	{
		n *= (x * x) / ((2 * i - 1) * (2 * i));
		Ch += n;
		++i;
	}
	return Sin + x * Ch;
}

int main()
{
	double a = -1, b = 0, h = 0.1, eps = 0.0001, S;
	for (double i = b; i >= a; i -= h)
	{
		S = f(i, eps);
		cout.width(6);
		cout << i << '|';
		cout.width(10);
		cout << S << '|';
		cout.width(10);
		cout << sin(i) + i * cosh(i) << '\n';
	}
}