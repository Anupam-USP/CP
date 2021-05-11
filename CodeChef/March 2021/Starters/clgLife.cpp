#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, string> mp;
        ll f[n], c[k];
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
            mp.insert(pair<int, string>(f[i], "f"));
        }

        for (int i = 0; i < k; i++)
        {
            cin >> c[i];
            mp.insert(pair<int, string>(c[i], "c"));
        }

        int cnt = 0;
        vector<int> a;
        vector<string> b;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            a.push_back(it->first);
            b.push_back(it->second);
        }

        if(b[0]=="c")
            cnt++;
        for (int i = 1; i < b.size();i++){
            if(b[i]!=b[i-1])
                cnt++;
        }
        cout<<cnt << endl;
    }
    return 0;
}