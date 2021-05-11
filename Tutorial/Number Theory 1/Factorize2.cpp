// Using Prime sieve
#include <bits/stdc++.h>
using namespace std;
#define ll int

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

int cntDiv(int m, vector<int> &primes)
{
    // To count the number of divisors

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
            ans *= (cnt + 1);
        }
        i++;
        p = primes[i];
    }
    if (m != 1)
        ans *= 2;

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N = 100000;
    int p[N + 5] = {0};
    vector<ll> primes = primeSieve(p, 100);

    int t;
    cin >> t;
    while (t--)
    {
        int no;
        cin >> no;

        vector<ll> factors = factorize(no, primes);
        for (auto f : factors)
        {
            cout << f << " ";
        }
        int div = cntDiv(no, primes);
        cout << "\nNo of divisors of " << no << ": " << div << endl;
    }
    return 0;
}