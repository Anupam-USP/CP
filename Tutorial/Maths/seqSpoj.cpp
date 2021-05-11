#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector<vector<ll>>
#define MOD 1000000000

ll k;
vector<ll> a, b, c;

vec multiply(vec A, vec B)
{
    vec C(k + 1, vector<ll>(k + 1));
    for (ll i = 1; i <= k; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            for (ll x = 1; x <= k; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

vec pow(vec A, ll p)
{
    if (p == 1)
        return A;
    else if (p & 1)
    {
        return multiply(A, pow(A, p - 1));
    }
    else
    {
        vec X = pow(A, p / 2);
        return multiply(X, X);
    }
}

ll compute(ll n)
{
    if (n == 0)
        return 0;
    else if (n <= k)
        return b[n - 1];
    else
    {
        vector<ll> f1(k + 1);
        for (ll i = 1; i <= k; i++)
        {
            f1[i] = b[i - 1];
        }

        vec T(k + 1, vector<ll>(k + 1));
        for (ll i = 1; i <= k; i++)
        {
            for (ll j = 1; j <= k; j++)
            {
                if (i < k)
                {
                    if (j == i + 1)
                    {
                        T[i][j] = 1;
                    }
                    else
                    {
                        T[i][j] = 0;
                    }
                }
                else
                {
                    T[i][j] = c[k - j];
                }
            }
        }

        T = pow(T, n - 1);

        ll res = 0;
        for (ll i = 0; i <= k; i++)
        {
            res = (res + (T[1][i] * f1[i]) % MOD) % MOD;
        }

        return res;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, n, num;
    cin >> t;
    while (t--)
    {
        cin >> k;
        for (ll i = 0; i < k; i++)
        {
            cin >> num;
            b.push_back(num);
        }

        for (ll i = 0; i < k; i++)
        {
            cin >> num;
            c.push_back(num);
        }

        cin >> n;
        cout << compute(n) << endl;

        b.clear();
        c.clear();
    }
    return 0;
}