//
// Created by Yory on 2019/2/3.
//

#ifndef ALGORITHM_LINKEDLISTHEPLER_H
#define ALGORITHM_LINKEDLISTHEPLER_H

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace LinkedListHelper {

    ListNode* createRandomLinkedList(int start, int end, int k) {
        ListNode* dummyHead = new ListNode(-1);
        srand(time(NULL));

        ListNode* cur = dummyHead;
        for (int i = 0; i < k; ++i) {
            int num = rand() % (end - start + 1) + start;
            cout<<"insert "<<num<<endl;
            cur->next = new ListNode(num);
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummyHead->next;
    }

    ListNode* createLinkedList(int start, int end) {
        ListNode* dummyHead = new ListNode(-1);
        srand(time(NULL));

        ListNode* cur = dummyHead;
        for (int i = start; i < end; ++i) {
            cout<<"insert "<<i<<endl;
            cur->next = new ListNode(i);
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummyHead->next;
    }

    void printLinkedList(ListNode* listNode) {
        while (listNode != nullptr) {
            cout<<listNode->val<<' ';
            listNode = listNode->next;
        }
    }

    ListNode* createCycleList(vector<int> nums, int pos) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        for (int i = 0; i < nums.size(); ++i) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }

        if (pos != -1) {
            ListNode* tail = cur;
            cur = dummyHead->next;

            for (int j = 0; j < pos; ++j) {
                cur = cur->next;
            }
            tail->next = cur;
        }

        return dummyHead->next;
    }

}

#endif //ALGORITHM_LINKEDLISTHEPLER_H
