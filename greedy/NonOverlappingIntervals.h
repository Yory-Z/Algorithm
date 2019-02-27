//
// Created by Yory on 2019/2/16.
//

#ifndef ALGORITHM_NONOVERLAPPINGINTERVALS_H
#define ALGORITHM_NONOVERLAPPINGINTERVALS_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class NonOverlappingIntervals {
public:
    static bool compare(Interval& a, Interval& b) {
        if (a.end != b.end) {
            return a.end < b.end;
        }
        return a.start < b.start;
    }

    void test() {
/*        vector<Interval> vec{Interval(1, 2), Interval(2, 3),
                             Interval(3, 4), Interval(1, 3)};*/

        vector<Interval> vec{Interval(1, 2), Interval(1, 2),
                             Interval(1, 2)};

        cout<<eraseOverlapIntervals(vec);
    }

private:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()){
            return 0;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int res = 1;
        int pre = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= intervals[pre].end) {
                ++res;
                pre = i;
            }
        }
        return intervals.size() - res;
    }
};

#endif //ALGORITHM_NONOVERLAPPINGINTERVALS_H
