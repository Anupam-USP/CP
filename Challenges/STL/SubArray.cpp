#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    unordered_set<ll> s;
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll j = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        while (j < n && s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
        sum += (j - i) * (j - i + 1) / 2;
        s.erase(arr[j]);
    }

    cout << sum;

    return 0;
}