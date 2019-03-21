//
// Created by Yory on 2019/3/21.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDLISTII_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDLISTII_H

#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;

class RemoveDuplicatesFromSortedListII {
public:
    void test() {
//        vector<int> nums{1,2,3,3,4,4,5};
//        vector<int> nums{1,1,1,2,3};
        vector<int> nums{-1,0,0,0,0,3,3};
        ListNode* head = LinkedListHelper::createLinkedList(nums);

        cout<<"before: "<<endl;
        LinkedListHelper::printLinkedList(head);

        head = deleteDuplicates(head);

        cout<<endl;
        cout<<"after: "<<endl;
        LinkedListHelper::printLinkedList(head);

    }

private:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            ListNode* begin = cur;
            if (cur->next && begin->val == cur->next->val) {
                while (cur->next && begin->val == cur->next->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDLISTII_H
