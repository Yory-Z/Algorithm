//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_PERMUTATIONII_H
#define ALGORITHM_PERMUTATIONII_H

#include <vector>
#include <set>
#include <iostream>
using namespace std;

class PermutationII {
public:
    void test();

private:
    set<vector<int>> res;
    vector<bool> used;

    vector<vector<int>> permuteUnique(vector<int>& nums);
    void trackBack(vector<int>& nums, vector<int> &solve);
};

void PermutationII::test() {
    vector<int> nums{1, 1, 3};

    vector<vector<int>> tempRes = permuteUnique(nums);
    for (vector<int> &vec : tempRes) {
        for (int i : vec) {
            cout<<i<<' ';
        }
        cout<<endl;
    }

}

vector<vector<int>> PermutationII::permuteUnique(vector<int>& nums) {
    used = vector<bool>(nums.size(), false);

    vector<int> solve;
    trackBack(nums, solve);
    return vector<vector<int>>(res.cbegin(), res.cend());
}

void PermutationII::trackBack(vector<int>& nums, vector<int> &solve) {
    if (solve.size() == nums.size()) {
        res.insert(solve);
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

#endif //ALGORITHM_PERMUTATIONII_H
