#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

template <typename T>
class Graph
{
    map<T, list<T> > l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited, int *arr)
    {
        //  Recursive function traverse graph
        arr[0]++;
        visited[src] = true;
        for (T nbr : l[src])
        {
            if(!visited[nbr]){
                dfs_helper(nbr, visited, arr);
            }
        }
    }

    auto dfs_(){
        map<T, bool> visited;
        vector<int> v;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        int cnt = 0;
        for (auto p:l){
            int arr[2] = {0};
            T node = p.first;
            if(!visited[node]){
                dfs_helper(node, visited, arr);
                cnt++;
                v.push_back(arr[0]);
            }
        }

        return v;
    }

};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Graph<ll> g;
    ll n, t;
    cin >> n >> t;
    while(t--){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        g.addEdge(tmp1, tmp2);
    }
    
    auto x = g.dfs_();
    ll ans = nCr(n, 2);
    for(auto it: x){
        ans -= nCr(it, 2);
    }
    cout << ans;
    return 0;
}