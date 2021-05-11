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
        ll n, m;
        cin >> n >> m;
        ll a[n];
        ll has[m + 1] = {0};

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            has[a[i]]++;
        }

        ll flag = 0;
        for (int i = 1; i <= m; i++)
        {
            // cout << has[i]<<" ";
            if (has[i] == 0)
            {
                cout << "YES" << endl;
                break;
            }
            flag++;
        }
        if (flag == (m))
            cout << "NO" << endl;
    }
    return 0;
}