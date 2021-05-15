#include <bits/stdc++.h>
using namespace std;
#define ll long long

void move(int n, char src, char helper, char dest)
{
    if (n == 0)
        return;

    move(n - 1, src, dest, helper);
    cout << "Moving disk " << n << " from " << src << " to " << dest << endl;
    move(n - 1, helper, dest, src);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}