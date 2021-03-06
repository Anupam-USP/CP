#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int tmp[100];
    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i <= mid)
        tmp[k++] = a[i++];

    while (j <= e)
        tmp[k++] = a[j++];

    for (int i = s; i <= e; i++)
        a[i] = tmp[i];
}

void mergeSort(int *a, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, e);
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

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}