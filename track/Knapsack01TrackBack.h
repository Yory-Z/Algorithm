//
// Created by Yory on 2019/1/9.
//

#ifndef ALGORITHM_KNAPSACK01TRACKBACK_H
#define ALGORITHM_KNAPSACK01TRACKBACK_H

#include <iostream>
#include <vector>

class Knapsack01TrackBack {
public:
    void test() {
        vector<int> weight{2, 1, 3, 5, 4, 1};
        vector<int> value{2, 3, 1, 4, 6, 2};
        int capacity = 7;

        int ans = knapsack(weight, value, capacity);
        cout<<"res: "<<ans<<endl;
    }

private:
    int n;// the sum of the object
    int capacity;// the capacity of the package

    vector<int> solve;// the solution of the bestValue
    vector<int> currentSolve;// keep the current solution when tracking back

    int bestValue;// the bestValue, the answer
    int currentValue;// keep the current value when tracking back
    int restValue;// the rest value of the solution tree when tracking back, used for cutting the solution tree

    int knapsack(vector<int>& weight, vector<int>& value, int c) {
        if (weight.empty() || weight.size() != value.size()) {
            return 0;
        }

        // initialize
        n = weight.size();
        capacity = c;
        bestValue = 0;
        currentValue = 0;
        restValue = 0;

        solve = vector<int>(n, 0);
        currentSolve = vector<int>(n, 0);

        for (int i = 0; i < n; ++i) {
            restValue += value[i];
        }

        trackBack(weight, value, 0);

        // print the solution
        for (int j = 0; j < n; ++j) {
            if (solve[j] == 1){
                cout<<"weight["<<j<<"] = "<<weight[j]<<endl;
            }
        }
        return bestValue;
    }

    void trackBack(vector<int>& weight, vector<int>& value, int k) {
        if (k == n){
            // the currentValue must better the the bestValue
            bestValue = currentValue;
            for (int i = 0; i < n; ++i) {
                solve[i] = currentSolve[i];
            }
            return;
        }

        restValue -= value[k];
        if (weight[k] <= capacity){
            // try to put this object into the knapsack
            capacity -= weight[k];
            currentSolve[k] = 1;
            currentValue += value[k];

            trackBack(weight, value, k + 1);

            // tracked back, this time, try don't put this object into the knapsack
            currentValue -= value[k];
            currentSolve[k] = 0;
            capacity += weight[k];
        }

        // cut the rest tree, this operation will save much time
        if (currentValue + restValue > bestValue) {
            currentSolve[k] = 0;
            trackBack(weight, value, k + 1);
        }
        restValue += value[k];
    }
};

#endif //ALGORITHM_ZEROONEPACKAGETRACKBACK_H
