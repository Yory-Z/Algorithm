//
// Created by Yory on 2018/12/28.
//
#include <algorithm>
#include "vector"
#include "set"
using std::vector;
using std::set;

#ifndef ALGORITHM_THREESUMTRACKBACK_H
#define ALGORITHM_THREESUMTRACKBACK_H

class ThreeSumTrackBack {
public:
    void testThreeSum();

private:
    int currentValue;
    int currentSize;
    int *dist;
    set<vector<int>> result;
    vector<int> numbers;

    void BackTrack(int t);
    void PrintResult();
    bool checkDuplicated(vector<int> &vet);

};


void ThreeSumTrackBack::testThreeSum() {
        numbers = {-1, 0, 1, 2, -1, -4};
//    numbers = {-8,8,5,-2,-8,-9,-10,6,-3,-5,5,-6,-2,-6,5,-5,7,3,-4,0,-5,-2};
//    numbers = {-7,-5,5,-6,-2,1,7,3,-4,-2,-2,-4,-8,-1,8,8,-2,-7,3,2,-7,8,-3,-10,5,2,8,7,7};
    currentValue = 0;
    currentSize = 0;

    dist = new int[numbers.size()];
    for (int i = 0; i < numbers.size(); ++i) {
        dist[i] = 0;
    }

    BackTrack(0);
    PrintResult();

}


void ThreeSumTrackBack::BackTrack(int t) {

    if (currentValue == 0 && currentSize == 3){
        vector<int> temp;
        for (int i = 0; i < numbers.size(); ++i) {
            if (dist[i] == 1){
                temp.push_back(numbers.at(i));
            }
        }
        if (temp.size() == 3 && result.count(temp) ==0 && checkDuplicated(temp)){
            cout<<"Into-------------------------------------"<<endl;
            result.insert(temp);
        }
        return;
    }

    if (t == numbers.size()){
        return;
    }

    currentValue += numbers[t];
    ++currentSize;
    dist[t] = 1;
    BackTrack(t + 1);
    dist[t] = 0;
    --currentSize;
    currentValue -= numbers[t];

    BackTrack(t + 1);
}

void ThreeSumTrackBack::PrintResult() {
    cout<<"currentValue: "<<currentValue<<endl;
    for (auto it = result.cbegin(); it != result.cend(); ++it) {
        vector<int> temp = *it;
        for (int j = 0; j < temp.size(); ++j) {
            cout<<temp.at(j)<<' ';
        }
        cout<<endl;
    }
}

bool ThreeSumTrackBack::checkDuplicated(vector<int> &vet) {
    for (auto it = result.cbegin(); it != result.cend() ; ++it) {
        vector<int> vetTemp = *it;
        set<int> setTemp;
        set<int> tester;
        for (int i = 0; i < vetTemp.size(); ++i) {
            setTemp.insert(vetTemp.at(i));
            tester.insert(vet.at(i));
        }
        if (setTemp == tester){
            return false;
        }
    }
    return true;
}

#endif //ALGORITHM_THREESUMTRACKBACK_H
