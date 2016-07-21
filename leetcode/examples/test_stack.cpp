//
//  test_stack.cpp
//  leetcode
//
//  Created by NoteFAN on 5/10/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <math.h>
#include "stack_operation.h"

using namespace std;

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    cout << "Test: Number Zero" << endl;
    string s_zero = "()[]{}}";
    ValidParentheses valid_parentheses;
    bool result_zero = valid_parentheses.CheckValidParentheses(s_zero);
    cout << "result:" << result_zero << endl;
    
    cout << "\nTest: Number One" << endl;
    string s_one = "(((((()))()()";
    LongestValidParentheses longest_valid_parentheses;
    size_t result_one = longest_valid_parentheses.GetLongestValidParenthesesOne(s_one);
    cout << "result:" << result_one << endl;
    result_one = longest_valid_parentheses.GetLongestValidParenthesesTwo(s_one);
    cout << "result:" << result_one << endl;
    
    cout << "\nTest: Number Two" << endl;
    vector<int> s_two = {2, 1, 5, 6, 2, 3};
    LargestRectangleInHistogram largest_rectangle_in_histogram;
    int result_two = largest_rectangle_in_histogram.GetLargestRectangleInHistogram(s_two);
    cout << "result:" << result_two << endl;
    
    cout << "\nTest: Number Three" << endl;
    vector<string> s_three = {"2", "1", "+", "3", "*"};
    vector<string> s_three_other = {"4", "13", "5", "/", "+"};
    EvaluateReversePolishNotation evaluate_reverse_polish_notation;
    int result_three = evaluate_reverse_polish_notation.GetEvaluateValue(s_three);
    cout << "result:" << result_three << endl;
    result_three = evaluate_reverse_polish_notation.GetEvaluateValue(s_three_other);
    cout << "result:" << result_three << endl;
    
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




