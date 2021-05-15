#include <bits/stdc++.h>
using namespace std;
#define ll long long

void generate_string(char *in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // 1 digit at time
    int digit = in[i] - '0';
    char c = digit + 'A' - 1;
    out[j] = c;
    generate_string(in, out, i + 1, j + 1);

    // 2 digit at time
    if (in[i + 1] != '\0')
    {
        int secondDigit = in[i + 1] - '0';
        int no = digit * 10 + secondDigit;
        if(no<=26){
            c = no + 'A' - 1;
            out[j] = c;
            generate_string(in, out, i + 2, j + 1);
        }
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
    generate_string(in, out, 0, 0);
    return 0;
}