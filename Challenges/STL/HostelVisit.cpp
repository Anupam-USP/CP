#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    priority_queue<long long ll> pq;
    long long ll k, q;
    cin >> q >> k;
    cin.get();
    long long ll x, y, z, p;
    while (q)
    {
        cin >> p;
        if (p == 1)
        {
            cin >> x >> y;
            z = pow(x, 2) + pow(y, 2);
            if (pq.size() == k)
            {
                if (z < pq.top())
                {
                    pq.pop();
                    pq.push(z);
                }
            }
            else
            {
                pq.push(z);
            }
        }
        else if (p == 2)
        {
            cout << pq.top() << endl;
        }
        q--;
    }
    return 0;
}