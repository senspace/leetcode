//
//  test_sort_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 5/25/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include "sort_operation.h"

using namespace std;

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    cout << "\nTest: Number Zero" << endl;
    int a[12] = {1, 4, 5, 6, 8, 10};
    int b[6] = {2, 7, 9, 11, 12, 13};
    MergeSortedArray merge_sorted_array;
    merge_sorted_array.Merge(a, 6, b, 6);
    cout << "result: " << endl;
    for (int i = 0; i < 12; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "\nTest: Number One" << endl;
    ListNode *list_one = new ListNode(1);
    ListNode *temp = list_one;
    for (int i = 3; i < 10; i += 2, temp = temp->next) {
        temp->next = new ListNode(i);
    }
    ListNode *list_two = new ListNode(2);
    temp = list_two;
    for (int i = 4; i < 12; i += 2, temp = temp->next) {
        temp->next = new ListNode(i);
    }
    MergeSortedLists merge_sorted_lists;
    ListNode *root = merge_sorted_lists.MergeTwoSortedLists(list_one, list_two);
    cout << "Result: " << endl;
    for (ListNode *it = root; it; it = it->next) {
        cout << it->val << " ";
    }
    cout << endl;
    vector<ListNode *> lists;
    lists.push_back(root);
    ListNode *list_three = new ListNode(11);
    ListNode *list_four = new ListNode(12);
    temp = list_three;
    for (int i = 13; i < 20; i += 2, temp = temp->next) {
        temp->next = new ListNode(i);
    }
    temp = list_four;
    for (int i = 14; i < 22; i += 2, temp = temp->next) {
        temp->next = new ListNode(i);
    }
    lists.push_back(list_three);
    lists.push_back(list_four);
    root = merge_sorted_lists.MergeMultipleSortedLists(lists);
    for (ListNode *it = root; it; it = it->next) {
        cout << it->val << " ";
        it->val += 10;
    }
    cout << endl;
    // release the memory
    while (root != nullptr) {
        ListNode *temp = root;
        root = root->next;
        delete temp;
    }
    
    cout << "\nTest: Number Two" << endl;
    ListNode *list_five = new ListNode(10);
    list_five->next = new ListNode(8);
    list_five->next->next = new ListNode(6);
    list_five->next->next->next = new ListNode(7);
    list_five->next->next->next->next = new ListNode(9);
    InsertionSortList insertion_sort_list;
    ListNode *result_two = insertion_sort_list.SortList(list_five);
    for (ListNode *it = result_two; it; it = it->next) {
        cout << it->val << " ";
    }
    cout << endl;
    while (result_two != nullptr) {
        temp = result_two;
        result_two = result_two->next;
        delete temp;
    }
    
    cout << "\nTest: Number Three" << endl;
    ListNode *list_six = new ListNode(10);
    list_six->next = new ListNode(8);
    list_six->next->next = new ListNode(6);
    list_six->next->next->next = new ListNode(7);
    list_six->next->next->next->next = new ListNode(9);
    SortList sort_list;
    ListNode *result_three = sort_list.SortLinkedList(list_six);
    for (ListNode *it = result_three; it; it = it->next) {
        cout << it->val << " ";
    }
    cout << endl;
    while (result_three != nullptr) {
        temp = result_three;
        result_three = result_three->next;
        delete temp;
    }
    
    cout << "\nTest: Number Four" << endl;
    vector<int> num = {3, 4, -1, 1};
    FirstMissingPositive first_missing_positive;
    size_t result_four = first_missing_positive.GetFirstMissingPositive(num);
    cout << "Result:" << result_four << endl;
    
    cout << "\nTest: Number Five" << endl;
    num = {0, 1, 2, 1, 2, 0, 1, 2};
    SortColors sort_colors;
    sort_colors.SortColorsThree(num);
    for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




