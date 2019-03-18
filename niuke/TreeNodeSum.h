//
// Created by Yory on 2019/3/14.
//

#ifndef ALGORITHM_TREENODESUM_H
#define ALGORITHM_TREENODESUM_H

#include <vector>
#include <iostream>
using namespace std;

class TreeNodeSum {
public:
    void test() {
        int n = 6, k = 3;

        countSum(n, k);
        for (int i : res) {
            if (i > 0) {
                cout<<i<<" +"<<endl;
            } else {
                cout<<abs(i)<<" -"<<endl;
            }
        }
    }

private:
    int target;
    int endLevel;
    bool gotAns;
    int curSum;
    vector<int> vec;
    vector<int> res;

    void countSum(int n, int k) {
        target = n;
        endLevel = k;
        gotAns = false;
        vec = vector<int>(k, 0);
        res = vector<int>(k, 0);

        curSum = 1;
        vec[0] = 1;
        trackBack(1, 1);

        curSum = -1;
        vec[0] = -1;
        trackBack(1, 1);
    }

    void trackBack(int node, int level) {
        if (endLevel == level) {
            if (curSum == target && !gotAns) {
                transferAns();
            }
            return;
        }

        int left = node * 2;

        //add left
        if (curSum + left <= target) {
            curSum += left;
            vec[level] = left;
            trackBack(left, level + 1);
            curSum -= left;
        }

        //subtract left
        if (curSum - left <= target) {
            curSum -= left;
            vec[level] = -left;
            trackBack(left, level + 1);
            curSum += left;
        }

        int right = left + 1;

        //add right
        if (curSum + right <= target) {
            curSum += right;
            vec[level] = right;
            trackBack(right, level + 1);
            curSum -= right;
        }

        //subtract right
        if (curSum - right <= target) {
            curSum -= right;
            vec[level] = -right;
            trackBack(right, level + 1);
            curSum += right;
        }

    }

    void transferAns() {
        for (int i = 0; i < vec.size(); ++i) {
            res[i] = vec[i];
        }
    }
};


#endif //ALGORITHM_TREENODESUM_H
