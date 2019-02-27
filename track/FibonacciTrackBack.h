//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_FIBONACCITRACKBACK_H
#define ALGORITHM_FIBONACCITRACKBACK_H

#include <iostream>
#include <vector>
using namespace std;

class FibonacciTrackBack {
public:
    void test(double n) {
        cout<<fibonacci(n)<<endl;
    }

private:
    double fibonacci(double n) {
        return trackBack(n);
    }

    double trackBack(double i) {
        //end condition 1
        if (i == 0) {
            return 0;
        }
        //end condition 2
        if (i == 1) {
            return 1;
        }

        return trackBack(i - 1) + trackBack(i - 2);
    }
};

#endif //ALGORITHM_FIBONACCITRACKBACK_H
