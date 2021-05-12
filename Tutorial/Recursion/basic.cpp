#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fibo(ll n)
{
    // nth Fibonacci
    if (n == 0 or n == 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

void dec(ll n)
{
    if (n)
    {
        // dec(n - 1); // To be used for increasing order
        cout << n << " ";
        dec(n - 1); //For decreasing order
    }
    return;
}

bool isSorted(int a[], int n)
{
    if (n == 0 or n == 1)
        return true;

    if (a[0] < a[1] and isSorted(a + 1, n - 1))
        return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    // cout << fibo(n) << endl;
    // dec(n);
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << isSorted(a, n);

    return 0;
}