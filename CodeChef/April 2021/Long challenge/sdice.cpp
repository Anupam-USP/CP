#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define fo(i, n) for (i = 0; i < n; i++)
#define fok(i, k, n) for (i = k; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;

const int N = 3e5, M = N;

int mpow(int base, int exp)
{
    base %= MOD;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % MOD;
        base = ((ll)base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

void solve()
{
    ll i, j, n, m;
    cin >> n;
    if(n==1)
        cout << 20 << endl;
    else if(n==2)
        cout << 36 << endl;
    else if(n==3)
        cout << 51 << endl;
    else if(n==4)
        cout << 60 << endl;
    else{
        ll rem = n % 4;
        ll ans = ((n - rem) / 4) * 44;
        if(rem==0)
            ans += 16;
        else if(rem==1)
            ans += 32;
        else if(rem==2)
            ans += 44;
        else if(rem==3)
            ans += 55;

        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
