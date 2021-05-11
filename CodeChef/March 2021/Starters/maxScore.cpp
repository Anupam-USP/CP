#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compareQuest(Quest q1, Quest q2)
{
    return (q1.score > q2.score);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<Quest> v;
    int n, q, k, i;
    cin >> n >> q;

    for (i = 0; i < n; i++)
    {
        cin >> v[i].score;
        cin >> v[i].time;
    }

    return 0;
}