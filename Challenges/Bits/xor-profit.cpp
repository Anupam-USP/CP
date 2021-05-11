#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll x, y, leastBit;
    cin >> x >> y;
    for (ll a = x; a <= y; a++)
    {
        for (ll b = x; b <= y; b++)
        {
            leastBit = max(leastBit, (a ^ b));
        }
    }
    cout << leastBit;
    return 0;
}