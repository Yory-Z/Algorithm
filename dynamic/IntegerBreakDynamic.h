//
// Created by Yory on 2019/2/6.
//

#ifndef ALGORITHM_INTEGERBREAKDYNAMIC_H
#define ALGORITHM_INTEGERBREAKDYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class IntegerBreakDynamic {
public:
    void test() {
        int n = 10;
        cout<<integerBreak(n)<<endl;
    }

private:
    int integerBreak(int n) {
        vector<int> memo = vector<int>(n + 1, 0);
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                memo[i] = max(j * max(memo[i - j], (i - j)), memo[i]);
            }
        }
        return memo[n];
    }
};

#endif //ALGORITHM_INTEGERBREAKDYNAMIC_H
