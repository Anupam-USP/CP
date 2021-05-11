#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string b)
{
    if (a.size() <= b.size() && b.substr(0, a.size()) == a)
        return false;
    else if (b.size() <= a.size() && a.substr(0, b.size()) == b)
        return true;
    else
        return a < b;
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, i;
    cin >> n;
    cin.get();
    string s[n];
    for (i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    sort(s, s + n, compare);

    for (i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
}