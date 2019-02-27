//
// Created by Yory on 2019/2/27.
//

#ifndef ALGORITHM_VALIDNUMBER_H
#define ALGORITHM_VALIDNUMBER_H

#include <iostream>
#include <string>
using namespace std;

class ValidNumber {
public:
    void test() {
//        string str = "0";
//        string str = "0.1";
//        string str = "abc";
//        string str = "1 a";
//        string str = "2e10";
//        string str = "-90e3";
//        string str = " 1e";
//        string str = "e3";
//        string str = " 6e-1";
//        string str = " 99e2.5";
//        string str = "53.5e93";
//        string str = " --6";
//        string str = "-+3";
//        string str = "95a54e53";
//        string str = " ";
        string str = "1 ";

        cout<<isNumber(str)<<endl;
    }

private:
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }

        int i = 0;
        bool hasDigit = false;

        // jump blank space
        if (s[i] == ' ') {
            jumpSpace(s, i);
            if (i >= s.size()) {
                return false;
            }
        }

        // jump + or -
        if (s[i] == '+' || s[i] == '-') {
            ++i;
            if (i >= s.size() || !isdigit(s[i])) {
                return false;
            }
        }

        // jump digit
        if (i < s.size() && isdigit(s[i])) {
            hasDigit = true;
            jumpDigit(s, i);
        }

        // jump decimal
        if (s[i] == '.') {
            ++i;
            if (!hasDigit) {
                return false;
            }
            // jump the digit after decimal
            jumpDigit(s, i);
        }

        // jump e
        if (!hasDigit && s[i] == 'e') {
            return false;
        } else if (s[i] == 'e') {
            ++i;
            // jump -
            if (i < s.size() && s[i] == '-') {
                ++i;
                if (i >= s.size() || !isdigit(s[i])) {
                    return false;
                }
            } else if (i >= s.size()) {
                return false;
            }

            // jump digit
            while (i < s.size()) {
                if (!isdigit(s[i])) {
                    return false;
                }
                ++i;
            }
        }

        return i == s.size();
    }

    void jumpSpace(string& s, int& i) {
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
    }

    void jumpDigit(string& s, int& i) {
        while (i < s.size() && isdigit(s[i])) {
            ++i;
        }
    }
};


#endif //ALGORITHM_VALIDNUMBER_H
