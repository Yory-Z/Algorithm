//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_MINIMUMPATHSUMTRACKBACK_H
#define ALGORITHM_MINIMUMPATHSUMTRACKBACK_H

#include <iostream>
#include <vector>
using namespace std;

class MinimumPathSumTrackBack {
public:
    void test() {
        vector<vector<int>> grid{
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
        };

        cout<<minPathSum(grid)<<endl;

    }

private:
    int bestSum;
    int minPathSum(vector<vector<int>>& grid) {
        bestSum = INT32_MAX;
        minPath(grid, 0, 0, grid[0][0]);
        return bestSum;
    }

    void minPath(vector<vector<int>>& grid, int i, int j, int currentSum) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            if (currentSum < bestSum) {
                bestSum = currentSum;
            }
            return;
        }

        if (i < grid.size() - 1 && currentSum + grid[i + 1][j] < bestSum) {
            minPath(grid, i + 1, j, currentSum + grid[i + 1][j]);
        }

        if (j < grid[0].size() - 1 && currentSum + grid[i][j + 1] < bestSum) {
            minPath(grid, i, j + 1, currentSum + grid[i][j + 1]);
        }
    }
};

#endif //ALGORITHM_MINIMUMPATHSUMTRACKBACK_H
