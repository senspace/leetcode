//
//  basic_string_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 4/20/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include "basic_string_operation.h"

using namespace std;

/* Time complexity: O(n) Space complexity: O(1) */
bool ValidPalindrome::IsValidPolindrome(string s) {
    // ignoring cases
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin(), right = prev(s.end());
    while (left < right) {
        if (!isalpha(*left)) {
            ++left;
        } else if (!isalpha(*right)) {
            --right;
        } else if (*left == *right) {
            ++left;
            --right;
        } else {
            return false;
        }
    }
    return true;
}

/*
 * 暴力算法
 * Time complexity: O(m*n) Space complexity: O(1)
 */
char *ImplementStr::FirstOccurrenceOne(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char *)haystack;
    }
    while (*haystack) {
        const char *compared = haystack;
        const char *comparing = needle;
        while (*compared == *comparing) {
            ++compared;
            ++comparing;
            if (!*comparing) {
                return (char *)haystack;
            }
        }
        ++haystack;
    }
    return nullptr;
}

/*
 * KMP
 * Time complexity: O(m+n) space complexity: O(1)
 */
char *ImplementStr::FirstOccurrenceTwo(const char *haystack, const char *needle) {
    int pos = kmp(haystack, needle);
    if (pos == -1) {
        return nullptr;
    }
    else {
        return (char *)haystack + pos;
    }
}

/* 
 * Function: String to Integer
 * Time complexity: O(n) Space complexity: O(1) 
 */
int StringToInteger::atoi(const char *str) {
    int num = 0;
    int i = 0;
    int sign = 1;
    size_t length = strlen(str);
    while (str[i] == ' ' && i < length) {
        ++i;
    }
    if (str[i] == '+') {
        ++i;
    } else if(str[i] == '-') {
        sign = -1;
        ++i;
    }
    for (; i < length; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && ((str[i] - '0') > INT_MAX % 10))) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}

/*
 * Function: Add Binary
 * Time complexity: O(n) Space complexity: O(1)
 */
string AddBinary::AddBinaryOne(string one, string two) {
    string result;
    size_t length = one.size() > two.size() ? one.size() : two.size();
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());
    int carry = 0;
    for (size_t i = 0; i < length; ++i) {
        int ai = i < one.size() ? one.at(i) - '0' : 0;
        int bi = i < two.size() ? two.at(i) - '0' : 0;
        int element = (ai + bi + carry) % 2;
        carry = (ai + bi + carry) / 2;
        result.insert(result.begin(), element + '0');
    }
    if (carry == 1) {
        result.insert(result.begin(), '1');
    }
    return result;
}

/*
 * Function: Regular Expression Matching
 * Time complexity: O(n) Space complexity: O(1)
 */
bool RegularExpressionMatching::IsMatch(string s, string p) {
    // case one
    if (p.size() == 0) {
        return s.size() == 0;
    }
    // case two
    if (p.size() == 1) {
        return (s.size() == 1) && (p.at(0) == s.at(0) || p.at(0) == '.');
    }
    if (p.at(1) == '*') {
        if (IsMatch(s, p.substr(2))) {
            return true;
        } else {
            return s.size() > 0
                && (p.at(0) == s.at(0) || p.at(0) == '.')
                && IsMatch(s.substr(1), p);
        }
    } else {
        return s.size() > 0
            && (p.at(0) == s.at(0) || p.at(0) == '.')
            && IsMatch(s.substr(1), p.substr(1));
    }
}

/*
 * Function: Wildcard Matching[递归版]
 * Time complexity: O(n! * m!) Space complexity: O(n)
 */
bool WildcardMatching::IsMatchOne(string s, string p) {
    if (p.size() == 0) {
        return s.size() == 0;
    } else if (p.at(0) == '*') {
        int index_p = 0;
        int index_s = 0;
        // skip continuous '*'
        while (p.at(index_p) == '*') {
            ++index_p;
        }
        if (p.substr(index_p).size() == 0) {
            return true;
        }
        while (s.substr(index_s).size() > 0 && !IsMatchOne(s.substr(index_s), p.substr(index_p))) {
            ++index_s;
        }
        return s.substr(index_s).size() != 0;
    } else {
        return s.size() > 0
            && (p.at(0) == s.at(0) || p.at(0) == '?')
            && IsMatchOne(s.substr(1), p.substr(1));
    }
}

/*
 * Function: Wildcard Matching【贪心算法]
 * Time complexity: O(n * m) Space complexity: O(1)
 */
bool WildcardMatching::IsMatchTwo(string s, string p) {
    int i = 0, j = 0;
    int star = -1;
    int mark = -1;
    while (i < s.size()) {
        if (j < p.size() && (p.at(j) == '?' || p.at(j) == s.at(i))) {
            ++i;
            ++j;
        } else if (j < p.size() && p.at(j) == '*') {
            star = j;
            ++j;
            mark = i;
        } else if (star != -1) {
            j = star + 1;
            i = ++mark;
        } else {
            return false;
        }
    }
    while (j < p.size() && p.at(j) == '*') {
        return true;
    }
    return j == p.size();
}

/*
 * Function: Longest Common Prefix[纵向扫描]
 * Time complexity: O(n1 + n2 + ...) Space complexity: O(1)
 */
string LongestCommonPrefix::LongestCommonPrefixOne(vector<string> &strs) {
    if (strs.empty()) {
        return " ";
    }
    for (size_t i = 0; i < strs[0].size(); ++i) {
        for (size_t j = 1; j < strs.size(); ++j) {
            if (strs[0][i] != strs[j][i]) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

/*
 * Function: Valid Number(有限自动机-Finite automata machine)
 * Time complexity:O(n) Space complexity:O(n)
 * Analysis:[9种状态]
 *  zero: 初始无输入或只有space的状态
 *  one: 输入数字之后的状态
 *  two: 前面无数字，只输入dot的状态
 *  three: 输入符号状态
 *  four: 前面有数字和有dot的状态
 *  five: 'e'或'E'输入后的状态
 *  six: 输入'e'之后输入sign的状态
 *  seven: 输入'e'之后输入数字的状态
 *  eight: 前面有有效输入之后，输入space的状态
 */
bool ValidNumber::IsNumberOne(string s) {
    enum InputType {
        INVALID,    // 0 -> include alphas, '(', '&' and so on
        SPACE,      // 1
        SIGN,       // 2 -> '+', '-'
        DIGIT,      // 3 -> numbers
        DOT,        // 4 -> '.'
        EXPONENT,   // 5 -> 'e', 'E'
        NUM_INPUTS  // 6
    };
    const int transition_table[][NUM_INPUTS] = {
        // 0 INVALID, 1 SAPCE, 2 SIGN, 3 DIGIT, 4 DOT, 5 EXPONENT
        -1, 0, 3, 1, 2, -1,     // 0: 初始无输入或者只有space的状态
        -1, 8, -1, 1, 4, 5,     // 1: 输入数字之后的状态
        -1, -1, -1, 4, -1, -1,  // 2: 前面无数字，只输入dot的状态
        -1, -1, -1, 1, 2, -1,   // 3: 输入符号的状态
        -1, 8, -1, 4, -1, 5,    // 4: 前面有数字和有dot的状态
        -1, -1, 6, 7, -1, -1,   // 5: 'e'或'E'输入之后的状态
        -1, -1, -1, 7, -1, -1,   // 6: 输入'e'之后输入sign的状态
        -1, 8, -1, 7, -1, -1,    // 7: 输入'e'之后输入数字的状态
        -1, 8, -1, -1, -1, -1,    // 8: 前面有有效输入之后，输入space的状态
    };
    int state = 0;
    for (int i = 0; i < s.size(); ++i) {
        InputType input = INVALID;
        if (s.at(i) == ' ') {
            input = SPACE;
        } else if (s.at(i) == '+' || s.at(i) == '-') {
            input = SIGN;
        } else if (isdigit(s.at(i))) {
            input = DIGIT;
        } else if (s.at(i) == '.') {
            input = DOT;
        } else if (s.at(i) == 'e' || s.at(i) == 'E') {
            input = EXPONENT;
        }
        state = transition_table[state][input];
        if (state == -1) {
            return false;
        }
    }
    // If the current state belongs to one of the accepting (final) states,
    // then the number is valid.
    return state == 1 || state == 4 || state == 7 || state == 8;
}

/* Time complexity:O(n) Space complexity:O(1) */
bool ValidNumber::IsNumberTwo(string s) {
    const char *str = s.c_str();
    char *endptr;
    strtod(str, &endptr);
    if (endptr == str) {
        return false;
    }
    for (; *endptr; ++endptr) {
        if (!isspace(*endptr)) {
            return false;
        }
    }
    return true;
}

/*
 * Function: Integer to Roman
 * Time complexity:O(num) Space complexity:O(1)
 * 罗马数字共有七个，即I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)
 * 算法分析：
 * 将单个罗马字符扩展成组合形式，来避免需要额外处理类似IX这种特殊情况。[1 4 5 9 10 ...]
 * I: 1   IV: 4   V: 5    IX: 9
 * X: 10  XL: 40  L: 50   XC: 90
 * C: 100 CD: 400 D: 500  CM: 900
 * M: 1000
 */
string IntegerToRoman::IntToRoman(int num) {
    vector<pair<int, string>> roman;
    roman.push_back(make_pair(1000, "M"));
    roman.push_back(make_pair(900, "CM"));
    roman.push_back(make_pair(500, "D"));
    roman.push_back(make_pair(400, "CD"));
    roman.push_back(make_pair(100, "C"));
    roman.push_back(make_pair(90, "XC"));
    roman.push_back(make_pair(50, "L"));
    roman.push_back(make_pair(40, "XL"));
    roman.push_back(make_pair(10, "X"));
    roman.push_back(make_pair(9, "IX"));
    roman.push_back(make_pair(5, "V"));
    roman.push_back(make_pair(4, "IV"));
    roman.push_back(make_pair(1, "I"));
    
    string result;
    int number = num;
    for (int i = 0; number > 0; ++i) {
        int count = number / roman.at(i).first;
        for (int j = 0; j < count; ++j) {
            result += roman.at(i).second;
        }
        number %= roman.at(i).first;
    }
    return result;
}

/*
 * Function: Roman numeral to Integer
 * Time complexity:O(n) Space complexity:O(1)
 * 罗马数字共有七个，即I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)
 * 算法分析:
 *
 */
int RomanToInteger::RomanToInt(string s) {
    vector<pair<int, string>> roman;
    roman.push_back(make_pair(1000, "M"));
    roman.push_back(make_pair(900, "CM"));
    roman.push_back(make_pair(500, "D"));
    roman.push_back(make_pair(400, "CD"));
    roman.push_back(make_pair(100, "C"));
    roman.push_back(make_pair(90, "XC"));
    roman.push_back(make_pair(50, "L"));
    roman.push_back(make_pair(40, "XL"));
    roman.push_back(make_pair(10, "X"));
    roman.push_back(make_pair(9, "IX"));
    roman.push_back(make_pair(5, "V"));
    roman.push_back(make_pair(4, "IV"));
    roman.push_back(make_pair(1, "I"));
    int result = 0;
    int i = 0;
    int index = 0;
    while(i < s.size() && index < 13) {
        string target = roman[index].second;
        if (s.substr(i, roman[index].second.size()) == target) {
            result += roman[index].first;
            i += target.size();
        } else {
            ++index;
        }
    
    }
    return result;
}

int RomanToInteger::RomanToIntOne(string s) {
    int result = 0;
    if (s.size() == 0) {
        return result;
    }
    result += roman_[*s.begin()];
    for (auto it = next(s.begin()); it != s.end(); ++it) {
        if (roman_[*it] > roman_[*prev(it)]) {
            result += roman_[*it] - 2 * roman_[*prev(it)];
        } else {
            result += roman_[*it];
        }
    }
    return result;
}

/* 
 * Function: Count and Say
 * Time complexity: O(n^2) Space complexity: O(n) 
 */
string CountSay::CountAndSay(int n) {
    if (n < 1) {
        return "";
    }
    string result("1");
    for (int i = 1; i < n; ++i) {
        string temp = "";
        char prev = result.at(0);
        int count = 1;
        for (int j = 1; j < result.size(); ++j) {
            if (result.at(j) == prev) {
                ++count;
            } else {
                temp += to_string(count);
                temp.push_back(prev);
                count = 1;
                prev = result.at(j);
            }
        }
        temp += to_string(count);
        temp.push_back(prev);
        result = temp;
    }
    return result;
}

/*
 * Number Eleven: Anagrams
 * Time complexity: O(n) Time complexity: O(n)
 */
unordered_map<string, vector<string>> Anagrams::GetAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> records;
    for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
        string key = *it;
        sort(key.begin(), key.end());
        records[key].push_back(*it);
    }
    return records;
}

/*
 * Number Twelve: Simplify Path
 * Time complexity: O(n) Time complexity: O(n)
 */
string SimplifyPath::GetSimplityPath(string path) {
    string result, cur_dir;
    vector<string> all_dirs;
    path.push_back('/');
    for (size_t i = 0; i < path.size(); ++i) {
        if (path.at(i) == '/') {
            if (cur_dir.empty()) {
                continue;
            } else if (cur_dir == ".") {
                cur_dir.clear();
            } else if (cur_dir == "..") {
                if (!all_dirs.empty()) {
                    all_dirs.pop_back();
                }
                cur_dir.clear();
            } else {
                all_dirs.push_back(cur_dir);
                cur_dir.clear();
            }
        } else {
            cur_dir.push_back(path.at(i));
        }
    }
    for (vector<string>::iterator it = all_dirs.begin(); it != all_dirs.end(); ++it) {
        result.append("/" + *it);
    }
    if (result.empty()) {
        result = "/";
    }
    return result;
}

/*
 * Number Twelve: Length of Last Word(STL)
 * Time complexity: O(n) Space complexity: O(1) */
size_t LengthOfLastWord::GetLengthOfLastWordOne(string s) {
    string::reverse_iterator first = find_if(s.rbegin(), s.rend(), ::isalpha);
    string::reverse_iterator last = find_if_not(first, s.rend(), ::isalpha);
    return distance(first, last);
}

/* 
 * 顺序扫描
 * Time complexity: O(n) Space complexity: O(1) 
 * 算法分析：
 * 首先想到的是找到s的尾部，然后反向扫最后一个word得到长度。但这样扫需要两个pass，效率还不是最优，目标是一个pass解决。
 * 用两个变量lastLen, curLen分别记录前一个和当前word的长度。
 * 1. 当前字符为字母时，说明当前word仍然没结束，更新curLen++
 * 2. 当前字符为空格时，如果curLen不为0，说明是一个word刚结束，将lastLen更新为curLen。
 * 3. 当前字符为空格且curLen=0，说明前一个字符也是空格，不需要额外操作。
 * 4. 由于只有在遇到空格时才更新lastLen，当最后一个word后没有空格就结束时，lastLen还没有被更新，
 * 所以在搜索完整个s后，如果curLen不为0，则curLen才是真正最后word的长度。而如果最后一个word后
 * 有空格，则lastLen为长度。
 */
size_t LengthOfLastWord::GetLengthOfLastWordTwo(string s) {
    size_t last_length = 0, cur_length = 0;
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (isalpha(*it)) {
            ++cur_length;
        } else if (cur_length != 0) {
            last_length = cur_length;
            cur_length = 0;
        }
    }
    return cur_length == 0 ? last_length : cur_length;
}











