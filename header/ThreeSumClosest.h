//
// Created by Yory on 2019/1/8.
//

#ifndef ALGORITHM_THREESUMCLOSET_H
#define ALGORITHM_THREESUMCLOSET_H

#include <vector>
#include <algorithm>
using std::vector;

class ThreeSumClosest {
public:
    void testThreeSumClosest();

private:
    int threeSumClosest(vector<int>& nums, int target);

    int updateAnswer(int &answer, int sum, int target);
};

void ThreeSumClosest::testThreeSumClosest() {
    vector<int> nums{-1, 2, 1, -4};
//    vector<int> nums{0, 2, 1, -3};
    int target = 1;

    int res = threeSumClosest(nums, target);
    cout<<"res: "<<res<<endl;
}

int ThreeSumClosest::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int answer = nums.at(0) + nums.at(1) + nums.at(2);
    for (int i = 0; i < nums.size(); ++i) {
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right){
            int leftTemp = nums.at(left);
            int rightTemp = nums.at(right);
            int sum = nums.at(i) + leftTemp + rightTemp;
            int res = updateAnswer(answer, sum, target);

            cout<<"nums["<<i<<"]: "<<nums[i]<<", nums["<<left<<"]: "<<leftTemp<<", nums["<<right<<"]: "<<rightTemp<<", ";
            cout<<"sum: "<<sum<<", res: "<<res<<endl;

            if (res < 0){
                ++left;
            } else if (res > 0){
                --right;
            } else {

                return sum;
            }

/*            while (left < right && nums.at(left) == leftTemp){
                ++left;
            }
            while (left < right && nums.at(right) == rightTemp){
                --right;
            }*/
        }
        while (i < nums.size() - 1  && nums.at(i + 1) == nums.at(i)){
            ++i;
        }
    }
    return answer;
}

int ThreeSumClosest::updateAnswer(int &answer, int sum, int target) {
    int dis = sum - target;
    if (dis == 0){
        return 0;
    }

    int currentDis = answer - target;
    if (abs(currentDis) > abs(dis)){
        answer = sum;
    }
    return dis > 0 ? 1 : -1;
}


#endif //ALGORITHM_THREESUMCLOSET_H
