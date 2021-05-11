#include <bits/stdc++.h>
using namespace std;
ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long ll n;
    cin >> n;
    cin.get();
    ll a[n], b[n], c[n + n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll i = 0, j = 0, k = 0;
    while (i <= n && j <= n)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    cout << c[n - 1];

    return 0;
}