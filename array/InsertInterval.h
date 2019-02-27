//
// Created by Yory on 2019/2/21.
//

#ifndef ALGORITHM_INSERTINTERVAL_H
#define ALGORITHM_INSERTINTERVAL_H

#include <vector>
#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class InsertInterval {
public:
    void test() {
        vector<Interval> vec;

/*        vec.push_back(Interval(1, 3));
        vec.push_back(Interval(6, 9));
        Interval temp = Interval(2, 5);*/

/*        vec.push_back(Interval(1, 2));
        vec.push_back(Interval(3, 5));
        vec.push_back(Interval(6, 7));
        vec.push_back(Interval(8, 10));
        vec.push_back(Interval(12, 16));
        Interval temp = Interval(4, 8);*/

/*        vec.push_back(Interval(1, 5));
        Interval temp = Interval(1, 7);*/

        vec.push_back(Interval(1, 5));
        Interval temp = Interval(2, 7);

        vec = insert(vec, temp);
        for (Interval it : vec) {
            cout<<it.start<<"->"<<it.end<<endl;
        }
    }

private:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        if (newInterval.start < intervals[0].start) {
            intervals.insert(intervals.begin(), newInterval);
        } else {
            bool modify = false;
            for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++it) {
                if ((*it).start >= newInterval.start) {
                    intervals.insert(it, newInterval);
                    modify = true;
                    break;
                }
            }
            if (!modify) {
                intervals.push_back(newInterval);
            }
        }

        if (intervals.size() > 1) {
            for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end() - 1; ++it) {
                if ((*it).end >= (*(it + 1)).start) {
                    if ((*it).end < (*(it + 1)).end)
                        (*it).end = (*(it + 1)).end;
                    intervals.erase(it +1);
                    --it;
                }
            }
        }

        return intervals;
    }
};

#endif //ALGORITHM_INSERTINTERVAL_H
