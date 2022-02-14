#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
using namespace std;
void RandomMatrix(int n, int A[20][20]);
void PrintMatrix(int n, int A[20][20]);

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int n, A[20][20];
	n = rand() % 5 + 2;
	RandomMatrix(n, A);
	PrintMatrix(n, A);
	system("pause");

}


void RandomMatrix(int n, int A[20][20])
{
	srand(time(NULL));
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = rand() % 20;
	

}
void PrintMatrix(int n, int A[20][20])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << A[i][j];
		cout << endl;
	}
}

