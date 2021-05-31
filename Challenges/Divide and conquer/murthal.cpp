#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool canCook(int n, int l, int *a, int time)
{
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        int sum = 0, timer = 1;
        while (sum <= time)
        {
            sum += (a[i] * timer++);
            if (sum <= time)
                cnt++;
            else
                break;

            if (cnt == n)
                return true;
        }
    }
    return false;
}

int getCookTime(int n, int l, int *a)
{
    int s = 0;
    int e = a[l - 1] * (n * (n + 1) / 2);
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool canBeCooked = canCook(n, l, a, mid);
        if (canBeCooked)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int p, l;
    cin >> p >> l;
    int a[l];
    for (int i = 0; i < l; i++)
    {
        cin >> a[i];
    }
    cout << getCookTime(p, l, a);
    return 0;
}