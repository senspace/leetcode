//
//  test_array.cpp
//  leetcode
//
//  Created by NoteFAN on 3/16/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include "array.h"

using namespace std;

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**********************************TESTS***********************************/
    /**************************************************************************/
    /* Test: Number One */
    int arr[] = {1, 2, 3, 5, 5, 5, 6, 6, 7, 8, 9, 20, 21, 22, 22, 22, 23, 24};
    RemoveDuplicatesFromSortedArray *remove_duplicates;
    // int length = remove_duplicates->RemoveDuplicates(arr, 18);
    // int length = remove_duplicates->RemoveDuplicatesBasedOnSTLOne(arr, 18);
    // int length = remove_duplicates->RemoveDuplicatesBasedOnSTLTwo(arr, 18);
    int length = remove_duplicates->RemoveDuplicatesAdvanced(arr, 18);
    cout << "Test: Number One" << endl;
    for(int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;
    /* Test: Number Two */
    int arr_two[] = {5, 6, 7, 8, 9, 20, 21, 22, 23, 24, 1, 2, 3};
    int arr_two_duplicates[] = {5, 7, 7, 7, 9, 20, 21, 21, 23, 24, 1, 2, 2};
    SearchRotatedSortedArray *search_value;
    cout << "Test: Number Two" << endl;
    for(int i = 0; i < 13; ++i) {
        // int index = search_value->SearchArray(arr_two, 13, arr_two[i]);
        int index = search_value->SearchArrayAdvanced(arr_two_duplicates, 13,
                                                      arr_two_duplicates[i]);
        cout << "index of target:" << index << endl;
    }
    cout << endl;
    /* Test: Number Three */
    int arr_three_a[] = {1, 2, 3, 5, 5, 5, 6, 6};
    int arr_three_b[] = {7, 8, 9, 20, 21, 22, 22, 22, 23, 24};
    MedianOfTwoSortedArrays *search_median;
    cout << "Test: Number Three" << endl;
    double median_value = search_median->FindMedianSortedArrays(arr_three_a, 8, arr_three_b, 10);
    cout << "Median of Two Sorted Arrays:" << median_value << endl;
    /* Test: Number Four */
    const vector<int> num = {1, 2, 3, 5, 6, 7, 8, 9, 20, 21, 22, 23, 24};
    LongestConsecutiveSequence *search_longest_consecutive_sequence;
    int longest = search_longest_consecutive_sequence->FindLongestConsecutiveSequence(num);
    cout << "\nTest: Number Four" << endl;
    cout << "Longest Consecutive Sequence:" << longest << endl;
    /* Test: Number Five */
    TwoSum *two_sum;
    const vector<int> results = two_sum->FindIndexsForTwoSum(num, 22);
    cout << "\nTest: Number Five" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << "The index:" << results[i] << endl;
    }
    /* Test: Number Six */
    ThreeSum *three_sum;
    vector<vector<int>> result;
    const int target = 10;
    vector<int> sum = {1, 2, 3, 5, 6, 7, 8, 9, 20, 21, 22, 23, 24};
    result = three_sum->FindIndexsForThreeSum(sum, target);
    cout << "\nTest: Number Six" << endl;
    for(auto it = result.begin(); it < result.end(); ++it) {
        cout << "{ ";
        for (int i = 0; i < it->size(); ++i) {
            cout << it->at(i) << " ";
        }
        cout << "}";
    }
    int sum_closet = three_sum->FindSumClosest(sum, 80);
    cout << "\nThe sum of three elements: " << sum_closet << endl;
    /* Test: Number Seven */
    FourSum *four_sum;
    vector<vector<int>> four_sum_results;
    const int four_sum_target = 0;
    vector<int> four_sum_sum = {1, 0, -1, 0, -2, 2};
    cout << "\nTest: Number Seven" << endl;
    cout << "The method one:\n";
    four_sum_results = four_sum->FindIndexsForFourSumOne(four_sum_sum,
                                                         four_sum_target);
    for (auto it = four_sum_results.begin(); it < four_sum_results.end(); ++it) {
        cout << "{ ";
        for (int i = 0; i < it->size(); ++i) {
            cout << it->at(i) << " ";
        }
        cout << "}";
    }
    cout << "\nThe method two:\n";
    four_sum_results = four_sum->FindIndexsForFourSumTwo(four_sum_sum,
                                                         four_sum_target);
    for (auto it = four_sum_results.begin(); it < four_sum_results.end(); ++it) {
        cout << "{ ";
        for (int i = 0; i < it->size(); ++i) {
            cout << it->at(i) << " ";
        }
        cout << "}";
    }
    cout << "\nThe method three:\n";
    four_sum_results = four_sum->FindIndexsForFourSumThree(four_sum_sum,
                                                           four_sum_target);
    for (auto it = four_sum_results.begin(); it < four_sum_results.end(); ++it) {
        cout << "{ ";
        for (int i = 0; i < it->size(); ++i) {
            cout << it->at(i) << " ";
        }
        cout << "}";
    }
    cout << "\n\nTest: Number Eight" << endl;
    int a[] = { 1, 2, 2, 4, 3, 5, 6, 8, 7, 8, 3, 6 };
    int b[] = { 1, 2, 2, 4, 3, 5, 6, 8, 7, 8, 3, 6 };
    RemoveElement remove_element;
    int index_one = remove_element.RemoveElementInstacesOne(a, 10, 3);
    cout << "The new length of the array(method one): " << index_one << endl;
    int index_two = remove_element.RemoveElementInstacesTwo(b, 10, 3);
    cout << "The new length of the array(method one): " << index_two << endl;

    cout << "\nTest: Number Nine" << endl;
    NextPermutation next_permutation;
    string result_nine = next_permutation.KthGetPermutation(3, 3);
    cout << result_nine << endl;
    
    cout << "\nTest: Number Ten" << endl;
    TrappingRainWater trapping_rain_water;
    vector<int> num_ten = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trap_rain_one = trapping_rain_water.ComputeTrapWaterOne(num_ten);
    int trap_rain_two = trapping_rain_water.ComputeTrapWaterTwo(num_ten);
    int trap_rain_three = trapping_rain_water.ComputeTrapWaterThree(num_ten);
    cout << "The total(one):" << trap_rain_one << endl;
    cout << "The total(two):" << trap_rain_two << endl;
    cout << "The total(three):" << trap_rain_three << endl;
    
    cout << "\nTest: Number Eleven" << endl;
    RotateImage rotate_image;
    vector<vector<int>> num_eleven = {{1, 2}, {4, 3}};
    cout << "The initital matrix:" << endl;
    for (int i = 0; i < num_eleven.size(); ++i) {
        for (int j = 0; j < num_eleven.size(); ++j) {
            cout << num_eleven[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Rotate by 90 degrees:" << endl;
    rotate_image.RotateImageTwo(num_eleven);
    for (int i = 0; i < num_eleven.size(); ++i) {
        for (int j = 0; j < num_eleven.size(); ++j) {
            cout << num_eleven[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest: Number Twelve" << endl;
    ClimbingStairs climbing_stairs;
    int num_twelve = climbing_stairs.ClimbStairsTwo(14);
    cout << "The number of distinct ways:" << num_twelve << endl;
    
    cout << "\nTest: Number Thirteen" << endl;
    vector<vector<int>> matrix_thirteen = {{1, 1, 1, 0}, {1, 1, 1, 1}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    for (int i = 0; i < matrix_thirteen.size(); ++i) {
        for (int j = 0; j < matrix_thirteen[0].size(); ++j) {
            cout << matrix_thirteen[i][j] << " ";
        }
        cout << endl;
    }
    SetMatrixZeroes set_matrix_zeroes;
    set_matrix_zeroes.SetMatrixZeroesTwo(matrix_thirteen);
    cout << "The results:" << endl;
    for (int i = 0; i < matrix_thirteen.size(); ++i) {
        for (int j = 0; j < matrix_thirteen[0].size(); ++j) {
            cout << matrix_thirteen[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest: Number Fourteen" << endl;
    vector<int> num_fourteen = {1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1};
    Candy candy;
    int result_fourteen = candy.MinimumCandyTwo(num_fourteen);
    cout << "Result:" << result_fourteen << endl;
    
    cout << "\nTest: Number Fifteen" << endl;
    int num_fifteen[] = {1, 1, 2, 2, 4, 3, 4, 3, 5, 7, 6, 6, 7};
    int num_sixteen[] = {1, 1, 1, 2, 2, 3, 2, 3, 3, 6, 6, 6, 7};
    SingleNumber single_number;
    int result_fifteen = single_number.SingleNumberOne(num_fifteen, 13);
    int result_sixteen = single_number.SingleNumberTwo(num_sixteen, 13);
    cout << "Result:" << result_fifteen << endl;
    cout << "Result:" << result_sixteen << endl;
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    // Sleep(3000);
    finish = clock();
    /* calculate all the time */
    total_time = (double)(finish - start) * 1000 / CLOCKS_PER_SEC; //unit: ms
    cout << "\n\nTime: " << total_time << " ms" << endl;
    
    return 0;
}



