//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_ROTATEIMAGE_H
#define ALGORITHM_ROTATEIMAGE_H

#include <iostream>
#include <vector>
using namespace std;

class RotateImage {
public:
    void test() {
        vector<vector<int>> matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

/*        vector<vector<int>> matrix = {
                {5, 1, 9,11},
                {2, 4, 8,10},
                {13, 3, 6, 7},
                {15,14,12,16}
        };*/

        rotateII(matrix);

        for (vector<int> vec : matrix) {
            for (int i : vec) {
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }

private:
    void rotate(vector<vector<int>>& matrix) {
        const int size = matrix.size() - 1;
        int end = matrix.size() - 1;
        vector<int> temp(end, 0);

        for (int i = 0; i < matrix.size() / 2; ++i) {

            //copy the value
            int index = 0;
            for (int k = i; k < end; ++k, ++index) {
                temp[index] = matrix[i][k];
            }

            //rotate left
            for (int k = i; k < end; ++k) {
                matrix[i][k] = matrix[size - k][i];
            }

            //rotate bottom
            for (int k = i; k < end; ++k) {
                matrix[k + 1][i] = matrix[end][k + 1];
            }

            //rote right
            for (int k = i; k < end; ++k) {
                matrix[end][k + 1] = matrix[size - k - 1][end];
            }

            --index;
            for (int k = i; k < end; ++k, --index) {
                matrix[size - k - 1][end] = temp[index];
            }

            --end;
        }
    }

    void rotateII(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0, b = n - 1;
        while (a < b) {
            for (int i = 0; i < b - a; ++i) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            ++a;
            --b;
        }
    }
};

#endif //ALGORITHM_ROTATEIMAGE_H
