//
// Created by Yory on 2019/3/21.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST_H

#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;

class RemoveDuplicatesFromSortedList {
public:
    void test() {
//        vector<int> nums{1,1,2};
//        vector<int> nums{1,1,2,3,3};
        vector<int> nums{1,1,1,3};
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
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};


#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST_H
