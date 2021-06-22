#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

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
        int m, n, p;
        cin >> p;
        vector<pair<int, int>> v;
        for (int i = 0; i < p; i++)
        {
            cin >> m >> n;
            v.push_back(make_pair(m, n));
        }
        sort(v.begin(), v.end(), compare);
        ll cnt = 1;
        ll curr = v[0].second;
        for (int i = 1; i < p; i++)
        {
            if (v[i].first >= curr)
            {
                curr = v[i].second;
                cnt++;
            }
        }
        cout << cnt << endl;
        v.clear();
    }
    return 0;
}