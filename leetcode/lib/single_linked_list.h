//
//  list.h
//  leetcode
//
//  Created by NoteFAN on 4/10/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "math.h"

using namespace std;

/* single linked list */
struct ListNode {
    int var;
    ListNode *next;
    ListNode(int x) : var(x), next(nullptr) {}
};

/* Delete a linked list */
ListNode *DeleteList(ListNode *head);

/* Recursive delete a list */
void RecursiveDelete(ListNode *head);

/* 
 * Number Zero: 按递增次序输出单链表中各结点的数据元素
 * Description:
 *   给定一个带表头结点的单链表，设head为头指针，结点的结构为(data, next)，data为整型元素，
 * next为指针，试写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
 *（要求：不允许使用数组作为辅助空间）
 * 算法思想：
 *     对链表进行遍历，在每趟遍历中查找出整个链表的最小值元素，输出并释放结点所占空间；
 * 再查找次小值元素，输出并释放空间，如此下去，直至链表为空，最后释放头结点所占存储空间，
 * 该算法的时间复杂度为O(n2)
 */
class MinDelete {
public:
    void MinDeleteElement(ListNode *head);
protected:
    
private:
    
};

/*
 * Number One: Add Two Numbers
 * Description:
 *     You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain 
 * a single digit. Add the two numbers and return it as a linked list.
 *     Input: (2 -> 4 -> 3) + (5 ->6 -> 4)
 *     Output: 7 -> 0 -> 8
 */
class AddNumber {
public:
    ListNode *AddTwoNode(ListNode *list1, ListNode *list2);
protected:
    
private:
    
};

/*
 * Number Two: Reverse Linked List II
 * Description:
 *     Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example, Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
 * return 1->4->3->2->5->nullptr.
 * Note:Given m,n satisfy the following condition: 1 <= m <= n <= length of list.
 */
class ReverseLinkedList {
public:
    /* Time complexity: O(n), Space complexity: O(1) */
    ListNode *ReverseLinkedListBetween(ListNode *head, int m, int n);
protected:
    
private:
    
};

/*
 * Number Three: Partition List
 * Description:
 *     Given a linked list and a value x, partition it such that all nodes less 
 * than x come before nodes greater than or equal to x. You should preserve the 
 * original relative order of the nodes in each of the two partitions.
 *     For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
 */
class PartitionList {
public:
    /* Time complexity: O(n), Space complexity: O(1) */
    ListNode *PartitionListOrder(ListNode *head, int x);
protected:
    
private:
    
};

/*
 * Number Four: Remove Duplicates from Sorted List
 * Description:
 * "question one"
 *     Given a sorted linked list, delete all duplicates such that each element 
 * appear only once.
 *     For example, Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3.
 * "question two"
 *     Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 */
class RemoveDuplicatesFromSortedList {
public:
    /* Time complexity: O(), Space complexity: O() */
    ListNode *RemoveDuplicatesFromSortedListOne(ListNode *head);
    /* Time complexity: O(), Space complexity: O() */
    ListNode *RemoveDuplicatesFromSortedListTwo(ListNode *head);
    /* Time complexity: O(), Space complexity: O() */
    ListNode *RemoveDuplicatesFromSortedListThree(ListNode *head);
    /* Time complexity: O(), Space complexity: O() */
    ListNode *RemoveDuplicatesFromSortedListFour(ListNode *head);
protected:
    
private:
    struct VariableSign {
        int var;
        bool duplicate;
        VariableSign(int x): var(x), duplicate(false) {}
    };
    
    void recur(ListNode *pre, ListNode *cur) {
        if (cur == nullptr) {
            return;
        }
        if (pre->var == cur->var) {
            pre->next = cur->next;
            delete cur;
            recur(pre, pre->next);
        } else {
            recur(pre->next, cur->next);
        }
    }
};

/*
 * Number Five: Rotate List
 * Description:
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example, Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
 * 算法解析：
 *     先遍历一遍,得出链表长度len,注意 k 可能大于 len,因此令 k% = len.
 * 将尾节点next指针指向首节点,形成一个环,接着往后跑len − k步,从这里断开,就是要求的结果了。
 */
class RotateList {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    ListNode *RotateListRight(ListNode *head, size_t k);
protected:
    
private:
    
};

/*
 * Number Six: Remove Nth Node From End of List
 * Description:
 * Given a list, remove the nth node from the end of list and return its head.
 * For example, Given linked list: 1->2->3->4->5 and n = 2. After removing the 
 * second node from the end, the linked list becomes 1->2->3->5.
 * Note: Given n will always be valid. Try to do this in one pass.
 * 算法解析: 设两个指针p,q, 让q先走n步, 然后p和q一起走, 直到q走到尾节点, 删除p->next即可.
 */
class RemoveNode {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    ListNode *RemoveNthNodeFromEndOfList(ListNode *head, int n);
protected:
    
private:
    
};

/*
 * Number Seven: Swap Nodes in Pairs
 * Description:
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example, Given linked list: 1->2->3->4, you should return the list as 
 * 2->1->4->3.
 * Note: You algorithm should use only constant space. You may not modify the 
 * values in the list, only nodes itself can be changed.
 */
class SwapNodesInPairs {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    ListNode *SwapNodesInPairsOne(ListNode *head);
protected:
    
private:
    
};

/*
 * Number Eight: Reverse Nodes in k-Group
 * Description:
 * Given a linked list, reverse the nodes of a linked list k at a time and return
 * its modified list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is. You may not alter the values in the
 * nodes, only nodes itself may be changed. Only constant memory is allowed.
 * For example, Given linked list: 1->2->3->4->5, 
 * For k = 2, you should return the list as 2->1->4->3->5.
 * For k = 3, you should return the list as 3->2->1->4->5.
 */
class ReverseNodes {
public:
    /* 迭代版: Time complexity: O(n) Space complexity: O(1) */
    ListNode *ReverseNodesInKGroupOne(ListNode *head, int k);
    ListNode *Reverse(ListNode *pre, ListNode *begin, ListNode *end);
    /* 递归版: Time complexity: O() Space complexity: O() */
    ListNode *ReverseNodesInKGroupTwo(ListNode *head, int k);
protected:
    
private:

};

/* Definition for singly-linked list with a random pointer. */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int a): label(a), next(nullptr), random(nullptr) {}
};

/*
 * Number Nine: Copy List with Random Pointer
 * Description:
 * A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null. Return a deep copy of the list.
 */
class CopyList {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    RandomListNode *CopyListWithRandomPointer(RandomListNode *head);
protected:
    
private:
    
};

/*
 * Number Ten: Linked List Cycle
 * Description One:
 *     Given a linked list, determine if it has a cycle in it.
 * Follow up: Can you slove it without using extra space?
 * Solution:
 *    The best solution runs in O(N) time and uses O(1) space. 
 * It uses two pointers (one slow pointer and one fast pointer). 
 * The slow pointer advances one node at a time, while the fast pointer traverses 
 * twice as fast. If the list has loop in it, eventually the fast and slow pointer 
 * will meet at the same node. On the other hand, if the loop has no loop, 
 * the fast pointer will reach the end of list before the slow pointer does.
 *
 * Description Two:
 *     Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null. 
 * Follow up: Can you solve it without using extra space?
 * Solution:
 *    当 fast 与 slow 相遇时,slow 肯定没有遍历完链表,而 fast 已经在环内循环了 n 圈 (1 ≤ n)。
 * 假 设 slow 走了 s 步,则 fast 走了 2s 步(fast 步数还等于 s 加上在环上多转的 n 圈),设环长为 r,
 * 则:2s = s+nr, s = nr. 设整个链表长 L,环入口点与相遇点距离为 a,起点到环入口点的距离为 x,
 * 则 x+a = nr =(n–1)r+r=(n−1)r+L−x, x = (n−1)r+(L–x–a), L–x–a 为相遇点到环入口点的距离,
 * 由此可知,从链表头到环入口点等于n − 1圈内环 + 相遇点到环入口点,于是我们可以从 head 开始另设
 * 一个指针slow2,两个慢指针每次前进一步,它俩一定会在环入口点相遇。
 */
class LinkedListCycle {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    bool DetectingLoopSingleLinkedList(ListNode *head);
    /* Time complexity: O(n) Space complexity: O(1) */
    ListNode *LoopSingleLinkedList(ListNode *head);
protected:
    
private:
    
};

/*
 * Number Eleven: Recorder List
 * Description:
 * Given a singly list L: L0 -> L1 -> L2 -> ... -> Ln-2 -> Ln-1 -> Ln, recorder
 * it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 * You must do this in-place without altering the nodes' values.
 * For example, Given {1, 2, 3, 4}, recorder it to {1, 4, 2, 3}.
 * 算法解析：
 * 要求in-place, 也就是只能使用O(1)的空间。可以找到中间节点，断开，把后半截单链表reverse1一下，
 * 再合并两个单链表即可。
 */
class RecorderList {
public:
    ListNode *Recorder(ListNode *head);
protected:
    
private:
    
};

/*
 * Number Twelve: LRU Cache
 * Description:
 * Design and implement a data structure for Least Recently Used(LRU) cache.
 * It should support the following operations: get and set.
 *    get(key) - Get the value(will always be posive) of the key if the key exists
 * in the cache, otherwise return -1.
 *    set(key) - Set or insert the value if the key is not already present. When
 * the cache reached its capacity, it should invalidate the least recently used
 * item before inserting a new item.
 * 算法分析：
 * 为了使查找、插入和删除都有较高的性能,我们使用一个双向链表(std::list)和一个哈希表
 * (std::unordered_map), 因为:
 * • 哈希表保存每个节点的地址,可以基本保证在O(1)时间内查找节点
 * • 双向链表插入和删除效率高,单向链表插入和删除时,还要查找节点的前驱节点
 * 具体实现细节:
 * • 越靠近链表头部,表示节点上次访问距离现在时间最短,尾部的节点表示最近访问最少;
 * • 访问节点时,如果节点存在,把该节点交换到链表头部,同时更新hash表中该节点的地址;
 * • 插入节点时,如果cache的size达到了上限capacity,则删除尾部节点,同时要在hash表中
 * 删除对应的项, 新节点插入链表头部.
 */
class LeastRecentlyUsedCache {
public:
    LeastRecentlyUsedCache(int capacity) {
        this->capacity_ = capacity;
    }
    int get(int key);
    void set(int key, int value);
protected:
    
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int a, int b) : key(a), value(b) {}
    };
    list<CacheNode> cache_list_;
    unordered_map<int, list<CacheNode>::iterator> cache_map_;
    int capacity_;
};



#endif /* list_h */
