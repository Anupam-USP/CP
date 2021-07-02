#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T> 
class Graph
{
    map<T, list<T> > l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    auto shortest_path(T src, T dest)
    {
        map<T, int> dist;
        map<T, T> parent;
        queue<T> q;

        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (int_fast32_t it : l[node])
            {
                if (dist[it] == INT_MAX)
                {
                    q.push(it);
                    dist[it] = dist[node] + 1;
                    parent[it] = node;
                }
            }
        }

        // Print the distances
        auto tmp = dest;
        while(tmp!=src){
            cout << tmp << " <- ";
            tmp = parent[tmp];
        }
        cout << src << endl;
        return dist[dest];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = -11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = 2;
    board[34] = -22;
    Graph<int> g;
    for (int i = 0; i <= 36;i++){
        for (int dice = 1; dice <= 6;dice++){
            int j = i + dice;
            j += board[j];
            if(j<=36){
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36);
    cout << g.shortest_path(0, 36) << endl;
    return 0;
}