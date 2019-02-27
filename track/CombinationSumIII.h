//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_COMBINATIONSUMIII_H
#define ALGORITHM_COMBINATIONSUMIII_H

#include <vector>
#include <iostream>
using namespace std;

class CombinationSumIII {
public:
    void test();

private:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> solve;
        trackBack(1, k, n, solve);
        return res;
    }

    void trackBack(int index, int k, int target, vector<int> &solve) {
        if (solve.size() == k && target <= 0) {
            if (target == 0) {
                res.push_back(solve);
            }
            return;
        }

        for (int i = index; i <= 9; ++i) {
            solve.push_back(i);
            trackBack(i + 1, k, target - i, solve);
            solve.pop_back();
        }
    }
};

void CombinationSumIII::test() {
    int k = 3;
    int n = 7;

    combinationSum3(k, n);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res.at(i).size(); ++j) {
            cout<<res.at(i).at(j)<<' ';
        }
        cout<<endl;
    }
}


#endif //ALGORITHM_COMBINATIONSUMIII_H
