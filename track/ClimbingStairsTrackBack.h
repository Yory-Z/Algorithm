//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_CLIMBINGSTAIRSTRACKBACK_H
#define ALGORITHM_CLIMBINGSTAIRSTRACKBACK_H

#include <vector>
#include <iostream>
using namespace std;

class ClimbingStairsTrackBack {
public:
    void test();

private:
    vector<int> memory;
    int climbStairsTrackBack(int n) {
        memory = vector<int>(n + 1, -1);
        return trackBack(n);
    }

    int trackBack(int n) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        if (memory[n] == -1){
            memory[n] = trackBack(n - 1) + trackBack(n - 2);
        }
        return memory[n];
    }
};

void ClimbingStairsTrackBack::test() {
    for (int i = 1; i < 10; ++i) {
        cout<<climbStairsTrackBack(i)<<endl;
    }
}


#endif //ALGORITHM_CLIMBINGSTAIRSTRACKBACK_H
