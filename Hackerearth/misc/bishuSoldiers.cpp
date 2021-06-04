#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int sol[n];
    for (int i = 0; i < n; i++)
        cin >> sol[i];
    sort(sol, sol + n);
    int q;
    cin >> q;
    while (q--)
    {
        int power;
        cin >> power;
        int i = 0, ans = 0, cnt = 0;
        while (sol[i] <= power and i < n)
        {
            ans += sol[i];
            cnt++;
            i++;
        }
        
        cout << cnt << " " << ans << endl;
    }
    return 0;
}