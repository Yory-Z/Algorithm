//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_FINDALLNUMBERSDISAPPEARED_H
#define ALGORITHM_FINDALLNUMBERSDISAPPEARED_H

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class FindAllNumbersDisappeared {
public:
    void test() {
        vector<int> nums{4,3,2,7,8,2,3,1};

        vector<int> res = findDisappearedNumbersII(nums);
        for (int i : res) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

private:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i = 1; i <= nums.size(); ++i) {
            mySet.insert(i);
        }

        for(int i : nums) {
            if (mySet.find(i) != mySet.end()) {
                mySet.erase(i);
            }
        }

        return vector<int>(mySet.cbegin(), mySet.cend());
    }

    vector<int> findDisappearedNumbersII(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }

};

#endif //ALGORITHM_FINDALLNUMBERSDISAPPEARED_H
