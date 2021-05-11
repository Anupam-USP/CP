#include <bits/stdc++.h>
using namespace std;

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
        ll a, b, cnt = 0;
        cin >> a >> b;
        for (ll i = a; i <= b; i++)
        {
            cnt += __builtin_popcount(i);
        }
        cout << cnt << endl;
    }
    return 0;
}