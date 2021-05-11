#include <bits/stdc++.h>
using namespace std;
#define ll long long ll

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    mpz_class n, k, kl, nat;
    cin >> n >> k;
    nat = (n - k) / 2;
    kl = nat + k;
    cout << kl << endl
         << nat;
    return 0;
}