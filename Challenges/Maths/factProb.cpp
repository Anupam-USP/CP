// My approach
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// ll fact(ll n)
// {
//     if (n > 0)
//     {
//         if (n == 1 || n == 0)
//             return 1;
//         else
//             return n * fact(n - 1);
//     }
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, k;
//         cin >> n >> k;
//         ll nfact = fact(n);
//         int x = 0,mindiv = 0;
//         cout << nfact << endl;
//     }
//     return 0;
// }

// CB approach
#include <bits/stdc++.h>
using namespace std;
#define INT_MAXI 100000000
#define ll long long

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
        ll n, k;
        cin >> n >> k;
        ll ans = INT_MAXI;

        // Prime factorisation
        ll occ = 0;
        for (int i = 2; i <= sqrt(k); i++)
        {
            if (k % i == 0)
            {
                occ = 0;
                while (k % i == 0)
                {
                    occ++;
                    k = k / i;
                }

                ll cnt = 0, p = i;
                while(p<=n){
                    cnt += n / p;
                    p = p * i;
                }
                ans = min(ans, cnt / occ);
            }
        }

        if(k>1){
            ll cnt = 0, p = k;
            while(p<=n){
                cnt += n / p;
                p *= k;
            }
            ans = min(ans, cnt);
        }

        if(ans==INT_MAXI)
            ans = 0;

        cout << ans << endl;
    }

    return 0;
}