//
// Created by Yory on 2019/2/27.
//

#ifndef ALGORITHM_ADDBINARY_H
#define ALGORITHM_ADDBINARY_H

#include <string>
#include <iostream>
using namespace std;

class AddBinary {
public:
    void test() {
/*        string a{"11"};
        string b{"1"};*/

        string a{"1010"};
        string b{"1011"};

/*        string a{"111"};
        string b{"11111"};*/

/*        string a{"101"};
        string b{"10"};*/

        cout<<addBinary(a, b)<<endl;
        cout<<addBinaryII(a, b)<<endl;
    }

private:
    string addBinaryII(string a, string b) {
        string str;

        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            str = char(carry % 2 + '0') + str;
            carry /= 2;
        }
        return str;
    }

    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        string str(max(a.size(), b.size()) + 1, '0');
        int index = str.size() - 1;

        while (i >= 0) {
            int temp = (a[i] - '0') + carry + (j >= 0 ? (b[j] - '0') : 0);
            if (temp == 3) {
                carry = 1;
                str[index] = '1';
            } else if (temp == 2) {
                carry = 1;
                str[index] = '0';
            } else {
                carry = 0;
                str[index] = temp + '0';
            }
            --i;
            --j;
            --index;
        }

        if (index >= 0) {
            if (carry == 1) {
                str[index] = '1';
            } else {
                str.erase(str.begin());
            }
        }
        return str;
    }
};

#endif //ALGORITHM_ADDBINARY_H
