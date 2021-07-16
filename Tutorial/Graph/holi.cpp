#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph
{
    int V;
    list<pair<int, int> > *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int> >[V];
    }

    void addEdge(int u, int v, int cost)
    {
        l[u].push_back(make_pair(v,cost));
        l[v].push_back(make_pair(u,cost));
    }

    int dfsHelper(int node, bool *visited, int *cnt, int &ans){
        visited[node] = true;
        cnt[node] = 1;

        for(auto nbr_pair:l[node]){
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;

            if(!visited[nbr]){
                cnt[nbr] += dfsHelper(nbr, visited, cnt, ans);
                int nx = cnt[nbr];
                int ny = V - nx;
                ans = 2 * min(nx, ny) * wt;
            }
        }

        return cnt[node];
    }

    int dfs(){
        bool *visited = new bool[V]{0};
        int *count = new int[V]{0};
        int ans = 0;

        dfsHelper(0, visited, count, ans);
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}