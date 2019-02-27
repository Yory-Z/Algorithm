//
// Created by Yory on 2019/2/21.
//

#ifndef ALGORITHM_MAXIMUMSUBARRAY_H
#define ALGORITHM_MAXIMUMSUBARRAY_H

#include <iostream>
#include <vector>
using namespace std;

class MaximumSubarray {
public:
    void test() {
        vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
//        vector<int> nums{-2};

        cout << maxSubArrayDynamic(nums)<<endl;
        cout << maxSubArrayDynamicII(nums)<<endl;
    }

private:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int bestSum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int tempSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                tempSum += nums[j];
                if (tempSum > bestSum) {
                    bestSum = tempSum;
                }
            }
        }
        return bestSum;
    }

    int maxSubArrayDynamic(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        memo[0] = nums[0];
        int res = memo[0];

        for (int i = 1; i < nums.size(); ++i) {
            memo[i] = nums[i] + (memo[i - 1] > 0 ? memo[i - 1] : 0);
            res = max(res, memo[i]);
        }
        return res;
    }

    int maxSubArrayDynamicII(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i] + (nums[i - 1] > 0 ? nums[i - 1] : 0);
            res = max(res, nums[i]);
        }
        return res;
    }
};

#endif //ALGORITHM_MAXIMUMSUBARRAY_H
