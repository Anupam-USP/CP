#include <bits/stdc++.h>
using namespace std;

ll main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll n, h, x;
    ll flag = 0;
    cin >> n >> h >> x;
    while (n--)
    {
        ll t;
        cin >> t;
        if (t + x == h)
        {
            cout << "YES" << endl;
            flag++;
            break;
        }
    }
    if (flag == 0)
        cout << "NO" << endl;
    return 0;
}