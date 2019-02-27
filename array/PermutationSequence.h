//
// Created by Yory on 2019/2/22.
//

#ifndef ALGORITHM_PERMUTATIONSEQUENCE_H
#define ALGORITHM_PERMUTATIONSEQUENCE_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class PermutationSequence {
public:
    void test() {
        int n = 4;
        int k = 9;

        cout<<getPermutation(n, k)<<endl;
        cout<<getPermutationII(n, k)<<endl;
    }

private:
    string getPermutation(int n, int k) {
        vector<int> vec(n, 0);
        for(int i = 0; i < n; ++i) {
            vec[i] = i + 1;
        }

        for(int i = 0; i < k - 1; ++i) {
            next_permutation(vec.begin(), vec.end());
        }

        string str;
        for(int i = 0; i < vec.size(); ++i) {
            str += to_string(vec[i]);
        }
        return str;
    }

    string getPermutationII(int n, int k) {
        vector<int> factors(n, 0);
        vector<int> num(n, 0);

        factors[0] = 1;
        num[0] = 1;
        for (int i = 1; i < n; ++i) {
            factors[i] = i * factors[i - 1];
            num[i] = i + 1;
        }

        --k;
        string str;
        for (int i = 1; i <= n; ++i) {
            int index = k / factors[n - i];
            str += to_string(num[index]);
            num.erase(num.begin() + index);
            k -= index * factors[n - i];
        }
        return str;
    }

};

#endif //ALGORITHM_PERMUTATIONSEQUENCE_H
