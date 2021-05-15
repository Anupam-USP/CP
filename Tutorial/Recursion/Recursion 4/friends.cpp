#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ways(int n, int k)
{
    if (n == 0)
        return 1;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += i * ways(n - i, k);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    cout << ways(n, k);
    return 0;
}