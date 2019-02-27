//
// Created by Yory on 2019/2/21.
//

#ifndef ALGORITHM_GROUPANAGRAMS_H
#define ALGORITHM_GROUPANAGRAMS_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class GroupAnagrams {
public:
    void test() {
        vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
//        vector<string> strs{"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};

        vector<vector<string>> res = groupAnagrams(strs);
        for (vector<string> vec : res) {
            for (string str : vec) {
                cout<<str<<", ";
            }
            cout<<endl;
        }
    }

private:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        for (int i = 0; i < strs.size(); ++i) {
/*            string temp = strs[i];
            sort(temp.begin(), temp.end());
            myMap[temp].push_back(strs[i]);*/
            myMap[strSort(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (unordered_map<string, vector<string>>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    string strSort(string str) {
        int count[26] = {0};
        for (char ch : str) {
            count[ch - 'a']++;
        }

        string res;
        for (int i = 0; i < 26; ++i) {
            res += string(count[i], i - 'a');
        }
        return res;
    }
};

#endif //ALGORITHM_GROUPANAGRAMS_H
