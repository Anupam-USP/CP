#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int n = 10000000;
bitset<10000005> b;
vector<int> prime;

void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (b[i])
        {
            prime.push_back(i);
            for (ll j = i * i; j <= n; j += i)
            {
                b[j] = 0;
            }
        }
    }
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll i = 0;
    while(prime[i]<n)
        i++;

    while (prime[i] <= k)
    {
        cout << prime[i] << endl;
        i++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }

    return 0;
}