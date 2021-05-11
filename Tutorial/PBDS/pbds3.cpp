#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;
 
ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll a[n], b[n], c[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
 
    for (ll i = 0; i < n; i++)
        cin >> b[i];
 
    for (ll i = 0; i < n; i++)
        c[i] = a[i] - b[i];
 
    PBDS st;
    long long ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += st.size() - st.order_of_key({-c[i], 10000000});
        st.insert({c[i], i});
    }
    cout << ans;
}