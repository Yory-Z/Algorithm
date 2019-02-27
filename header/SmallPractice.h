//
// Created by Yory on 2018/12/27.
//

#ifndef ALGORITHM_SAMLLPRACTICE_H
#define ALGORITHM_SAMLLPRACTICE_H

#include <cstdlib>
#include <vector>
#include<string>
#include <queue>
#include <algorithm>
using namespace std;

#include "../util/ArrayHelper.h"

class SmallPractice{
public:
    void testLongestCommonPrefix();
    void testFindTheNth();
    void testLetterCombinations();
    void testIntegerPartition();
    void testRemoveDuplicate();
    static void testCountAndSay();

private:
    string longestCommonPrefix(vector<string>& strs);
    int findTheNth(int* arr, int sum, int nth);
    vector<string> letterCombinations(string digits);
    int IntegerPartition(int n, int m);
    int removeDuplicate(vector<int>& nums);

    static string countAndSay(int n);

};

void SmallPractice::testCountAndSay() {

    for (int i = 1; i < 8; ++i) {
        cout<<i<<":"<<countAndSay(i)<<endl;
    }
}

string SmallPractice::countAndSay(int n) {
    string res{"1"};
    for (int i = 1; i < n; ++i) {
        string temp;
        int count = 1;
        for (int j = 0; j < res.size(); ++j) {
            if (j + 1 < res.size() && res.at(j) == res.at(j + 1)) {
                ++count;
            } else {
                temp += to_string(count) + res.at(j);
                count = 1;
            }
        }
        res = temp;
    }
    return res;
}

void SmallPractice::testLetterCombinations() {
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    for (vector<string>::iterator it = res.begin(); it != res.end() ; ++it) {
        cout<<*it<<' ';
    }
    cout<<endl;
}

vector<string> SmallPractice::letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0){
        return res;
    }
    string maps[]{"", "", "abc", "def",
                 "ghi", "jkl", "mno",
                 "pqrs", "tuv", "wxyz"};

    res.push_back("");
    for (int i = 0; i < digits.size(); ++i) {
        string str = maps[digits.at(i) - '0'];
        vector<string> temp;
        for (int k = 0; k < res.size(); ++k){
             for (int j = 0; j < str.size(); ++j){
                temp.push_back(res.at(k) + str.at(j));
            }
        }
        res = temp;
    }
    return res;
}

void SmallPractice::testLongestCommonPrefix() {
    vector<string> strs;
//    strs = {""};
//    strs = {"a"};
    strs = {"c", "c"};
//    strs = {"flower","flow","flight"};
//    strs = {"dog","racecar","car"};

    string res = longestCommonPrefix(strs);
    cout<<"res: "<<res<<endl;

}

string SmallPractice::longestCommonPrefix(vector<string> &strs) {
    if(strs.empty()){
        return "";
    } else if (strs.size() == 1){
        return strs.at(0);
    }

    int index = 0;
    while(true){
        string tempStr = strs.at(0);
        if (tempStr.empty() || tempStr.size() == index){
            break;
        }

        char temp = tempStr.at(index);
        bool flag = false;
        for(int i = 1; i < strs.size(); ++i){
            tempStr = strs.at(i);
            if (tempStr.empty() || tempStr.size() == index){
                flag = true;
                break;
            }

            if(temp != tempStr.at(index)){
                flag = true;
                break;
            }

        }

        if(flag)
            break;
        else
            ++index;
    }
    return string(strs.at(0), 0, index);
}


void SmallPractice::testIntegerPartition() {
    int n = 6;
    int res = IntegerPartition(n, n);
    cout<<"res: "<<res<<endl;
}

int SmallPractice::IntegerPartition(int n, int m) {
    if (n < 1 || m < 1) {
        return 0;
    } else if (n == 1 || m == 1){
        return 1;
    } else if(n < m){
        return IntegerPartition(n, n);
    } else if (n == m){
        return 1 + IntegerPartition(n, m - 1);
    } else {
        return IntegerPartition(n - m, m) + IntegerPartition(n, m - 1);
    }
}


void SmallPractice::testRemoveDuplicate() {
    vector<int> nums;
    int res = removeDuplicate(nums);
    cout<<"res: "<<res<<endl;
}

int SmallPractice::removeDuplicate(vector<int> &nums) {

    if(nums.size() == 0){
        return 0;
    }

    for(int i = 0; i < nums.size() - 1; ++i) {

        if (nums.at(i) == nums.at(i + 1)) {
            int endIndex = i + 1;
            while(endIndex < nums.size() - 1 && nums.at(endIndex) == nums.at(endIndex + 1)){
                ++endIndex;
            }
            nums.erase(nums.begin() + i, nums.begin() + endIndex);
        }

    }

    return nums.size();
}


#endif //ALGORITHM_SAMLLPRACTICE_H
