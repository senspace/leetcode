//
//  sort_operation.h
//  leetcode
//
//  Created by NoteFAN on 5/25/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef SORT_OPERATION_H
#define SORT_OPERATION_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


/*
 * Title: Merge Sorted Array
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note: You may assume that A has enough space to hold additional elements from B. 
 * The number of elements initialized in A and B are m and n respectively.
 */
class MergeSortedArray {
public:
    /* Time complexity: O(m + n) Space complexity: O(1) */
    void Merge(int a[], int m, int b[], int n);
protected:
    
private:

};

/*
 * Title One: Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should 
 * be made by splicing together the nodes of the first two lists.
 *
 * Title Two: Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and 
 * describe its complexity.
 */
class MergeSortedLists {
public:
    /* Time complexity: O(min(m, n)) Space complexity: O(1) */
    ListNode *MergeTwoSortedLists(ListNode *list_one, ListNode *list_two);
    
    /* Time complexity: O(n1 + n2 + n3...) Space complexity: O(1) */
    ListNode *MergeMultipleSortedLists(vector<ListNode *> &lists);
protected:

private:

};

/*
 * Title: Insertion Sort List
 * Sort a linked list using insertion sort.
 */
class InsertionSortList {
public:
    /* Time complexity: O(n^2) Space complexity: O(1) */
    ListNode *SortList(ListNode *head);
protected:
    
private:
    ListNode *FindInsertionPosition(ListNode *head, int val);
};

/*
 * Title: Sort List
 * Sort a linked list in O(nlogn) time using constant space complexity.
 * Analysis:
 * 常数空间且 O(nlogn),单链表适合用归并排序,双向链表适合用快速排序。
 * 本题可以复用”Merge Two Sorted Lists” 的代码。
 */
class SortList {
public:
    /* Time complexity: O(nlogn) Space complexity: O(1) */
    ListNode *SortLinkedList(ListNode *head);
    ListNode *MergeTwoLists(ListNode *l1, ListNode *l2);
protected:
    
private:

};

/*
 * Title: First Missing Positive
 * Given an unsorted integer array, find the first missing positive integer.
 * For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 * Analysis:[A[0] = 1, A[1] = 2, .... A[n-1] = n,目标是尽可能将数字i放到数组第i-1个位置]
 * 本质上是桶排序 (bucket sort),每当 A[i]!=i+1 的时候,将 A[i] 与 A[A[i]-1] 交换,
 * 直到无法交换为止,终止条件是A[i]==A[A[i]-1].
 * Method: 扫描数组中每个数:
 * 1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
 * 2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
 * 3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
 这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
 */
class FirstMissingPositive {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    size_t GetFirstMissingPositive(vector<int> &num);
    vector<int> BucketSort(vector<int> &num);
protected:
    
private:

};

/*
 * Title: Sort Colors
 * Given an array with n objects colored red, white or blue, sort them so that 
 * objects of the same color are adjacent, with the colors in the order red, 
 * white and blue. Here, we will use the integers 0, 1, and 2 to represent the 
 * color red, white, and blue respectively.
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * Follow Up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0’s, 1’s, and 2’s, then overwrite 
 * array with total number of 0’s, then 1’s and followed by 2’s.
 * Could you come up with an one-pass algorithm using only constant space?
 */
class SortColors {
public:
    /* two-pass -> Time complexity: O(n) Space complexity: O(1) */
    vector<int> SortColorsOne(vector<int> &num);
    /* one-pass(two points) -> Time complexity: O(n) Space complexity: O(1) */
    vector<int> SortColorsTwo(vector<int> &num);
    /* use partition() -> Time complexity: O(n) Space complexity: O(1) */
    void SortColorsThree(vector<int> &num);
protected:
    
private:
    template<typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last,
                              UnaryPredicate pred) {
        ForwardIterator position = first;
        for (; first != last; ++first) {
            if (pred(*first)) {
                swap(*first, *position++);
            }
        }
        return position;
    }
};


#endif /* sort_operation_h */
