//
// Created by Yory on 2019/3/19.
//

#ifndef ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H
#define ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H

#include <vector>
#include <iostream>
using namespace std;

class SearchInRotatedSortedArray {
public:
    void test() {
        vector<int> nums{4,5,6,7,0,1,2};
        int target = 0;

        cout<<"res: "<<search(nums, target);
    }

private:
    int search(vector<int>& nums, int target) {
        if (nums.empty()){
            return -1;
        }

        if (nums.size() == 1) {
            return nums.at(0) == target ? 0 : -1;
        }

        if (nums.at(0) < nums.at(nums.size()-1)){
            return binarySearch(nums, target, 0, nums.size() - 1);
        }

        int pivot = findPivot(nums);
        if (pivot == -1){
            return -1;
        }

        if(target >= nums.at(0)) {
            return binarySearch(nums, target, 0, pivot - 1);
        }
        return binarySearch(nums, target, pivot, nums.size() - 1);
    }

    int findPivot(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums.at(mid) > nums.at(mid + 1)){
                return mid + 1;
            } else if (nums.at(left) < nums.at(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return -1;
    }


    int binarySearch(vector<int> &nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums.at(mid) == target) {
                return mid;
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

#endif //ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H
