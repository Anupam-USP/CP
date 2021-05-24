#include <bits/stdc++.h>
using namespace std;
#define ll long long

void count_(int *a, int *cnt, int i, int n, int sum)
{
    if (i == n)
    {
        if (sum == 0)
            (*cnt)++;
        return;
    }
    count_(a, cnt, i + 1, n, sum);
    sum += a[i];
    return count_(a, cnt, i + 1, n, sum);
}

void solution()
{
    int n, cnt = 0, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    count_(a, &cnt, 0, n, sum);
    if (cnt > 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
        solution();
    }
    return 0;
}