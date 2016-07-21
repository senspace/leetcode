//
//  stack_operation.hpp
//  leetcode
//
//  Created by NoteFAN on 5/10/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef STACK_OPERATION_H
#define STACK_OPERATION_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * Number Zero: Valid Parentheses
 * Descriptions:
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid. The brackets must close in the correct 
 * order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
class ValidParentheses {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    bool CheckValidParentheses(string s);
protected:
    
private:
    bool IsLeft(char a) {
        if (a == '(' || a == '{' || a == '[') {
            return true;
        }
        return false;
    }
    
    bool IsClose(char a, char b) {
        if (a == '(') return b == ')';
        if (a == '{') return b == '}';
        if (a == '[') return b == ']';
        return false;
    }
};

/*
 * Number One: Longest Valid Parentheses
 * Descriptions:
 * Given a string containing just the characters '(' and ')', find the length of 
 * the longest valid (well-formed) parentheses substring. For "(()", the longest 
 * valid parentheses substring is "()", which has length = 2. Another example is 
 * ")()())", where the longest valid parentheses substring is "()()", which has 
 * length = 4.
 * Reference: http://bangbingsyb.blogspot.sg/search?q=Longest+Valid+Parentheses
 */
class LongestValidParentheses {
public:
    /* 
     * Method: stack
     * Time complexity: O(n) Space complexity: O(n)
     */
    size_t GetLongestValidParenthesesOne(string s);
    
    /* 
     * Dynamic programming
     * Time complexity: O(n) Space complexity: O(n) 
     */
    size_t GetLongestValidParenthesesTwo(string s);
protected:
    
private:

};

/*
 * Number Two: Largest Rectangle in Histogram
 * Descriptions:
 * Given n non-negative integers representing the histogram's bar height where 
 * the width of each bar is 1, find the area of largest rectangle in the histogram. 
 */
class LargestRectangleInHistogram {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    int GetLargestRectangleInHistogram(vector<int> &height);
protected:
    
private:

};

/*
 * Number Three: Evaluate Reverse Polish Notation
 * Descriptions:
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
class EvaluateReversePolishNotation {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    int GetEvaluateValue(vector<string> &tokens);
protected:
    
private:
    bool IsOperators(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int Evaluate(int x, int y, string op) {
        if (op == "+") {
            return x + y;
        } else if (op == "-") {
            return x - y;
        } else if (op == "*") {
            return x * y;
        } else if (op == "/") {
            return x / y;
        } else {
            return 0;
        }
    }
};










#endif /* stack_operation_hpp */
