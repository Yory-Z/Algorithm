//
// Created by Yory on 2019/1/27.
//

#ifndef ALGORITHM_TWOSUM_H
#define ALGORITHM_TWOSUM_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
    static void testTwoSum();

private:
    static vector<int> twoSum(vector<int>& nums, int target);
};

void TwoSum::testTwoSum() {

    vector<int> nums{2, 7, 11, 15};
    int target = 123;

    vector<int> res = twoSum(nums, target);
    for (int i : res) {
        cout<<i<<' ';
    }
    cout<<endl;
}

vector<int> TwoSum::twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); ++i) {
        int temp = target - nums.at(i);
        if (myMap.find(temp) != myMap.end()){
            return vector<int>{myMap[temp], i};
        }
        myMap[nums.at(i)] = i;
    }
    return vector<int>{};
}


#endif //ALGORITHM_TWOSUM_H
