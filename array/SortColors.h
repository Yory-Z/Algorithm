//
// Created by Yory on 2019/3/19.
//

#ifndef ALGORITHM_SORTCOLORS_H
#define ALGORITHM_SORTCOLORS_H

#include <vector>
#include <iostream>
using namespace std;

class SortColors {
public:
    void test() {
        vector<int> vec{2,0,2,1,1,0};
//        vector<int> vec{2,1,1,2,1,2,1};
//        vector<int> vec{1,2,0};

        cout<<"before: "<<endl;
        for (int i : vec) {
            cout<<i<<" ";
        }
        cout<<endl;

        sortColorsII(vec);

        cout<<"after: "<<endl;
        for (int i : vec) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

private:
    void sortColorsII(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for (int i : nums) {
            if (i == 0) {
                nums[b++] = 2;
                nums[w++] = 1;
                nums[r++] = 0;
            } else if (i == 1) {
                nums[b++] = 2;
                nums[w++] = 1;
            } else {
                ++b;
            }
        }
    }

    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        findZero(nums);

        int left = 0;
        int i = left + 1;
        int right = nums.size();
        while (i < right) {
            if (nums[i] == 0) {
                swap(nums[left + 1], nums[i]);
                ++left;
                ++i;
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[i], nums[right - 1]);
                --right;
            }
        }
    }

    void findZero(vector<int>& nums) {
        if (nums[0] != 0) {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    swap(nums[0], nums[i]);
                    return;
                }
            }

            if (nums[0] != 1) {
                for (int i = 1; i < nums.size(); ++i) {
                    if (nums[i] == 1) {
                        swap(nums[0], nums[i]);
                        return;
                    }
                }
            }
        }
    }

};


#endif //ALGORITHM_SORTCOLORS_H
