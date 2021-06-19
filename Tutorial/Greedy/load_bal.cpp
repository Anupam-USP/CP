#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[9000];
    int n, i, val, diff;
    while (1)
    {
        int load = 0, max_load = 0;
        cin >> n;
        if (n == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            load += arr[i];
        }

        if (load % n != 0)
        {
            cout << -1 << endl;
            continue;
        }

        load = load / n;
        diff = 0;
        // greedy step
        for (int i = 0; i < n; i++)
        {
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << endl;
    }
    return 0;
}