//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_NQUEEN_H
#define ALGORITHM_NQUEEN_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class NQueen {
public:
    void test();

private:
    vector<bool> col, dia1, dia2;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n);
    void putQueen(int index, int n, vector<int>& row);
    vector<string> generateBoard(int n, vector<int>& row);
};

void NQueen::test() {
    int n = 4;
    res = solveNQueens(n);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res.at(i).size(); ++j) {
            cout<<res.at(i).at(j)<<endl;
        }
        cout<<endl;
    }
}

vector<vector<string>> NQueen::solveNQueens(int n) {
    col = vector<bool>(n, false);
    dia1 = vector<bool>(2 * n - 1, false);
    dia2 = vector<bool>(2 * n - 1, false);

    vector<int> row;
    putQueen(0, n, row);
    return res;
}

void NQueen::putQueen(int index, int n, vector<int>& row) {
    if (index == n) {
        res.push_back(generateBoard(n, row));
    }

    for (int i = 0; i < n; ++i) {
        if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
            col[i] = true;
            dia1[index + i] = true;
            dia2[index - i + n - 1] = true;
            row.push_back(i);

            putQueen(index + 1, n, row);

            row.pop_back();
            col[i] = false;
            dia1[index + i] = false;
            dia2[index - i + n - 1] = false;
        }
    }
}

vector<string> NQueen::generateBoard(int n, vector<int>& row) {
    vector<string> board(n, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        board[i][row[i]] = 'Q';
    }
    return board;
}

#endif //ALGORITHM_NQUEEN_H
