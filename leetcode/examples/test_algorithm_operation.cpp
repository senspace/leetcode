//
//  test_algorithm_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 6/14/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include "algorithm_operation.h"

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
    double data_zero = 2.0;
    int num_zero = 10;
    Pow pow;
    double result_zero = pow.GetPow(data_zero, num_zero);
    cout << result_zero << endl;
    
    cout << "\nTest: Number One" << endl;
    Sqrt sqrt;
    for (int i = 1; i < 100; ++i) {
        cout<< i << ": " << sqrt.GetSqrt(i) << endl;
    }
    
    cout << "\nTest: Number Two" << endl;
    vector<int> number_two = {2, 3, 1, 1, 4};
    // vector<int> number_two = {3, 2, 1, 0, 4};
    JumpGame jump_game;
    JumpGameII jump_game_ii;
    bool result_two = jump_game.CheckJumpThree(number_two);
    int result_two_other = jump_game_ii.CheckJump(number_two);
    cout << "result:" << result_two << endl;
    cout << "result:" << result_two_other << endl;

    cout << "\nTest: Number Three" << endl;
    BestTimeToBuyAndSellStockI best_time_buy_sell_stock_i;
    vector<double> prices_three = {1.0, 3.0, 5.0, 1.5, 0.5, 6.5};
    double result_three = best_time_buy_sell_stock_i.GetMaximumProfit(prices_three);
    cout << "result:" << result_three << endl;
    BestTimeToBuyAndSellStockII best_time_buy_sell_stock_ii;
    double result_three_other = best_time_buy_sell_stock_ii.GetMaximumProfit(prices_three);
    cout << "Result:" << result_three_other << endl;
    
    cout << "\nTest: Number Four" << endl;
    string s_four = "abcabcbb";
    LongestSubstringWithoutRepeatingCharacters longest_substring;
    int result_four = longest_substring.GetLongestSubstring(s_four);
    cout << "Result:" << result_four << endl;
    
    cout << "\nTest: Number Five" << endl;
    vector<int> num_five = {2, 3, 5, 6, 7, 8, 10};
    ContainerWithMostWater container_with_most_water;
    int result_five = container_with_most_water.GetMostWater(num_five);
    cout << "Result:" << result_five << endl;
    
    cout << "\nTest: Number Six" << endl;
    vector<vector<int>> numbers_six = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Triangle triangle;
    int result_six = triangle.GetMinimumPathSum(numbers_six);
    cout << "Result:" << result_six << endl;
    
    cout << "\nTest: Number Seven" << endl;
    vector<int> numbers_seven = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Subarray subarray;
    int result_seven = subarray.MaximumSubarray(numbers_seven);
    cout << "Result:" << result_seven << endl;
    
    cout << "\nTest: Number Eight" << endl;
    string s_eight = "cabababcbc";
    PalindromePartitioningII palindrome_partitioning_ii;
    int result_eight = palindrome_partitioning_ii.MinimumCut(s_eight);
    cout << "Result: " << result_eight << endl;
    
    cout << "\nTest: Number Nine" << endl;
    MaximalRectangle maximal_rectangle;
    vector<vector<int>> matrix_nine = {{0, 0, 1, 0},
                                       {0, 0, 1, 1},
                                       {1, 0, 1, 1},
                                       {1, 1, 1, 1}};
    int result_nine = maximal_rectangle.GetMaximalRectangleTwo(matrix_nine);
    cout << "result:" << result_nine << endl;
    
    cout << "\nTest: Number Ten" << endl;
    BestTimeBuyAndSellStockIII stock;
    vector<double> prices = {3, 4, 9, 2, 10};
    double result_ten = stock.MaximumProfit(prices);
    cout << "Result:" << result_ten << endl;
    
    cout << "\nTest: Number Eleven" << endl;
    InterleavingString interleaving_string;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac", s4 = "aadbbbaccc";
    bool result_eleven = interleaving_string.CheckInterleavingString(s1, s2, s3);
    cout << "result: " << result_eleven << endl;
    result_eleven = interleaving_string.CheckInterleavingString(s1, s2, s4);
    cout << "result: " << result_eleven << endl;
    result_eleven = interleaving_string.IsInterleavingString(s1, s2, s3);
    cout << "result: " << result_eleven << endl;
    result_eleven = interleaving_string.IsInterleavingString(s1, s2, s4);
    cout << "result: " << result_eleven << endl;
    
    cout << "\nTest: Number Twelve" << endl;
    ScrambleString scramble_string;
    s1 = "great";
    s2 = "rgtae";
    bool result_twelve = scramble_string.IsScrambleStringOne(s1, s2);
    cout << "result:" << result_twelve << endl;
    result_twelve = scramble_string.IsScrambleStringTwo(s1, s2);
    cout << "result:" << result_twelve << endl;

    cout << "\nTest: Number Thirteen" << endl;
    vector<vector<int>> matrix_thirteen = {{3, 3, 4}, {1, 1, 4}, {2, 2, 1}};
    MinimumPathSum minimum_path_sum;
    int result_thirteen = minimum_path_sum.GetMinimumPathSumOne(matrix_thirteen);
    cout << "result:" << result_thirteen << endl;
    result_thirteen = minimum_path_sum.GetMinimumPathSumTwo(matrix_thirteen);
    cout << "result:" << result_thirteen << endl;
    result_thirteen = minimum_path_sum.GetMinimumPathSumThree(matrix_thirteen);
    cout << "result:" << result_thirteen << endl;
    
    cout << "\nTest: Number Fourteen" << endl;
    string word1 = "sad2cdd", word2 = "std2d";
    EditDistance edit_distance;
    int result_fourteen = edit_distance.CountSteps(word1, word2);
    cout << "Result: " << result_fourteen << endl;

    cout << "\nTest: Number Fifteen" << endl;
    string word = "123456";
    DecodeWays decode_ways;
    int length_fifteen = decode_ways.CountDecodeWays(word);
    cout << "Result: " << length_fifteen << endl;
    
    cout << "\nTest: Number Sixteen" << endl;
    string S = "rabbbit", T = "rabbit";
    DistinctSubsequences distinct_subsequences;
    int result_sixteen = distinct_subsequences.NumberDistinctSubsequences(S, T);
    cout << "Result: " << result_sixteen << endl;
    result_sixteen = distinct_subsequences.NumberDistinctSubsequencesOne(S, T);
    cout << "Result: " << result_sixteen << endl;
    
    cout << "\nTest: Number Seventeen" << endl;
    string s_seventeen = "leetcode";
    unordered_set<string> dict = {"leet", "code"};
    WordBreak word_break;
    bool result_seventeen = word_break.CheckWordBreak(s_seventeen, dict);
    cout << "Result: " << result_seventeen << endl;
    
    cout << "\nTest: Number Eighteen" << endl;
    string s_eighteen = "catsanddog";
    unordered_set<string> dict_eighteen = {"cat", "cats", "and", "sand", "dog"};
    WordBreakII word_break_ii;
    vector<string> results_eighteen = word_break_ii.CheckWordBreak(s_eighteen, dict_eighteen);
    for (int i = 0; i < int(results_eighteen.size()); ++i) {
        cout << results_eighteen[i] << endl;
    }
    
    cout << "\nTest: Number Nineteen" << endl;
    int num_nineteen = 12321;
    PalindromeNumber palindrome_number;
    bool result_nineteen = palindrome_number.CheckPalindromeNumber(num_nineteen);
    cout << "Result: " << result_nineteen << endl;
   
    cout << "\nTest: Number Twenty" << endl;
    vector<Interval> num_twenty = {Interval(1, 2), Interval(3, 5), Interval(6, 7),
                                   Interval(8, 10), Interval(12, 16)};
    Interval num_interval = Interval(4, 9);
    InsertInterval insert_interval;
    vector<Interval> result_twenty = insert_interval.Insert(num_twenty, num_interval);
    for (vector<Interval>::iterator it = result_twenty.begin();
         it != result_twenty.end(); ++it) {
        cout << "[" << it->left << " " << it->right << "]" << endl;
    }
    
    cout << "\nTest: Number Twenty-one" << endl;
    string twenty_one = "ADOBECODEBANC";
    MinimumWindowSubstring minimum_windows_substring;
    string result_twenty_one = minimum_windows_substring.MinimumWindow(twenty_one, "ABC");
    cout << result_twenty_one << endl;
    
    cout << "\nTest: Number Twenty-two" << endl;
    string twenty_two_one = "111";
    string twenty_two_two = "222";
    MultiplyStrings multiply_strings;
    string result_twenty_two = multiply_strings.GetMultiplyString(twenty_two_one,
                                                                  twenty_two_two);
    cout << "Result:" << result_twenty_two << endl;

    cout << "\nTest: Number Twenty-three" << endl;
    Substring substring;
    string twenty_three_s = "barfoothefoobarman";
    set<string> twenty_three_l= {"foo", "bar"};
    vector<int> results_twenty_three = substring.FindStartingIndices(twenty_three_s,
                                                                     twenty_three_l);
    for (int i = 0; i < results_twenty_three.size(); ++i) {
        cout << results_twenty_three[i] << " ";
    }
    cout << endl;
    
    cout << "\nTest: Number Twenty-four" << endl;
    PascalTriangle pascal_triangle;
    vector<vector<int>> results_twenty_four = pascal_triangle.GeneratePascalTriangle(5);
    vector<int> result_twenty_four = pascal_triangle.GenerateRow(6);
    for (size_t i = 0; i < results_twenty_four.size(); ++i) {
        for (size_t j = 0; j < results_twenty_four[i].size(); ++j) {
            cout << results_twenty_four[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "The kth row: " << endl;
    for (size_t i = 0; i < result_twenty_four.size(); ++i) {
        cout << result_twenty_four[i] << " ";
    }
    cout << endl;
    
    cout << "\nTest: Number Twenty-five" << endl;
    SpiralMatrix spiral_matrix;
    vector<vector<int>> numbers_twenty_five = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result_twenty_five = spiral_matrix.SpiralOrder(numbers_twenty_five);
    for (size_t i = 0; i < result_twenty_five.size(); ++i) {
        cout << result_twenty_five[i] << " ";
    }
    cout << endl;
    vector<vector<int>> matrix_twenty_five = spiral_matrix.GenerateMatrix(3);
    for (int i = 0; i < int(matrix_twenty_five.size()); ++i) {
        for (int j = 0; j < int(matrix_twenty_five.size()); ++j) {
            cout << matrix_twenty_five[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Twenty-six" << endl;
    string s_twenty_six = "PAYPALISHIRING";
    ZigzagConversion zigzag_conversion;
    string result_twenty_six = zigzag_conversion.Conversion(s_twenty_six, 3);
    cout << result_twenty_six << endl;
    
    cout << "\nTest: Number Twenty-seven" << endl;
    int dividend = 20001;
    int divisor = 200;
    Divide divide;
    cout << "Result:" << divide.DivideTwoIntegers(dividend, divisor) << endl;

    cout << "\nTest: Number Twenty-eight" << endl;
    vector<string> text = {"This", "is", "an", "example", "of", "text", "justification."};
    TextJustification text_justification;
    vector<string> result_twenty_eight = text_justification.function(text, 16);
    for (int i = 0; i < int(result_twenty_eight.size()); ++i) {
        cout << "[" << result_twenty_eight[i] << "]" << endl;
    }

    
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




