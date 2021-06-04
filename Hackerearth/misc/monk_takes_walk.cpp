#include <bits/stdc++.h>
using namespace std;
#define ll long long

char vowels[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < 10;j++){
                if(s[i]==vowels[j])
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}