//
// Created by Yory on 2018/12/28.
//
#include <algorithm>
#include "vector"
using std::vector;

#ifndef ALGORITHM_THREESUM_H
#define ALGORITHM_THREESUM_H

class ThreeSum {
public:
    void testThreeSum();

private:
    vector<vector<int>> Traverse(vector<int>& nums);
    void PrintResult(vector<vector<int>> &result);
};


void ThreeSum::testThreeSum() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    vector<vector<int>> resTemp = Traverse(nums);
    PrintResult(resTemp);
}

vector<vector<int>> ThreeSum::Traverse(vector<int> &nums) {
    vector<vector<int>> resTemp;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right){
            int sum = nums.at(i) + nums.at(left) + nums.at(right);
            if (sum > 0){
                --right;
            } else if (sum < 0){
                ++left;
            } else {
                vector<int> temp{nums.at(i), nums.at(left), nums.at(right)};
                resTemp.push_back(temp);

                while (left < right && nums.at(left) == temp.at(1))
                    ++left;

                while (left < right && nums.at(right) == temp.at(2))
                    --right;
            }
        }

        while (i + 1 < nums.size() && nums.at(i + 1) == nums.at(i))
            ++i;
    }
    return resTemp;
}

void ThreeSum::PrintResult(vector<vector<int>> &result) {
    for (auto it = result.cbegin(); it != result.cend(); ++it) {
        vector<int> temp = *it;
        for (int j = 0; j < temp.size(); ++j) {
            cout<<temp.at(j)<<' ';
        }
        cout<<endl;
    }
}


#endif //ALGORITHM_THREESUM_H
