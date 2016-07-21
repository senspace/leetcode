//
//  basic_string_operation.h
//  leetcode
//
//  Created by NoteFAN on 4/20/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef BASIC_STRING_OPERATION_H
#define BASIC_STRING_OPERATION_H

#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
 * Number One: Valid Palindrome
 * Description:
 * Given a string, determine if it is a palindrome, considering only alphanumeric 
 * characters and ignoring cases.
 * For example,
 *    "A man, a plan, a canal: Panama" is a palindrome.
 *    "race a car" is not a palindrome.
 * Note: Have you consider that the string might be empty? This is a good quetion
 * to ask during an interview. For the purpose of this problem, we define empty
 * string as valid palindrome.
 */
class ValidPalindrome {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    bool IsValidPolindrome(string s);
protected:
    
private:
    
};

/*
 * Number Two: Implement strStr()
 * Description:
 * Returns a pointer to the first occurrence of needle in haystack, 
 * or null if needle is not part of haystack.
 */
class ImplementStr {
public:
    /*
     * 暴力算法
     * Time complexity: O(m*n) Space complexity: O(1)
     */
    char *FirstOccurrenceOne(const char *haystack, const char *needle);
    /*
     * KMP
     * Time complexity: O(m+n) space complexity: O(1)
     */
    char *FirstOccurrenceTwo(const char *haystack, const char *needle);
protected:
    
private:
    /*
     * @brief 计算部分匹配表，即next数组
     * @param[int] pattern 模式串
     * @param[out] next 数组
     * @return None
     */
    static void GetNext(const char *pattern, int next[]) {
        size_t length = strlen(pattern);
        int j = 0;
        int k = -1;
        next[0] = -1;
        while (j < length - 1) {
            //p[k]表示前缀，p[j]表示后缀
            if (k == -1 || pattern[j] == pattern[k]) {
                ++j;
                ++k;
                
                if (pattern[j] != pattern[k]) {
                    next[j] = k;
                } else {
                    // 因为不能出现p[j] = p[next[j]],
                    // 所以当出现时需要继续递归，k = next[k] = next[next[k]]
                    next[j] = next[k];
                }
            } else {
                k = next[k];
            }
        }
    }
    
    /*
     * @brief KMP algorithm
     * @param[int] text 文本
     * @param[int] pattern 模式串
     * @return 成功则返回第一次匹配的位置， 失败则返回-1
     */
    static int kmp(const char *text, const char *pattern) {
        int i = 0, j = 0;
        int slen = int(strlen(text));
        int plen = int(strlen(pattern));
        /* "", "" */
        if (slen == 0 && plen == 0) {
            return 0;
        }
        /* "a", "" */
        if (plen == 0) {
            return 0;
        }
        int *next = new int[plen];
        GetNext(pattern, next);
        while (i < slen && j < plen) {
            if (j == -1 || text[i] == pattern[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        free(next);
        if (j == plen) {
            return i - j;
        } else {
            return -1;
        }
    }
};

/*
 * Number Three: String to Integer(atoi)
 * Description:
 * Implement atoi to convert a string to an integer.
 * Hint: 
 *     Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 * Notes: 
 *     It is intended for this problem to be specified vaguely (ie, no given 
 * input specs). You are responsible to gather all the input requirements up front.
 */
class StringToInteger {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int atoi(const char *str);
protected:
    
private:

};


/*
 * Number Three: Add Binary
 * Description:
 * Given two binary strings, return their sum (also a binary string).
 * For example, a = "11", b = "1", return "100".
 */
class AddBinary {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    string AddBinaryOne(string one, string two);
protected:
    
private:
    
};

/*
 * Number Four: Longest Palindromic Substring
 * Description:
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, and there exists
 * one unique longest palindromic substring.
 * 算法分析: (最长回文子串,非常经典的题)
 *    思路一:暴力枚举, 以每个元素为中间元素, 同时从左右出发, 复杂度O(n^2)。
 *    思路二:记忆化搜索,复杂度 O(n^2)。设f[i][j]表示 [i,j] 之间的最长回文子串,递推方程如下:
 *      f[i][j] = if(i == j) S[j]
 *                if(S[i] == S[j] && f[i + 1][j - 1] == S[i + 1][j - 1]) S[i][j]
 *                else max(f[i + 1][j - 1], f[i][j - 1], f[i + 1][j])
 *    思路三:动规,复杂度 O(n^2)。设状态为f(i, j), 表示区间[i,j]是否为回文串,则状态转移方程为:
 *                | true                                ,i = j
 *      f[i][j] = | S[i]=S[j]                           ,j = i + 1
 *                | S[i]=S[j] and f(i + 1, j − 1)       ,j>i+1
 *    思路四:Manacher’s Algorithm, 时间复杂度O(n)。详细解释见:
 *      http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
 *      https://www.felix021.com/blog/read.php?2040 (chinese)
 */
typedef string::const_iterator Iterator;

namespace std {
    template<>
    struct hash<pair<Iterator, Iterator>> {
        size_t operator()(pair<Iterator, Iterator> const &p) const {
            return ((size_t) &(*p.first) ^ (size_t) &(*p.second));
        }
    };
}

class LongestPalindromicSubstring {
public:
    /* 
     * 思路二:记忆化搜索
     * Time complexity: O(n^2) Space complexity: O(n^2) 
     */
    string LongestPalindromicSubstringOne(string const &str) {
        cache.clear();
        return CachedLongestPalindrome(str.begin(), str.end());
    }
    /*
     * 思路三:动规
     * Time complexity: O(n^2) Space complexity: O(n^2)
     */
    string LongestPalindromicSubstringTwo(string s) {
        size_t n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);
        // 最大回文子串长度，起点
        size_t max_len = 1, start = 0;
        for (size_t i = 0; i < n; ++i) {
            f[i][i] = true;
            for (size_t j = 0; j < i; ++j) {
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
    /*
     * 思路四:Manacher’s Algorithm
     * Time complexity: O(n) Space complexity: O(n)
     * id: 为已知的 {右边界最大} 的回文子串的中心;
     * mx: 为id+P[id]，也就是这个子串的右边界.
     */
    string LongestPalindromicSubstringThree(string s) {
        string t = PreProcess(s);
        int length = int(t.size());
        int p[length];
        fill_n(p, length, 0);
        int id = 0, mx = 0;
        
        for (int i = 1; t[i] != '$'; ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) {
                ++p[i];
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        // find the maximum element in the array named 'p'
        int max_len = 0;
        int center_index = 0;
        for (int i = 1; i < length - 1; ++i) {
            if (p[i] > max_len) {
                max_len = p[i];
                center_index = i;
            }
        }
        return s.substr((center_index - 1 - max_len) / 2, max_len);
    }
    /*
     * 思路五: expanded from its center
     * Time complexity: O(n^2) Space complexity: O(1)
     * Analysis:
     * A simpler approach, O(N^2) time and O(1) space:
     * We observe that a palindrome mirrors around its center. Therefore, 
     * a palindrome can be expanded from its center, and there are only 2N-1 
     * such centers. You might be asking why there are 2N-1 but not N centers? 
     * The reason is the center of a palindrome can be in between two letters. 
     * Such palindromes have even number of letters (such as “abba”) and its 
     * center are between the two ‘b’s. Since expanding a palindrome around 
     * its center could take O(N) time, the overall complexity is O(N^2).
     */
    string LongestPalindromicSubstringFour(string s) {
        int length = int(s.size());
        if (length == 0) {
            return "";
        }
        string longest = s.substr(0, 1);
        for (int i = 0; i < length - 1; ++i) {
            string temp = ExpandAroundCenter(s, i, i);
            if (temp.size() > longest.size()) {
                longest = temp;
            }
            temp = ExpandAroundCenter(s, i, i + 1);
            if (temp.size() > longest.size()) {
                longest = temp;
            }
        }
        return longest;
    }
protected:
    
private:
    /*
     * 思路二:记忆化搜索
     * Time complexity: O(n^2) Space complexity: O(n^2)
     */
    unordered_map<pair<Iterator, Iterator>, string> cache;
    
    string LongestPalindrome(Iterator first, Iterator end) {
        size_t length = distance(first, end);
        if (length < 2) {
            return string(first, end);
        }
        string s = CachedLongestPalindrome(next(first), prev(end));
        if (s.length() == length - 2 && *first == *prev(end)) {
            return string(first, end);
        }
        
        auto s1 = CachedLongestPalindrome(next(first), end);
        auto s2 = CachedLongestPalindrome(first, prev(end));
        
        // return max(s, s1, s2)
        if (s.size() > s1.size()) {
            return s.size() > s2.size() ? s : s2;
        } else {
            return s1.size() > s2.size() ? s1 : s2;
        }
    }
    
    string CachedLongestPalindrome(Iterator first, Iterator end) {
        auto key = make_pair(first, end);
        auto pos = cache.find(key);
        
        if (pos != cache.end()) {
            return pos->second;
        } else {
            cache[key] = LongestPalindrome(first, end);
            return cache[key];
        }
    }
    
    /*
     * 思路四:Manacher’s Algorithm
     * Transform s to t
     * For example, s = "abba", t = "^#a#b#b#a#$"
     * ^ and $ signs ate sentinels appended to each end to avoid bounds checking
     */
    string PreProcess(string s) {
        size_t length = s.size();
        if (length == 0) {
            return "^$";
        }
        string result = "^";
        for (size_t i = 0; i < length; ++i) {
            result.push_back('#');
            result.push_back(s.at(i));
        }
        result.append("#$");
        return result;
    }
    
    /*
     * 思路五: expanded from its center
     * Time complexity: O(n^2) Space complexity: O(1)
     */
    string ExpandAroundCenter(string s, int c1, int c2) {
        int length = int(s.size());
        int l = c1, r = c2;
        while ((l >= 0) && (r <= length - 1) && (s[l] == s[r])) {
            --l;
            ++r;
        }
        return s.substr(l + 1, r - l - 1);
    }
};

/*
 * Number Five: Regular Expression Matching
 * Description:
 * Implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character. 
 * '*' Matches zero or more of the preceding element. 
 * The matching should cover the entire input string (not partial).
 * The function prototype should be:
 *  bool Ismatch(const char *s, const char *p);
 * Some examples:
 *  IsMatch("aa", "a") -> false
 *  IsMatch("aa", "aa") -> true
 *  IsMatch("aaa", "aa") -> false
 *  IsMatch("aa", "a*") -> true
 *  IsMatch("aa", ".*") -> true
 *  IsMatch("ab", ".*") -> true
 *  IsMatch("aab", "c*a*b") -> true
 */
class RegularExpressionMatching {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    bool IsMatch(string s, string p);
protected:
    
private:

};

/*
 * Number Six: Wildcard Matching
 * Description:
 * Implement wildcard pattern matching with support for '?' and '*'.
 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 
 * The matching should cover the entire input string (not partial).
 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 
 * Some examples:
 *  isMatch("aa","a") → false
 *  isMatch("aa","aa") → true
 *  isMatch("aaa","aa") → false
 *  isMatch("aa", "*") → true
 *  isMatch("aa", "a*") → true
 *  isMatch("ab", "?*") → true
 *  isMatch("aab", "c*a*b") → false
 */
class WildcardMatching {
public:
    /*
     * 递归版
     * Time complexity:O(n! * m!) Space complexity:O(n)
     */
    bool IsMatchOne(string s, string p);
    /*
     * 贪心算法(greedy)
     * Time complexity:O(n * m) Space complexity:O(1)
     */
    bool IsMatchTwo(string s, string p);
protected:
    
private:
    
};

/*
 * Number Seven: Longest Common Prefix
 * Description:
 * Write a function to find the longest common prefix string amongest an array
 * of string.
 * Analysis: 从位置 0 开始,对每一个位置比较所有字符串,直到遇到一个不匹配。
 */
class LongestCommonPrefix {
public:
    /* Time complexity:O(n1 + n2 + ...) Space complexity:O(1) */
    string LongestCommonPrefixOne(vector<string> &strs);
protected:
    
private:

};

/*
 * Number Eight: Valid Number
 * Description:
 * Validate if a given string is numeric. 
 * Examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. 
 * You should gather all requirements up front before implementing one.
 */
class ValidNumber {
public:
    /* Time complexity:O(n) Space complexity:O(n) */
    bool IsNumberOne(string s);
    /* Time complexity:O(n) Space complexity:O(1) */
    bool IsNumberTwo(string s);
protected:
    
private:

};

/*
 * Number Nine: Integer to Roman
 * Description:
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Roman Numeral
 * 罗马数字共有七个，即I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)。
 * 按照下面的规则可以表示任意正整数。
 * 重复数次：一个罗马数字重复几次，就表示这个数的几倍。
 * 右加左减：在一个较大的罗马数字的右边记上一个较小的罗马数字，表示大数字加小数字。
 * 在一个较大的数字的左边记上一个较小的罗马数字，表示大数字减小数字。但是，左减不能跨越等级。
 * 比如，99不可以用IC表示，用XCIX表示。
 * 加线乘千：在一个罗马数字的上方加上一条横线或者在右下方写M，表示将这个数字乘以1000，
 * 即是原数的1000倍。同理，如果上方有两条横线，即是原数的1000000倍。
 * 单位限制：同样单位只能出现3次，如40不能表示为XXXX，而要表示为XL。
 * Note: 罗马数字没有零，运算的时候不能进位，不能做除法，即使十分简单的运算，也极为困难。
 */
class IntegerToRoman {
public:
    /* Time complexity: O(num) Space complexity: O(1) */
    string IntToRoman(int num);
protected:
    
private:

};

/*
 * Number Nine: Roman numeral to Integer
 * Description:
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class RomanToInteger {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int RomanToInt(string s);
    int RomanToIntOne(string s);
protected:
    
private:
    unordered_map<char, int> roman_ = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},\
                                       {'C', 100}, {'D', 500}, {'M', 1000}};
};

/*
 * Number Ten: Count and Say
 * Description:
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *  1 is read off as "one 1" or 11.
 *  11 is read off as "two 1s" or 21.
 *  21 is read off as "one 2, then one 1" or 1211.
 *  Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */
class CountSay {
public:
    /* Time complexity: O(n^2) Space complexity: O(n) */
    string CountAndSay(int n);
protected:
    
private:

};

/*
 * Number Eleven: Anagrams
 * Description:
 * Given an array of strings, return all groups of strings that are anagrams. 
 * Note: All inputs will be in lower-case.
 * 算法分析:
 * Anagram(回文构词法)是指打乱字母顺序从而得到新的单词。
 * 回文构词法有一个特点:单词里的字母的种类和数目没有改变,只是改变了字母的排列顺序。 
 * 因此,将几个单词按照字母顺序排序后,若它们相等,则它们属于同一组anagrams 。
 */
class Anagrams {
public:
    /* Time complexity: O(n) Time complexity: O(n) */
    unordered_map<string, vector<string>> GetAnagrams(vector<string> &strs);
protected:
    
private:

};

/*
 * Number Twelve: Simplify Path
 * Description:
 * Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 *  path = "/home/", => "/home"
 *  path = "/a/./b/../../c/", => "/c"
 *  click to show corner cases.
 * Corner Cases:
 *  Did you consider the case where path = "/../"? In this case, you should return "/".
 *  Another corner case is the path might contain multiple slashes '/' together, 
 *  such as "/home//foo/". In this case, you should ignore redundant slashes and 
 *  return "/home/foo".
 */
class SimplifyPath {
public:
    /* Time complexity: O(n) Time complexity: O(n) */
    string GetSimplityPath(string path);
protected:
    
private:
    
};

/*
 * Number Twelve: Length of Last Word
 * Description:
 * Given a string s consists of upper/lower-case alphabets and empty space 
 * characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5.
 */
class LengthOfLastWord {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    size_t GetLengthOfLastWordOne(string s);
    /* Time complexity: O(n) Space complexity: O(1) */
    size_t GetLengthOfLastWordTwo(string s);
protected:
    
private:


};


















#endif /* basic_string_operation_h */
