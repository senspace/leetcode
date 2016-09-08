//
//  main.cpp
//  leetcode
//
//  Created by NoteFAN on 3/16/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) return head;
    int length = 1;
    ListNode *node = head;
    while (node->next != nullptr) ++length;
    k %= length;
    if (k == 0) return head;
    ListNode *new_tail = head;
    for (int i = 1; i < length - k; ++i) {
        new_tail = new_tail->next;
    }
    ListNode *new_head = new_tail->next;
    new_tail->next = nullptr;
    node->next = head;
    return new_head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode dummy(0);
    ListNode *node = &dummy;
    for (int i = 1; i < 5; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }
    ListNode *result = rotateRight(&dummy, 2);
    while(result) {
        cout << result->val << " ";
        ListNode *node = result;
        result = result->next;
        delete node;
    }
    
    
    return 0;
}






