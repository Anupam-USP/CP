#include <iostream>
#define ll long long

using namespace std;

ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
        
    a %= m;
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a);
            res %= m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

int main()
{

    ll t, a, n, p;
    cin >> t;
    while (t--)
    {
        cin >> a >> n >> p;
        ll ans = a % p;
        for (int i = 2; i <= n; i++)
        {
            ans = power(ans, i, p) % p;
            ans %= p;
        }
        cout << ans << endl;
    }
    return 0;
}