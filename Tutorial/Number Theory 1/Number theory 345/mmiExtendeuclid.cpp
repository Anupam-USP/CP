// Multiplicative modulo inverse using extended euclidean
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int x, y, GCD;

void gcdext(int a, int b)
{
    // extended euclidean
    if (b == 0)
    {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    gcdext(b, a % b);
    int cX = y;
    int cY = x - (a / b) * y;

    x = cX;
    y = cY;
}

int invModulo(int a, int m)
{
    if (__gcd(a, m) == 1)
        gcdext(a, m);
    // To make it positive
    return (x + m) % m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << invModulo(18, 7);
    return 0;
}