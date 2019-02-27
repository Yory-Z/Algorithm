//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_FIRSTMISSINGPOSITIVE_H
#define ALGORITHM_FIRSTMISSINGPOSITIVE_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FirstMissingPositive {
public:
    void test() {
//        vector<int> nums{1, 2, 0};
//        vector<int> nums{3, 4, -1, 1};
//        vector<int> nums{7, 8, 9, 11, 12};
//        vector<int> nums{-5};
//        vector<int> nums{1};
//        vector<int> nums{1, 2};
        vector<int> nums{-1,4,2,1,9,10};

        cout<<firstMissingPositiveII(nums);
    }

private:
    int firstMissingPositive(vector<int>& nums) {
        for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
            if (*it <= 0) {
                nums.erase(it);
            } else {
                ++it;
            }
        }

        int len = nums.size();
        if (len == 0) {
            return 1;
        } else if(len == 1 && nums[0] == 1) {
            return 2;
        } else if(len == 1 && nums[0] > 1) {
            return 1;
        }

        for (int i = 0; i < len; ++i) {
            int temp = abs(nums[i]) - 1;
            if (temp < len && temp >= 0) {
                nums[temp] = nums[temp] > 0 ? -nums[temp] : nums[temp];
            }
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return len + 1;
    }

    int firstMissingPositiveII(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }

};

#endif //ALGORITHM_FIRSTMISSINGPOSITIVE_H
