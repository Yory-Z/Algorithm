//
// Created by Yory on 2019/2/25.
//

#ifndef ALGORITHM_UNIQUEPATHS_H
#define ALGORITHM_UNIQUEPATHS_H

#include <iostream>
#include <vector>
using namespace std;

class UniquePathsDynamic {
public:
    void test() {
        int m = 51;
        int n = 9;

//        cout<<uniquePaths(m, n)<<endl;
        cout<<uniquePathsII(m, n)<<endl;
        cout<<uniquePathsIII(m, n)<<endl;
    }

private:
    int uniquePathsIII(int m, int n) {
        vector<int> memo(m, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                memo[j] += memo[j - 1];
            }
        }
        return memo[m - 1];
    }

    int uniquePathsII(int m, int n) {
        vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            memo[0][i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            memo[i][0] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
        return memo[n - 1][m - 1];
    }


};

#endif //ALGORITHM_UNIQUEPATHS_H
