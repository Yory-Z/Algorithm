//
// Created by Yory on 2019/2/27.
//

#ifndef ALGORITHM_REMOVENTHNODEFROMENDOFLIST_H
#define ALGORITHM_REMOVENTHNODEFROMENDOFLIST_H

#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;

class RemoveNthNodeFromEndOfList {
public:
    void test() {
        int start = 1;
        int end = 13;
        ListNode* head = LinkedListHelper::createLinkedList(start, end);
        cout<<"before: "<<endl;
        LinkedListHelper::printLinkedList(head);
        cout<<endl;

        int n = 3;
        head = removeNthFromEnd(head, n);
        cout<<"after: "<<endl;
        LinkedListHelper::printLinkedList(head);
    }

private:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preNode = new ListNode(-1);
        preNode->next = head;

        ListNode* slow = preNode;
        ListNode* faster = preNode;
        for (int i = 0; i <= n; ++i)
            faster = faster->next;

        while (faster != NULL) {
            slow = slow->next;
            faster = faster->next;
        }
        slow->next = slow->next->next;

        //here, we should return preNode->next, not head, head wasn't be deleted
        return preNode->next;
    }
};

#endif //ALGORITHM_REMOVENTHNODEFROMENDOFLIST_H
