#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<ll> a;
    ll n;
    cin >> n;
    cin.get();
    for (ll i = 0; i < 2 * n; i++)
    {
        ll z;
        cin >> z;
        a.push_back(z);
    }
    sort(a.begin(), a.end());
    cout << a[n - 1];
    return 0;
}