#include <bits/stdc++.h>
using namespace std;
#define ll long long
char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_keypad(char *in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = in[i] - '0';
    if(digit==0 or digit==1)
        generate_keypad(in, out, i + 1, j);
        
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