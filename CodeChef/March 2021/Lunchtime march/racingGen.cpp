#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int x, r, m;
        cin >> x >> r >> m;
        if((m-r)*60>x)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}