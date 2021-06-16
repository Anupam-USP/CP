#include <bits/stdc++.h>
using namespace std;
#define ll long long

int abs(int i, int j){
    if(i>j)
        return i - j;
    return j - i;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int arr[100000] = {0};
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        int n, rank_p;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> rank_p;
            arr[rank_p]++;
        }

        int actual_rank = 1, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                ans += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}