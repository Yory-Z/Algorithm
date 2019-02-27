//
// Created by Yory on 2019/2/25.
//

#ifndef ALGORITHM_SUDOKUSOLVER_H
#define ALGORITHM_SUDOKUSOLVER_H

#include <vector>
#include <iostream>
using namespace std;

class SudokuSolver {
public:
    void test() {
        vector<vector<char>> board{
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
        };

        for(vector<char> vec : board) {
            for (char ch : vec) {
                cout<<ch<<" ";
            }
            cout<<endl;
        }

        solveSudoku(board);

        for(vector<char> vec : board) {
            for (char ch : vec) {
                cout<<ch<<" ";
            }
            cout<<endl;
        }
    }

private:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) {
            return true;
        }

        if (j == 9) {
            return solve(board, i + 1, 0);
        }

        if (board[i][j] != '.') {
            return solve(board, i, j + 1);
        }

        for (char k = '1'; k <= '9'; ++k) {
            if (check(board, i, j, k)) {
                board[i][j] = k;
                if (solve(board, i, j + 1)) {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, int row, int col, char value) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == value)
                return false;

            if (board[i][col] == value)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
                return false;
        }
        return true;
    }
};

#endif //ALGORITHM_SUDOKUSOLVER_H
