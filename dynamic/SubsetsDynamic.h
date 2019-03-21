//
// Created by Yory on 2019/3/21.
//

#ifndef ALGORITHM_SUBSETSDYNAMIC_H
#define ALGORITHM_SUBSETSDYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class SubsetsDynamic {
public:
    void test() {
        vector<int> nums{1,2,3};
        vector<vector<int>> res = subsets(nums);
        for (vector<int> vec : res) {
            for (int i : vec) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }

private:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{vector<int>()};
        for (int num : nums) {
            int n = res.size();
            for (int i = 0; i < n; ++i) {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }

};

#endif //ALGORITHM_SUBSETSDYNAMIC_H
