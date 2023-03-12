#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
    int* arr;
    LARGE_INTEGER freq, head, tail;
    QueryPerformanceFrequency(&freq);
    int n, sum = 0, num;
    cin >> n;
    num = pow(2, n);
    arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = i;
    }
     int sum1 = 0, sum2 = 0;
     QueryPerformanceCounter(&head);
     for (int x = 0; x < 10; x++)
     {
         for (int i = 0; i < num; i += 2)
         {
             sum1 += arr[i];
             sum2 += arr[i + 1];
         }
         sum = sum1 + sum2;
     }
     QueryPerformanceCounter(&tail);
     cout << (tail.QuadPart - head.QuadPart) * 1.0 / freq.QuadPart << endl ;
    return 0;
}