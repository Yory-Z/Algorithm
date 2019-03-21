//
// Created by Yory on 2019/3/21.
//

#ifndef ALGORITHM_MINIMUMWINDOWSUBSTRING_H
#define ALGORITHM_MINIMUMWINDOWSUBSTRING_H

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class MinimumWindowSubstring {
public:
    void test() {
        string s = "sdfsADOBECODEBANC";
        string t = "ABC";

/*        string s = "a";
        string t = "a";*/

/*        string s = "aa";
        string t = "aa";*/

/*        string s = "abc";
        string t = "b";*/

/*        string s = "bba";
        string t = "ab";*/

/*        string s = "a";
        string t = "b";*/

        cout<<minWindow(s, t)<<endl;
        cout<<minWindowII(s, t)<<endl;
    }

private:
    string minWindowII(string s, string t) {
        unordered_map<char, int> memo;
        for (char ch : t) {
            memo[ch]++;
        }

        int tar = t.size();
        int min = INT32_MAX, left = 0;
        int start = 0, i = 0;
        while (i <= s.size() && start < s.size()) {
            if (tar) {
                if (i == s.size()) {
                    break;
                }
                memo[s[i]]--;
                if (memo[s[i]] >= 0){
                    --tar;
                }
                ++i;
            } else {
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                memo[s[start]]++;
                if (memo[s[start]] > 0) {
                    ++tar;
                }
                ++start;
            }
        }
        return min == INT32_MAX ? "" : s.substr(left, min);
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> memo;
        for (char ch : t) {
            memo[ch]++;
        }

        int found = 0;
        int start = 0;
        int end = s.size() + 1;

        int left = 0, right = 0;
        while (left < s.size() && memo.find(s[left]) == memo.end()) {
            ++left;
        }
        right = left;

        for (;right < s.size(); ++right) {
            if (memo.find(s[right]) == memo.end()) {
                continue;
            }

            if (memo[s[right]] > 0) {
                ++found;
            }
            memo[s[right]]--;

            while (found == t.size()) {
                if (right - left < end - start) {
                    start = left;
                    end = right;
                }

                if (memo[s[left]] == 0) {
                    --found;
                }
                memo[s[left]]++;

                ++left;
                while (left < right && memo.find(s[left]) == memo.end()) {
                    ++left;
                }
            }
        }
        return end == s.size() + 1 ? "" : s.substr(start, end - start + 1);
    }
};


#endif //ALGORITHM_MINIMUMWINDOWSUBSTRING_H
