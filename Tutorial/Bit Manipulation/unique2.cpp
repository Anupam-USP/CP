#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, res = 0, no, a[100005];
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> no;
        a[i] = no;
        res = (res ^ no);
    }
    ll temp = res;
    ll pos = 0;
    while ((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    ll mask = (1 << pos);
    ll x = 0, y = 0;
    for (ll i = 0; i < n; i++)
    {
        if ((a[i] & mask) > 0)
        {
            x = x ^ a[i];
        }
    }

    y = (res ^ x);
    cout << min(x, y) << ' ' << max(x, y);
    return 0;
}