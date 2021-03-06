#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007; // To avoid overflow
map<ll, ll> F

    ll
    f(ll n)
{
    if (F.count(n) == 0)
        return f[n];
    ll k = n / 2;
    if (n % 2 == 0)
    {
        // n=2*k
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    }
    else
    {
        //n=2*k+1
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    F[0] = F[1] = 1;
    while (cin >> n)
        cout << (n == 0 ? 0 : f(n - 1));

    return 0;
}