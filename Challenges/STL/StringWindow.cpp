#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map<char, ll> ms1, ms2;
    ll n = s1.size(), m = s2.size();
    ll result_l = -1, result_r = 1e5;

    for (auto x : s2)
        ms2[x]++;

    ll l = 0, r = 0;
    for (ll r = 0; r < n; r++)
    {
        ms1[s1[r]]++;

        bool good = true;
        for (auto x : ms2)
        {
            if ((ms1.count(x.first) == 0) || (ms1[x.first] < x.second))
            {
                good = false;
                break;
            }
        }
        if (!good)
            continue;
        while (l < n && l <= r && (ms2.count(s1[l]) == 0 || ms1[s1[l]] > ms2[s1[l]]))
        {
            ms1[s1[l]]--;
            if (ms1[s1[l]] == 0)
                ms1.erase(s1[l]);
            l++;
        }

        if (result_r - result_l + 1 > r - l + 1)
        {
            result_l = l;
            result_r = r;
        }
    }
    if (result_l == -1)
        cout << "No String";
    else
        cout << s1.substr(result_l, result_r - result_l + 1);
    return 0;
}