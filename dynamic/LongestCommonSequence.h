//
// Created by Yory on 2019/2/7.
//

#ifndef ALGORITHM_LONGESTCOMMONSEQUENCE_H
#define ALGORITHM_LONGESTCOMMONSEQUENCE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class LongestCommonSequence {
public:
    void test(){
        string str1{"0ABCD"};
        string str2{"0AEBD"};

        cout<<LCS(str1, str2)<<endl;
        findPath(str1, str2, str1.size(), str2.size());
    }

private:
    vector<vector<int>> memo;

    int LCS(string& str1, string& str2) {
        if (str1.size() == 0 || str2.size() == 0){
            return 0;
        }

        memo = vector<vector<int>>(str1.size() + 1, vector<int>(str2.size() + 1, 0));

        for (int i = 1; i < str1.size(); ++i) {
            for (int j = 1; j < str2.size(); ++j) {
                if (str1[i] == str2[j]) {
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                } else {
                    memo[i][j] = max(memo[i -1][j], memo[i][j - 1]);
                }
            }
        }

        return memo[str1.size()-1][str2.size()-1];
    }

    void findPath(string& str1, string& str2, int i, int j) {
        if (i == 0 || j == 0){
            return;
        }

        if (str1[i] == str2[j]) {
            cout<<str1[i]<<' ';
            findPath(str1, str2, i - 1, j - 1);
        } else if (memo[i][j] == memo[i - 1][j]) {
            findPath(str1, str2, i - 1, j);
        } else {
            findPath(str1, str2, i, j - 1);
        }
    }

};

#endif //ALGORITHM_LONGESTCOMMONSEQUENCE_H
