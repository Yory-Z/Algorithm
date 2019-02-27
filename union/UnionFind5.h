//
// Created by Yory on 2019/1/20.
//

#ifndef ALGORITHM_UNIONFIND5_H
#define ALGORITHM_UNIONFIND5_H

#include <cassert>

class UnionFind5 {
private:
    int* parent;
    int* rank;//save the root's rank
    int count;

public:
    UnionFind5(int n);
    ~UnionFind5();

    int find(int p);
    bool isConnected(int p, int q);
    void unionElements(int p, int q);

    void print();
};

UnionFind5::UnionFind5(int n):count(n) {
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < count; ++i){
        parent[i] = i;
        rank[i] = 1;
    }
}

UnionFind5::~UnionFind5() {
    delete [] parent;
}

int UnionFind5::find(int p) {
    assert(p >= 0 && p < count);
    while (p != parent[p]){
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

bool UnionFind5::isConnected(int p, int q) {
    return find(p) == find(q);
}

void UnionFind5::unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot){
        return;
    }

    if (rank[pRoot] < rank[qRoot]) {
        parent[pRoot] = qRoot;
    } else if (rank[qRoot] < rank[pRoot]) {
        parent[qRoot] = pRoot;
    } else{
        //rank[qRoot] == rank[pRoot]
        parent[pRoot] = qRoot;
        rank[qRoot] += 1;
    }

}

void UnionFind5::print() {
    for (int i = 0; i < count; ++i) {
        cout<<i<<'\t';
    }
    cout<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<parent[i]<<'\t';
    }
    cout<<endl;
}

#endif //ALGORITHM_UNIONFIND5_H
