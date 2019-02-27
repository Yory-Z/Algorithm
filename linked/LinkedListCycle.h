//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_LINKEDLISTCYCLE_H
#define ALGORITHM_LINKEDLISTCYCLE_H

#include <iostream>
#include <vector>
#include "../util/LinkedListHepler.h"
using namespace std;
using namespace LinkedListHelper;

class LinkedListCycle {
public:
    void test() {
        vector<int> nums{3,2,0,-4};
        int pos = 1;

/*        vector<int> nums{1,2};
        int pos = 0;*/

/*        vector<int> nums{1};
        int pos = -1;*/

        cout<<hasCycle(LinkedListHelper::createCycleList(nums, pos));
    }

private:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && slow != nullptr) {
            slow = slow->next;
            for (int i = 0; i < 3; ++i) {
                fast = fast->next;
                if (fast == nullptr)
                    return false;
            }

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

#endif //ALGORITHM_LINKEDLISTCYCLE_H
