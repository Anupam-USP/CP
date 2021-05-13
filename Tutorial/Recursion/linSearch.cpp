#include <bits/stdc++.h>
using namespace std;
#define ll long long

int firstOcc(int *a, int n, int key)
{
    if (n == 0)
        return -1;
    if (a[0] == key)
        return 0;

    int i = firstOcc(a + 1, n - 1, key);
    if (i == -1)
        return -1;
    return i + 1;
}

int lastOcc(int *a, int n, int key)
{
    if (n == 0)
        return -1;

    int last = lastOcc(a + 1, n - 1, key);
    if (last == -1)
    {
        if (a[0] == key)
            return 0;
        return -1;
    }

    return last + 1;
}

void allOcc(int *a, int i, int n, int key)
{
    if (i == n)
        return;
    if (a[i] == key)
        cout << i << " ";
    allOcc(a, i + 1, n, key);
}

int storeOcc(int *a,int i,int n,int key,int *out,int j){
    if(i==n)
        return j;
    if(a[i]==key){
        out[j] = i;
        storeOcc(a, i + 1, n, key, out, j + 1);
    }
    return storeOcc(a, i + 1, n, key, out, j);
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
    cout << "First occurence " << firstOcc(a, n, key) << endl;
    cout << "Last occurence " << lastOcc(a, n, key) << endl;
    cout << "All occurence: ";
    allOcc(a, 0, n, key);

    return 0;
}