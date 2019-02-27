//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_CONTAINERWITHMOSTWATER_H
#define ALGORITHM_CONTAINERWITHMOSTWATER_H

#include <vector>
#include <iostream>
using namespace std;

class ContainerWithMostWater {
public:
    void test(){
        vector<int> height{1,8,6,2,5,4,8,3,7};

        cout<<maxArea(height);
    }

private:
    int maxArea(vector<int>& height) {
        int res = 0;
        int front = 0, back = height.size() - 1;
        while (front < back) {
            int temp = 0;
            if (height[front] > height[back]) {
                temp = (back - front) * height[back];
                --back;
            } else {
                temp = (back - front) * height[front];
                ++front;
            }
            if (temp > res) {
                res = temp;
            }
        }
        return res;
    }
};

#endif //ALGORITHM_CONTAINERWITHMOSTWATER_H
