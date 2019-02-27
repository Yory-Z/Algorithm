//
// Created by Yory on 2019/2/20.
//

#ifndef ALGORITHM_MULTIPLYSTRINGS_H
#define ALGORITHM_MULTIPLYSTRINGS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class MultiplyStrings {
public:
    void test() {
        string num1 = "2", num2 = "0";
//        string num1 = "6", num2 = "501";

        cout<<multiply(num1, num2)<<endl;
    }

private:
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            int super = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int temp = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + super;
                ans[i + j + 1] = (char)(temp % 10 + '0');
                super = temp / 10;
            }
            ans[i] += super;
        }

        size_t pos = ans.find_first_not_of('0');
        if (string::npos != pos) {
            return ans.substr(pos);
        }
        return "0";
    }
};

#endif //ALGORITHM_MULTIPLYSTRINGS_H
