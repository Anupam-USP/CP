// Creating adjucancy list
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph
{
    int v;
    list<int> *l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print(){
        for (int i = 0; i < v;i++){
            cout << "Vertex " << i << " -> ";
            for(auto it: l[i]){
                cout << it << ", ";
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
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.print();
    return 0;
}