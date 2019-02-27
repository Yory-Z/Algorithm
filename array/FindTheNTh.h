//
// Created by Yory on 2019/2/27.
//

#ifndef ALGORITHM_FINDTHENTH_H
#define ALGORITHM_FINDTHENTH_H

#include <iostream>
#include <algorithm>
#include "../util/ArrayHelper.h"


class FindTheNTh {
public:
    void test() {
        int sum = 10;
        int nth = 2;
        int *arr = ArrayHelper::GenerateUnorderArray(sum, 0, sum*4);
        int *arr2 = ArrayHelper::CopyArray(arr, sum);

        cout<<"find location: "<<nth<<endl;
        ArrayHelper::PrintArray(arr, sum);
        int res = findTheNth(arr, sum, nth);
        cout<<"result: "<<res<<endl;

        cout<<endl;
        cout<<"Sorted:"<<endl;
        sort(arr2, arr2 + sum);
        ArrayHelper::PrintArray(arr2, sum);
    }

private:
    int findTheNth(int *arr, int sum, int nth) {
        int left = 0, right = sum - 1;
        int i = left + 1, j = right;
        int tar = arr[left];
        // nth = nth - 1;// find the nth, count the first index
        nth = sum - nth;// count backwards

        while (true){
            while (true){
                while (i <= right && tar > arr[i])
                    ++i;

                while (j >= left && tar < arr[j])
                    --j;

                if (i > j){
                    break;
                }

                swap(arr[i], arr[j]);
                ++i;
                --j;
            }
            swap(arr[left], arr[j]);

            // find the answer
            if (nth == j){
                return arr[j];
            } else if (nth < j){
                // search from left
                right = j - 1;
            } else if (nth > j){
                // search from right
                left = j + 1;
            }

            i = left + 1;
            j = right;
            tar = arr[left];
        }
    }
};

#endif //ALGORITHM_FINDTHENTH_H
