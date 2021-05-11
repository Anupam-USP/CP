#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    unordered_map<ll, ll> m1;
    vector<ll> arr;
    ll n, k, b;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> b;
        arr.push_back(b);
        m1[arr[i]] = i;
    }
    ll num = n;
    while (k > 0 && num != 0)
    {
        ll init = m1.at(num);
        ll best = n - num;
        if (arr[best] != arr[init])
        {
            swap(arr[best], arr[init]);
            m1[arr[init]] = init;
            k--;
        }
        num--;
    }
    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

/* Brute force approach
ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, k;
    cin >> n >> k;
    ll arr[1000], i = 0, j = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (i < k)
    {
        ll max_idx = max_element(arr + j, arr + n) - arr;
        if (j != max_idx)
        {
            swap(arr[j], arr[max_idx]);
            i++;
        }
        j++;
    }

    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}*/