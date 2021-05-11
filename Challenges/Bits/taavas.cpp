#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a;
    cin >> a;
    ll len = a.length();
    long long ll ans = 0;
    ans += ((1 << len) - 2);

    for (ll i = len - 1, pos = 0; i >= 0; i--, pos++)
    {
        if (a[i] == '7')
        {
            ans += (1 << pos);
        }
    }
    cout << ans + 1;
    return 0;
}