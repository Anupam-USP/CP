#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.first > p2.first;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d, f, D, F, prev, ans = 0, flag = 0;
        cin >> n;
        vector<pair<ll, ll>> v;
        priority_queue<ll> pq;
        for (int i = 0; i < n; i++)
        {
            cin >> d >> f;
            v.push_back(make_pair(d, f));
        }
        cin >> D >> F;
        sort(v.begin(), v.end(), compare);

        // Update the value w.r.t truck as it is given w.r.t destination in reverse
        for (int i = 0; i < n; i++)
        {
            v[i].first = D - v[i].first;
        }

        // Logic
        prev = 0;
        auto x = 0; // Current city


        // Part 1: Visiting all the fuel stations
        while (x < n)
        {
            if (F >= (v[x].first - prev))
            {
                F = F - (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else
            {
                // check if visited a fuelling station
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;
                continue;
            }
            x++;
        }

        // Part 2: Checking for last station
        if (flag == 1)
        {
            cout << -1 << endl;
            continue;
        }
        D = D - v[n - 1].first;
        if (F >= D)
        {
            cout << ans << endl;
            continue;
        }
        while (F < D)
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans++;
        }
        if (flag == 1)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}