#include <bits/stdc++.h>
using namespace std;
ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll arr[] = {10, 20, 30, 30, 40, 50};
    ll n = sizeof(arr) / sizeof(ll);
    set<ll> s;

    for (ll i = 0; i < n; i++)
        s.insert(arr[i]);

    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << endl;

    s.erase(30);

    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " -> ";

    return 0;
}