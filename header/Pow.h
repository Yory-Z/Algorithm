//
// Created by Yory on 2019/2/21.
//

#ifndef ALGORITHM_POW_H
#define ALGORITHM_POW_H

#include <iostream>
#include <vector>
using namespace std;

class Pow {
public:
    void test() {
/*        double x = 2;
        int n = 10;*/

/*        double x = 2.1;
        int n = 3;*/

/*        double x = 2;
        int n = -2;*/

        double x = 0.00001;
        int n = -2147483647;

        double res = myPow(x, n);
        cout<<res<<endl;
    }

private:
    double myPow(double x, int n) {
        return trackBack(x, n);
    }

    double trackBack(double x, long n) {
        if (n == 0)
            return 1;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return (n % 2 == 0) ? trackBack(x * x, n / 2) : x * trackBack(x * x, n / 2);
    }
};

#endif //ALGORITHM_POW_H
