//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_COMBINATIONSUMII_H
#define ALGORITHM_COMBINATIONSUMII_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CombinationSumII {
public:
    void test();

private:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    void trackBack(vector<int>& candidates, int target, int index, vector<int> &solve);
//    bool checkDuplicate(vector<int> &solve);
};

void CombinationSumII::test() {
/*    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;*/

/*    vector<int> candidates{2,5,2,1,2};
    int target = 5;*/

    vector<int> candidates{4,4,2,1,4,2,2,1,3};
    int target = 6;

    vector<vector<int>> tempRes = combinationSum2(candidates, target);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < tempRes.at(i).size(); ++j) {
            cout<<tempRes.at(i).at(j)<<' ';
        }
        cout<<endl;
    }
}

vector<vector<int>> CombinationSumII::combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> solve;
    trackBack(candidates, target, 0, solve);
    return vector<vector<int>>(res.cbegin(), res.cend());
}

void CombinationSumII::trackBack(vector<int>& candidates, int target, int index, vector<int> &solve) {
    if (target <= 0){
        if (target == 0) {
            res.push_back(solve);
        }
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        solve.push_back(candidates.at(i));
        trackBack(candidates, target - candidates.at(i), i + 1, solve);

        //skip duplicate answer
        while (i + 1 < candidates.size() && candidates[i] == candidates[i+1])
            ++i;
        solve.pop_back();
    }
}

#endif //ALGORITHM_COMBINATIONSUMII_H
