#include <iostream>
#include <vector>
using namespace std;

class NQueensSolver
{
private:
    int N;
    vector<vector<int>> board;
    int solutionCount;

public:
    NQueensSolver(int n) : N(n), solutionCount(0)
    {
        board.resize(N, vector<int>(N, 0));
    }

    void printSolution()
    {
        cout << "Solution " << ++solutionCount << ":\n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << "\n";
        }
        cout << "\n";
    }

    bool isSafe(int row, int col)
    {
        // Check this row on the left
        for (int i = 0; i < col; ++i)
            if (board[row][i])
                return false;

        // Check upper diagonal on left
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j])
                return false;

        // Check lower diagonal on left
        for (int i = row, j = col; i < N && j >= 0; ++i, --j)
            if (board[i][j])
                return false;

        return true;
    }

    void solve(int col)
    {
        if (col == N)
        {
            printSolution();
            return;
        }

        for (int i = 0; i < N; ++i)
        {
            if (isSafe(i, col))
            {
                board[i][col] = 1;
                solve(col + 1);
                board[i][col] = 0; // backtrack
            }
        }
    }



    void solveNQueens()
    {
        solve(0);
        cout << "Total solutions for " << N << "×" << N << " board: " << solutionCount << "\n";
    }
};

int main()
{
    int size;
    cout << "Enter the size of the chessboard (N): ";
    cin >> size;

    NQueensSolver solver(size);
    solver.solveNQueens();

    return 0;
}
