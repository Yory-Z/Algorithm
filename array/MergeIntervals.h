//
// Created by Yory on 2019/2/21.
//

#ifndef ALGORITHM_MERGEINTERVALS_H
#define ALGORITHM_MERGEINTERVALS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <ctime>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct myCmp {
    bool operator()(Interval it1, Interval it2) {
        return it1.start >= it2.start;
    }
};


bool cmp(Interval it1, Interval it2) {
    return it1.start < it2.start;
}

class MergeIntervals {
public:
    void test() {
        vector<Interval> vec;

/*        vec.push_back(Interval(8, 10));
        vec.push_back(Interval(2, 6));
        vec.push_back(Interval(1, 3));
        vec.push_back(Interval(15, 18));*/

/*        vec.push_back(Interval(1, 4));
        vec.push_back(Interval(4, 5));*/

/*        vec.push_back(Interval(1, 5));
        vec.push_back(Interval(1, 4));*/

        vec.push_back(Interval(4, 5));
        vec.push_back(Interval(2, 4));
        vec.push_back(Interval(4, 6));
        vec.push_back(Interval(3, 4));
        vec.push_back(Interval(0, 0));
        vec.push_back(Interval(1, 1));
        vec.push_back(Interval(3, 5));
        vec.push_back(Interval(2, 2));

        vec = merge(vec);
/*        srand(time(NULL));
        quickSort(vec, 0, vec.size() - 1);*/

        for (int i = 0; i < vec.size(); ++i) {
            cout<<vec[i].start<<"->"<<vec[i].end<<endl;
        }
    }

private:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});

//        sort(intervals.begin(), intervals.end(), cmp);

        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end() - 1; ++it) {
            if ((*it).end >= (*(it + 1)).start) {
                if ((*it).end < (*(it + 1)).end)
                    (*it).end = (*(it + 1)).end;
                intervals.erase(it +1);
                --it;
            }
        }
        return intervals;
    }

    void mySort(vector<Interval>& intervals) {
        priority_queue<Interval, vector<Interval>, myCmp> que;
        for (int i = 0; i < intervals.size(); ++i) {
            que.push(intervals[i]);
        }

        int i = 0;
        while (!que.empty()) {
            intervals[i++] = que.top();
            que.pop();
        }
    }

    void quickSort(vector<Interval>& intervals, int left, int right) {
        if (left >= right) {
            return;
        }

        swap(intervals[left], intervals[rand() % (right - left + 1) + left]);
        Interval tar = intervals[left];

        int lt = left;
        int i = left + 1;
        int gt = right + 1;
        while (i < gt) {
            if (intervals[i].start < tar.start) {
                swap(intervals[i], intervals[++lt]);
                ++i;
            } else if (intervals[i].start > tar.start) {
                swap(intervals[i], intervals[--gt]);
            } else {
                ++i;
            }
        }
        swap(intervals[left], intervals[lt]);

        quickSort(intervals, left, lt - 1);
        quickSort(intervals, gt, right);
    }
};

#endif //ALGORITHM_MERGEINTERVALS_H
