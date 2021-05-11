#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define N 100000
vector<int> primes;
int p[N+5] = {0};

void sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);
            for (int j = i; j <= N; j+=i)
            {
                p[j] = 1; // Marking non primes as 1
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        bool segment[n - m + 1];
        for (int i = 0; i < n - m + 1; i++)
        {
            segment[i] = 0;
        }

        for (auto x : primes)
        {
            // If greater than n**0.5 loop will break
            if (x * x > n)
                break;

            int start = (m / x) * x;
            
            // If prime lies in segmented sieve
            if(x>=m and x<=n)
                start = 2 * x;

            for (int j = start; j <= n; j += x)
            {
                segment[j - m] = 1;
            }
        }
        for (int i = m; i <= n;i++){
            if(segment[i-m]==0 and i!=1){
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}