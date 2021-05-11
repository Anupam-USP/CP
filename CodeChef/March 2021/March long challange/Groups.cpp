#include <bits/stdc++.h>
using namespace std;

ll main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll cnt = 0;
        if (s[0] == '1')
        {
            cnt++;
        }
        for (ll i = 1; i < s.length(); i++)
        {
            if (s[i] == '1' and s[i] != s[i - 1])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}