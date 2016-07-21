//
//  stack_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 5/10/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include "stack_operation.h"

/*
 * Valid Parentheses
 * Time complexity: O(n) Space complexity: O(n)
 */
bool ValidParentheses::CheckValidParentheses(string s) {
    stack<char> stk;
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (IsLeft(*it)) {
            stk.push(*it);
        } else {
            if (stk.empty() || !IsClose(stk.top(), *it)) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

/*
 * Longest Valid Parentheses
 * Time complexity: O(n) Space complexity: O(n)
 */
size_t LongestValidParentheses::GetLongestValidParenthesesOne(string s) {
    stack<pair<int, char>> stk;
    size_t cur_length = 0, max_length = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s.at(i) == '(') {
            stk.push(make_pair(i, '('));
        } else {
            if (stk.empty() || stk.top().second == ')') {
                stk.push(make_pair(i, ')'));
            } else {
                stk.pop();
                if (stk.empty()) {
                    cur_length = i + 1;
                } else {
                    cur_length = i - stk.top().first;
                }
                max_length = max(max_length, cur_length);
            }
        }
    }
    return max_length;
}

/*
 * Longest Valid Parentheses
 * Time complexity: O(n) Space complexity: O(n)
 */
size_t LongestValidParentheses::GetLongestValidParenthesesTwo(string s) {
    int length = int(s.size()), max_length = 0;
    vector<int> dp(length + 1, 0);
    for (int i = 1; i <= length; ++i) {
        int j = i - 2 - dp[i - 1];
        if (s[i - 1] == '(' || j < 0 || s[j] == ')') {
            dp[i] = 0;
        } else {
            dp[i] = dp[i - 1] + 2 + dp[j];
            max_length = max(max_length, dp[i]);
        }
    }
    return size_t(max_length);
}

/*
 * Largest Rectangle in Histogram
 * Time complexity: O(n) Space complexity: O(n)
 * Method:
 *    仔细考察Brute Force算法，发现问题在于指针重复扫描。以递增序列为例：
 * 0 1 2 3 4 5 6
 * 在计算s[0]的时候扫描了右边6个数，计算s[1]时继续扫描右边5个数，依次类推。而没能利用到这个
 * 序列的递增性质。当序列从i递增到j时，bar i~j的面积一定都能扩展到j。而一旦在j+1递减了，那么
 * 表示bar i~j中的部分bar k无法继续扩展，条件是h[k]>h[j+1]。
 * 1. 利用这个性质，可以将递增序列cache在一个stack中，一旦遇到递减，则根据h[j+1]来依次从
 * stack里pop出那些无法继续扩展的bar k，并计算面积。
 * 2. 由于面积的计算需要同时知道高度和宽度，所以在stack中存储的是序列的坐标而不是高度。
 * 因为知道坐标后很容易就能知道高度，而反之则不行。
 */
int LargestRectangleInHistogram::GetLargestRectangleInHistogram(vector<int> &height) {
    if (height.size() == 0) {
        return 0;
    }
    height.insert(height.begin(), -1);
    height.push_back(-1);
    
    stack<int> stk;
    int max_area = 0;
    
    for (int i = 0; i < int(height.size()); ++i) {
        while (!stk.empty() && height[i] < height[stk.top()]) {
            int h = height[stk.top()];
            stk.pop();
            if (height[stk.top()] < h) {
                max_area = max(max_area, (i - stk.top() - 1) * h);
            }
        }
        stk.push(i);
    }
    // reset height
    height.erase(height.begin());
    height.pop_back();
    return max_area;
}

/*
 * Number Three: Evaluate Reverse Polish Notation
 * Time complexity: O(n) Space complexity: O(n)
 * Method:
 * 典型的stack问题。逐一扫描每个token，如果是数字，则push入stack，如果是运算符，则从stack中
 * pop出两个数字，进行运算，将结果push回stack。最后留在stack里的数即为最终结果。
 */
int EvaluateReversePolishNotation::GetEvaluateValue(vector<string> &tokens) {
    stack<int> stk;
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        if (IsOperators(*it)) {
            int y = stk.top();
            stk.pop();
            int x = stk.top();
            stk.pop();
            stk.push(Evaluate(x, y, *it));
        } else {
            stk.push(stoi(*it));
        }
    }
    return stk.top();
}










