#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    PBDS st;
    ll inv_cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        inv_cnt += (st.size() - st.order_of_key(a[i]));
        st.insert(a[i]);
    }
    cout << inv_cnt;
    return 0;
}