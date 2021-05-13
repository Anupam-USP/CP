#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bubbleSort(int a[], int n)
{
    // base case
    if (n == 1)
        return;
    // rec case
    for (int j = 0; j < n - 1; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
    }
    bubbleSort(a, n - 1);
}

void bubbleSort_Rec(int a[], int j, int n)
{
    // Further recursive
    // base case
    if (n == 1)
        return;
    if (j == (n - 1))
        return bubbleSort_Rec(a, 0, n - 1);

    // rec case
    if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);

    bubbleSort_Rec(a, j + 1, n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a[] = {5, 4, 2, 1, 3};
    int n = 5;
    bubbleSort_Rec(a, 0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}