//
// Created by Yory on 2019/1/20.
//

#ifndef ALGORITHM_UNIONFIND3_H
#define ALGORITHM_UNIONFIND3_H

#include <cassert>

class UnionFind3 {
private:
    int* parent;
    int* sz;//save the root's sum of child
    int count;

public:
    UnionFind3(int n);
    ~UnionFind3();

    int find(int p);
    bool isConnected(int p, int q);
    void unionElements(int p, int q);

    void print();
};

UnionFind3::UnionFind3(int n):count(n) {
    parent = new int[n];
    sz = new int[n];
    for (int i = 0; i < count; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
}

UnionFind3::~UnionFind3() {
    delete [] parent;
}

int UnionFind3::find(int p) {
    assert(p >= 0 && p < count);
    while (p != parent[p]){
        p = parent[p];
    }
    return p;
}

bool UnionFind3::isConnected(int p, int q) {
    return find(p) == find(q);
}

void UnionFind3::unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot){
        return;
    }

    if (sz[pRoot] < sz[qRoot]) {
        parent[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    } else {
        parent[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
    }

}

void UnionFind3::print() {
    for (int i = 0; i < count; ++i) {
        cout<<i<<'\t';
    }
    cout<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<parent[i]<<'\t';
    }
    cout<<endl;
}

#endif //ALGORITHM_UNIONFIND3_H
