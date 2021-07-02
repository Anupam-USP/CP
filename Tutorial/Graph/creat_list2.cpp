// Creating list hash-map
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph
{
    unordered_map<string, list<pair<string, int> > > l;

public:
    void addEdge(string x, string y, bool bidir, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (bidir)
            l[y].push_back(make_pair(x, wt));
    }

    void print()
    {
        for (auto it : l)
        {
            auto city = it.first;

            cout << city << " -> ";
            list<pair<string, int> > nbrs = it.second;
            for (auto nbr : nbrs)
            {
                auto dest = nbr.first;
                auto dist = nbr.second;
                cout << dest << " " << dist << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", false, 40);
    g.addEdge("A", "D", true, 50);
    g.print();
    return 0;
}