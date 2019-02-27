//
// Created by Yory on 2019/2/6.
//

#ifndef ALGORITHM_INTEGERBREAKTRACKBACK_H
#define ALGORITHM_INTEGERBREAKTRACKBACK_H

#include <vector>
#include <iostream>
using namespace std;

class IntegerBreakTrackBack {
public:
    void test() {
        int n = 10;
        cout<<integerBreak(n)<<endl;
    }

private:
    vector<int> memo;
    int integerBreak(int n) {
        memo = vector<int>(n + 1, -1);
        int res = trackBack(n);
        return res;
    }

    int trackBack(int n) {
        if (n == 1){
            return 1;
        }

        if (memo[n] != -1){
            return memo[n];
        }

        int res = -1;
        for (int i = 1; i < n; ++i) {
            res = max(res, max(i * (n - i), i * trackBack(n - i)));
        }
        memo[n] = res;

        return res;
    }

};

#endif //ALGORITHM_INTEGERBREAKTRACKBACK_H
