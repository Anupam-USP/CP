#include <bits/stdc++.h>
using namespace std;
#define ll long long

int get_profit(int *p, int *w, int n,int c){
    if(n==0 or c==0)
        return 0;

    int inc = 0, exc = 0;
    if(w[n-1]<=c){
        inc = p[n - 1] + get_profit(p, w, n - 1, c - w[n - 1]);
    }
    exc = get_profit(p, w, n - 1, c);

    return max(inc, exc);
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, c;
    cin >> n >> c;
    int p[n], w[n];
    for (int i = 0; i < n;i++)
        cin >> p[i];
    for (int i = 0; i < n;i++)
        cin >> w[i];

    cout << get_profit(p, w, n, c) << endl;
    return 0;
}