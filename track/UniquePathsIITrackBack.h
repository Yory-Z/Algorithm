//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_UNIQUEPATHSIITRACKBACK_H
#define ALGORITHM_UNIQUEPATHSIITRACKBACK_H

#include <iostream>
#include <vector>
using namespace std;

class UniquePathsIITrackBack {
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

        cout<<uniquePathsWithObstacles(obstacleGrid);
    }

private:
    int ans;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ans = 0;
        if (obstacleGrid.empty() || obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1) {
            return ans;
        }
        unique(0, 0, obstacleGrid);
        return ans;
    }

    void unique(int i, int j, vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[i][j] == 1) {
            return;
        }

        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            ++ans;
            return;
        }

        if (i < obstacleGrid.size() - 1) {
            unique(i + 1, j, obstacleGrid);
        }
        if (j < obstacleGrid[0].size() -1) {
            unique(i, j + 1, obstacleGrid);
        }
    }
};

#endif //ALGORITHM_UNIQUEPATHSIITRACKBACK_H
