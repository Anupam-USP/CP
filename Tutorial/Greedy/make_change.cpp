#include <bits/stdc++.h>
using namespace std;
#define ll long long

int make_change(int *coins, int money, int n){
    int ans = 0;
    while(money>0){
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        cout << coins[idx] << " + ";
        money -= coins[idx];
        ans++;
    }
    cout << endl;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int money;
    cin >> money;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int n = sizeof(coins) / sizeof(int);
    int ans = make_change(coins, money, n);
    cout << "Coins required: " << ans << endl;

    return 0;
}