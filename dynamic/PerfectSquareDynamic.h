//
// Created by Yory on 2019/2/6.
//

#ifndef ALGORITHM_PERFECTSQUAREDYNAMIC_H
#define ALGORITHM_PERFECTSQUAREDYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class PerfectSquareDynamic {
public:
    void test() {
        int n = 57;
        cout<<numSquares(n);
    }

private:
    int numSquares(int n) {
        vector<int> memo = vector<int>(n + 1, n);

        memo[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                memo[i] = min(memo[i], 1 + memo[i - j * j]);
            }
        }
        return memo[n];
    }


};

#endif //ALGORITHM_PERFECTSQUAREDYNAMIC_H
