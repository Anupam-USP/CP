#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    // euclidean
    return b == 0 ? a : gcd(b, a % b);
}

ll modInv(ll a, ll m)
{
    if (m == 1)
        return 0;
    int m0 = m, y = 0, x = 1;

    while (a > 1)
    {
        int q = a / m, t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

void solve()
{
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    
    ll x, y, z;
    ll g = gcd(w, d);

    if (p % g != 0)
    {
        cout << -1 << endl;
        return;
    }

    if (n * w < p)
    {
        cout << -1 << endl;
        return;
    }
    p /= g;
    w /= g;
    d /= g;
    // y=p"/q"
    y = ((p % w) * modInv(d, w)) % w;
    x = (p - y * d) / w;
    if (x + y > n)
    {
        cout << -1 << endl;
        return;
    }
    if (x < 0)
    {
        cout << -1 << endl;
        return;
    }
    z = n - (x + y);
    cout << x << " " << y << " " << z << endl;
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}