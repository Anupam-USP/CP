#include <bits/stdc++.h>
using namespace std;
#define ll long long

float root(int n, int p)
{
    int s = 0;
    float ans = -1;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (mid * mid == n)
            ans = mid;
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    float inc = 0.1;
    for (int i = 1; i <= p; i++)
    {
        while (ans * ans <= n)
            ans += inc; 
        ans -= inc;
        inc /= 10;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, p;
    cin >> n >> p;
    cout << root(n, p) << endl;
    return 0;
}