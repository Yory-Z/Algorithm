//
// Created by Yory on 2019/3/18.
//

#ifndef ALGORITHM_SIMPLIFYPATH_H
#define ALGORITHM_SIMPLIFYPATH_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class SimplifyPath {
public:
    void test() {
//        string path = "/home/";
//        string path = "/../";
//        string path = "/home//foo/";
        string path = "/a/./b/../../c/";
//        string path = "/a/../../b/../c//.//";
//        string path = "/a//b////c/d//././/..";
//        string path = "/...";

        cout<<simplifyPath(path)<<endl;
    }

private:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".") {
                continue;
            }

            if (tmp == ".." && !stk.empty()) {
                stk.pop_back();
            } else if (tmp != "..") {
                stk.push_back(tmp);
            }
        }

        for (string str : stk) {
            res += "/" + str;
        }
        return res.empty() ? "/" : res;
    }
};


#endif //ALGORITHM_SIMPLIFYPATH_H
