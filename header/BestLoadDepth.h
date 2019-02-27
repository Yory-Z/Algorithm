//
// Created by Yory on 2018/12/19.
//

#ifndef ALGORITHM_TRACKBACK_H
#define ALGORITHM_TRACKBACK_H

class BestLoadDepth{
public:
    void testBestLoad();

private:
    int boxSum;//集装箱的数量
    int *boxWeight;//每个集装箱的重量
    int maxLoad;//轮船最大载重量
    int currentLoad;//当前载重量
    int bestWeight;//当前最优载重量
    int restWeight;//剩余集装箱重量

    int *solve;//存储转入轮船的集装箱
    int *bestSolve;//存储最优解

    void BackTrackCut(int i);
};

void BestLoadDepth::testBestLoad() {
    int temp[]{6, 11, 17, 8, 9};
    boxSum = end(temp) - begin(temp);

    boxWeight = temp;
    maxLoad = 21;
    currentLoad = 0;
    bestWeight = 0;

    solve = new int[boxSum];
    bestSolve = new int[boxSum];
    for(int i = 0; i < boxSum; ++i){
        restWeight += boxWeight[i];
        solve[i] = 0;
    }

    BackTrackCut(0);

    cout<<"bestW: "<<bestWeight<<endl;
    for(int i = 0; i < boxSum; ++i){
        if (bestSolve[i])
            cout<<i<<" : "<<boxWeight[i]<<endl;
    }
    cout<<endl;
}

void BestLoadDepth::BackTrackCut(int i) {
//    cout<<"i: "<<i<<", boxSum: "<<boxSum<<", cW: "<<currentLoad<<", bestW: "<<bestWeight<<endl;
    if (i >= boxSum){
        if(currentLoad > bestWeight){
            for(int j = 0; j < boxSum; ++j){
                bestSolve[j] = solve[j];
            }
            bestWeight = currentLoad;
        }
        return;
    }

    //search left subtree
    restWeight -= boxWeight[i];
    if(currentLoad + boxWeight[i] <= maxLoad){
        solve[i] = 1;
        currentLoad += boxWeight[i];
        BackTrackCut(i+1);
        currentLoad -= boxWeight[i];
    }

    //search right subtree
    if(currentLoad + restWeight > bestWeight){
        solve[i] = 0;
        BackTrackCut(i+1);
    }
    restWeight += boxWeight[i];
}

#endif //ALGORITHM_TRACKBACK_H

