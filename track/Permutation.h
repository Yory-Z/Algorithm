//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_PERMUTATION_H
#define ALGORITHM_PERMUTATION_H

#include <vector>
#include <iostream>
using namespace std;

class Permutation {
public:
    void test() {
        vector<int> nums{1, 2, 3, 4, 5};

        permute(nums);

        int index = 1;
        for (int i = 0; i < res.size(); ++i) {
            cout<<index++<<": ";
            for (int j = 0; j < res.at(i).size(); ++j) {
                cout<<res.at(i).at(j)<<' ';
            }
            cout<<endl;
        }
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);

        vector<int> solve;
        trackBack(nums, solve);
        return res;
    }
    void trackBack(vector<int>& nums, vector<int> &solve) {
        if (solve.size() == nums.size()) {
            res.push_back(solve);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                solve.push_back(nums[i]);
                trackBack(nums, solve);
                solve.pop_back();
                used[i] = false;
            }
        }
    }
};

#endif //ALGORITHM_PERMUTATION_H
