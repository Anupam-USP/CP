#include <bits/stdc++.h>
using namespace std;
#define ll long long

string big_multiply(ll x, int coeff, int n)
{
    string arr1 = to_string(x), arr2 = to_string(coeff);
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    int ans_size = (arr1.size())*n;
    int ans[ans_size] = {0};

    //Multiplying
    //In a reverse manner, just to avoid reversing strings explicitly
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1.size(); j++)
        {
            //Convert array elements (char -> int)
            int p = (int)(arr1[i]) - '0';
            int q = (int)(arr2[j]) - '0';

            //Excerpt from Shravan's answer above
            ans[i + j] += p * q;
            ans[i + j + 1] = ans[i + j + 1] + ans[i + j] / 10;
            ans[i + j] %= 10;
        }
    }

    //Declare array to store string form of final answer
    string s = "";

    for (auto i = 0; i < ans_size; ++i)
        s += to_string(ans[i]);

    reverse(s.begin(), s.end());

    //If last element is 0, it should be skipped
    if (s[0] == '0')
    {
        string ss(s, 1, s.size() - 1);
        s = ss;
    }

    //Final answer
    cout << s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string x;
    cin >> x;
    ll f = (3 * pow(x, 3)) - (x) + 10;
    ll g = (4 * pow(x, 3)) + (2 * pow(x, 2)) - (5 * x) + 4;
    ll h = f + g;
    cout << h << endl;
    return 0;
}