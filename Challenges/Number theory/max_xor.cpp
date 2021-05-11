#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll max_xor = a[0];
    for (int i = 1; i < n;i++)
        max_xor = max_xor ^ a[i];
    ll maxi = INT_MIN;
    for (auto it : a)
    {
        max_xor = max_xor ^ it;
        if(max_xor>maxi)
            maxi = max_xor;
    }
    cout << maxi << endl;
    return 0;
}