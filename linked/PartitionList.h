//
// Created by Yory on 2019/3/22.
//

#ifndef ALGORITHM_PARTITIONLIST_H
#define ALGORITHM_PARTITIONLIST_H

#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;

class PartitionList {
public:
    void test() {
        vector<int> nums{1,4,3,2,5,2};
        int x = 3;

        ListNode* head = LinkedListHelper::createLinkedList(nums);
        cout<<"before: "<<endl;
        LinkedListHelper::printLinkedList(head);

        head = partition(head, x);

        cout<<endl;
        cout<<"before: "<<endl;
        LinkedListHelper::printLinkedList(head);
    }

private:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(-1);
        ListNode* behindDummy = new ListNode(-1);

        ListNode* cur = head;
        ListNode* lessCur = lessDummy;
        ListNode* behindCur = behindDummy;
        while (cur) {
            if (cur->val < x) {
                lessCur->next = cur;
                lessCur = cur;
            } else {
                behindCur->next = cur;
                behindCur = cur;
            }
            cur = cur->next;
        }
        lessCur->next = behindDummy->next;
        behindCur->next = nullptr;
        return lessDummy->next;
    }
};


#endif //ALGORITHM_PARTITIONLIST_H
