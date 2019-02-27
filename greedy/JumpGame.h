//
// Created by Yory on 2018/12/17.
//

#ifndef ALGORITHM_GREED_H
#define ALGORITHM_GREED_H

#include <vector>
#include <iostream>
using namespace std;

class JumpGame{
public:
    void testJumpGame();

    void testJumpGameJumpTime();

private:
    bool jumpGameBackTracking(int position, vector<int> &nums);
    bool jumpGameDPTopDown(int position, vector<int> &nums, int condition[]);
    bool jumpGameDPBottomUp(vector<int> &nums);
    bool jumpGameGreedy(vector<int> &nums);

    int jumpGameJumpTime(vector<int> &nums);
};

void JumpGame::testJumpGame() {
//    vector<int> nums{1};
    vector<int> nums{2,3,1,1,4};
//    vector<int> nums{3,2,1,0,4};
//    bool res = jumpGameBackTracking(0, nums2);

/*    int size = nums.size();
    int *condition = new int[size];
    for(int i = 0; i < size; ++i){
        condition[i] = -1;
    }
    condition[size-1] = 1;
    bool res = jumpGameDPTopDown(0, nums, condition);*/

//    bool res = jumpGameDPBottomUp(nums);

    bool res = jumpGameGreedy(nums);

    cout<<"res: "<<res<<endl;
}

bool JumpGame::jumpGameBackTracking(int position, vector<int> &nums) {
    if (position == nums.size() - 1){
        return true;
    }

    int temp1 = position + nums.at(position);
    int temp2 = nums.size() - 1;
    int furthestJump = temp1 <= temp2 ? temp1 : temp2;
    for(int nextPosition = position + 1; nextPosition <= furthestJump; ++nextPosition){
        if (jumpGameBackTracking(nextPosition, nums)){
            return true;
        }
    }
    return false;
}

bool JumpGame::jumpGameDPTopDown(int position, vector<int> &nums, int condition[]) {
    if (condition[position] != -1){
        return condition[position] == 1;
    }

    int temp1 = position + nums.at(position);
    int temp2 = nums.size() - 1;
    int furthestJump = temp1 <= temp2 ? temp1 : temp2;
    for(int nextPosition = position + 1; nextPosition <= furthestJump; ++nextPosition){
        if (jumpGameBackTracking(nextPosition, nums)){
            condition[position] = true;
            return true;
        }
    }
    condition[position] = false;
    return false;

}

bool JumpGame::jumpGameDPBottomUp(vector<int> &nums) {
    int *res = new int[nums.size()];
    for(int i = 0; i < nums.size(); ++i){
        res[i] = -1;
    }
    res[nums.size() - 1] = 1;

    for(int i = nums.size() - 2; i >= 0; --i){
        int temp1 = i + nums[i];
        int temp2 = nums.size() -1;
        int furJump = temp1 <= temp2 ? temp1 : temp2;
        for(int j = i + 1; j <= furJump; ++j) {
            if (res[j] == 1) {
                res[i] = 1;
                break;
            }
        }
    }
    return res[0] == 1;
}

bool JumpGame::jumpGameGreedy(vector<int> &nums) {
    int lastPos = nums.size() - 1;
    for(int i = nums.size() - 1; i >= 0; --i){
        if (i + nums[i] >= lastPos){
            lastPos = i;
        }
    }
    return lastPos == 0;
}


void JumpGame::testJumpGameJumpTime() {
//    vector<int> nums{1};
    vector<int> nums{2,3,1,1,4};

    int res = jumpGameJumpTime(nums);
    cout<<"res: "<<res<<endl;
}

int JumpGame::jumpGameJumpTime(vector<int> &nums) {
    int n = nums.size();
    if(n<2)return 0;
    int level=0,currentMax=0,i=0,nextMax=0;

    while(currentMax-i+1>0){
        level++;
        for(;i<=currentMax;i++){
            nextMax=max(nextMax,nums[i]+i);
            if(nextMax>=n-1)return level;
        }
        currentMax=nextMax;
    }
    return 0;
}



#endif //ALGORITHM_GREED_H