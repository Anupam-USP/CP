#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isSafe(int board[][10], int i, int j, int n)
{
    // For column
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
            return false;
    }

    // For left diagonal
    int x = i, y = j;
    while (x >= 0 and y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // for right diagonal
    x = i;
    y = j;
    while (x >= 0 and y < n)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    return true;
}

bool solve(int board[][10], int i, int n)
{
    if (i == n)
    {
        // print board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;

            bool nextQueen = solve(board, i + 1, n);
            if (nextQueen)
                return true;

            // Backtracking
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int board[10][10] = {0};
    solve(board, 0, n);
    return 0;
}