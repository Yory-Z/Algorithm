//
// Created by Yory on 2019/1/10.
//

#ifndef ALGORITHM_DINNERFRIEND_H
#define ALGORITHM_DINNERFRIEND_H

#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::cin;
using std::set;
using std::cout;
using std::endl;


class DinnerFriend {
public:
    void test();

private:
    struct Border {
        int from;
        int to;
        Border(int from, int to){
            this->from = from;
            this->to = to;
        }
    };

    struct Node {
        int num;
        int degree;
        Node(int num, int degree){
            this->num = num;
            this->degree = degree;
        }

        operator int () const{
            return degree;
        }
        void subtractDegree(){
            this->degree -= 1;
        }
    };

    void initNodeDegree(const set<int> &nodeSet, const vector<Border*> &preVec, vector<Node*> &nodeVec){
        for (int num : nodeSet) {
            int degree = 0;
            for (Border *border : preVec) {
                if (num == border->from || num == border->to)
                    ++degree;
            }
            nodeVec.push_back(new Node(num, degree));
        }
    }

    bool checkExistMoreOneDegree(const vector<Node *> &nodeVec){
        for (Node *node : nodeVec){
            if (node->degree > 1){
                return true;
            }
        }
        return false;
    }

    Node* removeMaxNode(vector<Node*> &nodeVec){
        Node *maxNode = nodeVec.at(0);
        int dis = 0;
        for (int i = 1; i < nodeVec.size(); ++i){
            Node *node = nodeVec.at(i);
            if (maxNode->degree < node->degree){
                maxNode = node;
                dis = i;
            }
        }
        nodeVec.erase(nodeVec.begin() + dis);
        return maxNode;
    }

    void removeMaxNode(vector<Border*> &preVec, vector<Node*> &nodeVec, vector<int> &resVec){
        Node *maxNode = removeMaxNode(nodeVec);
        resVec.push_back(maxNode->num);

        for (auto borderIt = preVec.begin(); borderIt != preVec.end(); ++borderIt) {
            Border *border = *borderIt;

            int targetNum = -1;
            if (border->from == maxNode->num){
                targetNum = border->to;
            } else if (border->to == maxNode->num) {
                targetNum = border->from;
            }

            if (targetNum != -1){
                for (auto nodeIt = nodeVec.begin(); nodeIt != nodeVec.end(); ++nodeIt) {
                    Node *node = *nodeIt;
                    if (node->num == targetNum){
                        node->subtractDegree();
                        break;
                    }
                }

                preVec.erase(borderIt);
                --borderIt;
            }
        }

    }
};

void DinnerFriend::test() {
    vector<Border*> preVec;
    set<int> nodeSet;

    int from = 0, to = 0;
    while (true){
        cin>>from>>to;
        if (from == 0 && to == 0){
            break;
        }
        preVec.push_back(new Border(from, to));
        nodeSet.insert(from);
        nodeSet.insert(to);
    }

    vector<Node*> nodeVec;
    initNodeDegree(nodeSet, preVec, nodeVec);

    vector<int> resVec;
    while (checkExistMoreOneDegree(nodeVec)){
        removeMaxNode(preVec, nodeVec, resVec);
    }

    cout<<resVec.size()<<endl;
    for (int num : resVec){
        cout<<num<<", ";
    }
    cout<<endl;
}

/*

1 2
1 3
2 4
7 6
4 3
5 6
0 0

 */

#endif //ALGORITHM_DINNERFRIEND_H
