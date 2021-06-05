#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
#define all(x) (x).begin(), (x).end()

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
    ll D, d, p, q;
    cin >> D >> d >> p >> q;
    ll ans = 0, i = 0, cnt = 0;
    // while (i < D)
    // {
    //     ans += (cnt * q);
    //     i++;
    //     if (i % d == 0)
    //         cnt++;
    // }
    ll pa = D / d, r = D % d;
    for (int i = 0; i < pa; i++)
    {
        ans += (i * d * q);
    }
    ans += (D * p);
    ans += (pa * r * q);
    cout << ans << endl;
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
    while (t--)
    {
        solve();
    }
    return 0;
}
