//
// Created by Yory on 2019/1/20.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H

#include <cassert>

class UnionFind1 {
private:
    int *id;
    int count;

public:
    UnionFind1(int n);
    ~UnionFind1();

    int find(int p);
    bool isConnected(int p, int q);
    void unionElements(int p, int q);

    void print();
};

UnionFind1::UnionFind1(int n): count(n) {
    id = new int[n];
    for (int i = 0; i < n; ++i) {
        id[i] = i;
    }
}

UnionFind1::~UnionFind1() {
    delete [] id;
}

int UnionFind1::find(int p) {
    assert(p >= 0 && p < count);
    return id[p];
}

bool UnionFind1::isConnected(int p, int q) {
    return find(p) == find(q);
}

void UnionFind1::unionElements(int p, int q) {
    int pId = find(p);
    int qId = find(q);

    if (pId == qId) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        if (id[i] == pId){
            id[i] = qId;
        }
    }
}

void UnionFind1::print() {
    for (int i = 0; i < count; ++i) {
        cout<<i<<'\t';
    }
    cout<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<id[i]<<'\t';
    }
    cout<<endl;
}

#endif //ALGORITHM_UNIONFIND_H
