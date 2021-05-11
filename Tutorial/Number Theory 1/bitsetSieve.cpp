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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    for (int i = 0; i < 100;i++){
        cout << prime[i] << endl;
    }
        return 0;
}