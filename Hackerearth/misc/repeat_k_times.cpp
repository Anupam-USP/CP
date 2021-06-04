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
    int a[n], ans[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans[a[i]]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < *max_element(a, a + n); i++)
    {
        if (ans[i] == k)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}