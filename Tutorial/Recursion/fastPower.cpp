#include <bits/stdc++.h>
using namespace std;
#define ll long long

int power(int a, int n)
{
    if (n == 0)
        return 1;
    return a * power(a, n - 1);
}

int fastPower(int a, int n)
{
    if (n == 0)
        return 1;
    int smaller_ans = fastPower(a, n / 2);
    smaller_ans *= smaller_ans;
    if (n & 1)
        return smaller_ans * a;
    return smaller_ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    cout << fastPower(a, n);
    return 0;
}