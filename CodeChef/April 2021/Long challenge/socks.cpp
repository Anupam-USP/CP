#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a, b, c;
    cin >> a >> b >> c;
    if((a==b) || (b==c) || (a==c))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}