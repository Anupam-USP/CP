#include <bits/stdc++.h>
using namespace std;

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
        int u, v, a, s;
        cin >> u >> v >> a >> s;
        if (u < v)
        {
            cout << "Yes" << endl;
        }
        else
        {
            double sa = ((u * u) - (v * v)) / (2 * a);
            if (sa <= s)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}