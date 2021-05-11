#include <bits/stdc++.h>
using namespace std;

ll main()
{
    ll arr[] = {10, 2, 49, 23, 5, 6};
    ll n = sizeof(arr) / sizeof(ll);
    ll key;
    cin >> key;
    auto it = find(arr, arr + n, key);
    ll idx = it - arr;

    if (idx == n)
        cout << key << " not present" << endl;
    else
        cout << key << " present at index: " << idx << endl;

    bool present = binary_search(arr, arr + n, key);
    if (present)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}