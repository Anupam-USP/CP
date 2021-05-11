#include <bits/stdc++.h>
using namespace std;

ll DecimalToBinary(ll n)
{
    ll ans = 0, p = 1;
    while (n > 0)
    {
        ll last_bit = (n & 1);
        ans += (last_bit * p);
        p = p * 10;
        n = n >> 1;
    }
    return ans;
}

ll BinaryTDec(string A)
{
    ll cnt = 0, p = 1;
    for (ll i = A.length() - 1; i >= 0; i--)
    {
        cnt += A[i] * p;
        p = p * 2;
    }
    return cnt;
}

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        long long c, a = 0, b = 0;
        cin >> c;
        string d = bitset<64>(c).to_string();
        string A = bitset<64>(a).to_string();
        string B = bitset<64>(b).to_string();

        A[d.find('1')] = '1';
        for (ll i = d.find('1') + 1; i < 64; i++)
        {
            B[i] = '1';
            if (d[i] == '0')
            {
                A[i] = '1';
            }
        }
        cout << stoi(A, nullptr, 2) * stoi(B, nullptr, 2) << endl;
    }

    return 0;
}