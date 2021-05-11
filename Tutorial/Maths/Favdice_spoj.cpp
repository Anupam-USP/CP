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
        ll n;
        cin >> n;
        double ans = 0.0;
        for (ll i = 1; i <= n; i++)
        {
            ans += n / (i * 1.0);
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}