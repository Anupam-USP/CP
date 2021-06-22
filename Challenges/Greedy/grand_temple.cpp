#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x, x + n);
    sort(y, y + n);

    ll dx = x[0] - 1;
    ll dy = y[0] - 1;
    for (int i = 1; i < n; i++)
    {
        dx = max(dx, x[i] - x[i - 1] - 1);
        dy = max(dy, y[i] - y[i - 1] - 1);
    }
    return 0;
}