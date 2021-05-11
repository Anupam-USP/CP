#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (i = k; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
fcp
const int N = 3e5, M = N;

int mpow(int base, int exp)
{
    base %= MOD;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % MOD;
        base = ((ll)base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

void solve()
{
    int i, j = 0, n, m;
    cin >> n >> m;
    vl a;
    int k = m;
    
    if(m<=(n-1)/2)
    {
        fo(i, n) a.push_back(i + 1);

        for (int i = 1; i < n; i += 2)
        {
            if (k)
            {
                j++;
                ll tmp = a.at(n - 1);
                a.pop_back();
                a.insert(a.begin() + i, tmp);
            }
            else
                break;
            k--;
        }
        if (j != m)
            cout << -1;
        else
        {
            fo(i, n) cout << a[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
