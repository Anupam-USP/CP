#include <bits/stdc++.h>
using namespace std;
#define ll long long

string prime(long long n)
{
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return "NO";
    }
    return "YES";
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
        cout << "NO" << endl;
    else
    {
        long double sqt = sqrt(n);
        if ((sqt - floor(sqt)) == 0)
            cout << prime(floor(sqt)) << endl;

        else
            cout << "NO" << endl;
    }
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
        solve();
    return 0;
}