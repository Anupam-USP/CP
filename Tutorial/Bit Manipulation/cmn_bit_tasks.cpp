#include <bits/stdc++.h>
using namespace std;

bool isOdd(ll n)
{
    return n & 1;
}

ll getBit(ll n, ll i)
{
    ll mask = 1 << i;
    ll bit = ((n & mask) > 0) ? 1 : 0;
    return bit;
}

ll setBit(ll n, ll i)
{
    ll mask = 1 << i;
    ll ans = n | mask;
    return ans;
}

ll clearBit(ll &n, ll i)
{
    ll mask = ~(1 << i);
    n = n & mask;
}

ll updateBit(ll &n, ll i, ll v)
{
    ll mask = ~(1 << i);
    ll clearedN = n & mask;
    n = clearedN | (v << i);
}

ll clearLastBits(ll n, ll i)
{
    ll mask = (-1 << i);
    return n & mask;
}

ll clearRange(ll &n, ll i, ll j)
{
    ll left = (~0) << (j + 1);
    ll right = (1 << i) - 1;
    ll mask = left | right;
    return n & mask;
}

ll replaceNM(ll n, ll m, ll i, ll j)
{
    ll cleared_n = clearRange(n, i, j);
    return cleared_n|(m<<i);
}

ll numberSetBits(ll n){

    ll ans = 0;
    /*while(n>0){
        ans += (n & 1);
        n = n >> 1;
    }
    Time Complexity=O(log n)
    */
    while(n>0){
        n = n & (n - 1);
        ans++;
    }

    return ans;
}

ll DecimalToBinary(ll n){
    ll ans = 0,p=1;
    while(n>0){
        ll last_bit = (n & 1);
        ans += (last_bit * p);
        p = p * 10;
        n = n >> 1;
    }
    return ans;
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n = 20, m = 2;
    ll i = 1, j = 3;
    // cout << getBit(n, i)<<endl;
    // n = setBit(n, i);
    // clearBit(n, i);
    // updateBit(n, 2, 0);
    // updateBit(n, 3, 1);
    // n = clearLastBits(n, i);
    // cout << clearRange(n, i, j);
    // cout << replaceNM(n, m, i, j);
    // cout << numberSetBits(n)<<" : "<<__builtin_popcount(n);
    cout << DecimalToBinary(n);
    return 0;
}