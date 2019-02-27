//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_CLIMBINGSTAIRSDYNAMIC_H
#define ALGORITHM_CLIMBINGSTAIRSDYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class ClimbingStairsDynamic {
public:
    void test() {
        for (int i = 1; i < 10; ++i) {
            cout<<climbStairs(i)<<endl;
        }
    }

private:
    vector<int> memory;

    int climbStairs(int n) {
        memory = vector<int>(n + 1, -1);
        memory[1] = 1;
        memory[2] = 2;
        for(int i = 3; i <= n; ++i){
            memory[i] = memory[i - 1] + memory[i - 2];
        }
        return memory[n];
    }
};

#endif //ALGORITHM_CLIMBINGSTAIRSDYNAMIC_H
