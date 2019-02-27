//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_COWLIVEDAYS_H
#define ALGORITHM_COWLIVEDAYS_H

#include <iostream>
using namespace std;

class CowLiveDays {
public:
    void test() {
        live();
    }

private:
    void live() {
        int x, f, d, p;
        cin >> x >> f >> d >> p;

        if (d < f * x) {
            cout<<(d / x)<<endl;
            return;
        }

        d -= f * x;
        int apple = 0;
        while ((d - p) / x > apple) {
            d = d - p;
            ++apple;
        }
        cout<<(f + apple)<<endl;
    }
};

#endif //ALGORITHM_COWLIVEDAYS_H
