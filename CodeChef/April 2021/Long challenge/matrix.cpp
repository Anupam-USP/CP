#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
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
    ll i, j;
    ll n, m, k;
    cin >> n >> m >> k;

    ll cnt = 0;
    ll a[n][m];
    fo(i, n)
    {
        fo(j, m)
        {
            cin >> a[i][j];
            if (a[i][j] >= k)
                cnt++;
        }
    }

    ll tmp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                tmp[i][j] = 1;
                tmp[i][j + 1] = 1;
            }
            else if (tmp[i][j] != 1)
            {
                tmp[i][j] = 0;
            }
            if(i==(n-1))
                tmp[i][j] = 0;
        }
    }

    ll res[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i][j] = 0;
            for (int q = 0; q < m; q++)
                res[i][j] += tmp[i][q] * a[q][j];
        }
    }

    vl sum,avg;
    fo(i, n)
    {
        fo(j, m)
        {
            if(res[i][j]!=0){
                sum.push_back(res[i][j]);
            }
        }
    }

    fo(i,sum.size()-1){
        ll temp = 0;
        for (int j = 0; j < min(m - 1);j++){
            temp += sum[i + j];
        }
        temp/= (m-1)
    }
    cout << cnt << endl;
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
