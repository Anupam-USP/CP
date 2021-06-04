#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, y, s, t;
    cin >> x >> y >> s >> t;
    int cnt = 0;
    for (int i = x; i <= (x + s); i++)
    {
        for (int j = y; j <= (y + s);j++){
            if(i+j<=t)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
