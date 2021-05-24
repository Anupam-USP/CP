#include <bits/stdc++.h>
using namespace std;
#define ll long long

int search(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[s] <= a[mid])
        {
            if (key >= a[s] and key <= a[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if (key <= a[e] and key >= a[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key;
    cin >> key;
    cout << search(a, n, key) << endl;
    return 0;
}