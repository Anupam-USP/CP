#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ifPlaced(int *stall, int n, int c, int place){
    int lastcow = stall[0];
    int cnt = 1;
    for (int i = 0; i < n;i++){
        if((stall[i]-lastcow)>=place){
            lastcow = stall[i];
            cnt++;
            if(cnt==c)
                return true;
        }
    }
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, c;
    cin >> n >> c;
    int stall[n];
    for (int i = 0; i < n;i++)
        cin >> stall[i];

    sort(stall, stall + n);
    int s = 0, ans = -1;
    int e = n - 1;
    while(s<=e){
        int mid = (s + e) / 2;
        bool cowPlaced = ifPlaced(stall, n, c, mid);
        if(cowPlaced){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}