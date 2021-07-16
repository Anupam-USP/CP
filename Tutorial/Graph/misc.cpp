#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;

        vector<ll> v;
        map<ll, ll> m;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            v.push_back(a);
            m[a]++;
        }
        if (k > m.size())
        {
            cout << 0 << endl;
        }
        cout << (m.size() - k) * x << endl;
    }
    return 0;
}