//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_FINDTHEDUPLICATENUMBER_H
#define ALGORITHM_FINDTHEDUPLICATENUMBER_H

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class FindTheDuplicateNumber {
public:
    void test() {
//        vector<int> nums{1,3,4,2,2};
//        vector<int> nums{3,1,3,4,2};
//        vector<int> nums{2,2,2,2,2};
        vector<int> nums{9,5,9,6,9,3,8,2,7,1};

        cout<<findDuplicateII(nums)<<endl;
        cout<<findDuplicateIII(nums)<<endl;
    }

private:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i = 0; i < nums.size(); ++i) {
            if (mySet.find(nums[i]) != mySet.end())
                return nums[i];
            mySet.insert(nums[i]);
        }
        return -1;
    }

    int findDuplicateII(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);


        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

    int findDuplicateIII(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low <= high) {
            int mid = (int) (low + (high - low) * 0.5);
            int cnt = 0;
            for (int a : nums) {
                if (a <= mid) ++cnt;
            }
            if (cnt <= mid) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

#endif //ALGORITHM_FINDTHEDUPLICATENUMBER_H
