// In hacker blocks using PigeonHole principle
#include <bits/stdc++.h>
using namespace std;
#define ll long
ll a[1000005], freq[1000005];

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
        memset(freq, 0, sizeof(freq));
        freq[0] = 1;
        ll sum = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;
            freq[sum]++;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll m = freq[i];
            ans += (m) * (m - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}