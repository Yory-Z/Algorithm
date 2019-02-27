//
// Created by Yory on 2019/2/3.
//

#ifndef ALGORITHM_MERGESORTEDLIST_H
#define ALGORITHM_MERGESORTEDLIST_H

#include <vector>
#include <queue>
#include <iostream>
#include "../util/LinkedListHepler.h"
using namespace std;
using namespace LinkedListHelper;

struct myCmp{
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val >= l2->val;
    }
};


class MergeSortedList {
public:
    static void test();

private:
    static ListNode* mergeKLists(vector<ListNode*>& lists);

    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    static ListNode* merge(vector<ListNode*>& lists, int start, int end);
};

void MergeSortedList::test() {

    vector<ListNode *> vec;
    for (int i = 3; i < 6; ++i) {
        vec.push_back(LinkedListHelper::createLinkedList(0, 100, i));
    }
    LinkedListHelper::printLinkedList(mergeKLists(vec));
}

ListNode* MergeSortedList::mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, myCmp> pq;
    for (int i = 0; i < lists.size(); ++i) {
        ListNode* cur = lists.at(i);
        while (cur != nullptr) {
            pq.push(cur);
            cur = cur->next;
        }
    }

    ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;
    while (!pq.empty()) {
        cur->next = pq.top();
        pq.pop();
        cur = cur->next;
    }
    cur->next = nullptr;
    return dummyHead->next;
}



ListNode* MergeSortedList::mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode* node = new ListNode(-1);
    ListNode* head = node;
    node->next = NULL;

    while (l1 != NULL && l2 != NULL) {

        if (l1->val <= l2->val){
            node->next = l1;
            node = l1;
            l1 = l1->next;
        } else {
            node->next = l2;
            node = l2;
            l2 = l2->next;
        }
    }

    if (l1 != NULL) {
        node->next = l1;
    } else if (l2 != NULL) {
        node->next = l2;
    }
    return head->next;
}

ListNode* MergeSortedList::merge(vector<ListNode*>& lists, int start, int end) {
    if (start == end) {
        return lists.at(start);
    }

    if (start + 1 == end){
        return mergeTwoLists(lists.at(start), lists.at(end));
    }

    int mid = start + (end - start) / 2;
    ListNode* leftNode = merge(lists, start, mid);
    ListNode* rightNode = merge(lists, mid + 1, end);
    return mergeTwoLists(leftNode, rightNode);
}

#endif //ALGORITHM_MERGESORTEDLIST_H
