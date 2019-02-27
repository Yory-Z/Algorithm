//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_FIBONACCITRACKBACKII_H
#define ALGORITHM_FIBONACCITRACKBACKII_H

#include <iostream>
#include <vector>
using namespace std;

class FibonacciTrackBackII {
public:
    void test(double n) {
        cout<<fibonacci(n)<<endl;
    }

private:
    vector<double> memo;
    double fibonacci(double n) {
        memo = vector<double>(n + 1, -1);
        return trackBackII(n);
    }

    double trackBackII(double i) {
        //end condition 1
        if (i == 0) {
            return 0;
        }
        //end condition 2
        if (i == 1) {
            return 1;
        }

        //if have the solution in i, return it
        if (memo[i] != -1) {
            return memo[i];
        }

        //keep the solution
        memo[i] = trackBackII(i - 1) + trackBackII(i - 2);
        return memo[i];
    }
};

#endif //ALGORITHM_FIBONACCITRACKBACKII_H
