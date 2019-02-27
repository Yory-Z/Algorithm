//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_COWROAD_H
#define ALGORITHM_COWROAD_H

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class CowRoad {
public:
    void test() {
        int edgeSum, startSum, start, terminate;
        int from, to, distance;
        scanf("%d%d%d%d", &edgeSum, &startSum, &start, &terminate);

        initGraph(startSum);
        while (startSum--) {
            scanf("%d%d%d", &from, &to, &distance);
            temp.to = to;
            temp.dis = distance;
            vec[from].push_back(temp);
        }

//        printf("%d\n", shortestFromTo(edgeSum, start, terminate) + shortestFromTo(edgeSum, terminate, start));
        printf("%d\n", shortestFromTo(edgeSum, start, terminate));
        return;
    }

private:
    struct Edge {
        int dis;//the distance of the road
        int to;//the destination of the road

        bool friend operator <(Edge x1, Edge x2) {
            return x1.dis > x2.dis;
        }
    } temp, now;

    vector<vector<Edge>> vec;// keep the edge in sparse graph
    vector<bool> visit;// save the edge was visited
    vector<int> disTo;// save the distance to the edge

    void initGraph(int startSum) {
        vec = vector<vector<Edge>>(startSum + 1, vector<Edge>());
    }

    void initRecord(int edgeSum) {
        visit = vector<bool>(edgeSum + 1, false);
        disTo = vector<int>(edgeSum + 1, INT32_MAX);
    }

    int shortestFromTo(int edgeSum, int from, int to) {

        priority_queue<Edge> que;
        initRecord(edgeSum);

        // initial the start edge
        temp.to = from;
        temp.dis = 0;
        que.push(temp);
        disTo[from] = 0;

        while (!que.empty()) {
            // get the shortest edge from the priority queue
            now = que.top();
            que.pop();

            if (!visit[now.to]) {
                // mark the edge visited
                visit[now.to] = true;
                for (int i = 0; i < vec[now.to].size(); ++i) {
                    // if the node vec[now.to][i].to haven't been visited
                    // and the distance from source node to the current node vec[now.to][i].to is shorter than current distance
                    // then update it
                    if (!visit[vec[now.to][i].to] && disTo[now.to] + vec[now.to][i].dis < disTo[vec[now.to][i].to]) {
                        // update the shortest distance
                        disTo[vec[now.to][i].to] = disTo[now.to] + vec[now.to][i].dis;
                        // push the edge into priority queue
                        temp.to = vec[now.to][i].to;
                        temp.dis = disTo[vec[now.to][i].to];
                        que.push(temp);
                    }
                }
            }
        }

        return disTo[to];
    }

};

#endif //ALGORITHM_COWROAD_H

//tes case
/*
5 12 1 3
0 1 5
0 2 2
0 3 6
1 4 1
2 1 1
2 4 5
2 3 3
3 4 2
3 0 3
4 1 3
1 2 4
4 2 2

ans: 11
*/

/*
3 3 1 3
1 2 3
2 3 3
3 1 1

ans: 7
*/
