#include <bits/stdc++.h>
using namespace std;
#define ll long long

void create_primes(ll n, ll m)
{
    ll primes[100000000ll] = {0};
    primes[2] = 1;
    for (int i = 3; i <= m; i += 2)
    {
        primes[i] = 1;
    }

    for (ll i = 3; i <= m; i += 2)
    {
        if (primes[i] == 1)
        {
            for (ll j = i * i; j <= m; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    for (ll i = n; i <= m; i++)
    {
        if (primes[i] == 1)
            cout << i << endl;
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    create_primes(n, m);
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}