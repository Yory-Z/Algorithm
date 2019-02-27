//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_COMBINATION_H
#define ALGORITHM_COMBINATION_H

#include <vector>
#include <iostream>
using namespace std;

class Combination {
public:
    void test();

private:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k) {
        vector<int> solve;
        trackBack(n, k, 1, solve);
        return res;
    }

    void trackBack(int n, int k, int start, vector<int>& solve) {
        if (solve.size() == k) {
            res.push_back(solve);
            return;
        }

        for (int i = start; i <= n - (k - solve.size()) + 1; ++i) {
            solve.push_back(i);
            trackBack(n, k, i + 1, solve);
            solve.pop_back();
        }
    }
};

void Combination::test() {
    int n = 5;
    int k = 3;

    combine(n, k);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res.at(i).size(); ++j) {
            cout<<res.at(i).at(j)<<' ';
        }
        cout<<endl;
    }
}

#endif //ALGORITHM_COMBINATION_H
