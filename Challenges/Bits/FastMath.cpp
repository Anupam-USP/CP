#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1, s2, s3;
    ll n;
    cin >> n;
    while (n > 0)
    {
        cin >> s1 >> s2;
        s3 = s1;
        ll x = s1.length();
        for (ll i = 0; i < x; i++)
        {
            if (s1[i] == s2[i])
                s3[i] = '0';
            else
                s3[i] = '1';
        }
        cout << s3 << endl;
        n--;
    }
    return 0;
}