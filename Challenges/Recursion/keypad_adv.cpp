#include <bits/stdc++.h>
using namespace std;
#define ll long long
string keypad[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string searchIn[] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void chkSubstr(char *subStr)
{
    for (int p = 0; p < 11; p++)
    {
        if (searchIn[p].find(subStr) != string::npos)
        {
            cout << searchIn[p] << '\n';
        }
    }
    return;
}

void generate_keypad(char *in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';

        return;
    }

    int digit = in[i] - '0';

    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        generate_keypad(in, out, i + 1, j + 1);
    }

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char in[100];
    cin >> in;
    char out[100];
    generate_keypad(in, out, 0, 0);
    return 0;
}