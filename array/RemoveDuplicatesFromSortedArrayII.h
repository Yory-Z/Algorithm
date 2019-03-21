//
// Created by Yory on 2019/3/19.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAYII_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAYII_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class RemoveDuplicatesFromSortedArrayII {
public:
    void test() {
        vector<int> nums{1,1,1,2,2,3};
//        vector<int> nums{0,0,1,1,1,1,2,3,3};
//        vector<int> nums{1,2,2,2};
//        vector<int> nums{1,1,1,2,2,2,3,3};

        cout<<"before: "<<endl;
        for (int i : nums) {
            cout<<i<<" ";
        }
        cout<<endl;

        cout<<"res: "<<removeDuplicatesII(nums);

        cout<<"after: "<<endl;
        for (int i : nums) {
            cout<<i<<" ";
        }
        cout<<endl;

    }

private:
    int removeDuplicatesII(vector<int>& nums) {
        int i = 0;
        for (int n : nums) {
            if (i < 2 || n > nums[i - 2]) {
                nums[i++] = n;
            }
        }
        nums.erase(nums.begin() + i, nums.end());
        return i;
    }

    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (i + 2 < nums.size() && nums[i] == nums[i + 2]) {
                int startIndex = i + 2;
                int endIndex = startIndex;
                while (endIndex + 1 < nums.size() && nums[endIndex] == nums[endIndex + 1]) {
                    ++endIndex;
                }

                nums.erase(nums.begin() + startIndex, nums.begin() + endIndex + 1);
                i = startIndex;
            } else {
                ++i;
            }
        }
        return nums.size();
    }

};

#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAYII_H
