//
// Created by Yory on 2019/2/22.
//

#ifndef ALGORITHM_SPIRALMATRIXII_H
#define ALGORITHM_SPIRALMATRIXII_H

#include <iostream>
#include <vector>
using namespace std;

class SpiralMatrixII {
public:
    void test() {
        int n = 5;

        vector<vector<int>> res = generateMatrix(n);
        for (vector<int> vec : res) {
            for (int i : vec) {
                cout<<i<<' ';
            }
            cout<<endl;
        }
    }

private:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n));

        int value = 0;
        while (r1 <= r2 && c1 <= c2) {
            //insert top
            for (int i = c1; i <= c2; ++i) {
                matrix[r1][i] = ++value;
            }

            //insert right
            for (int i = r1 + 1; i < r2; ++i) {
                matrix[i][c2] = ++value;
            }

            //insert bottom
            for (int i = c2; i > c1; --i) {
                matrix[r2][i] = ++value;
            }

            //insert left
            for (int i = r2; i > r1; --i) {
                matrix[i][c1] = ++value;
            }

            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return matrix;
    }
};

#endif //ALGORITHM_SPIRALMATRIXII_H
