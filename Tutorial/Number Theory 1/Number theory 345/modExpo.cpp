// Fast modulo exponentiation
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modExp(ll a, ll b, ll m){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << modExp(a, b, c) << endl;
    return 0;
}