//
// Created by Yory on 2018/12/24.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

#include "../header/MinHeap.h"

#define INF 10000

template <class Type>
class Graph{
public:
    Graph();
    ~Graph();
    void PrintResult();

private:
    int num;//the number of Graph's node
    int *prev;//array of previous node
    Type **graph;//adjacent matrix of Graph G
    Type *dist;//array of shortest distance
    void ShortestPath(const int v);
};
template <class Type>
class MinHeapNode{
    friend Graph<Type>;

public:
   operator int () const{
       return length;
   }

private:
    int i;
    Type length;
};

template <class Type>
Graph<Type>::Graph() {
    int edgeSum;
    cin>>num>>edgeSum;

    dist = new int[num + 1];
    prev = new int[num + 1];

    for (int j = 1; j <= num; ++j) {
        dist[j] = INF;
        prev[j] = -1;
    }

    graph = new int*[num + 1];
    for (int i = 0; i <= num; ++i) {
        graph[i] = new int[num + 1];
    }

    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            graph[i][j] = INF;
        }
    }

    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            cout<<graph[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;

    int i, j, weight;
    for (int k = 1; k <= edgeSum ; ++k) {
        cin>>i>>j>>weight;
        graph[i][j] = weight;
    }

    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            cout<<graph[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
    ShortestPath(1);
}

template <class Type>
Graph<Type>::~Graph() {
    PrintResult();

    delete []dist;
    delete []prev;
    for (int i = 0; i <= num; ++i) {
        delete []graph[i];//delete everything  the Array's pointer has pointed
    }
    delete []graph;//delete the pointer arrays
}


template <class Type>
void Graph<Type>::ShortestPath(const int v) {
    //define a heap, default capacity 1000
    MinHeap<MinHeapNode<Type>> H;

    //define extended node
    MinHeapNode<Type> E;

    E.i = v;
    E.length = 0;
    dist[v] = 0;

    //search the solving space tree
    while (true){
        for (int j = 1; j <= num; ++j) {
            if(graph[E.i][j] < INF && E.length + graph[E.i][j] < dist[j]){
                //node i can reach node j, and meet the constraints
                dist[j] = E.length + graph[E.i][j];
                prev[j] = E.i;

                //insert to the active node queue
                MinHeapNode<Type> N;
                N.i = j;
                N.length = dist[j];
                H.Insert(N);
            }
//            H.printAll();
        }

        try {
            E = H.RemoveMin();
        }catch (int){
            break;
        }
    }
}

template <class T>
void Graph<T>::PrintResult() {

    for (int i = 2; i <= num; i++){
        cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;
    }
    cout<<endl;
    for (int i = 2; i <= num; i++) {
        cout << "The shortest path from 1 to " << i << " is " << dist[i] << endl;
    }
}

#endif //ALGORITHM_GRAPH_H

/*
11 19
1 2 2
1 3 3
1 4 4
2 3 3
2 5 7
2 6 2
3 6 9
3 7 2
4 7 2
5 8 3
5 9 3
6 9 3
6 7 1
7 9 5
7 10 1
8 11 3
9 11 2
10 9 2
10 11 2
 */
