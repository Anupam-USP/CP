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

int p[1000007] = {};
vector<ll> primes;

void primeSieve()
{
    p[0] = p[1] = 1;
    primes.push_back(2);
    for (ll i = 3; i < 1000000; i += 2)
    {
        if (!p[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < 1000000; j += i)
            {
                p[j] = 1;
            }
        }
    }
}

map<int, int> factors;
void factorize(int m)
{
    int i = 0;
    ll p = primes[i];
    int ans = 1;

    while (p * p <= m)
    {
        if (m % p == 0)
        {
            int cnt = 0;
            while (m % p == 0)
            {
                cnt++;
                m = m / p;
            }
            factors[p] += cnt;
        }
        i++;
        p = primes[i];
    }
    if (m != 1)
        factors[m] += 1;
}

int NumOfDiv(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        factorize(arr[i]);
    }
    int ans = 1;
    for (auto it : factors)
    {
        int tmp = it.second + 1;
        ans = ((ans % MOD) * (tmp % MOD)) % MOD;
    }
    return ans % MOD;
}

void solve()
{
    int i, j, n, m;
    cin >> n;
    int *arr = new int[n];
    fo(i, n) cin >> arr[i];
    cout << NumOfDiv(arr, n) << endl;
    factors.clear();
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
    primeSieve();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
