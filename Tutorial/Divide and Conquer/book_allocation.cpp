#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(int *arr, int n, int m, int curr_min)
{
    int stud = 1;
    int curr_page = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_page + arr[i] > curr_min)
        {
            stud++;
            curr_page = arr[i];
            if (stud > m)
                return false;
        }
        else
        {
            curr_page += arr[i];
        }
    }
    return true;
}

int findPage(int *books, int n, int m, int sum)
{
    if (n < m)
        return -1;
    int s = books[n - 1];
    int e = sum;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossible(books, n, m, mid))
        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int books[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
        sum += books[i];
    }
    sort(books, books + n);
    cout << findPage(books, n, m, sum) << endl;
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