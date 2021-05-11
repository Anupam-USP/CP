#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
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

const int N = 3e5, M = N;
const int max_n = 200005;
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

ll dp[max_n];

void solve()
{
    ll k = 0, i, n, s;
    cin >> s >> n;
    while(s>0){
        ll x = s % 10;
        k += ((n + x < 10) ? 1 : dp[n + x - 10]);
        k %= MOD;
        s=s/10;
    }

    cout << k % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    ll i;
    fo(i, 9) dp[i] = 2;
    dp[9] = 3;
    fok(i,10,max_n){
        dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}
