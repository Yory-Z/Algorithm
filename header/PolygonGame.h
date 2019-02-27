//
// Created by Yory on 2019/1/10.
//

#ifndef ALGORITHM_POLYGONGAME_H
#define ALGORITHM_POLYGONGAME_H

#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::cin;
using std::set;
using std::cout;
using std::endl;

class PolygonGame {
public:
    void test();

private:
    struct Border {
        int from;
        int to;
        bool isChord;
        Border(int from, int to){
            this->from = from;
            this->to = to;
            isChord = false;
        }
    };

    struct Node {
        int num;
        int degree;
        Node(int num, int degree){
            this->num = num;
            this->degree = degree;
        }
        void subtractDegree(){
            this->degree -= 1;
        }
        void addDegree(){
            this->degree += 1;
        }
    };

    //count the degree of all the node
    void initDegree(const set<int> &nodeSet, vector<Node*> &nodeVec, const vector<Border*> &preVec){
        for (set<int>::const_iterator it = nodeSet.cbegin(); it != nodeSet.cend(); ++it) {
            Node *node = new Node(*it, 0);
            for (vector<Border*>::const_iterator vecIt = preVec.cbegin(); vecIt != preVec.cend(); ++vecIt) {
                Border *border = *vecIt;
                if (border->from == node->num){
                    node->addDegree();
                }
                if (border->to == node->num){
                    node->addDegree();
                }
            }
            nodeVec.push_back(node);
        }
    }

    int findTwoDegreeNodeNum(const vector<Node*> &nodeVec, const vector<Border*> &preVec){
        for (vector<Node*>::const_iterator it = nodeVec.cbegin(); it != nodeVec.cend(); ++it) {
            Node *node = *it;
            //find the node whose degree is 2 and borders at least have one border which is not chord
            if (node->degree == 2 && checkNodeBorder(node->num, preVec)){
                return node->num;
            }
        }
        return -1;
    }

    bool checkNodeBorder(int num, const vector<Border*> &preVec){
        int time = 0;
        for (Border *border : preVec){
            if ((border->from == num || border->to == num) && border->isChord)
                ++time;
        }
        return time < 2;
    }

    //move the target node's two border to the result vector
    //and subtract the degree of the target node and the two nodes linked with the target
    void removeTwoDegreeNodeBorder(vector<Border*> &preVec, vector<Border*> &resVec, vector<Node*> &nodeVec, int nodeNum){
        Border *border1 = nullptr;
        Border *border2 = nullptr;

        //find the node's number which linking with the parameter nodeNum
        for (vector<Border*>::iterator it = preVec.begin(); it != preVec.end(); ++it) {
            Border *temp = *it;
            if (temp->from == nodeNum || temp->to == nodeNum){
                if (border1 == nullptr){
                    border1 = temp;
                } else{
                    border2 = temp;
                }
                preVec.erase(it);
                --it;
                //if the border is not chord, push it into result vector
                if (!temp->isChord){
                    resVec.push_back(temp);
                }
            }
        }

        int num1 = border1->from == nodeNum ? border1->to : border1->from;
        int num2 = border2->from == nodeNum ? border2->to : border2->from;

        //mark the chord border (num1, num2)
        for (vector<Border*>::iterator it = preVec.begin(); it != preVec.end(); ++it) {
            Border *temp = *it;
            if ((temp->from == num1 && temp->to == num2) || (temp->from == num2 && temp->to == num1)){
                temp->isChord = true;
                break;
            }
        }

        //subtract the three node's degree
        subtractDegree(nodeVec, nodeNum, num1, num2);
    }

    //subtract the three nodes' degree
    void subtractDegree(vector<Node*> &nodeVec, int num1, int num2, int num3){
        for (Node *node : nodeVec) {
            int num = node->num;
            //the root node should subtract two time
            if (num == num1){
                node->subtractDegree();
                node->subtractDegree();
            } else if (num == num2 || num == num3){
                node->subtractDegree();
            }
        }
    }

    //get the result from the result vector
    void getNodeOrder(vector<Border*> &resVec, vector<int> &numVec){
        Border *border = resVec.at(0);
        int beginNum = border->from;
        int from = border->to;

        numVec.push_back(beginNum);
        numVec.erase((numVec.begin()));

        while (!resVec.empty()) {
            for (vector<Border*>::iterator resIt = resVec.begin(); resIt != resVec.end(); ++resIt) {
                border = *resIt;
                if (border->from == from){
                    numVec.push_back(from);
                    from = border->to;
                    resVec.erase(resIt);
                    break;
                }
            }
        }

    }
};

void PolygonGame::test() {
    vector<Border*> preVec;
    vector<Border*> resVec;
    set<int> nodeSet;
    vector<Node*> nodeVec;

    int from, to;
    while (true){
        cin>>from>>to;
        if (from == 0 && to == 0){
            break;
        }
        preVec.push_back(new Border(from, to));
        nodeSet.insert(from);
        nodeSet.insert(to);
    }

    //initial the degree of all the node
    initDegree(nodeSet, nodeVec, preVec);

    while (resVec.size() < nodeSet.size()){
        //find the node whose degree is 2 and borders at least have one border which is not chord
        int nodeNum = findTwoDegreeNodeNum(nodeVec, preVec);
        cout<<"nodeNum: "<<nodeNum<<endl;

        //move the target node's two border to the result vector
        //and subtract the degree of the target node and the two nodes linked with the target
        removeTwoDegreeNodeBorder(preVec, resVec, nodeVec, nodeNum);
    }

    vector<int> numVec;
    getNodeOrder(resVec, numVec);
    for (int num : numVec) {
        cout<<num<<' ';
    }
    cout<<endl;
}

/*

1 5
5 2
2 7
7 6
6 4
4 8
8 3
3 1
2 3
2 8
7 4
5 3
2 4
0 0
*/
#endif //ALGORITHM_POLYGONGAME_H
