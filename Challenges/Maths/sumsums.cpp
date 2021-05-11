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
#define MOD 987654321
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

ll pow(ll a, ll b){
    ll res = 1;

    while(b){
        if(b & 1) res = res*a % MOD;
        a = a*a % MOD;
        b >>= 1;
    }

    return res;
}

void solve()
{
    ll n,k;
    cin >> n >> k;

    int s = 0, a[n];
    fo(i,n){
        cin >> a[i];
        a[i] %= MOD;
        s += a[i];
        if(s>MOD) s -= MOD;
    }

    ll c = (pow(N-1,k)+((k & 1)? 1 : -1))*pow(n,MOD-2) % MOD * s % MOD,tmp;
    fo(i,n){
        tmp = c+((k & 1)? -a[i] : a[i]);
        tmp %= MOD;
        if(tmp<0) tmp += MOD;

        cout<<tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    // int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
