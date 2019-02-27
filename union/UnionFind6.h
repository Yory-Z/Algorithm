//
// Created by Yory on 2019/1/20.
//

#ifndef ALGORITHM_UNIONFIND6_H
#define ALGORITHM_UNIONFIND6_H

#include <cassert>

class UnionFind6 {
private:
    int* parent;
    int* rank;//save the root's rank
    int count;

public:
    UnionFind6(int n);
    ~UnionFind6();

    int find(int p);
    bool isConnected(int p, int q);
    void unionElements(int p, int q);

    void print();
};

UnionFind6::UnionFind6(int n):count(n) {
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < count; ++i){
        parent[i] = i;
        rank[i] = 1;
    }
}

UnionFind6::~UnionFind6() {
    delete [] parent;
}

int UnionFind6::find(int p) {
    assert(p >= 0 && p < count);
/*    while (p != parent[p]){
        parent[p] = parent[parent[p]];
        p = parent[p];
    }*/

    if (p != parent[p]){
        parent[p] = find(parent[p]);
    }
    return parent[p];
}

bool UnionFind6::isConnected(int p, int q) {
    return find(p) == find(q);
}

void UnionFind6::unionElements(int p, int q) {
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

void UnionFind6::print() {
    for (int i = 0; i < count; ++i) {
        cout<<i<<'\t';
    }
    cout<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<parent[i]<<'\t';
    }
    cout<<endl;
}

#endif //ALGORITHM_UNIONFIND6_H
