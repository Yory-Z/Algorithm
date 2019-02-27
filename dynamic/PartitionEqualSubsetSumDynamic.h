//
// Created by Yory on 2019/2/16.
//

#ifndef ALGORITHM_PARTITIONEQUALSUBSETSUMDYNAMIC_H
#define ALGORITHM_PARTITIONEQUALSUBSETSUMDYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class PartitionEqualSubsetSumDynamic {
public:
    void test() {
        //        vector<int> nums{1, 5, 11, 5};
        vector<int> nums{1, 2, 3, 5};
//        vector<int> nums{3,3,3,4,5};

        cout<<canPartitionII(nums);
    }

private:
    bool canPartition(vector<int>& nums){
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

        int target = sum / 2;
        vector<vector<bool>> memo = vector<vector<bool>>(nums.size(), vector<bool>(target + 1, false));
        for (int j = 0; j <= target; ++j) {
            memo[0][j] = nums[0] == j;
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                memo[i][j] = memo[i - 1][j];
                if (j >= nums[i]) {
                    memo[i][j] = memo[i][j] || memo[i - 1][j - nums[i]];
                }
            }
        }
        return memo[nums.size() - 1][target];
    }

    bool canPartitionII(vector<int>& nums){
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

        int target = sum / 2;
        vector<bool> memo = vector<bool>(target + 1, false);
        for (int j = 0; j <= target; ++j) {
            memo[j] = nums[0] == j;
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                memo[j] = memo[j] || memo[j - nums[i]];
            }
        }
        return memo[target];
    }

};


#endif //ALGORITHM_PARTITIONEQUALSUBSETSUMDYNAMIC_H
