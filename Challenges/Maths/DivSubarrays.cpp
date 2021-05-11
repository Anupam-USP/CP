#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
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
        ll i, n;
        cin >> n;
        ll a[n], sum[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = (sum[i] + a[i]) % n;
        }

        ll cnt[n + 1]={0};
        ll res = 0;

        for (int i = 0; i <= n; i++){
            cnt[sum[i]]++;
        }
        for (int i = 0; i <= n; i++)
        {
            if (cnt[i] >= 2)
            {
                res += nCr(cnt[i], 2);
            }
        }
        cout << res << endl;
    }

    return 0;
}