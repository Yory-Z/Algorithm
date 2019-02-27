//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_PRODUCTOFARRAYEXCEPTSELF_H
#define ALGORITHM_PRODUCTOFARRAYEXCEPTSELF_H

#include <vector>
#include <iostream>
using namespace std;

class ProductOfArrayExceptSelf {
public:
    void test(){
        vector<int> nums{1,2,3,4};

        vector<int> res = productExceptSelfII(nums);
        for(int i : res) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

private:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i) {
                    temp *= nums[j];
                }
            }
            res.push_back(temp);
        }
        return res;
    }

    vector<int> productExceptSelfII(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = 1;
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        vector<int> res(n);
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = left[i] * right;
            right *= nums[i];
        }
        return res;
    }
};

#endif //ALGORITHM_PRODUCTOFARRAYEXCEPTSELF_H
