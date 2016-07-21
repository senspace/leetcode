//
//  sort_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 5/25/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include <functional>
#include <algorithm>
#include "sort_operation.h"

using namespace std;

/* Time complexity: O(m + n) Space complexity: O(1) */
void MergeSortedArray::Merge(int a[], int m, int b[], int n) {
    int length = m + n;
    while (m && n) {
        a[--length] = a[m - 1] > b[n - 1] ? a[--m] : b[--n];
    }
    while (m) {
        a[--length] = a[--m];
    }
    while (n) {
        a[--length] = b[--n];
    }
}

/* Time complexity: O(min(m, n)) Space complexity: O(1) */
ListNode * MergeSortedLists::MergeTwoSortedLists(ListNode *list_one,
                                                 ListNode *list_two) {
    ListNode dummy(-1);
    ListNode *root = &dummy;
    while (list_one != nullptr && list_two != nullptr) {
        if (list_one->val < list_two->val) {
            root->next = list_one;
            root = root->next;
            list_one = list_one->next;
        } else {
            root->next = list_two;
            root = root->next;
            list_two = list_two->next;
        }
    }
    root->next = list_one != nullptr ? list_one : list_two;
    return dummy.next;
}

/* Time complexity: O(n1 + n2 + n3...) Space complexity: O(1) */
ListNode *MergeSortedLists::MergeMultipleSortedLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return nullptr;
    ListNode *head = lists[0];
    for (size_t i = 1; i < lists.size(); ++i) {
        head = MergeTwoSortedLists(head, lists[i]);
    }
    return head;
}

/* Time complexity: O(n^2) Space complexity: O(1) */
ListNode *InsertionSortList::SortList(ListNode *head) {
    ListNode *dummy = new ListNode(INT_MIN);
    for (ListNode *it = head; it; ) {
        ListNode *position = FindInsertionPosition(dummy, it->val);
        ListNode *temp = it->next;
        it->next = position->next;
        position->next = it;
        it = temp;
    }
    ListNode *new_head = dummy->next;
    delete dummy;
    return new_head;
}

ListNode *InsertionSortList::FindInsertionPosition(ListNode *head, int val) {
    ListNode *prev = nullptr;
    for (ListNode *current = head; current != nullptr && current->val <= val;
         current = current->next) {
        prev = current;
    }
    return prev;
}

/* Recursively -> Time complexity: O(nlogn) Space complexity: O(1) */
ListNode *SortList::SortLinkedList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // get the node in the center of list
    ListNode *slow = head, *fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow;
    slow = slow->next;
    fast->next = nullptr;
    
    ListNode *l1 = SortLinkedList(head);
    ListNode *l2 = SortLinkedList(slow);
    
    return MergeTwoLists(l1, l2);
}

ListNode *SortList::MergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(INT_MIN);
    ListNode *it;
    for (it = &dummy; l1 != nullptr && l2 != nullptr; it = it->next) {
        if (l1->val <= l2->val) {
            it->next = l1;
            l1 = l1->next;
        } else {
            it->next = l2;
            l2 = l2->next;
        }
    }
    it->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
}

/* Time complexity: O(n) Space complexity: O(1) */
size_t FirstMissingPositive::GetFirstMissingPositive(vector<int> &num) {
    BucketSort(num);
    for (size_t i = 0; i < num.size(); ++i) {
        if (num[i] != i + 1) {
            return i + 1;
        }
    }
    return num.size();
}

vector<int> FirstMissingPositive::BucketSort(vector<int> &num) {
    size_t length = num.size();
    for (size_t i = 0; i < length;) {
        if (num[i] == i + 1 || num[i] < 1 || num[i] > length || num[i] == num[num[i] - 1]) {
            ++i;
            continue;
        } else {
            swap(num[i], num[num[i] - 1]);
        }
    }
    return num;
}

/* two-pass -> Time complexity: O(n) Space complexity: O(1) */
vector<int> SortColors::SortColorsOne(vector<int> &num) {
    size_t count[3] = {0, 0, 0};
    for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
        ++count[*it];
    }
    size_t index = 0;
    for (int i = 0; i < 3; ++i) {
        for (size_t j = 0; j < count[i]; ++j, ++index) {
            num[index] = i;
        }
    }
    return num;
}

/* one-pass(two points) -> Time complexity: O(n) Space complexity: O(1) */
vector<int> SortColors::SortColorsTwo(vector<int> &num) {
    // red: 0, white: 1, blue: 2
    size_t length = num.size();
    size_t red = 0, blue = length - 1;
    for (size_t i = 0; i < blue + 1; ) {
        if (num[i] == 0) {
            swap(num[i++], num[red++]);
        } else if (num[i] == 2) {
            swap(num[i], num[blue--]);
        } else {
            ++i;
        }
    }
    return num;
}

/* use partition() -> Time complexity: O(n) Space complexity: O(1) */
void SortColors::SortColorsThree(vector<int> &num) {
    partition(partition(num.begin(), num.end(), bind1st(equal_to<int>(), 0)),
              num.end(), bind1st(equal_to<int>(), 1));
}











