#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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

int max3(int a, int b, int c){
    return max(max(a, b), c);
}

int max_sum(ll *a, int l, int m, int n){
    int tmp;
    int cLeft = INT_MIN, cRight = INT_MIN;
    tmp = 0;
    for (int i = m; i >= l;i--){
        tmp += a[i];
        if(tmp>cLeft)
            cLeft = tmp;
    }
    for (int i = m + 1; i <= n;i++){
        tmp += a[i];
        if(tmp<cRight)
            cRight = tmp;
    }

    return max3(cLeft + cRight, cLeft, cRight);
}

int maxSubArrSum(ll *arr, int l, int h)
{
    // base case
    if (l == h)
        return arr[l];

    // recursion case
    int mid = (l + h) / 2;
    int leftSum = maxSubArrSum(arr, l, mid);
    int rightSum = maxSubArrSum(arr, mid + 1, h);
    int centerSumMax = max_sum(arr, l, mid, h);

    return max3(leftSum, rightSum, centerSumMax);
}

void solve()
{
    ll i, j, n, m;
    cin >> n;
    ll a[n];
    fo(i, n) cin >> a[i];
    cout << maxSubArrSum(a, 0, n);
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
