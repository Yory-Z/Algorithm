//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_TRAPPINGRAINWATER_H
#define ALGORITHM_TRAPPINGRAINWATER_H

#include <vector>
#include <iostream>
using namespace std;

class TrappingRainWater {
public:
    void test(){
        vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
//        vector<int> height{5,4,1,2};
//        vector<int> height{5,2,1,2,1,5};
//        vector<int> height;

        cout<<trap(height)<<endl;
        cout<<trapII(height)<<endl;
        cout<<trapDynamic(height)<<endl;
    }

private:
    int trap(vector<int>& height) {
        const int n = height.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int maxLeft = 0, maxRight = 0;
            for (int j = i; j >= 0; --j) {
                maxLeft = max(maxLeft, height[j]);
            }

            for (int k = i; k < n; ++k) {
                maxRight = max(maxRight, height[k]);
            }
            res += min(maxLeft, maxRight) - height[i];
        }
        return res;
    }

    int trapII(vector<int>& height) {
        const int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    res += leftMax - height[left];
                }
                ++left;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    res += rightMax - height[right];
                }
                --right;
            }
        }
        return res;
    }

    int trapDynamic(vector<int>& height) {
        const int n = height.size();
        if (n <= 3) {
            return 0;
        }

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};

#endif //ALGORITHM_TRAPPINGRAINWATER_H
