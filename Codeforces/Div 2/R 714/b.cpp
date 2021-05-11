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
    int i, j, n, m;
    cin >> n;
    vi a(n);
    fo(i, n) cin >> a[i];
    int min1 = *min_element(a.begin(), a.end());
    int cnt = 0;
    for (auto it : a)
    {
        if (min1 == it)
            cnt++;
        if ((min1&it)!=min1){
            cout << 0 << endl;
            return;
        }
    }

    ll fact = 1;
    fok(i,1, n - 1) fact = (fact * i) % MOD;
    ll ans = (cnt * (cnt - 1)) % MOD;
    ans = (ans * fact) % MOD;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
