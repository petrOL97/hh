#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
	return sin(x) / x; // Integrate function
}

double RectangleMethod(double a, double b, double n) // Simple rectangle method (a, b) - integration cut, n - number of bins
{
	double I;
	double h;
	int i;

	h = (b - a) / n;
	I = 0;
	for (i = 0;i < n;i++)
		I += h*f(a + h*(i + 0.5));
	return I;
}
double Adopt(double a, double b, double eps)// Adoptive method, eps - error accuracy
{
double I, I1, I2;
I1 = RectangleMethod(a, b, 2);
I2 = RectangleMethod(a, b, 4);
if (fabs(I1 - I2) < eps / 2)
	I = I2;
else
{
	I = Adopt(a, (a + b) / 2, eps) + Adopt((a + b) / 2, b, eps);
}
return I;
}

void main()
{
	setlocale(LC_ALL, "");
	double a, b, eps;
	cout << "Input integration limits: ";
	cin >> a >> b;
	cout << "Input eps: ";
	cin >> eps;
	cout << Adopt(a, b, eps) << endl;
	system("pause");
}