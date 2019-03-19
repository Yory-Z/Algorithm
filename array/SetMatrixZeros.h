//
// Created by Yory on 2019/3/19.
//

#ifndef ALGORITHM_SETMATRIXZEROS_H
#define ALGORITHM_SETMATRIXZEROS_H

#include <vector>
#include <iostream>
using namespace std;

class SetMatrixZeros {
public:
    void test() {
        vector<vector<int>> matrix{
        {1,1,1},
        {1,0,1},
        {1,1,1}
        };

/*        vector<vector<int>> matrix{
                {0,1,2,0},
                {3,4,5,2},
                {1,3,1,5}
        };*/

        cout<<"before: "<<endl;
        for (vector<int> vec : matrix) {
            for (int i : vec) {
                cout<<i<<' ';
            }
            cout<<endl;
        }

        setZeroes(matrix);

        cout<<"after: "<<endl;
        for (vector<int> vec : matrix) {
            for (int i : vec) {
                cout<<i<<' ';
            }
            cout<<endl;
        }
    }

private:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }

        vector<bool> memo(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); ++i) {
            bool hasZero = false;
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    hasZero = true;
                    memo[j] = true;
                }
            }
            if (hasZero) {
                for (int k = 0; k < matrix[i].size(); ++k) {
                    matrix[i][k] = 0;
                }
            }
        }

        for (int l = 0; l < memo.size(); ++l) {
            if (memo[l]) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][l] = 0;
                }
            }
        }
    }


};


#endif //ALGORITHM_SETMATRIXZEROS_H
