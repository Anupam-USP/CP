#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
int cnt[N + 1] = {0};
int sum[N + 1] = {0};

void sieve()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            sum[i] += cnt[j];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    sieve();

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        cout << sum[k] << endl;
    }

    return 0;
}