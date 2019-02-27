//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_WILDCARDMATCHINGTRACKBACK_H
#define ALGORITHM_WILDCARDMATCHINGTRACKBACK_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class WildcardMatchingTrackBack {
public:
    void test() {
/*        string s = "aa";
        string p = "a";*/

/*        string s = "aa";
        string p = "*";*/

/*        string s = "cb";
        string p = "?a";*/

/*        string s = "adceb";
        string p = "*a*b";*/

        string s = "acdcb";
        string p = "a*c?b";

/*        string s = "a";
        string p = "a*";*/

        cout<<isMatch(s, p)<<endl;
    }

private:
    vector<vector<int>> memo;
    bool isMatch(string s, string p) {
        if (s.size() == 0 && string::npos == p.find_first_not_of('*')) {
            return true;
        }

        if (p.size() == 0) {
            return false;
        }

        memo = vector<vector<int>>(s.size(), vector<int>(p.size(), -1));
        return matching(s, p, 0, 0);
    }

    bool matching(string &s, string &p, int i, int j) {
        if (s.size() == i && p.size() == j) {
            return true;
        } else if(i > s.size() || p.size() == j) {
            return false;
        }

        if (i < s.size()) {
            if (memo[i][j] != -1) {
                return memo[i][j] == 1;
            }
        }

        bool res = false;
        if (p[j] == '*') {
            res = matching(s, p, i + 1, j) ||
                  matching(s, p, i + 1, j + 1) ||
                  matching(s, p, i, j + 1);
        } else if (p[j] == '?') {
            res = matching(s, p, i + 1, j + 1);
        } else if (p[j] == s[i]) {
            res = matching(s, p, i + 1, j + 1);
        }

        if (i < s.size()) {
            memo[i][j] = res ? 1 : 0;
        }
        return res;
    }
};

#endif //ALGORITHM_WILDCARDMATCHINGTRACKBACK_H
