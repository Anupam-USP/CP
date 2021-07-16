#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed = true)
    {
        l[x].push_back(y);
        if (!directed)
            l[y].push_back(x);
    }

    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                bool cycle_mila = cycle_helper(nbr, visited, node);
                if (cycle_mila)
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }

    bool contain_cycle()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        return cycle_helper(0, visited, -1);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 0);
    if (g.contain_cycle())
    {
        cout << "Contains cycle" << endl;
    }
    else
        cout << "Do not contain cycle" << endl;
    return 0;
}