//
// Created by Yory on 2019/2/7.
//

#ifndef ALGORITHM_PARTITIONEQUALSUBSETSUMTRACKBACK_H
#define ALGORITHM_PARTITIONEQUALSUBSETSUMTRACKBACK_H

#include <vector>
#include <iostream>
using namespace std;

class PartitionEqualSubsetSumTrackBack {
public:
    void test(){
//        vector<int> nums{1, 5, 11, 5};
        vector<int> nums{1, 2, 3, 5};
//        vector<int> nums{3,3,3,4,5};

        cout<<canPartition(nums);
    }

private:
    //-1 meas haven't been calculated
    //0 meas false, 1 meas true
    vector<vector<int>> memo;

    bool canPartition(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
        return tryPartition(nums, nums.size() - 1, sum / 2);
    }

    bool tryPartition(vector<int>& nums, int index, int target) {
        if (target == 0){
            return true;
        }

        if (target < 0 || index < 0) {
            return false;
        }

        if (memo[index][target] != -1) {
            return memo[index][target] == 1;
        }

        memo[index][target] = (tryPartition(nums, index - 1, target) ||
                tryPartition(nums, index - 1, target - nums[index])) ? 1 : 0;
        return memo[index][target] == 1;
    }

};

#endif //ALGORITHM_PARTITIONEQUALSUBSETSUMTRACKBACK_H
