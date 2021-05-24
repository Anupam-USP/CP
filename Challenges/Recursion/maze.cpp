#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ratInMaze(char maze[1000][1000], int soln[][1000], int i, int j, int m, int n)
{
    if (i == m and j == n)
    {
        soln[m][n] = 1;
        // Printing path
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl; 
        return true;
    }

    // Rat should be in maze
    if (i > m or j > n)
        return false;
    if (maze[i][j] == 'X')
        return false;

    soln[i][j] = 1;
    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    if (rightSuccess)
        return true;
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

    // Backtracking
    soln[i][j] = 0;
    if (downSuccess)
        return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    char maze[1000][1000];
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> maze[i][j];
        }
    }
    int soln[1000][1000] = {0};
    bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
    if(!ans)
        cout << -1 << endl;
    
    return 0;
}