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
    for (ll i = 2; i <= n; i += 2)
    {
        if (b[i] == 1)
        {
            prime.push_back(i);
            for (ll j = i * i; j <= n; j += i){
                b[j] = 0;
            }
        }
    }
}

bool isPrime(ll No){
    if(No<n){
        return b[No] == 1 ? true : false;
    }

    for (ll i = 0; prime[i] * (ll)prime[i] <= No;i++){
        if(No%prime[i]==0){
            return false;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    sieve();
    if(isPrime(2345678198))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}