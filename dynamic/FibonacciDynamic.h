//
// Created by Yory on 2019/2/26.
//

#ifndef ALGORITHM_FIBONACCIDYNAMIC_H
#define ALGORITHM_FIBONACCIDYNAMIC_H

#include <iostream>
#include <vector>
using namespace std;

class FibonacciDynamic {
public:
    void test(double n) {
        cout<<fibonacci(n)<<endl;
    }

private:
    double fibonacci(double n) {
        vector<double> memo(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;

        for (double i = 2; i <= n; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n];
    }
};

#endif //ALGORITHM_FIBONACCIDYNAMIC_H

/*
void testFibonacci() {
    int n = 8;
    time_t time1 = clock();

    FibonacciTrackBack test;
    test.test(n);

    time_t time2 = clock();

    FibonacciTrackBackII testII;
    testII.test(n);

    time_t time3 = clock();

    FibonacciDynamic testIII;
    testIII.test(n);

    time_t time4 = clock();

    cout<<"n: "<<n<<endl;
    cout<<"solution1: cause time: "<<(double)(time2 - time1) / CLOCKS_PER_SEC<<" S."<<endl;
    cout<<"solution2: cause time: "<<(double)(time3 - time2) / CLOCKS_PER_SEC<<" S."<<endl;
    cout<<"solution2: cause time: "<<(double)(time4 - time3) / CLOCKS_PER_SEC<<" S."<<endl;
}
*/

