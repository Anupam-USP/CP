#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        for (int i = 0; i < n;i++)
            cin >> v1[i];
        for (int i = 0; i < n;i++)
            cin >> v2[i];

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int ans = 0;
        for (int i = 0; i < n;i++){
            ans += abs(v1[i] - v2[i]);
        }

        cout << ans << endl;
    }
    return 0;
}