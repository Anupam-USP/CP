#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    map<ll, ll> mp;
    cin >> t;
    ll a[t], i = 0;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        mp.insert(pair<ll, ll>(x, y));
        a[i] = x;
        i++;
    }

    ll minc = 0, flag = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (minc < abs(itr->first - itr->second))
        {
            minc = abs(itr->first - itr->second);
            flag++;
        }
    }
    cout << minc << endl;
    if (mp[a[flag]] > a[flag])
        cout << 2 << endl;
    else
        cout << 1 << endl;

    return 0;
}