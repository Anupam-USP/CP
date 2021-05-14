#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    // euclidean
    return b == 0 ? a : gcd(b, a % b);
}

ll x, y, GCD;

void gcdext(int a, int b)
{
    // extended euclidean
    if (b == 0)
    {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    gcdext(b, a % b);
    int cX = y;
    int cY = x - (a / b) * y;

    x = cX;
    y = cY;
}

int invModulo(int a, int m)
{
    if (gcd(a, m) == 1)
        gcdext(a, m);
    // To make it positive
    return (x + m) % m;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int nums[3] = {3, 4, 5};
    int rem[3] = {2, 3, 1};
    ll ans = 0;
    ll prod = 1;
    for (int i = 0; i < 3;i++)
        prod *= nums[i];
    cout << prod << endl;
    for (int i = 0; i < 3; i++)
    {
        ll pp = prod/nums[i];
        ll inv = invModulo(pp, nums[i]);
        ans += (rem[i] * pp * inv) % prod;
    }
    cout << ans;
    return 0;
}