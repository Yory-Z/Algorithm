//
// Created by Yory on 2019/1/9.
//

#ifndef ALGORITHM_BESTLOADBREADTH_H
#define ALGORITHM_BESTLOADBREADTH_H

#include <iostream>
using std::end;
using std::begin;

#include <queue>
using std::queue;


class BestLoadBreadth {
public:
    void testBestLoadBreadth();

private:
    struct Node{
        Node *parent;
        bool left;
        int weight;
        Node(Node *parent, bool left, int weight){
            this->parent = parent;
            this->left = left;
            this->weight = weight;
        }
    };

    int n;
    int capacity;
    int bestWeight;
    int nodeWeight;
    int restWeight;
    int *weight;
    Node *currentNode;
    Node *bestNode;
    queue<Node *> que;

/*    int BeastLoad(int *weight, int capacity, int n);
    void EnterQueue(Node *node, int level){
        if (level == n){
            if ()
        }
    }*/
};

void BestLoadBreadth::testBestLoadBreadth() {
    int temp[]{6, 11, 17, 8, 9};
    n = end(temp) - begin(temp);
    weight = temp;

    capacity = 21;
    bestWeight = 0;
    nodeWeight = 0;
    currentNode = nullptr;
    bestNode = nullptr;

    restWeight = 0;
    for (int i = 1; i < n; ++i) {
        restWeight += weight[i];
    }



}

/*int BestLoadBreadth::BeastLoad(int *weight, int capacity, int n) {
    que.push(nullptr);
    int level = 0;

    while (true){
        int currentWeight = nodeWeight + weight[level];
        if (currentWeight < capacity){
            if (currentWeight > bestWeight){
                bestWeight = currentWeight;
            }

            if (level < n){
                que.push(currentWeight);
            }
        }

        if (nodeWeight + restWeight > bestWeight && level < n){
            que.push(nodeWeight);
        }

        nodeWeight = que.front();
        que.pop();

        if (nodeWeight == -1){
            if (que.empty()){
                return bestWeight;
            }
            que.push(-1);
            nodeWeight = que.front();
            que.pop();
            ++level;
            restWeight -= weight[level];
        }

    }
}*/


#endif //ALGORITHM_BESTLOADBREADTH_H
