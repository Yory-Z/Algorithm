//
// Created by Yory on 2019/1/17.
//

#ifndef ALGORITHM_FOURSUM_H
#define ALGORITHM_FOURSUM_H

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

#include <iostream>
using std::cout;
using std::endl;

class FourSum {
public:
    static void testFourSum();

private:
    static vector<vector<int>> traverse(vector<int> &nums, int target);
};

void FourSum::testFourSum() {

//    vector<int> nums{1, 0, -1, 0, -2, 2};
//    vector<int> nums;
//    vector<int> nums{-3, -1, 0, 2, 4, 5};
    vector<int> nums{-1,-5,-5,-3,2,5,0,4};

    int target = -7;
    vector<vector<int>> res = traverse(nums, target);
    for (vector<int> vec : res) {
        for (int temp : vec) {
            cout<<temp<<' ';
        }
        cout<<endl;
    }
}


vector<vector<int>> FourSum::traverse(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    if (nums.size() < 4){
        return res;
    }

    for (int i = 0; i < nums.size() - 3; ++i) {

        for (int j = i + 1; j < nums.size() - 2; ++j) {

            int left = j + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int temp1 = nums.at(i);
                int temp2 = nums.at(j);
                int temp3 = nums.at(left);
                int temp4 = nums.at(right);

                //the current maximum sum is smaller than the target, we can break this loop
                if (nums.at(i) + nums.at(right) + nums.at(right - 1) + nums.at(right - 2) < target)
                    break;
                //the current minimum sum is bigger than the target, we can return the result
                if (nums.at(i) + nums.at(i + 1) + nums.at(i + 2) + nums.at(i + 3) > target)
                    return res;

                int sum = temp1 + temp2 + temp3 + temp4;
                if (sum > target) {
                    --right;
                } else if (sum < target){
                    ++left;
                } else {
                    res.push_back({temp1, temp2, temp3, temp4});

                    //jump the duplicate number
                    while (left < right && nums.at(left) == temp3)
                        ++left;
                    while (left < right && nums.at(right) == temp4)
                        --right;
                }

            }
            //jump the duplicate number
            while (j + 1 < nums.size() - 2 && nums.at(j) == nums.at(j + 1))
                ++j;
        }
        //jump the duplicate number
        while (i + 1 < nums.size() - 3 && nums.at(i) == nums.at(i + 1))
            ++i;
    }
    return res;
}

#endif //ALGORITHM_FOURSUM_H
