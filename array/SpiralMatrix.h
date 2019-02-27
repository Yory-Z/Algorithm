//
// Created by Yory on 2019/2/21.
//

#ifndef ALGORITHM_SPIRALMATRIX_H
#define ALGORITHM_SPIRALMATRIX_H

#include <vector>
#include <iostream>
using namespace std;

class SpiralMatrix {
public:
    void test() {
/*        vector<vector<int>> matrix = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
        };*/

        vector<vector<int>> matrix = {
                { 1, 2, 3, 4 },
                { 5, 6, 7, 8 },
                { 9,10,11,12 }
        };

        vector<int> res = spiralOrder(matrix);
        for (int i : res) {
            cout<<i<<" ";
        }
        cout<<endl;

        vector<int> res2 = spiralOrderII(matrix);
        for (int i : res2) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

private:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        int dirR[] = {0, 1, 0, -1};
        int dirC[] = {1, 0, -1, 0};
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        int end = row * col;

        int curR = 0, curC = 0;
        int dir = 0;
        for (int i = 0; i < end; ++i) {
            visit[curR][curC] = true;
            res.push_back(matrix[curR][curC]);
            int nextR = curR + dirR[dir];
            int nextC = curC + dirC[dir];

            if (nextR >= 0 && nextR < row &&
                nextC >= 0 && nextC < col && !visit[nextR][nextC]) {
                curR = nextR;
                curC = nextC;
            } else {
                dir = (dir + 1) % 4;
                curR += dirR[dir];
                curC += dirC[dir];
            }
        }
        return res;
    }

    vector<int> spiralOrderII(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        while (r1 <= r2 && c1 <= c2) {
            //copy top
            for (int i = c1; i <= c2; ++i) {
                res.push_back(matrix[r1][i]);
            }

            //copy right
            for (int i = r1 + 1; i <= r2; ++i) {
                res.push_back(matrix[i][c2]);
            }

            if (r1 < r2 && c1 < c2) {
                //copy bottom
                for (int i = c2 - 1; i > c1; --i) {
                    res.push_back(matrix[r2][i]);
                }

                //copy left
                for (int i = r2; i > r1; --i) {
                    res.push_back(matrix[i][r1]);
                }
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return res;
    }
};

#endif //ALGORITHM_SPIRALMATRIX_H
