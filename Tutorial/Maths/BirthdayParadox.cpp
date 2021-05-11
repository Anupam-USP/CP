#include <bits/stdc++.h>
using namespace std;

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    float x = 1.0, num = 365, denom = 365, p;
    ll people = 0;
    cin >> p;
    while (x > 1 - p)
    {
        x = (x * num) / denom;
        num--;
        people++;
        cout << "People are " << people << " and probability is " << x << endl;
    }
    return 0;
}