#include <bits/stdc++.h>
using namespace std;
ll main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char s[100] = "Today is a good day";
    char *ptr = strtok(s, " ");
    cout << ptr << endl;
    while (ptr)
    {
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }
    return 0;
}