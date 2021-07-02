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
        l[y].push_back(x);
    }

    void BFS(T src)
    {
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            cout << node << " ";
            for (auto it : l[node])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }

    void shortest_path(T src)
    {
        map<T, int> dist;
        queue<T> q;

        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

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
                }
            }
        }

        // Print the distances
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node: " << node << " dist from source: " << d << endl;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.shortest_path(0);

    return 0;
}