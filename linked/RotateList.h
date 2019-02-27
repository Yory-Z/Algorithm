//
// Created by Yory on 2019/2/25.
//

#ifndef ALGORITHM_ROTATELIST_H
#define ALGORITHM_ROTATELIST_H

#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;

class RotateList {
public:
    void test() {
        ListNode* head = LinkedListHelper::createLinkedList(0, 3);
        cout<<"before: "<<endl;
        LinkedListHelper::printLinkedList(head);
        cout<<endl;

        cout<<"after: "<<endl;
        LinkedListHelper::printLinkedList(rotateRight(head, 4));
    }

private:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* cur = dummy;
        int length = 0;
        while (cur->next != NULL) {
            ++length;
            cur = cur->next;
        }

        int rotateLen = k % length;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for (int i = 0; i < rotateLen; ++i) {
            fast = fast->next;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = dummy->next;
        dummy->next = slow->next;
        slow->next = NULL;
        return dummy->next;
    }
};

#endif //ALGORITHM_ROTATELIST_H
