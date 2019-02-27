//
// Created by Yory on 2019/2/16.
//

#ifndef ALGORITHM_ASSIGNCOOKIE_H
#define ALGORITHM_ASSIGNCOOKIE_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class AssignCookie {
public:
    void test() {
/*        vector<int> g{1, 2, 3};
        vector<int> s{1, 1};*/

        vector<int> greedy{1, 2};
        vector<int> cookies{1, 2, 3};

        cout<<findContentChildren(greedy, cookies);
    }

private:
    int findContentChildren(vector<int>& greedy, vector<int>& cookies) {
        // first, we need to sort the greedy and cookies descending
        sort(greedy.begin(), greedy.end(), greater<int>());
        sort(cookies.begin(), cookies.end(), greater<int>());

        int gi = 0, si = 0;
        int res = 0;
        while (gi < greedy.size() && si < cookies.size()) {
            // the current cookie can content the current child's greedy
            if (cookies[si] >= greedy[gi]) {
                ++gi;
                ++si;
                ++res;
            } else {
                ++gi;
            }
        }
        return res;
    }

};


#endif //ALGORITHM_ASSIGNCOOKIE_H
