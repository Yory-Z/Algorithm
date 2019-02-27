//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_UNIQUEPATHSTRACKBACK_H
#define ALGORITHM_UNIQUEPATHSTRACKBACK_H

#include <iostream>
using namespace std;

class UniquePathsTrackBack {
public:
    void test() {
/*        int m = 3;
        int n = 2;*/

        int m = 7;
        int n = 3;

        cout<<uniquePaths(m, n)<<endl;
    }

private:
    int ans;
    int uniquePaths(int m, int n) {
        ans = 0;
        unique(m - 1, n - 1);
        return ans;
    }

    void unique(int m, int n) {
        if (m == 0 && n == 0) {
            ++ans;
            return;
        }

        if (m > 0) {
            unique(m - 1, n);
        }

        if (n > 0) {
            unique(m, n - 1);
        }
    }
};

#endif //ALGORITHM_UNIQUEPATHSTRACKBACK_H
