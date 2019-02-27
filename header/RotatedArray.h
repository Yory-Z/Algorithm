//
// Created by Yory on 2019/2/1.
//

#ifndef ALGORITHM_ROTATEDARRAY_H
#define ALGORITHM_ROTATEDARRAY_H

#include <vector>
#include <iostream>
using namespace std;

class RotatedArray {
public:
    static void test();

private:
    static int search(vector<int>& nums, int target);
    static int findPivot(vector<int>& nums);
    static int binarySearch(vector<int>& nums, int target, int left, int right);
};

void RotatedArray::test() {

//    vector<int> vec{4, 5, 6, 7, 8, 1, 2, 3};
//    vector<int> vec{7, 8, 1, 3, 4, 5, 6};
//    vector<int> vec{1, 2, 3, 5, 8, 9};
//    vector<int> vec{1, 3};
    vector<int> vec{3, 1};
//    vector<int> vec{8, 0, 1, 3, 5, 6};


    int target = 0;
    int res = search(vec, target);

    if(res != -1){
        cout<<"res: "<<vec.at(res)<<" , target: "<<target<<endl;
    } else {
        cout<<"res: "<<res<<endl;
    }

}

int RotatedArray::search(vector<int>& nums, int target) {
    if (nums.empty()){
        return -1;
    }

    if (nums.size() == 1) {
        return nums.at(0) == target ? 0 : -1;
    }

    if (nums.at(0) < nums.at(nums.size()-1)){
        return binarySearch(nums, target, 0, nums.size()-1);
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

int RotatedArray::findPivot(vector<int> &nums) {
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

int RotatedArray::binarySearch(vector<int> &nums, int target, int left, int right) {
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


#endif //ALGORITHM_ROTATEDARRAY_H
