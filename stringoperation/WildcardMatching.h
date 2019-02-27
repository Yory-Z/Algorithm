//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_WILDCARDMATCHING_H
#define ALGORITHM_WILDCARDMATCHING_H

#include <iostream>
#include <string>
using namespace std;

class WildcardMatching {
public:
    void test() {
/*        string s = "aa";
        string p = "a";*/

/*        string s = "aa";
        string p = "*";*/

/*        string s = "cb";
        string p = "?a";*/

        string s = "adceb";
        string p = "*a*b";

/*        string s = "acdcb";
        string p = "a*c?b";*/

/*        string s = "a";
        string p = "a*";*/

        cout<<isMatch(s, p)<<endl;
    }

private:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int match = 0, startIndex = -1;
        while (i < s.size()) {
            if (j < p.size() && (p[j] == '?' || s[i] == p[j])) {
                ++i;
                ++j;
            } else if (j < p.size() && p[j] == '*') {
                startIndex = j;
                match = i;
                ++j;
            } else if (startIndex != -1) {
                j = startIndex + 1;
                ++match;
                i = match;
            } else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*')
            ++j;

        return j == p.size();
    }

};

#endif //ALGORITHM_WILDCARDMATCHING_H
