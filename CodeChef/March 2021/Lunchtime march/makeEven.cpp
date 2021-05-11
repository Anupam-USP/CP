#include <bits/stdc++.h>
using namespace std;

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
        int n;
        cin >> n;
        int a[n];
        int flag = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[i] == 1)
            flag++;

        if (flag == n)
            cout << -1 << endl;
        else
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                if (a[i] % 2 == 0)
                {
                    a[i] = pow(a[i], max(a[i] / 2, 0));
                }
            }
        }
    }

    return 0;
}