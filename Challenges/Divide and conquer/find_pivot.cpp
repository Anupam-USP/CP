#include <bits/stdc++.h>
using namespace std;
#define ll long long

int search(int *a, int n){
    for (int i = 0; i < n;i++){
        if(a[i]>a[i+1])
            return i;
    }
    return -1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];
    cout << search(a, n);
    return 0;
}