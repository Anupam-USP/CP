#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> vec;

void gen_string(string in, string out, int i)
{
    int n = in.length();
    if (i == n)
    {
        vec.push_back(out);
    }

    if (in[i] != '0')
    {
        int digit = in[i] - '0';
        char ch = digit + 'a' - 1;
        gen_string(in, out + ch, i + 1);
    }

    if (i < n)
    {
        int digit = in[i] - '0';
        int tmp = in[i + 1] - '0';
        int no = digit * 10 + tmp;
        if (no <= 26)
        {
            char ch = no + 'a' - 1;
            // out[j] = ch;
            gen_string(in, out + ch, i + 2);
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
    string in;
    cin >> in;
    string out;
    gen_string(in, out, 0);
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    return 0;
}