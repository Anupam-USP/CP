#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    ll age;
    Person() {}
    Person(string n, ll a)
    {
        name = n;
        age = a;
    }
};

class PersonCompare
{
public:
    bool operator()(Person A, Person B)
    {
        // if used "<" we get greater to lower
        return A.age > B.age;
    }
};

ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    priority_queue<Person, vector<Person>, PersonCompare> pq;
    for (ll i = 0; i < n; i++)
    {
        string name;
        ll age;
        cin >> name >> age;
        Person p(name, age);
        pq.push(p);
    }

    // To find top 3 persons in a competition
    ll k = 3;
    for (ll i = 0; i < k; i++)
    {
        Person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }
    return 0;
}