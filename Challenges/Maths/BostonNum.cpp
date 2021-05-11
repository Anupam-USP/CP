#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sumOfDigit(ll c)
{
    ll ans = 0;
    while (c)
    {
        ll rem = c % 10;
        ans += rem;
        c /= 10;
    }
    return ans;
}

ll primeSum(ll c)
{
    ll ans = 0;
    vector<ll> a;

    while (c % 2 == 0)
    {
        a.push_back(2);
        c = c / 2;
    }

    for (ll i = 3; i <= sqrt(c); i = i + 2)
    {
        while (c % i == 0)
        {
            ll temp1 = i;
            while (temp1 > 0)
            {
                a.push_back(temp1 % 10);
                temp1 /= 10;
            }

            c = c / i;
        }
    }

    if (c > 2)
    {
        while (c > 0)
        {
            a.push_back(c % 10);
            c /= 10;
        }
    }

    for (ll i = 0; i < a.size(); i++)
    {
        ans += a[i];
    }
    return ans;
}

ll isBoston(ll c)
{
    ll dig_sum = sumOfDigit(c);
    ll prim_sum = primeSum(c);
    if (dig_sum == prim_sum)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll c;
    cin >> c;
    isBoston(c);
    return 0;
}