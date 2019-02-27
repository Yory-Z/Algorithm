//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_TRIANGLE_H
#define ALGORITHM_TRIANGLE_H

#include <vector>
#include <iostream>
using namespace std;

class Triangle {
public:
    void test() {
        vector<vector<int>> triangle = {
                {2},
                {3,4},
                {6,5,7},
                {4,1,8,3}
        };

        cout<<minimumTotalTopToBottom(triangle)<<endl;
        cout<<minimumTotalBottomToTop(triangle)<<endl;
    }

private:
    vector<int> minimum;

    int minimumTotalTopToBottom(vector<vector<int>>& triangle);

    int minimumTotalBottomToTop(vector<vector<int>>& triangle);
};

int Triangle::minimumTotalTopToBottom(vector<vector<int>>& triangle) {
    if (triangle.empty()) {
        return 0;
    }

    minimum = vector<int>(triangle[triangle.size()-1].size(), 0);
    minimum[0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = triangle[i].size() - 1; j >= 0; --j) {
            int minTemp = 0;
            if (j - 1 >= 0) {
                minTemp = minimum[j - 1];
            }

            if (j < i && j >= 0) {
                if (minTemp == 0) {
                    minTemp = minimum[j];
                } else {
                    minTemp = minTemp <= minimum[j] ? minTemp : minimum[j];
                }
            }

            minimum[j] = minTemp + triangle[i][j];
        }
    }

    int resMin = 0;
    for (int k = 1; k < minimum.size(); ++k) {
        if (minimum[resMin] > minimum[k]){
            resMin = k;
        }
    }
    return minimum[resMin];
}

int Triangle::minimumTotalBottomToTop(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
        return 0;
    }

    for (int i = triangle.size() - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

#endif //ALGORITHM_TRIANGLE_H
