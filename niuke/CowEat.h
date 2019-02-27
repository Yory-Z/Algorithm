//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_COWEAT_H
#define ALGORITHM_COWEAT_H

#include <iostream>
using namespace std;

class CowEat {
public:
    void test() {
        eat();
    }

private:
    void eat() {
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            int target, one, two, three;
            cin>>target>>one>>two>>three;

            int cal = 0;
            //calculate three
            cal += three / 2;
            three %= 2;

            //calculate two
            cal += two / 3;
            two %= 3;

            if (three == 1) {
                if (two == 1 && one >= 1) {
                    ++cal;
                    --three;
                    --two;
                    --one;
                } else if (one >= 3) {
                    cal += 1;
                    --three;
                    one -= 3;
                }
            }

            if (two >= 1) {
                if (two == 2 && one >= 2) {
                    ++cal;
                    two -= 2;
                    one -= 2;
                } else if (two == 1 && one >= 4) {
                    ++cal;
                    --two;
                    one -= 4 ;
                }
            }

            //calculate one
            cal += one / 6;
            one %= 6;

            cal >= target ? cout<<"Yes" : cout<<"No";
            cout<<endl;
        }
    }
};

#endif //ALGORITHM_COWEAT_H
