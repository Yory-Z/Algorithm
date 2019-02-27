//
// Created by Yory on 2019/1/9.
//

#ifndef ALGORITHM_GREEDY_H
#define ALGORITHM_GREEDY_H

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
using std::swap;
using std::cout;
using std::endl;

class BestLoadGreedy {
public:
    void testBestLoading();

private:
    struct Element {
        int weight;
        int container;
    };
    void BestLoading(int capacity, int *weight, int sum, int *res);
    void Sort(Element *element, int left, int right);
    void Swap(Element &e1, Element &e2) {
        Element temp = e1;
        e1 = e2;
        e2 = temp;
    }
};

void BestLoadGreedy::testBestLoading() {

    int weight[]{6, 11, 3, 10, 15, 8, 9};
    int sum = end(weight) - begin(weight);
    int capacity = 26;
    int *res = new int[sum];

    BestLoading(capacity, weight, sum, res);

    for (int j = 0; j < sum; ++j) {
        if (res[j] == 1){
            cout<<weight[j]<<' ';
        }
    }
    cout<<endl;
}

void BestLoadGreedy::BestLoading(int capacity, int *weight, int sum, int *res) {
    Element* element = new Element[sum];
    for (int i = 0; i < sum; ++i) {
        element[i].weight = weight[i];
        element[i].container = i;
        res[i] = 0;
    }

    for (int i = 0; i < sum; ++i) {
        cout<<"i: weight: "<<element[i].weight<<", container: "<<element[i].container<<endl;
    }

    srand(time(NULL));
    Sort(element, 0, sum - 1);

    for (int i = 0; i < sum && element[i].weight <= capacity; ++i) {
//        cout<<"capacity: "<<capacity<<endl;
        res[element[i].container] = 1;
        capacity -= element[i].weight;
    }

}

void BestLoadGreedy::Sort(Element *element, const int left, const int right) {
    if (left >= right){
        return;
    }

    Swap(element[left], element[rand() % right + left]);
    Element target = element[left];

    int lt = left;
    int i = left + 1;
    int gt = right + 1;
    while (i < gt){
        if (element[i].weight > target.weight){
            Swap(element[i], element[gt - 1]);
            --gt;
        } else if (element[i].weight < target.weight){
            Swap(element[i], element[lt + 1]);
            ++i;
            ++lt;
        } else {
            ++i;
        }
    }
    Swap(element[left], element[lt]);

    Sort(element, left, lt - 1);
    Sort(element, gt, right);
}



#endif //ALGORITHM_GREEDY_H
