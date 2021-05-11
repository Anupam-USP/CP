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
        ll n, k;
        cin >> n >> k;
        ll ans1 = (n + k - 1) / k;
        ll ans2 = n % k;
        if (ans2 == 0) ans2 = k;
        cout << ans1 << " " << ans2 << endl;

    }
    return 0;
}