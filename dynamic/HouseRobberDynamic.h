//
// Created by Yory on 2019/2/6.
//

#ifndef ALGORITHM_HOUSEROBBERDYNAMIC_H
#define ALGORITHM_HOUSEROBBERDYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class HouseRobberDynamic {
public:
    void test() {
//        vector<int> nums{1,2,3,1};
        vector<int> nums{2,7,9,3,1};
        cout<<rob(nums)<<endl;
    }

private:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> memo = vector<int>(nums.size(), -1);

        memo[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                int temp = nums[j] + (j + 2 < n ? memo[j + 2] : 0);
                memo[i] = max(memo[i], temp);
            }
        }
        return memo[0];
    }
};

#endif //ALGORITHM_HOUSEROBBERDYNAMIC_H
