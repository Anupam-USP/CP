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
    ll no, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> no;
        ans = ans ^ no;
    }
    cout << ans;
    return 0;
}