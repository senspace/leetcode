//
//  list.cpp
//  leetcode
//
//  Created by NoteFAN on 4/10/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
#include "math.h"
#include "single_linked_list.h"

using namespace std;

/* Delete a linked list */
ListNode *DeleteList(ListNode *head) {
    ListNode *p_temp = nullptr;
    while (head) {
        p_temp = head->next;
        delete head;
        head = p_temp;
    }
    return head;
}

/* Recursive delete a list */
void RecursiveDelete(ListNode *head) {
    if (!head) {
        return;
    }
    RecursiveDelete(head->next);
    delete head;
}

/* Time complexity: O(n^2) Space complexity: O(1) */
void MinDelete::MinDeleteElement(ListNode *head) {
    while (head->next != nullptr) {
        ListNode *pre = head;
        ListNode *p = pre->next;    // p为工作指针
        while (p->next != nullptr) {
            if (pre->next->var > p->next->var) {
                pre = p;
            }
            p = p->next;
        }
        ListNode *u = pre->next;
        pre->next = u->next;
        cout << u->var << " ";
        delete u;
    }
    delete head;
    cout << endl;
}

/* Time complexity: O(max(m, n)) Space complexity: O(1) */
ListNode *AddNumber::AddTwoNode(ListNode *list1, ListNode *list2) {
    ListNode result(-1);
    ListNode *point = &result;
    int carry = 0;
    for (ListNode *pa = list1, *pb = list2; \
         pa != nullptr || pb != nullptr; \
         pa = pa == nullptr ? nullptr: pa->next, \
         pb = pb == nullptr ? nullptr: pb->next, \
         point = point->next) {
        const int a = pa == nullptr ? 0 : pa->var;
        const int b = pb == nullptr ? 0 : pb->var;
        point->next = new ListNode((a + b + carry) % 10);
        carry = (a + b) / 10;
    }
    return result.next;
}

/* Time complexity: O(n) Space complexity O(1) */
ListNode *ReverseLinkedList::ReverseLinkedListBetween(ListNode *head, int m, int n) {
    ListNode result(-1);
    result.next = head;
    ListNode *prev = &result;
    for (int i = 0; i < m - 1; ++i) {
        prev = prev->next;
    }
    ListNode *head2 = prev;
    prev = prev->next;
    ListNode *cur = prev->next;
    for (int i = m; i < n; ++i) {
        prev->next = cur->next;
        cur->next = head2->next;
        head2->next = cur;
        cur = prev->next;
    }
    
    return result.next;
}

/* Time complexity: O(n) Space complexity O(1) */
ListNode *PartitionList::PartitionListOrder(ListNode *head, int x) {
    ListNode left_dummy(-1);
    ListNode right_dummy(-1);
    ListNode *left_head = &left_dummy;
    ListNode *right_head = &right_dummy;
    
    for (auto it = head; it != nullptr; it = it->next) {
        if (it->var < x) {
            left_head->next = it;
            left_head = left_head->next;
        } else {
            right_head->next = it;
            right_head = right_head->next;
        }
    }
    left_head->next = right_dummy.next;
    right_head->next = nullptr;
    
    return left_dummy.next;
}


/* 迭代版: Time complexity: O(n), Space complexity: O(1) */
ListNode *RemoveDuplicatesFromSortedList::RemoveDuplicatesFromSortedListOne(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    for (ListNode *pre = head, *cur = pre->next; pre->next != nullptr; cur = pre->next) {
        if (pre->var != cur->var) {
            pre = pre->next;
        } else {
            ListNode *p_temp = cur;
            pre->next = cur->next;
            delete p_temp;
        }
    }
    return head;
}

/* 递归版: Time complexity: O(n), Space complexity: O(1) */
ListNode *RemoveDuplicatesFromSortedList::RemoveDuplicatesFromSortedListTwo(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode *pre = head;
    ListNode *cur = pre->next;
    if (cur != nullptr) {
        recur(pre, cur);
    }
    return head;
}

/* 迭代版: Time complexity: O(n), Space complexity: O(1) */
ListNode *RemoveDuplicatesFromSortedList::RemoveDuplicatesFromSortedListThree(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *head2 = &dummy;
    VariableSign sign = VariableSign(head2->next->var);
    ListNode *pre, *cur;
    for (pre = head2->next, cur = pre->next; cur != nullptr; cur = pre->next) {
        if (cur->var == sign.var) {
            pre->next = cur->next;
            delete cur;
            sign.duplicate = true;
        } else {
            if (sign.duplicate) {
                ListNode *p_temp = pre;
                head2->next = cur;
                pre = cur;
                delete p_temp;
                sign.duplicate = false;
                sign.var = pre->var;
            } else {
                head2 = pre;
                pre = cur;
                sign.var = pre->var;
            }
        }
    }
    if (sign.duplicate) {
        head2->next = pre->next;
        delete pre;
    }
    return dummy.next;
}

/* 递归版: Time complexity: O(n), Space complexity: O(1) */
ListNode *RemoveDuplicatesFromSortedList::RemoveDuplicatesFromSortedListFour(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *p_temp = head->next;
    if (head->var == p_temp->var) {
        while (p_temp && head->var == p_temp->var) {
            ListNode *temp = p_temp;
            p_temp = p_temp->next;
            delete temp;
        }
        delete head;
        return RemoveDuplicatesFromSortedListFour(p_temp);
    } else {
        head->next = RemoveDuplicatesFromSortedListFour(head->next);
        return head;
    }
}
    
/* Time complexity: O(n) Space complexity: O(1) */
ListNode *RotateList::RotateListRight(ListNode *head, size_t k) {
    size_t length = 0;
    ListNode *it;
    for (it = head; it->next != nullptr; it = it->next) {
        length += 1;
    }
    length += 1;
    it->next = head;
    size_t m = k % length;
    ListNode *head2 = head, *tail;
    for (size_t i = 0; i < length - m - 1; ++i) {
        head2 = head->next;
    }
    tail = head2;
    head2 = head2->next;
    tail->next = nullptr;
    return head2;
}
    
/* Time complexity: O(n) Space complexity: O(1) */
ListNode *RemoveNode::RemoveNthNodeFromEndOfList(ListNode *head, int n) {
    ListNode *p = head, *v = head;
    for (int i = 0; i < n; ++i) {
        v = v->next;
    }
    while (v->next != nullptr) {
        v = v->next;
        p = p->next;
    }
    ListNode *p_temp = p->next;
    p->next = p_temp->next;
    delete p_temp;
    return head;
}
    
/* Time complexity: O(n) Space complexity: O(1) */
ListNode *SwapNodesInPairs::SwapNodesInPairsOne(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode dummy(-1);
    dummy.next = head;
    for (ListNode *pre = &dummy, *cur = pre->next, *next = cur->next;
         next != nullptr;
         pre = cur, cur = pre->next, next = cur ? cur->next : nullptr) {
        pre->next = next;
        cur->next = next->next;
        next->next = cur;
    }
    return dummy.next;
}

/* 迭代版: Time complexity: O(n) Space complexity: O(1) */
ListNode *ReverseNodes::ReverseNodesInKGroupOne(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k < 2) {
        return head;
    }
    ListNode dummy(-1);
    dummy.next = head;
    for (ListNode *pre = &dummy, *end = head; end; end = pre->next) {
        for (int i = 1; i < k && end; ++i) {
            end = end->next;
        }
        if (end == nullptr) {
            break;
        }
        pre = Reverse(pre, pre->next, end);
    }
    return dummy.next;
}

/* reverse the list: [begin, end] */
ListNode *ReverseNodes::Reverse(ListNode *pre, ListNode *begin, ListNode *end) {
    ListNode *tail = end->next;
    ListNode *cur = begin;
    for (ListNode *next = cur->next; next != tail; next = cur->next) {
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return cur;
}

/* 递归版: Time complexity: O(n) Space complexity: O(1) */
ListNode *ReverseNodes::ReverseNodesInKGroupTwo(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k < 2) {
        return head;
    }
    ListNode *next_group = head;
    for (int i = 1; i < k && next_group; ++i) {
        next_group = next_group->next;
    }
    if (next_group) {
        next_group = next_group->next;
    } else {
        return head;
    }
    
    // next_group is the head of next group
    // new_next_group is the new head of next group after reversion
    ListNode *new_next_group = ReverseNodesInKGroupTwo(next_group, k);
    ListNode *prev = nullptr, *cur = head;
    while (cur != next_group) {
        ListNode *next = cur->next;
        cur->next = prev ? prev : new_next_group;
        prev = cur;
        cur = next;
    }
    // prev is the new head of this group
    return prev;
}

/*
 * deep copy
 * Time complexity: O(n) Space complexity: O(1)
 */
RandomListNode *CopyList::CopyListWithRandomPointer(RandomListNode *head) {
    for (RandomListNode *it = head; it; ) {
        RandomListNode *node = new RandomListNode(it->label);
        node->next = it->next;
        it->next = node;
        it = node->next;
    }
    for (RandomListNode *it = head; it; it = it->next->next) {
        if (it->random) {
            it->next->random = it->random->next;
        }
    }
    // split the single linked list
    RandomListNode dummy(-1);
    for (RandomListNode *cur = head, *new_cur = &dummy; cur; ) {
        new_cur->next = cur->next;
        new_cur = new_cur->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return dummy.next;
}

/* Time complexity: O(n) Space complexity: O(1) */
bool LinkedListCycle::DetectingLoopSingleLinkedList(ListNode *head) {
    for (ListNode *slow = head, *fast = head; fast && fast->next; ) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

/* Time complexity: O(n) Space complexity: O(1) */
ListNode *LinkedListCycle::LoopSingleLinkedList(ListNode *head) {
    ListNode *slow = head, *slow2 = head, *fast = head;
    bool meet = false;
    for (; fast && fast->next; ) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            meet = true;
            break;
        }
    }
    if (meet) {
        while (slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
    return nullptr;
}

/* Time complexity: O(n) Space complexity: O(1) */
ListNode *RecorderList::Recorder(ListNode *head) {
    int length = 0;
    ListNode dummy(-1);
    ListNode *p_temp = head;
    for (ListNode *it = head; it; it = it->next) {
        length += 1;
    }
    if (length < 3) {
        return head;
    }
    for (int i = 0; i < (length + 1) / 2 - 1; ++i) {
        p_temp = p_temp->next;
    }
    dummy.next = p_temp->next;
    p_temp->next = nullptr;
    // reverse the linked list
    ListNode *prev = dummy.next;
    ListNode *cur = prev->next;
    prev->next = nullptr;
    for (prev = cur; prev; prev = cur) {
        cur = prev->next;
        prev->next = dummy.next;
        dummy.next = prev;
    }
    prev = head;
    cur = dummy.next;
    for (int i = 0; i < length / 2; ++i) {
        ListNode *p_temp1 = prev->next;
        ListNode *p_temp2 = cur->next;
        prev->next = cur;
        cur->next = p_temp1;
        prev = p_temp1;
        cur = p_temp2;
    }
    return head;
}

int LeastRecentlyUsedCache::get(int key) {
    if (cache_map_.find(key) == cache_map_.end()) {
        return -1;
    }
    cache_list_.splice(cache_list_.begin(), cache_list_, cache_map_[key]);
    cache_map_[key] = cache_list_.begin();
    return cache_map_[key]->value;
}

void LeastRecentlyUsedCache::set(int key, int value) {
    if (cache_map_.find(key) == cache_map_.end()) {
        if (cache_list_.size() == capacity_) {
            cache_map_.erase(cache_list_.back().key);
            cache_list_.pop_back();
        }
        cache_list_.push_front(CacheNode(key, value));
        cache_map_[key] = cache_list_.begin();
    } else {
        cache_map_[key]->value = value;
        cache_list_.splice(cache_list_.begin(), cache_list_, cache_map_[key]);
        cache_map_[key] = cache_list_.begin();
    }
}





