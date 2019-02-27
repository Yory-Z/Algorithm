//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_MINIMUMPATHSUMDYNAMIC_H
#define ALGORITHM_MINIMUMPATHSUMDYNAMIC_H

#include <iostream>
#include <vector>
using namespace std;

class MinimumPathSumDynamic {
public:
    void test() {
        vector<vector<int>> grid{
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
        };

        cout<<minPathSum(grid)<<endl;
        cout<<minPathSumII(grid)<<endl;
        cout<<minPathSumIII(grid)<<endl;
    }

private:
    int minPathSumIII(vector<vector<int>>& grid)  {
        if (grid.empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();

        for (int i = 1; i < col; ++i) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < row; ++i) {
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < col; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }

    int minPathSumII(vector<vector<int>>& grid)  {
        if (grid.empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();

        vector<int> memo = vector<int>(col, 0);
        memo[0] = grid[0][0];
        for (int i = 1; i < col; ++i) {
            memo[i] = memo[i - 1] + grid[0][i];
        }

        for (int i = 1; i < row; ++i) {
            memo[0] += grid[i][0];
            for (int j = 1; j < col; ++j) {
                memo[j] = min(memo[j], memo[j - 1]) + grid[i][j];
            }
        }
        return memo[col - 1];
    }

    int minPathSum(vector<vector<int>>& grid)  {
        if (grid.empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> memo = vector<vector<int>>(row, vector<int>(col, 0));
        memo[0][0] = grid[0][0];
        for (int i = 1; i < col; ++i) {
            memo[0][i] = memo[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < row; ++i) {
            memo[i][0] = memo[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + grid[i][j];
            }
        }
        return memo[row - 1][col - 1];
    }
};

#endif //ALGORITHM_MINIMUMPATHSUMDYNAMIC_H
