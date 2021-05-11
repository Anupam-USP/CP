#include <iostream>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll cnt[64] = {0};
    ll n, no;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> no;
        ll j = 0;
        while (no > 0)
        {
            ll lastbit = (no & 1);
            cnt[j] += lastbit;
            j++;
            no = no >> 1;
        }
    }
    ll p = 1, ans = 0;
    for (ll i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
        ans += (cnt[i] * p);
        p = p * 2;
    }
    cout << ans << endl;
    return 0;
}