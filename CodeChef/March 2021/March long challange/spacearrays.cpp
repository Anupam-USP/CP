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
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll flag = 0, val = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i + 1 - a[i] < 0)
            {
                flag++;
            }
            val += (i + 1 - a[i]);
        }

        if (flag)
            cout << "Second" << endl;
        else
        {
            if (val % 2 == 0)
                cout << "Second" << endl;
            else
                cout << "First" << endl;
        }
    }

    return 0;
}