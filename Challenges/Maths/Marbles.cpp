#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n)
{
    if (n == 1 || n == 0)
        return 1;

    else
    {
        ll ans = n * fact(n - 1);
        return ans;
    }
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll k, n;
        cin >> n >> k;
        if (n - k < k - 1)
        {
            k = n - k + 1;
        }

        if (k == 1)
        {
            cout << 1 << endl;
            continue;
        }

        ll ans = 1;
        for (ll i = n - 1; i >= n - k + 1; i--)
        {
            ans = ans * i;
            ans = ans / (n - i);
        }
        cout << ans << endl;
        // cout << fact(k) << endl;
    }
    return 0;
}