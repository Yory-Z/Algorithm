//
// Created by Yory on 2019/3/10.
//

#ifndef ALGORITHM_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
#define ALGORITHM_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class LongestSubstringWithoutRepeatingCharacters {
public:
    void test() {
        string str = "abcabcbb";

        cout<<"res: "<<lengthOfLongestSubstring(str)<<endl;
    }

private:
    int lengthOfLongestSubstring(string s) {
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


};


#endif //ALGORITHM_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
