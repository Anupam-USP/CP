#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<ll> a, ll idx)
{
    if (idx == a.size())
    {
        for (auto it : a)
            cout << it << " ";
        cout << "\n";
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i == idx or a[i] != a[idx])
        {
            swap(a[i], a[idx]);
            solve(a, idx + 1);
            // swap(a[i],a[idx]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &it : a)
        cin >> it;
    sort(a.begin(), a.end());
    solve(a, 0);
}