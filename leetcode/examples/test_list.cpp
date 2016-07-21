//
//  test_list.cpp
//  leetcode
//
//  Created by NoteFAN on 4/10/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <math.h>
#include <single_linked_list.h>

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    cout << "Test: Number Zero" << endl;
    vector<int> num_zero = {2, 3, 4, 5, 9, 6};
    ListNode *head_zero = new ListNode(-1);
    ListNode *p_zero = head_zero;
    for (int i = 0; i < num_zero.size(); ++i, p_zero = p_zero->next) {
        p_zero->next = new ListNode(num_zero[i]);
    }
    MinDelete min_delete;
    min_delete.MinDeleteElement(head_zero);
    
    cout << "Test: Number One" << endl;
    AddNumber add_number;
    ListNode *pa = new ListNode(-1);
    ListNode *pb = new ListNode(-1);
    ListNode *point_a = pa, *point_b = pb;
    vector<int> a = {2, 4, 3};
    vector<int> b = {5, 6, 4};
    for (int i = 0; i < 3; ++i, point_a = point_a->next, point_b = point_b->next) {
        point_a->next = new ListNode(a[i]);
        point_b->next = new ListNode(b[i]);
    }
    ListNode *result_one = add_number.AddTwoNode(pa->next, pb->next);
    cout << "The result:" << endl;
    for (ListNode *p_one = result_one; p_one != nullptr; p_one = p_one->next) {
        cout << p_one->var << " ";
    }
    cout << endl;
    // release the memory
    while (pa != nullptr) {
        ListNode *p_temp = pa;
        pa = pa->next;
        delete p_temp;
    }
    while (pb != nullptr) {
        ListNode *p_temp = pb;
        pb = pb->next;
        delete p_temp;
    }
    while (result_one != nullptr) {
        ListNode *p_temp = result_one;
        result_one = result_one->next;
        delete p_temp;
    }
    
    cout << "Test: Number Two" << endl;
    vector<int> num_two = {2, 3, 4, 5, 9, 6, 10};
    ListNode *head_two = new ListNode(-1);
    ListNode *p_two = head_two;
    for (int i = 0; i < num_two.size(); ++i, p_two = p_two->next) {
        p_two->next = new ListNode(num_two[i]);
    }
    cout << "The example:" << endl;
    for (auto it = head_two->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    ReverseLinkedList reverse_linked_list;
    ListNode *result_two = reverse_linked_list.ReverseLinkedListBetween(head_two->next, 2, 4);
    cout << "The result:" << endl;
    for (auto it = result_two; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    while (result_two != nullptr) {
        ListNode *p_temp = result_two;
        result_two = result_two->next;
        delete p_temp;
    }
    
    cout << "Test: Number Three" << endl;
    vector<int> num_three = {4, 3, 2, 5, 9, 6, 10};
    ListNode *head_three = new ListNode(-1);
    ListNode *p_three = head_three;
    for (int i = 0; i < num_three.size(); ++i, p_three = p_three->next) {
        p_three->next = new ListNode(num_three[i]);
    }
    cout << "The example:" << endl;
    for (auto it = head_three->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    PartitionList partition_list;
    ListNode *result_three = partition_list.PartitionListOrder(head_three->next, 4);
    cout << "The result:" << endl;
    for (auto it = result_three; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    while (result_three != nullptr) {
        ListNode *p_temp = result_three;
        result_three = result_three->next;
        delete p_temp;
    }
    
    cout << "Test: Number Four" << endl;
    vector<int> num_four = {2, 2, 3, 3, 4, 4, 5, 5, 6, 10, 10};
    ListNode *head_four = new ListNode(-1);
    ListNode *p_four = head_four;
    for (int i = 0; i < num_four.size(); ++i, p_four = p_four->next) {
        p_four->next = new ListNode(num_four[i]);
    }
    cout << "The example:" << endl;
    for (auto it = head_four->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    RemoveDuplicatesFromSortedList remove_duplicates_from_sorted_list;
    /*
    ListNode *result_four = remove_duplicates_from_sorted_list.RemoveDuplicatesFromSortedListOne(head_four->next);
    for (auto it = result_four; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    ListNode *result_four = remove_duplicates_from_sorted_list.RemoveDuplicatesFromSortedListTwo(head_four->next);
    for (auto it = result_four; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    ListNode *result_four = remove_duplicates_from_sorted_list.RemoveDuplicatesFromSortedListThree(head_four->next);
    for (auto it = result_four; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    */
    ListNode *result_four = remove_duplicates_from_sorted_list.RemoveDuplicatesFromSortedListFour(head_four->next);
    for (auto it = result_four; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    while (result_four != nullptr) {
        ListNode * p_temp = result_four;
        result_four = result_four->next;
        delete p_temp;
    }
    
    cout << "Test: Number Five" << endl;
    vector<int> num_five = {2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head_five = new ListNode(-1);
    ListNode *p_five = head_five;
    for (int i = 0; i < num_five.size(); ++i, p_five = p_five->next) {
        p_five->next = new ListNode(num_five[i]);
    }
    cout << "The example:" << endl;
    for (ListNode *it = head_five->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    RotateList *rotate_list;
    ListNode *result_five = rotate_list->RotateListRight(head_five->next, 2);
    for (auto it = result_five; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    while (result_five != nullptr) {
        ListNode *p_temp = result_five;
        result_five = result_five->next;
        delete p_temp;
    }

    cout << "Test: Number Six" << endl;
    vector<int> num_six = {2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head_six = new ListNode(-1);
    ListNode *p_six = head_six;
    for (int i = 0; i < num_six.size(); ++i, p_six = p_six->next) {
        p_six->next = new ListNode(num_six[i]);
    }
    cout << "The example:" << endl;
    for (ListNode *it = head_six->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    RemoveNode *remove_node;
    ListNode *result_six = remove_node->RemoveNthNodeFromEndOfList(head_six->next, 4);
    for (auto it = result_six; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    while (result_six != nullptr) {
        ListNode *p_temp = result_six;
        result_six = result_six->next;
        delete p_temp;
    }
    
    cout << "\nTest: Number Seven" << endl;
    vector<int> num_seven= {2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head_seven = new ListNode(-1);
    ListNode *p_seven = head_seven;
    for (int i = 0; i < num_seven.size(); ++i, p_seven = p_seven->next) {
        p_seven->next = new ListNode(num_seven[i]);
    }
    cout << "The example:" << endl;
    for (ListNode *it = head_seven->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    SwapNodesInPairs swap_ndoes_in_pairs;
    ListNode *result_seven = swap_ndoes_in_pairs.SwapNodesInPairsOne(head_seven->next);
    for (auto it = result_seven; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    while (result_seven) {
        ListNode *p_temp = result_seven;
        result_seven = result_seven->next;
        delete p_temp;
    }
    
    cout << "\nTest: Number Eight" << endl;
    vector<int> num_eight = {2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head_eight = new ListNode(-1);
    ListNode *p_eight = head_eight;
    for (int i = 0; i < num_eight.size(); ++i, p_eight = p_eight->next) {
        p_eight->next = new ListNode(num_eight[i]);
    }
    cout << "The example:" << endl;
    for (ListNode *it = head_eight->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    ReverseNodes reverse_nodes;
    ListNode *result_eight = reverse_nodes.ReverseNodesInKGroupOne(head_eight->next, 3);
    for (ListNode *p_eight = result_eight; p_eight; p_eight = p_eight->next) {
        cout << p_eight->var << " ";
    }
    cout << endl;
    result_eight = reverse_nodes.ReverseNodesInKGroupOne(result_eight, 3);
    for (ListNode *p_eight = result_eight; p_eight; p_eight = p_eight->next) {
        cout << p_eight->var << " ";
    }
    cout << endl;
    while (result_eight) {
        ListNode *p_temp = result_eight;
        result_eight = result_eight->next;
        delete p_temp;
    }
    
    cout << "\nTest: Number Nine" << endl;
    vector<int> num_nine = {2, 3, 4, 5, 6, 7, 8, 9};
    RandomListNode *head_nine = new RandomListNode(-1);
    RandomListNode *p_nine = head_nine;
    for (int i = 0; i < num_nine.size(); ++i, p_nine = p_nine->next) {
        p_nine->next = new RandomListNode(num_nine[i]);
    }
    cout << "The example:" << endl;
    for (RandomListNode *it = head_nine->next; it != nullptr; it = it->next) {
        cout << it->label << " ";
    }
    cout << endl;
    CopyList *copy_list;
    RandomListNode *result_nine = copy_list->CopyListWithRandomPointer(head_nine->next);
    for (RandomListNode *it = result_nine; it != nullptr; it = it->next) {
        cout << it->label << " ";
    }
    cout << endl;
    while (head_nine) {
        RandomListNode *p_temp = head_nine;
        head_nine = head_nine->next;
        delete p_temp;
    }
    while (result_nine) {
        RandomListNode *p_temp = result_nine;
        result_nine = result_nine->next;
        delete p_temp;
    }
    
    cout << "\nTest: Number Ten" << endl;
    vector<int> num_ten = {2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head_ten = new ListNode(-1);
    ListNode *p_ten = head_ten;
    for (int i = 0; i < num_nine.size(); ++i, p_ten = p_ten->next) {
        p_ten->next = new ListNode(num_ten[i]);
    }
    cout << "The example:" << endl;
    for (ListNode *it = head_ten->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    ListNode *it = head_ten;
    for ( ; it->next != nullptr; it = it->next) {}
    it->next = head_ten->next;
    LinkedListCycle linked_list_cycle;
    bool result_ten = linked_list_cycle.DetectingLoopSingleLinkedList(head_ten);
    if (result_ten) {
        cout << "The single linked list has a cycle." << endl;
    } else {
        cout << "The single linked list doesn't have any cycle." << endl;
    }
    ListNode *result_ten_node = linked_list_cycle.LoopSingleLinkedList(head_ten);
    if (result_ten_node) {
        cout << "The value of entry point:" << result_ten_node->var << endl;
        // remove the loop point
        it = result_ten_node;
        while(it->next != result_ten_node) {
            it = it->next;
        }
        it->next = nullptr;

    } else {
        cout << "There is no cycle" << endl;
    }
    // release the memory
    while (head_ten) {
        ListNode *p_temp = head_ten;
        head_ten = head_ten->next;
        delete p_temp;
    }
    
    cout << "\nTest: Number Eleven" << endl;
    vector<int> num_eleven = {2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head_eleven = new ListNode(-1);
    ListNode *p_eleven = head_eleven;
    for (int i = 0; i < num_eleven.size(); ++i, p_eleven = p_eleven->next) {
        p_eleven->next = new ListNode(num_eleven[i]);
    }
    cout << "The example:" << endl;
    for (ListNode *it = head_eleven->next; it != nullptr; it = it->next) {
        cout << it->var << " ";
    }
    cout << endl;
    RecorderList recorder_list;
    ListNode *result_eleven = recorder_list.Recorder(head_eleven->next);
    for (ListNode *p_eleven = result_eleven; p_eleven; p_eleven = p_eleven->next) {
        cout << p_eleven->var << " ";
    }
    cout << endl;
    while (result_eleven) {
        ListNode *p_temp = result_eleven;
        result_eleven = result_eleven->next;
        delete p_temp;
    }

    
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




