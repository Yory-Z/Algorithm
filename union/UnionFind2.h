//
// Created by Yory on 2019/1/20.
//

#ifndef ALGORITHM_UNIONFIND2_H
#define ALGORITHM_UNIONFIND2_H

#include <cassert>

class UnionFind2 {
private:
    int* parent;
    int count;

public:
    UnionFind2(int n);
    ~UnionFind2();

    int find(int p);
    bool isConnected(int p, int q);
    void unionElements(int p, int q);

    void print();
};

UnionFind2::UnionFind2(int n):count(n) {
    parent = new int[n];
    for (int i = 0; i < count; ++i){
        parent[i] = i;
    }
}

UnionFind2::~UnionFind2() {
    delete [] parent;
}

int UnionFind2::find(int p) {
    assert(p >= 0 && p < count);
    while (p != parent[p]){
        p = parent[p];
    }
    return p;
}

bool UnionFind2::isConnected(int p, int q) {
    return find(p) == find(q);
}

void UnionFind2::unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot){
        return;
    }

    parent[pRoot] = qRoot;
}

void UnionFind2::print() {
    for (int i = 0; i < count; ++i) {
        cout<<i<<'\t';
    }
    cout<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<parent[i]<<'\t';
    }
    cout<<endl;
}
#endif //ALGORITHM_UNIONFIND2_H
