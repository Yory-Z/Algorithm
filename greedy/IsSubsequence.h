//
// Created by Yory on 2019/2/16.
//

#ifndef ALGORITHM_ISSUBSEQUENCE_H
#define ALGORITHM_ISSUBSEQUENCE_H

#include <iostream>
#include <string>
using namespace std;

class IsSubsequence {
public:
    void test() {
        string s = "abc";
        string t = "ahbgdc";

/*        string s = "axc";
        string t = "ahbgdc";*/

        cout<<isSubsequence(s, t)<<endl;
        cout<<isSubsequenceII(s, t);
    }

private:
    bool isSubsequence(string s, string t) {
        int si = 0, ti = 0;
        while (si < s.size() && ti < t.size()) {
            if (s[si] == t[ti]) {
                ++si;
            }
            ++ti;
        }
        return si == s.size();
    }

    bool isSubsequenceII(string s, string t) {
        int frontS = 0, frontT = 0;
        int backS = s.size() - 1, backT = t.size() - 1;

        while (frontS <= backS && frontT < backT) {
            if (s[frontS] == t[frontT]) {
                ++frontS;
            }
            ++frontT;

            if (s[backS] == t[backT]) {
                --backS;
            }
            --backT;
        }
        return frontS > backS;
    }
};

#endif //ALGORITHM_ISSUBSEQUENCE_H
