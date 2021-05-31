#include <bits/stdc++.h>
using namespace std;
#define ll long long

int partition(int *a, int s, int e)
{
    int j = s;
    int i = s;
    int pivot = a[e];
    while(j<e)
    {
        if (a[j] <= pivot)
        {
            swap(a[i], a[j]);
            i = i + 1;
            j = j + 1;
        }
        j++;
    }
    swap(a[i], a[e]);
    return i;
}

void quickSort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int pivot = partition(a, s, e);
    quickSort(a, s, pivot - 1);
    quickSort(a, pivot + 1, e);
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

    quickSort(a, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}