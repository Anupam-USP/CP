// Alice and Totient
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

vector<ll> primeSieve(ll *p, ll n)
{
    p[0] = p[1] = 0;
    p[2] = 1;

    for (int i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    for (ll i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }

    vector<ll> primes;
    primes.push_back(2);

    for (ll i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
            primes.push_back(i);
    }

    return primes;
}

vector<ll> factorize(int m, vector<ll> &primes)
{
    vector<ll> factors;
    factors.clear();

    int i = 0;
    ll p = primes[i];

    while (p * p <= m)
    {
        if (m % p == 0)
        {
            factors.push_back(p);
            while (m % p == 0)
            {
                m = m / p;
            }
        }
        i++;
        p = primes[i];
    }
    if (m != 1)
        factors.push_back(m);

    return factors;
}

void solve(vl primes)
{
    ll i, j, n, m;
    cin >> n;
    vector<ll> factors = factorize(n, primes);
    long double ans = n;
    for (auto f : factors){
        long double tmp = 1.0 / f;
        ans = ans * (1 - tmp);
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
    const ll N = 100000;
    ll p[N + 5] = {0};
    vector<ll> primes = primeSieve(p, 100);
    while (t--)
    {
        solve(primes);
    }
    return 0;
}
