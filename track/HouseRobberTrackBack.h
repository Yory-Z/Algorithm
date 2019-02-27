//
// Created by Yory on 2019/2/6.
//

#ifndef ALGORITHM_HOUSEROBBERTRACKBACK_H
#define ALGORITHM_HOUSEROBBERTRACKBACK_H

#include <vector>
#include <iostream>
using namespace std;

class HouseRobberTrackBack {
public:
    void test(){
//        vector<int> nums{1,2,3,1};
        vector<int> nums{2,7,9,3,1};
        cout<<rob(nums)<<endl;
    }

private:
    vector<int> memo;
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        memo = vector<int>(n, -1);
        for (int i = 0; i < n; ++i) {
            memo[i] = tryRob(i, nums);
        }
        return memo[n-1];
    }

    int tryRob(int index, vector<int>& nums) {
        if (index == 0) {
            return nums[0];
        }

        if (memo[index] != -1){
            return memo[index];
        }

        int res = -1;
        for (int i = index; i >= 0; --i) {
            int temp = nums[i] + (i - 2 >= 0 ? memo[i - 2] : 0);
            res = max(res, temp);
        }
        memo[index] = res;
        return res;
    }

};

#endif //ALGORITHM_HOUSEROBBERTRACKBACK_H
