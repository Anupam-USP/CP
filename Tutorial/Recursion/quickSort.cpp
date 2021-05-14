#include <bits/stdc++.h>
using namespace std;
#define ll long long

int partition(int *a, int s, int e)
{
    int j = s;
    int i = s - 1;
    int pivot = a[e];
    for (; j <= e - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i = i + 1;
            swap(a[i], a[j]);
        }
        j = j + 1;
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quick_sort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(a, s, e);
    quick_sort(a, s, p - 1);
    quick_sort(a, p + 1, e);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}