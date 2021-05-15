#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ways(int n){
    if(n<=3)
        return 1;
    return ways(n - 1) + ways(n - 4);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << ways(n);
    return 0;
}