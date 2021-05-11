#include <bits/stdc++.h>
using namespace std;
ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, i;
    cin >> n;
    cin.get();

    string s[100];
    for (i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    sort(s, s + n);

    for (i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}