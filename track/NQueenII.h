//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_NQUEENII_H
#define ALGORITHM_NQUEENII_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class NQueenII {
public:
    void test();

private:
    vector<bool> col, dia1, dia2;
    int res;

    int totalNQueens(int n);
    void putQueen(int index, int n, vector<int>& row);
};

void NQueenII::test() {
    int n = 8;
    totalNQueens(n);
    cout<<"res: "<<res;
}

int NQueenII::totalNQueens(int n) {
    col = vector<bool>(n, false);
    dia1 = vector<bool>(2 * n - 1, false);
    dia2 = vector<bool>(2 * n - 1, false);
    res = 0;

    vector<int> row;
    putQueen(0, n, row);
    return res;
}

void NQueenII::putQueen(int index, int n, vector<int>& row) {
    if (index == n) {
        ++res;
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

#endif //ALGORITHM_NQUEENII_H
