#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int r, o, c;
    cin >> r >> o >> c;
    o = 20 - o;
    int req = r - c;
    if (o >= 1 && o <= 19 && r > c && r < 720 && c < 720)
    {
        o *= 6;
        if ((6 * o) > req)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}