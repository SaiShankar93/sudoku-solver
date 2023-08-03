#include <bits/stdc++.h>
using namespace std;
//checking wheather moving to the block is safe or not
bool isSafe(int r, int c, int b[9][9], int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (b[i][c] == val || b[r][i] == val)
            return false;
        if (b[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val)
            return false;
    }
    return true;
}
bool solve(int b[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (b[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(i, j, b, val))
                    {
                        b[i][j] = val;
                        bool nextAns = solve(b);
                        if (nextAns)
                        {
                            return true;
                        }
                        else
                        {
                            b[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(int board[9][9])
{
    solve(board);
}
void takeInput(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
}
void printOutput(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int board[9][9];

    cout << "Enter the elements in the sudoku" << endl;
    takeInput(board);

    solveSudoku(board);

    cout << "The sudoku board after solving" << endl;
    printOutput(board);

    return 0;
}
