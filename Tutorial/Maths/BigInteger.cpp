#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Multiply(ll *a, ll &n, ll no)
{
    ll carry = 0;
    for (ll i = 0; i < n; i++)
    {
        ll prod = (a[i] * no) + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void BigFact(ll no)
{
    ll *a = new ll[1000];
    for (ll i = 0; i < 1000; i++)
        a[i] = 0;
    a[0] = 1;
    ll n = 1;
    for (ll i = 2; i <= no; i++)
    {
        Multiply(a, n, i);
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    delete[] a;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    BigFact(n);
    return 0;
}
