#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    // euclidean
    return b == 0 ? a : gcd(b, a % b);
}

ll x, y, GCD;

void gcdext(ll a, ll b)
{
    // extended euclidean
    if (b == 0)
    {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    gcdext(b, a % b);
    ll cX = y;
    ll cY = x - (a / b) * y;

    x = cX;
    y = cY;
}

ll invModulo(ll a, ll m)
{
    if (gcd(a, m) == 1)
        gcdext(a, m);
    // To make it positive
    return (x + m) % m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, prod = 1, ans = 0;
    cin >> n;
    ll a[n], r[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prod = prod * a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> r[i];

    for (int i = 0; i < n; i++)
    {
        ll pp = prod / a[i];
        ll inv = invModulo(pp, a[i]);
        ans += ((r[i] % prod) * (pp % prod) * (inv % prod)) % prod;
    }

    cout << ans % prod << endl;
    return 0;
}