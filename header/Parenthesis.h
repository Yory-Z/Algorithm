//
// Created by Yory on 2019/1/18.
//

#ifndef ALGORITHM_PARENTHESIS_H
#define ALGORITHM_PARENTHESIS_H

#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Parenthesis {
public:
    void testParenthesis();

    void testGenerateParenthesis();

    static void testLongestValidParentheses();

private:
    bool testParenthesis(string s);
    bool isCorrect(char ch1, char ch2);

    void generateParenthesis(int n, int k, char *arr, int left, int right, vector<string> &res);

    static int longestValidParentheses(string s);
    static int longestValidParentheses2(string s);
};

//generate parenthesis
void Parenthesis::testGenerateParenthesis() {

    int n = 3;
    char* arr = new char[n*2];
    vector<string> res;
    generateParenthesis(n * 2, 0, arr, 0, 0, res);

    for (string str : res) {
        cout<<str<<endl;
    }
}

void Parenthesis::generateParenthesis(int n, int k, char *arr, int left, int right, vector<string> &res) {
    if (k == n){
        string temp;
        for (int i = 0; i < n; ++i) {
            temp += arr[i];
        }
        res.push_back(temp);
        return;
    }

    if (left < n / 2){
        arr[k] = '(';
        generateParenthesis(n, k + 1, arr, left + 1, right, res);
    }

    if (right < left){
        arr[k] = ')';
        generateParenthesis(n, k + 1, arr, left, right + 1, res);
    }
}


void Parenthesis::testParenthesis() {
//    string str = "()";
//    string str = "(){}[]";
//    string str = "(]";
    string str = "([)]";
//    string str = "{[()]}";
//    string str = "((";

    bool res = testParenthesis(str);
    cout<<"res: "<<res<<endl;

}

bool Parenthesis::testParenthesis(string s) {
    if(s.size() % 2 == 1)
        return false;

    stack<char> sta;
    for (int i = 0; i < s.size(); ++i) {
        char ch = s.at(i);
        if (ch == '(' || ch == '[' || ch == '{'){
            sta.push(ch);
        } else {
            if (sta.empty() || !isCorrect(sta.top(), ch))
                return false;
            sta.pop();
        }
    }
    return sta.empty();
}

bool Parenthesis::isCorrect(char ch1, char ch2) {
    switch (ch1) {
        case '(':
            return ch2 == ')';
        case '[':
            return ch2 == ']';
        case '{':
            return ch2 == '}';
        default:
            break;
    }
    return false;
}


void Parenthesis::testLongestValidParentheses() {
//    string str = "(()";
    string str = ")()())";
//    string str = "()())((()))";
//    string str = "))((())())))()";

    int res = longestValidParentheses(str);
    cout<<"res: "<<res<<endl;
    res = longestValidParentheses2(str);
    cout<<"res: "<<res<<endl;
}

int Parenthesis::longestValidParentheses2(string s) {
    stack<int> sta;
    sta.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i) {
        int top = sta.top();
        if (top != -1 && s.at(i) == ')' && s.at(top) == '('){
            sta.pop();
            maxLen = max(maxLen, i - sta.top());
        } else {
            sta.push(i);
        }
    }
    return maxLen;
}

int Parenthesis::longestValidParentheses(string s) {
    int left = 0, right = 0;
    int maxLen = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s.at(i) == '('){
            ++left;
        } else {
            ++right;
        }

        if (left == right){
            maxLen = max(maxLen, 2 * right);
        } else if (right > left){
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;
    for(int i = s.size() - 1; i >= 0; --i){
        if(s.at(i) == '('){
            ++left;
        } else {
            ++right;
        }

        if (left == right){
            maxLen = max(maxLen, 2 * right);
        } else if (left > right){
            left = 0;
            right = 0;
        }
    }
    return maxLen;

}

#endif //ALGORITHM_PARENTHESIS_H
