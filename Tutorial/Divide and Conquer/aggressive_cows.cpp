#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ifPlaced(int stall[], int n, int c, int min_sep)
{
    int last_cow = stall[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (stall[i] - last_cow >= min_sep)
        {
            last_cow = stall[i];
            cnt++;
            if (cnt == c)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n, c;
    cin >> n >> c;
    int stall[n + 1];
    for (int i = 0; i < n; i++)
        cin >> stall[i];

    sort(stall, stall + n);
    int s = 0;
    int e = stall[n - 1] - stall[0];
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool ifCowPlaced = ifPlaced(stall, n, c, mid);
        if (ifCowPlaced)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;
}

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
        solve();
    }
    return 0;
}