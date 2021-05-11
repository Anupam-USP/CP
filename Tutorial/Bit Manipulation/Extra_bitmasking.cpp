// Fast exponential, Generating subsets
#include <bits/stdc++.h>
using namespace std;

ll fast_expo(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        ll last = (b & 1);
        if (last)
        {
            ans = ans * a;
        }
        b = b >> 1;
        a = a * a;
    }
    return ans;
}

ll SubsetGen(ll n, char a[])
{
    ll j = 0;
    while (n)
    {
        ll last = (n & 1);
        if (last)
        {
            cout << a[j];
        }

        j++;
        n = n >> 1;
    }
    cout << endl;
}

void PrllSubs(char a[])
{
    ll n = 0;
    while (a[n] != '\0')
        n++;
    for (ll i = 0; i < (1 << n); i++)
    {
        SubsetGen(i, a);
    }
    return;
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char a[100];
    cin >> a;
    PrllSubs(a);

    return 0;
}