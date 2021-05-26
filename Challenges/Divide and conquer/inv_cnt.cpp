#include <bits/stdc++.h>
using namespace std;
#define int long long

int merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int tmp[100000], cnt = 0;

    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
        {
            tmp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= e)
        tmp[k++] = a[j++];
    for (int i = s; i <= e; i++)
        a[i] = tmp[i];
    return cnt;
}

int inv_Count(int *a, int s, int e)
{
    if (s >= e)
        return 0;

    int mid = (s + e) / 2;
    int x = inv_Count(a, s, mid);
    int y = inv_Count(a, mid + 1, e);
    int z = merge(a, s, e);
    return x + y + z;
}

int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << inv_Count(a, 0, n - 1) << endl;
    }
    return 0;
}