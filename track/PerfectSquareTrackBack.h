//
// Created by Yory on 2019/2/6.
//

#ifndef ALGORITHM_PERFECTSQUARETRACKBACK_H
#define ALGORITHM_PERFECTSQUARETRACKBACK_H

#include <iostream>
using namespace std;

class PerfectSquareTrackBack {
public:
    void test() {
        int n = 13;
        cout<<numSquares(n);
    }

private:
    int bestSum;
    int numSquares(int n) {
        bestSum = n;
        trackBack(n, 0);
        return bestSum;
    }

    void trackBack(int rest, int currentNum) {
        if (rest == 0){
            if (currentNum < bestSum) {
                bestSum = currentNum;
            }
            return;
        }

        for (int i = 1; i * i <= rest; ++i) {
            trackBack(rest - i * i, currentNum + 1);
        }
    }

};


#endif //ALGORITHM_PERFECTSQUARETRACKBACK_H
