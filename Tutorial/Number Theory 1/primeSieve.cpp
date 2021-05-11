#include <bits/stdc++.h>
using namespace std;
#define ll long long

void primeSieve(ll n, ll k)
{
    ll p[k + 1] = {0};
    p[2] = 1;
    for (int i = 3; i < k + 1; i += 2)
    {
        p[i] = 1;
    }

    for (ll i = 3; i < k + 1; i += 2)
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= k; j += i)
            {
                p[j] = 0;
            }
        }
    }
    ll cnt = 0;
    for (int i = n; i <= k; i++)
    {
        if (p[i] == 1)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        primeSieve(n, k);
    }
    return 0;
}