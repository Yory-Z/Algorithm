//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_UNIQUEPATHSII_H
#define ALGORITHM_UNIQUEPATHSII_H

#include <vector>
#include <iostream>
using namespace std;

class UniquePathsIIDynamic {
public:
    void test() {
        vector<vector<int>> obstacleGrid{
                {0,0,0},
                {0,1,0},
                {0,0,0}
        };

//        vector<vector<int>> obstacleGrid;
//        vector<vector<int>> obstacleGrid{{0,0}};
//        vector<vector<int>> obstacleGrid{{0}};
//        vector<vector<int>> obstacleGrid{{1, 0}};
//        vector<vector<int>> obstacleGrid{{0, 1}};
//        vector<vector<int>> obstacleGrid{{1},{0}};
//        vector<vector<int>> obstacleGrid{{0},{1}};
//        vector<vector<int>> obstacleGrid{{0},{0}};

        cout<<uniquePathsWithObstaclesII(obstacleGrid)<<endl;
        cout<<uniquePathsWithObstaclesIII(obstacleGrid)<<endl;
    }

private:
    //this will cause int memory overflow
    int uniquePathsWithObstaclesIII(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;

        for (int i = 1; i < col; ++i) {
            obstacleGrid[0][i] = obstacleGrid[0][i - 1] == 1 && obstacleGrid[0][i] == 0 ? 1 : 0;
        }

        for (int i = 1; i < row; ++i) {
            obstacleGrid[i][0] = obstacleGrid[i - 1][0] == 1 && obstacleGrid[i][0] == 0 ? 1 : 0;

        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[row - 1][col - 1];
    }

    int uniquePathsWithObstaclesII(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long>> memo = vector<vector<long>>(row, vector<long>(col, 0));
        memo[0][0] = 1;

        for (int i = 1; i < col; ++i) {
            memo[0][i] = memo[0][i - 1] == 1 ? obstacleGrid[0][i] ^ 1 : 0;
        }

        for (int i = 1; i < row; ++i) {
            memo[i][0] = memo[i - 1][0] == 1 ? obstacleGrid[i][0] ^ 1 : 0;
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
                } else {
                    memo[i][j] = 0;
                }
            }
        }
        return memo[row - 1][col - 1];
    }



};

#endif //ALGORITHM_UNIQUEPATHSII_H
