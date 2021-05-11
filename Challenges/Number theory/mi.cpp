#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll x, y, GCD;

ll __gcd(ll a,ll b){

    if(b == 0){
        return (a);
    }

    return __gcd(b,(a%b));
}

void gcdext(ll a, ll b)
{
    // extended euclidean
    if (b == 0)
    {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    gcdext(b, a % b);
    ll cX = y;
    ll cY = x - (a / b) * y;

    x = cX;
    y = cY;
}

ll invModulo(ll a, ll m)
{
    if (__gcd(a, m) == 1)
        gcdext(a, m);
    // To make it positive
    return (x + m) % m;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll res = invModulo(n, MOD);
    cout << res << endl;
    return 0;
}