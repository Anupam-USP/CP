#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, n, k = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << __builtin_popcount(n) << endl;
    }
    return 0;
}