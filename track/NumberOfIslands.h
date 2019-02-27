//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_NUMBEROFISLANDS_H
#define ALGORITHM_NUMBEROFISLANDS_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class NumberOfIslands {
public:
    void test();

private:
    int row, col;
    vector<vector<bool>> visited;
    int dire[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row == 0) {
            return 0;
        }
        col = grid[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));

        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!visited[i][j] && grid[i][j] == '1'){
                    ++res;
                    depthFirstSearch(grid, i, j);
                }
            }
        }
        return res;
    }

    void depthFirstSearch(vector<vector<char>>& grid, int startX, int startY) {
        visited[startX][startY] = true;
        for (int i = 0; i < 4; ++i) {
            int newX = startX + dire[i][0];
            int newY = startY + dire[i][1];

            if (inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') {
                depthFirstSearch(grid, newX, newY);
            }
        }
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }
};

void NumberOfIslands::test() {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };

//    vector<vector<char>> grid;

    int res = numIslands(grid);
    cout<<"res: "<<res<<endl;
}

#endif //ALGORITHM_NUMBEROFISLANDS_H
