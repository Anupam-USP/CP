// Nums to spelling
#include <bits/stdc++.h>
using namespace std;
#define ll long long

char words[][10] = {"zero", "one", "two", "three", "four",
                    "five", "six", "seven", "eight", "nine"};

void convert(int n)
{
    if (n == 0)
        return;

    convert(n / 10); // If call is after words printed in reverse Format
    int digit = n % 10;
    cout << words[digit] << " ";
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    convert(n);
    return 0;
}