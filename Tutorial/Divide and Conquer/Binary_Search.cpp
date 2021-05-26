#include <bits/stdc++.h>
using namespace std;
#define ll long long

int binarySearch(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
            return mid;

        if (a[mid] > key)
            e = mid - 1;

        if (a[mid] < key)
            s = mid + 1;
    }
    return -1;
}

int firsOcc(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (a[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}

int lastOcc(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] > key)
            e = mid - 1;

        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key;
    cin >> key;
    cout << "Occurence: " << binarySearch(a, n, key) << endl;
    cout << "First occurence: " << firsOcc(a, n, key) << endl;
    cout << "Last occurence: " << lastOcc(a, n, key) << endl
         << "\nUsing STL" << endl;

    if (binary_search(a, a + n, key))
    {
        cout << "Present" << endl;
    }
    else
        cout << "Absent" << endl;
    auto lb = lower_bound(a, a + n, key), ub = upper_bound(a, a + n, key);
    cout << "Lower bound: " << lb - a 
         << "\nUpper bound: " << ub - a << "\nOccurences are: "
         << ub - lb << endl;
    return 0;
}