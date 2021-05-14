#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modExp(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

void solve()
{
    ll n, p;
    cin >> n >> p;
    if (n >= p)
        cout << 0 << endl;
    else
    {
        ll ans = -1;
        for (ll i = (n + 1); i <= (p - 1); i++)
        {
            ll tmp = modExp(i, p - 2, p);
            ans = (ans * tmp) % p;
        }
        cout << ans + p << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}