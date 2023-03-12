#include<iostream>
#include<Windows.h>
using namespace std;
int* arr;
void add(int n)
{
    if (n == 1)
        return;
    else
    {
        for (int i = 0; i < n / 2; i++)
            arr[i] += arr[n - i - 1];
        n /= 2;
        add(n);
    }
}
int main()
{
    LARGE_INTEGER freq, head, tail;
    QueryPerformanceFrequency(&freq);
    int n,sum=0,num;
    cin >> n;
    num = pow(2, n);
    arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = i;
    }
    QueryPerformanceCounter(&head);
    for(int i=0;i<10;i++)
    add(num);
    QueryPerformanceCounter(&tail);
    cout << (tail.QuadPart - head.QuadPart) * 1.0 / freq.QuadPart << endl;
    return 0;
}