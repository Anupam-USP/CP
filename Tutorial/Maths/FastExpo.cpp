#include <bits/stdc++.h>
using namespace std;

ll pow(ll a, ll n)
{
    if (n == 0)
        return 1;
    else
    {
        ll subprob = pow(a, n / 2);
        if (n & 1)
        {
            return a * subprob * subprob;
        }
        else
        {
            return subprob * subprob;
        }
    }
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a, n;
    cin >> a >> n;
    cout << pow(a, n) << endl;
    return 0;
}