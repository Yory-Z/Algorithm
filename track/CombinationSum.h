//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_COMBINATIONSUM_H
#define ALGORITHM_COMBINATIONSUM_H

#include <vector>
#include <iostream>
using namespace std;

class CombinationSum {
public:
    void test();

private:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

    void trackBack(vector<int>& candidates, int target, int currentSum, int index, vector<int> &solve);

    void trackBackTwo(vector<int>& candidates, int target, int index, vector<int> &solve);
};

void CombinationSum::test() {
/*    vector<int> candidates{2, 3, 6, 7};
    int target = 7;*/

    vector<int> candidates{2, 3, 5};
    int target = 8;

/*    vector<int> candidates;
    int target = 7;*/

    combinationSum(candidates, target);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res.at(i).size(); ++j) {
            cout<<res.at(i).at(j)<<' ';
        }
        cout<<endl;
    }
}

vector<vector<int>> CombinationSum::combinationSum(vector<int>& candidates, int target) {
    vector<int> solve;
//    trackBack(candidates, target, 0, 0, solve);

    trackBackTwo(candidates, target, 0, solve);
    return res;
}

void CombinationSum::trackBack(vector<int>& candidates, int target, int currentSum, int index, vector<int> &solve) {
    if (index == candidates.size() || currentSum >= target){
        if (currentSum == target) {
            res.push_back(solve);
        }
        return;
    }

    //contain current candidates[index]
    currentSum += candidates.at(index);
    solve.push_back(candidates.at(index));

    trackBack(candidates, target, currentSum, index, solve);

    solve.pop_back();
    currentSum -= candidates.at(index);


    //do not contain current candidates[index]
    trackBack(candidates, target, currentSum, index + 1, solve);
}

void CombinationSum::trackBackTwo(vector<int> &candidates, int target, int index, vector<int> &solve) {
    if (target <= 0){
        if (target == 0) {
            res.push_back(solve);
        }
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        solve.push_back(candidates.at(i));
        trackBackTwo(candidates, target - candidates.at(i), i, solve);
        solve.pop_back();
    }
}

#endif //ALGORITHM_COMBINATIONSUM_H
