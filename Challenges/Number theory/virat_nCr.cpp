#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
const ll MAX = 1000000;
ll factorial[MAX + 1];

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, r;
    cin >> n >> r;
    factorial[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    ll tmp1 = modExp(factorial[r], MOD - 2, MOD);
    ll tmp2 = modExp(factorial[n - r], MOD - 2, MOD);

    ll ans = ((tmp1 % MOD) * (tmp2 % MOD)) % MOD;
    ll res = ((factorial[n] % MOD) * (ans % MOD)) % MOD;

    cout << res % MOD << endl;
    return 0;
}