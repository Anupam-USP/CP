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

ll A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
ll size_a = sizeof(A) / sizeof(A[0]);
ll modularMult(ll a, ll b, ll n)
{
    ll r = 0;
    for (; b; b >>= 1, a <<= 1)
    {
        if (a >= n)
            a -= n;
        if (b & 1)
        {
            r += a;
            if (r >= n)
                r -= n;
        }
    }
    return r;
}

ll modExp(ll a, ll b, ll n)
{
    ll ret = 1;
    for (; b; b >>= 1, a = modularMult(a, a, n))
        if (b & 1)
            ret = modularMult(ret, a, n);
    return ret;
}

bool mrtest(ll n)
{ // miller rabin big primality test
    if (n == 1)
        return false;
    ll d = n - 1;
    ll s = 0;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }
    for (ll j = 0; j < size_a; j++)
    {
        if (A[j] > n - 1)
            continue;
        int ad = modExp(A[j], d, n);
        if (ad % n == 1)
            continue;
        bool notcomp = false;
        for (int r = 0; r <= max(0LL, s - 1); r++)
        {
            int rr = modExp(2, r, n);
            int ard = modExp(ad, rr, n);
            if (ard % n == n - 1)
            {
                notcomp = true;
                break;
            }
        }
        if (!notcomp)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll i, j, n, m;
    cin >> n;
    if (mrtest(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}