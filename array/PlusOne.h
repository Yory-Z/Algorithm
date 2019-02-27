//
// Created by Yory on 2019/2/27.
//

#ifndef ALGORITHM_PLUSONE_H
#define ALGORITHM_PLUSONE_H

#include <iostream>
#include <vector>
using namespace std;

class PlusOne {
public:
    void test() {
//        vector<int> digits{1, 2, 3};
//        vector<int> digits{4, 3, 2, 1};
//        vector<int> digits{9, 9, 9, 9};
        vector<int> digits{0};
//        vector<int> digits{4, 9, 8, 9};

        vector<int> res = plusOneII(digits);

        for (int i : res) {
            cout<<i<<' ';
        }
        cout<<endl;
    }

private:
    vector<int> plusOneII(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                ++digits[i];
                return digits;
            }
        }

        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }

    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        int carry = 0;

        int temp = digits[index] + 1;
        digits[index] = temp % 10 + carry;
        carry = temp / 10;
        --index;
        if (index < 0) {
            if (carry > 0)
                digits.insert(digits.begin(), carry);
            return digits;
        }

        while (true) {
            temp = digits[index] + carry;
            digits[index] = temp % 10;
            carry = temp / 10;
            if (carry == 0) {
                break;
            }
            --index;
            if (index < 0) {
                if (carry > 0)
                    digits.insert(digits.begin(), carry);
                break;
            }
        }
        return digits;
    }
};

#endif //ALGORITHM_PLUSONE_H
