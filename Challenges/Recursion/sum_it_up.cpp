#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int> &v, vector<int> &tmp, set<vector<int> > &s, int n, int target)
{
    if (n == 0)
        return;

    if (target == 0)
    {
        s.insert(tmp);
        return;
    }

    if (target >= v[n - 1])
    {
        tmp.push_back(v[n - 1]);
        solve(v, tmp, s, n - 1, (target - v[n - 1]));
        tmp.pop_back();
        solve(v, tmp, s, n - 1, target);
    }
    else
    {
        solve(v, tmp, s, n - 1, target);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, e, tar;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end(), greater<int>());
    cin >> tar;
    vector<int> tmp;
    set<vector<int> > s;
    solve(v, tmp, s, n, tar);

    for (auto it : s)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}