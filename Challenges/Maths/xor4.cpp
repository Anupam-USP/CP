#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    ull n;
    cin >> n;

    vector<ull> A;

    for (int i = 0; i < n; i++)
    {
        ull no;
        cin >> no;
        A.push_back(no);
    }

    if (n >= 130)
    {
        cout << "YES";
        return 0;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if (A[i] ^ A[j] ^ A[k] ^ A[l] == 0)
                        {
                            cout << "YES";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}