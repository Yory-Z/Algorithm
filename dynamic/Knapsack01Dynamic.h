//
// Created by Yory on 2019/2/7.
//

#ifndef ALGORITHM_KNAPSACK01DYNAMIC_H
#define ALGORITHM_KNAPSACK01DYNAMIC_H

#include <vector>
#include <iostream>
using namespace std;

class Knapsack01Dynamic {
public:
    void test() {
        vector<int> weight{2, 1, 3, 5, 4, 1};
        vector<int> value{2, 3, 1, 4, 6, 2};
        int c = 7;

        int ans = knapsack01(weight, value, c);
        cout<<"res: "<<ans<<endl;

        cout<<"res: "<<knapsack01II(weight, value, c)<<endl;
        cout<<"res: "<<knapsack01III(weight, value, c)<<endl;
    }

private:
    int knapsack01(const vector<int>& weight, const vector<int>& value, const int c) {
        if (weight.size() != value.size() || weight.empty()){
            return 0;
        }

        int n = weight.size();
        vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(c + 1, 0));
        for (int i = 0; i <= c; ++i) {
            memo[0][i] = i >= weight[0] ? value[0] : 0;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= c ; ++j) {
                memo[i][j] = memo[i - 1][j];
                if (j >= weight[i]) {
                    memo[i][j] = max(memo[i][j], value[i] + memo[i - 1][j - weight[i]]);
                }
            }
        }

        // this function is for finding the object we selected putted into the knapsack
        findPath(c, weight, memo);

        return memo[n - 1][c];
    }

    void findPath(int c, const vector<int>& weight, const vector<vector<int>>& memo) {
        cout<<"C: "<<c<<endl;
        vector<int> path;
        int n = weight.size();
        for (int i = n - 1; i > 0; --i) {
            if (memo[i][c] != memo[i - 1][c]) {
                path.push_back(i);
                c -= weight[i];
            }
        }

        if (memo[0][c] != 0) {
            path.push_back(0);
        }

        for (int j = path.size() - 1; j >= 0; --j) {
            cout<<"weight["<<path[j]<<"] = "<<weight[path[j]]<<endl;
        }
        cout<<endl;
    }

    //space: O(2c) = O(c)
    //this version can not find path
    int knapsack01II(const vector<int>& weight, const vector<int>& value, const int c) {
        if (weight.size() != value.size() || weight.empty()){
            return 0;
        }

        int n = weight.size();
        vector<vector<int>> memo = vector<vector<int>>(2, vector<int>(c + 1, 0));
        for (int i = 0; i <= c; ++i) {
            memo[0][i] = i >= weight[0] ? value[0] : 0;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= c; ++j) {
                memo[i % 2][j] = memo[(i - 1) % 2][j];
                if (j >= weight[i]) {
                    memo[i % 2][j] = max(memo[i % 2][j], value[i] + memo[(i - 1) % 2][j - weight[i]]);
                }
            }
        }
        return memo[(n - 1) % 2][c];
    }

    //space: O(c)
    //this version can not find path
    int knapsack01III(const vector<int>& weight, const vector<int>& value, const int c) {
        if (weight.size() != value.size() || weight.empty()){
            return 0;
        }

        int n = weight.size();
        vector<int> memory = vector<int>(c + 1, 0);
        for (int i = 0; i <= c; ++i) {
            memory[i] = i >= weight[0] ? value[0] : 0;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = c; j >= weight[i]; --j) {
                memory[j] = max(memory[j], value[i] + memory[j - weight[i]]);
            }
        }
        return memory[c];
    }
};

#endif //ALGORITHM_KNAPSACK01DYNAMIC_H
