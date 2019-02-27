//
// Created by Yory on 2019/2/16.
//

#ifndef ALGORITHM_MISSINGNUMBER_H
#define ALGORITHM_MISSINGNUMBER_H

#include <iostream>
#include <vector>
using namespace std;

class MissingNumber {
public:
    void test() {
        vector<int> nums{9,6,4,2,3,5,7,0,1};

        cout<<missingNumber(nums);
    }

private:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};

#endif //ALGORITHM_MISSINGNUMBER_H
