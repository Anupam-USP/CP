#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fo(i, n) for (auto i = 0; i < n; i++)
#define fok(i, k, n) for (auto i = k; i < n; i++)
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
#define all(x) (x).begin(),(x).end()

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

bool canPlaced(vl stalls, ll n, ll c, ll position){
    ll lastPlaced = stalls[0];
    ll cnt = 1;
    fok(i, 1, n)
    {
        if(stalls[i]-lastPlaced>=position){
            lastPlaced = stalls[i];
            cnt++;
            if(cnt==c)
                return true;
        }
    }
    return false;
}

void solve()
{
    ll i, j, n, m;
    cin >> n >> m;
    vl stalls(n);
    fo(i, n) cin >> stalls[i];
    sort(all(stalls));
    ll s = 0, ans = 0;
    ll e = stalls[n - 1] - stalls[0];
    while(s<=e){
        ll mid = s + (e - s) / 2;
        bool ifPlaced = canPlaced(stalls, n, m, mid);
        if(ifPlaced){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
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
