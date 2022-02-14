#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[11000];

void quickSort(int l, int r)
{
	int x = a[(l+r)/2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
		quickSort(i, r);

	if (l < j)
		quickSort(l, j);
}
void main()
{
	setlocale(LC_ALL, "Russian");	
	int n;
	cout << "Input the number of sort items: ";
	cin >> n;
	cout << endl;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
}