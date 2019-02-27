//
// Created by Yory on 2019/1/20.
//

#ifndef ALGORITHM_UNIONFINDHELPER_H
#define ALGORITHM_UNIONFINDHELPER_H

#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"
#include "UnionFind6.h"

using namespace std;

namespace UnionFindHelper {

    void test1(){
        UnionFind1 uf(15);
        uf.print();

        cout<<uf.find(3)<<", "<<uf.find(13)<<endl;
        uf.unionElements(1, 9);
        uf.unionElements(4, 8);
        uf.print();
        uf.unionElements(9, 8);
        uf.print();
    }

    void test2(){
        UnionFind2 uf(15);
        uf.print();

        cout<<uf.find(3)<<", "<<uf.find(13)<<endl;
        uf.unionElements(1, 9);
        cout<<"isConnected: "<<uf.isConnected(1, 9)<<endl;
        uf.unionElements(4, 8);
        uf.print();
        uf.unionElements(9, 8);
        uf.print();
    }

    void test3(){
        UnionFind3 uf(15);
        uf.print();

        cout<<uf.find(3)<<", "<<uf.find(13)<<endl;
        uf.unionElements(1, 9);
        cout<<"isConnected: "<<uf.isConnected(1, 9)<<endl;
        uf.unionElements(4, 8);
        uf.print();
        uf.unionElements(9, 8);
        uf.print();
    }

    void test4(){
        UnionFind4 uf(15);
        uf.print();

        cout<<uf.find(3)<<", "<<uf.find(13)<<endl;
        uf.unionElements(1, 9);
        cout<<"isConnected: "<<uf.isConnected(1, 9)<<endl;
        uf.unionElements(4, 8);
        uf.print();
        uf.unionElements(9, 8);
        uf.unionElements(11, 8);
        uf.unionElements(4, 12);
        uf.unionElements(14, 1);
        uf.print();
    }

    void test5(){
        UnionFind5 uf(15);
        uf.print();

        cout<<uf.find(3)<<", "<<uf.find(13)<<endl;
        uf.unionElements(1, 9);
        cout<<"isConnected: "<<uf.isConnected(1, 9)<<endl;
        uf.unionElements(4, 8);
        uf.print();
        uf.unionElements(9, 8);
        uf.unionElements(11, 8);
        uf.unionElements(4, 12);
        uf.unionElements(14, 1);
        uf.print();
    }

    void test6(){
        UnionFind6 uf(15);
        uf.print();

        cout<<uf.find(3)<<", "<<uf.find(13)<<endl;
        uf.unionElements(1, 9);
        cout<<"isConnected: "<<uf.isConnected(1, 9)<<endl;
        uf.unionElements(4, 8);
        uf.print();
        uf.unionElements(9, 8);
        uf.unionElements(11, 8);
        uf.unionElements(4, 12);
        uf.unionElements(14, 1);
        uf.print();
    }

    void testUnionFind1(int n){

        srand(time(NULL));

        UnionFind1 uf(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }

        for (int j = 0; j < n; ++j) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout<<n * 2<<" operations, cause time: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }

    void testUnionFind2(int n){

        srand(time(NULL));

        UnionFind2 uf(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }

        for (int j = 0; j < n; ++j) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout<<n * 2<<" operations, cause time: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }

    void testUnionFind3(int n){

        srand(time(NULL));

        UnionFind3 uf(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }

        for (int j = 0; j < n; ++j) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout<<n * 2<<" operations, cause time: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }

    void testUnionFind4(int n){

        srand(time(NULL));

        UnionFind4 uf(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }

        for (int j = 0; j < n; ++j) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout<<n * 2<<" operations, cause time: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }

    void testUnionFind5(int n){

        srand(time(NULL));

        UnionFind5 uf(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }

        for (int j = 0; j < n; ++j) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout<<n * 2<<" operations, cause time: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }

    void testUnionFind6(int n){

        srand(time(NULL));

        UnionFind6 uf(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }

        for (int j = 0; j < n; ++j) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout<<n * 2<<" operations, cause time: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }
}






#endif //ALGORITHM_UNIONFINDHELPER_H
