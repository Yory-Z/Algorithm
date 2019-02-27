//
// Created by Yory on 2019/2/7.
//

#ifndef ALGORITHM_LONGESTINCREASINGSUBSEQUENCE_H
#define ALGORITHM_LONGESTINCREASINGSUBSEQUENCE_H

#include <vector>
#include <iostream>
using namespace std;

class LongestIncreasingSubsequence {
public:
    void test() {
        vector<int> nums{10,9,2,5,3,7,101,18};
        cout<<lengthOfLIS(nums)<<endl;
    }

private:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> memo = vector<int>(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && memo[i] < memo[j] + 1)
                    memo[i] = memo[j] + 1;
            }
        }

        int maxIndex = 0;
        for (int k = 1; k < n; ++k) {
            if (memo[maxIndex] < memo[k]){
                maxIndex = k;
            }
        }
        return memo[maxIndex];
    }

};

#endif //ALGORITHM_LONGESTINCREASINGSUBSEQUENCE_H
