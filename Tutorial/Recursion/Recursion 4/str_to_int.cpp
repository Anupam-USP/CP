#include <bits/stdc++.h>
using namespace std;
#define ll long long

int convert(char *a, int n)
{
    if (n == 0)
        return 0;

    int digit = a[n - 1] - '0';
    int small_ans = convert(a, n - 1);
    return small_ans * 10 + digit;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char a[] = "1234";
    int len = strlen(a);
    cout << convert(a, len) << "\n"
         << convert(a, len) + 1;
    return 0;
}