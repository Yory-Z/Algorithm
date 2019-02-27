//
// Created by Yory on 2018/12/17.
//
#ifndef ALGORITHM_STRINGOPERATION_H
#define ALGORITHM_STRINGOPERATION_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;

class StringOperation{
public:
    static void testLongestString();

    void testSubstringWithAllWords();

    static void testLongestValidParentheses();

private:
    static int longestString(string s);
    static int longestStringFaster(string s);

    vector<int> SubstringWithAllWords(const string &s, vector<string> &words);
    vector<int> SubstringWithAllWordsWithMap(const string &s, vector<string> &words);

    static int longestValidParentheses(string s);
};

void StringOperation::testLongestString() {
    string s1 = "abcabcbb";
    int res = longestString(s1);
    cout<<"res: "<<res<<endl;
    int res2 = longestStringFaster(s1);
    cout<<"res2: "<<res2<<endl;
}

int StringOperation::longestString(string s) {
    int size = s.size();
    unsigned int i = 0, j = 0;
    int ans = 0;
    set<char> set;
    while (i < size && j < size) {
        if (set.count(s[j]) == 0) {
            set.insert(s[j++]);
            int temp = j - i;
            ans = ans > temp ? ans : temp;
        }
        else {
            set.erase(s[i++]);
        }
    }
    return ans;
}

int StringOperation::longestStringFaster(string s) {
    int ans = 0;
    unordered_map<char, int> myMap;
    for(int j = 0, i = 0; j < s.size(); ++j){
        if(myMap.find(s.at(j)) != myMap.end()){
            i = max(myMap.at(s.at(j)), i);
        }
        ans = max(ans, j - i + 1);
        myMap[s.at(j)] = j+1;
    }
    return ans;
}


void StringOperation::testSubstringWithAllWords() {

    string str = "barfoothefoobarman";
    vector<string> words{"bar","foo"};

/*    string str = "wordgoodgoodgoodbestword";
    vector<string> words{"word","good","best","word"};*/

    vector<int> res = SubstringWithAllWordsWithMap(str, words);
    for (int i : res){
        cout<<i<<' ';
    }
    cout<<endl;
}

vector<int> StringOperation::SubstringWithAllWordsWithMap(const string &s, vector<string> &words) {
    vector<int> res;
    if (s.empty() || words.empty() || s.size() < words.at(0).size()) {
        return res;
    }

    int wordLength = words.at(0).size();

    unordered_map<string, int> unOrMap;
    for (int i = 0; i < words.size(); ++i) {
        string str = words.at(i);
        if (unOrMap.count(str) == 0) {
            unOrMap.insert({str, 1});
        } else {
            unOrMap.at(str) += 1;
        }
    }

    int end = s.size() - words.size() * wordLength + 1;
    for (int i = 0; i < end; ++i) {
        unordered_map<string, int> tempMap;

        int index = i;
        while (index - i < words.size() * wordLength) {
            string str = s.substr(index, wordLength);
            if (unOrMap.count(str) != 0) {
                if (tempMap.count(str) == 0) {
                    tempMap.insert({str, 1});
                } else if(unOrMap.at(str) > tempMap.at(str)) {
                    tempMap.at(str) += 1;
                } else {
                    break;
                }
                index += wordLength;
            } else {
                break;
            }
        }

        if(index - i == words.size() * wordLength) {
            res.push_back(i);
            i += wordLength - 1;
        }
    }

    return res;
}

vector<int> StringOperation::SubstringWithAllWords(const string &s, vector<string> &words) {
    vector<int> res;
    if(s.empty() || words.empty() || words.at(0).size() > s.size()){
        return res;
    }

    bool* arr = new bool[words.size()];
    for(int i = 0; i < words.size(); ++i){
        arr[i] = false;
    }

    int end = s.size() - words.size() * words.at(0).size() + 1;
    for(int i = 0; i < end; ++i) {

        int index = i;
        for(int j = 0; j < words.size(); ++j){
            if (!arr[j] && s.substr(index, words.at(j).size()) == words.at(j)) {

                index += words.at(j).size();
                arr[j] = true;
                j = -1;
            }
        }

        if (index - i == words.size() * words.at(0).size()){
            res.push_back(i);
        }

        if (index != i) {
            for(int k = 0; k < words.size(); ++k){
                arr[k] = false;
            }
        }
    }

    return res;
}


void StringOperation::testLongestValidParentheses() {
//    string s = "(()";
//    string s = ")()())";
    string s = "))((())()))";
    int res = longestValidParentheses(s);
    cout<<"res: "<<res<<endl;
}

int StringOperation::longestValidParentheses(string s) {

    int i = 0;
    int ans = 0;
    int sum = 0;
    stack<char> sta;

    while(i < s.size()) {

        while(i < s.size() && s.at(i) == ')')
            ++i;

        int left = 0;
        while(i < s.size() && s.at(i) == '(') {
            ++left;
            sta.push(s.at(i++));
        }

        int right = 0;
        while(i < s.size() && !sta.empty() && s.at(i) == ')') {
            ++i;
            ++right;
            sta.pop();
        }

        if (right >= left) {
            sum += right * 2;
        }
        else{
            ans = max(ans, sum);
            sum = 0;
        }

    }
    return max(ans, sum);
}
#endif //ALGORITHM_STRINGOPERATION_H
