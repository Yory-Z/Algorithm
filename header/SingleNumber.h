//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_SINGLENUMBER_H
#define ALGORITHM_SINGLENUMBER_H

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class SingleNumber {
public:
    void test() {
        vector<int> vec{1,2,2};
//        vector<int> vec{4,1,2,1,2};
        cout<<singleNumberIIII(vec);
    }

private:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i = 0; i < nums.size(); ++i) {
            if (mySet.find(nums[i]) != mySet.end()){
                mySet.erase(nums[i]);
            } else {
                mySet.insert(nums[i]);
            }
        }
        return *mySet.begin();
    }

    int singleNumberII(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (myMap[nums[i]] == 1)
                myMap.erase(nums[i]);
            else
                ++myMap[nums[i]];
        }
        return myMap.begin()->first;
    }

    int singleNumberIII(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }

    int singleNumberIIII(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }

};

#endif //ALGORITHM_SINGLENUMBER_H
