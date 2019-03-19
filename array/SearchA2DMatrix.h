//
// Created by Yory on 2019/3/19.
//

#ifndef ALGORITHM_SEARCHA2DMATRIX_H
#define ALGORITHM_SEARCHA2DMATRIX_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SearchA2DMatrix {
public:
    void test() {
/*        int target = 0;
        vector<vector<int>> matrix{
                {1},
        };*/

        int target = 5;
        vector<vector<int>> matrix{
                {1,   3,  5,  7},
                {10, 11, 16, 20},
                {23, 30, 34, 50}
        };

/*        int target = 16;
        vector<vector<int>> matrix{
        {-10,-8},{-6,-5},{-2,-2},{-1,0},{3,4},{7,7},{8,9},{10,10},
                {11,11},
                {12,14},
                {15,16},
                {17,19},
                {20,21},
        {22,22},{25,27},{28,30},{32,32},{35,36}
        };*/

        cout<<"res: "<<searchMatrixII(matrix, target);
    }

private:
    bool searchMatrixII(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }

        int left = 0;
        int right = row * col - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            (matrix[mid / col][mid % col] < target) ? (left = mid + 1) : (right = mid);
        }
        return matrix[left / col][left % col] == target;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = searchRow(matrix, target);
        cout<<"row: "<<row<<endl;
        return binary_search(matrix[row].begin(), matrix[row].begin() + matrix[0].size(), target);
    }

    int searchRow(vector<vector<int>>& matrix, int target) {
        int begin = 0;
        int end = matrix.size() - 1;
        int mid;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if (matrix[mid][0] == target) {
                return mid;
            } else if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return begin == 0 ? 0 : begin - 1;
    }

};


#endif //ALGORITHM_SEARCHA2DMATRIX_H
