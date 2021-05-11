#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        map<ll, ll, greater <ll>> imd;
        int n, x;
        cin >> n >> x;

        while (n--)
        {
            ll s, r;
            cin >> s >> r;
            imd.insert(pair<ll, ll>(r, s));
        }

        for (auto it : imd)
        {
            if (it.second <= x)
            {
                cout << it.first << endl;
                break;
            }
        }
    }
}