#include <bits/stdc++.h>
using namespace std;
#define ll long long

void replacePi(char *a, int i)
{
    if (a[i] == '\0')
        return;

    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        int j = i + 2;
        while (a[j] != '\0')
        {
            j++;
        }
        while(j>=i+2){
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacePi(a, i + 4);
    }
    else
    {
        replacePi(a, i + 1);
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char a[10000];
    cin >> a;
    replacePi(a, 0);
    cout << a << endl;
    return 0;
}