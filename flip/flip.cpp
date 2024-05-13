/*
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).


*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void fliprow(vector<vector<int>>& grid, int m, int row)
{
    for (int i = 0; i < m; i++)
        grid[row][i] ^= 1;
}
void flipcol(vector<vector<int>>& grid, int n, int col)
{
    for (int i = 0; i < n; i++)
        grid[i][col] ^= 1;
}

int matrixScore(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; i++)if (!grid[i][0]) fliprow(grid, m, i);

    for (int j = 0; j < m; j++)
    {
        int zero = 0;
        for (int i = 0; i < n; i++)
            if (grid[i][j] == 0) zero++;
        if (zero > (n - zero)) flipcol(grid, n, j);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string binary;
        for (int j = 0; j < m; j++)
            binary += to_string(grid[i][j]);
        ans += stoi(binary, NULL, 2);
    }
    return ans;
}

int main()
{
    vector < vector<int>> mat =
    {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };
    cout << matrixScore(mat);
    return 0;
}
