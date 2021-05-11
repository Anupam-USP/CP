#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binomialCoeff(int n, int k)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

ll int catalan(int n)
{
    ll c = binomialCoeff(2 * n, n);
    return c / (n + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << catalan(n);
    return 0;
}