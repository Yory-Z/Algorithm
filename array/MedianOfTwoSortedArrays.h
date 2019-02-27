//
// Created by Yory on 2019/2/27.
//

#ifndef ALGORITHM_MEDIANOFTWOSORTEDARRAYS_H
#define ALGORITHM_MEDIANOFTWOSORTEDARRAYS_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MedianOfTwoSortedArrays {
public:
    void test() {
/*        vector<int> num1{1, 3};
        vector<int> num2{2};*/

        vector<int> num1{3, 6, 10, 11};
        vector<int> num2{1, 2, 4, 5, 6, 8, 9};

        cout<<findMedianSortedArrays(num1, num2)<<endl;
        cout<<findMedianSortedArrays(num2, num1)<<endl;
    }

private:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int iMin = 0, iMax = nums1.size();
        int halfLen = (nums1.size() + nums2.size() + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;

            if (i < iMax && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;// i is too small
            } else if (i > iMin && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;// i is too big
            } else {
                // i is perfect

                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }

                if ((nums1.size() + nums2.size()) % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == nums1.size()) {
                    minRight = nums2[j];
                } else if (j == nums2.size()) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }

};

#endif //ALGORITHM_MEDIANOFTWOSORTEDARRAYS_H
