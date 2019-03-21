//
// Created by Yory on 2019/3/21.
//

#ifndef ALGORITHM_SUBSETSTRACKBACK_H
#define ALGORITHM_SUBSETSTRACKBACK_H

#include <vector>
#include <iostream>
using namespace std;

class SubsetsTrackBack {
public:
    void test() {
        vector<int> nums{1,2,3};
        subsets(nums);

        for (vector<int> vec : ans) {
            for (int i : vec) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }

private:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSet;
        trackBack(nums, 0, curSet);
        return ans;
    }

    void trackBack(vector<int>& nums, int i, vector<int>& curSet) {
        if (i == nums.size()) {
            ans.push_back(curSet);
            return;
        }

        curSet.push_back(nums[i]);
        trackBack(nums, i + 1, curSet);
        curSet.pop_back();

        trackBack(nums, i + 1, curSet);
    }
};


#endif //ALGORITHM_SUBSETSTRACKBACK_H
