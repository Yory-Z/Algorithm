//
// Created by Yory on 2019/2/19.
//

#ifndef ALGORITHM_LINKEDLISTCYCLEII_H
#define ALGORITHM_LINKEDLISTCYCLEII_H

#include <vector>
#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;
using namespace LinkedListHelper;

class LinkedListCycleII {
public:
    void test() {
        vector<int> nums{3,2,0,-4};
        int pos = 1;

/*        vector<int> nums{1,2};
        int pos = 0;*/

/*        vector<int> nums{1};
        int pos = -1;*/

        ListNode* begin = detectCycle(LinkedListHelper::createCycleList(nums, pos));
        if (begin != nullptr)
            cout<<begin->val<<endl;
        else
            cout<<"null"<<endl;
    }

private:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // check if the linked list have cycle or not
        // and let the two pointers move into the cycle
        while (fast != nullptr && slow != nullptr) {
            slow = slow->next;
            for (int i = 0; i < 3; ++i) {
                fast = fast->next;
                if (fast == nullptr)
                    return nullptr;
            }

            if (fast == slow) {
                break;
            }
        }

        if (fast == nullptr || slow == nullptr) {
            return nullptr;
        }

        //has cycle, calculate the sum of nodes in the cycle
        int cycleNum = 1;
        fast = fast->next;
        while (fast != slow) {
            fast = fast->next;
            ++cycleNum;
        }

        fast = head;
        slow = head;
        for (int i = 0; i < cycleNum; ++i) {
            fast = fast->next;
        }

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

#endif //ALGORITHM_LINKEDLISTCYCLEII_H
