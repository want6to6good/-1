#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int** a1 = new int* [n];
	int** a2 = new int* [n];
	int** r1 = new int* [n];
    int** r2 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a1[i] = new int[n];
		a2[i] = new int[n];
		r1[i] = new int[n];
		r2[i] = new int[n];
		for (int x = 0; x < n; x++)
		{
			a1[i][x] = i+x;
			a2[i][x] = i+x;
			r1[i][x] = 0;
			r2[i][x] = 0;
		}
	}
	LARGE_INTEGER freq, head, tail;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&head);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int r = a1[j][i];
			for (int m = 0; m < n; m++)
			{
				r2[j][m] += (r * a2[i][m]);
			}
		}
	}
	QueryPerformanceCounter(&tail);
	cout << (tail.QuadPart - head.QuadPart) * 1.0 / freq.QuadPart << endl;
	return 0;
}