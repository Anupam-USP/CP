#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll maximum(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}
ll power(ll a, ll n)
{
    ll result = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            result = result * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return result;
}
int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
int main()
{
    //Check for Integer overflows you MORON
    fast();
    int t;
    cin >> t;
    while (t--)
    {
    }
    int n;
    cin >> n;
    char a[n][n];
    int i1, j1, i2, j2;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '*' && flag == 0)
            {
                i1 = i;
                j1 = j;
                flag++;
            }
            if (a[i][j] == '*' && flag == 1)
            {
                i2 = i;
                j2 = j;
            }
        }
    }
    //  cout<<i1<<" "<<j1<<endl;
    //cout<<i2<<" "<<j2<<endl;
    int i3, j3, i4, j4;

    if (i1 != i2 && j1 != j2)
    {
        i3 = i1;
        j3 = j2;
        i4 = i2;
        j4 = j1;
    }
    else if (i1 == i2)
    {
        if (i1 + 1 < n)
        {
            j3 = j1;
            i3 = i1 + 1;
            j4 = j2;
            i4 = i1 + 1;
        }
        else
        {
            j3 = j1;
            i3 = i1 - 1;
            j4 = j2;
            i4 = i1 - 1;
        }
    }
    else if (j1 == j2)
    {
        if (j1 + 1 < n)
        {
            i3 = i1;
            j3 = j1 + 1;
            i4 = i2;
            j4 = j1 + 1;
        }
        else
        {
            i3 = i1;
            j3 = j1 - 1;
            i4 = i2;
            j4 = j1 - 1;
        }
    }
    a[i3][j3] = '*';
    a[i4][j4] = '*';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}