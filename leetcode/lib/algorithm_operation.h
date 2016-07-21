//
//  algorithm.h
//  leetcode
//
//  Created by NoteFAN on 6/14/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef ALGORITHM_OPERATION_H
#define ALGORITHM_OPERATION_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/************************************分治算法***********************************/

/*
 * 1. 分治法的设计思想是：将一个难以直接解决的大问题，分割成一些规模较小的相同问题，以便各个击破，
 * 分而治之。
 * 2. 分治策略是：对于一个规模为n的问题，若该问题可以容易地解决（比如说规模n较小）则直接解决，
 * 否则将其分解为k个规模较小的子问题，这些子问题互相独立且与原问题形式相同，递归地解这些子问题，
 * 然后将各子问题的解合并得到原问题的解。这种算法设计策略叫做分治法。
 */

/*
 * Title: Pow(x, n)
 * Implement pow(x, n)
 * Solution: 二分法, x^n = x^{n/2} * x^{n/2} * x^{n%2}
 */
class Pow{
public:
    /* Time complexity: O(logn) Space complexity: O(1) */
    double GetPow(double x, int n);
protected:
    
private:
    double Power(double x, int n);
};

/*
 * Title: Sqrt(x)
 * Implement int sqrt(int x). Compute and return the square root of x.
 */
class Sqrt {
public:
    /* 
     * 二分查找
     * Time complexity: O(logn) Space complexity: O(1)
     * @param x: An Integer
     * @return: The sqrt of x
     */
    int GetSqrt(int x);
protected:

private:
    
};

/************************************贪心算法***********************************/

/*
 * 1. 所谓贪心算法是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上
 * 加以考虑，他所做出的仅是在某种意义上的局部最优解。
 * 2. 贪心算法没有固定的算法框架，算法设计的关键是贪心策略的选择。必须注意的是，贪心算法不是对所
 * 有问题都能得到整体最优解，选择的贪心策略必须具备无后效性，即某个状态以后的过程不会影响以前的状
 * 态，只与当前状态有关。所以对所采用的贪心策略一定要仔细分析其是否满足无后效性。
 * 3. 贪心算法的证明围绕着：整个问题的最优解一定由在贪心策略中存在的子问题的最优解得来的。
 */

/*
 * Title: Jump Game
 * Given an array of non-negative integers, you are initially positioned at the 
 * first index of the array. Each element in the array represents your maximum 
 * jump length at that position. Determine if you are able to reach the last index. 
 * For example: A = [2,3,1,1,4], return true. A = [3,2,1,0,4], return false.
 * Analysis:
 * 由于每层最多可以跳A[i]步,也可以跳 0 或 1 步,因此如果能到达最高层,则说明每一层都可以到达。
 * 有了这个条件,说明可以用贪心法。
 * 思路一:正向,从 0 出发,一层一层往上跳,看最后能不能超过最高层,能超过,说明能到达, 否则不能到达。
 * 思路二:逆向,从最高层下楼梯,一层一层下降,看最后能不能下降到第 0 层。
 * 思路三:如果不敢用贪心,可以用动规,设状态为f[i],表示从第 0 层出发,走到A[i]时剩余的最大步数,
 * 则状态转移方程为: f[i] = max(f[i - 1], A[i - 1]), i > 0.
 */
class JumpGame {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    bool CheckJumpOne(vector<int> A);
    /* Time complexity: O(n) Space complexity: O(1) */
    bool CheckJumpTwo(vector<int> A);
    /* Time complexity: O(n) Space complexity: O(1) */
    bool CheckJumpThree(vector<int> A);
protected:
    
private:

};

/*
 * Title: Jump Game II
 * Given an array of non-negative integers, you are initially positioned at the 
 * first index of the array. Each element in the array represents your maximum 
 * jump length at that position. Your goal is to reach the last index in the 
 * minimum number of jumps. 
 * For example:
 * Given array A = [2,3,1,1,4] The minimum number of jumps to reach the last 
 * index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
class JumpGameII {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int CheckJump(vector<int> A);
protected:
    
private:
    
};

/*
 * Best Time to Buy and Sell Stock I
 * Description: 
 * Say you have an array for which the ith element is the price of a given stock 
 * on day i. If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), design an algorithm to find
 * the maximum profit.
 * Analysis: 将原始价格序列转变成差分序列
 */
class BestTimeToBuyAndSellStockI {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    double GetMaximumProfit(vector<double> prices);
protected:
    
private:

};

/*
 * Best Time to Buy and Sell Stock II
 * Description:
 * Say you have an array for which the i-th element is the price of a given stock 
 * on day i. Design an algorithm to find the maximum profit. You may complete as 
 * many transactions as you like (ie, buy one and sell one share of the stock 
 * multiple times). However, you may not engage in multiple transactions at the 
 * same time (ie, you must sell the stock before you buy again).
 * Analysis: 贪心法,低进高出,把所有正的价格差价相加起来(将原始价格序列转变成差分序列)
 */
class BestTimeToBuyAndSellStockII {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    double GetMaximumProfit(vector<double> prices);
protected:
    
private:
    
};

/*
 * Title: Longest Substring Without Repeating Characters
 * Description:
 * Given a string, find the length of the longest substring without repeating 
 * characters. For example, the longest substring without repeating letters for
 * "abcabcab" is "abc", which the length is 3. For "bbbb" the longest substring 
 * is "b", with the length of 1.
 */
class LongestSubstringWithoutRepeatingCharacters {
public:
    /* Time compexity: O(n) Space complexity: O(1) */
    int GetLongestSubstring(string s);
protected:

private:
    
};

/*
 * Title: Container With Most Water
 * Description:
 * Given n non-negative integers a1, a2, ...,an, where each represents a point 
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
 * of linei is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
 * forms a container, such that the container contains the most water.
 * Analysis:
 * 1.首先假设我们找到能取最大容积的纵线为i , j (假定i<j)，那么得到的最大容积 
 * C = min( ai , aj ) * ( j- i) ；
 * 2.下面我们看这么一条性质：
 * ①: 在 j 的右端没有一条线会比它高；
 * ②:同理，在i的左边也不会有比它高的线；
 * 3.所以我们从两头向中间靠拢，同时更新候选值；在收缩区间的时候优先从x, y中较小的边开始收缩.
 * 直观的解释是：容积即面积，它受长和高的影响，当长度减小时候，高必须增长才有可能提升面积，所以
 * 我们从长度最长时开始递减，然后寻找更高的线来更新候补；
 */
class ContainerWithMostWater {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int GetMostWater(vector<int> height);
protected:

private:

};

/************************************动态规划***********************************/
/*
 * Title: Triangle
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below. For example, given the following 
 * triangle:
       [ [2], 
        [3,4], 
       [6,5,7], 
      [4,1,8,3] ] 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
 * Note: Bonus point if you are able to do this using only O(n) extra space, 
 * where n is the total number of rows in the triangle.
 */
class Triangle {
public:
    /* 
     * Time complexity: O(n^2) Space complexity: O(1)
     * Solution: Dynamic Programming
     * 设f(i, j)表示从i, j出发的最小路径之和，即可知：
     * f(i, j) = min(f(i + 1, j), f(i + 1, j + 1)) + (i, j)
     */
    int GetMinimumPathSum(vector<vector<int>> &numbers);
protected:
    
private:

};

/*
 * Title: Maximum Subarray
 * Find the contiguous subarray within an array (containing at least one number) 
 * which has the largest sum. 
 * For example, given the array [-2, 1, -3, 4, -1, 2, 1, -5, 4], the contiguous 
 * subarray [4, -1, 2, 1] has the largest sum = 6.
 * Analysis:
 * 最大连续子序列和,非常经典的题。当从头至尾遍历序列时，对于一个元素只有两种选择，加入之前的Subarray，
 * 或者重新开始作为新的Subway的起点: 1.如果之前的Subarray大于0，则可以加入之前的Subarray,
 * 如果小于等于0，则认为其对后续结果无用，此时可以将此元素作为新的Subway的起点。
 * 设f(i)表示以numbers[i]结尾的最大连续子序列和,则状态转移方程如下:
 *      f(i) = max(f[i - 1] + numbers[i], numbers[i]), 0 < j < n, f(0) = numbers[0];
 * 则最大连续子序列为max{f(j)}, 0 <= j < n.
 */
class Subarray {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int MaximumSubarray(vector<int> numbers);
protected:

private:

};

/* 
 * Title: Palindrome Partitioning II
 * Description:
 * Given a string s, partition s such that every substring of the partition is a 
 * palindrome. Return the minimum cuts needed for a palindrome partitioning of s.
 * For example, given s = "aab", Return 1 since the palindrome partitioning 
 * ["aa", "b"] could be produced using 1 cut.
 */
class PalindromePartitioningII {
public:
    /* 
     * Analysis:(DP)
     * 设f(i)表示[i, n - 1]之间的最小分割数，则获得状态转换方程:
     * f(i) = min(f(i), f(j + 1) + 1), i < j < n 且[i, j]之间为回文字符串.
     * 同时设p(i, j)表示[i, j]之间是否为回文字符串,false表示不是,true表示是.
     * Time complexity: O(n^2) Time complexity: O(n^2)
     */
    int MinimumCut(string s);
protected:

private:

};

/*
 * Title: Maximal Rectangle
 * Description:
 * Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle 
 * containing all ones and return its area.
 */
class MaximalRectangle {
public:
    /* 
     * Analysis:
     * 1. 转换矩阵: dp[i][j]就是当前的第j列 - 从上到第i行连续1的个数。
     * 2. 题目求解即转换成: 求柱状图的最大矩形面积
     * Time complexity: O(n^2) Space complexity: O(n)
     */
    int GetMaximalRectangleOne(vector<vector<int> > &matrix);
    /* 原理与上同,实现更简洁 */
    int GetMaximalRectangleTwo(vector<vector<int> > &matrix);
protected:
    
private:

};

/* 
 * Title: Best Time to Buy and Sell Stock III
 * Description:
 * Say you have an array for which the i-th element is the price of a given stock 
 * on day i. Design an algorithm to find the maximum profit. You may complete at 
 * most two transactions. Note: You may not engage in multiple transactions at 
 * the same time (ie, you must sell the stock before you buy again).
 */
class BestTimeBuyAndSellStockIII {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    double MaximumProfit(vector<double> prices);
protected:
    
private:

};

/*
 * Title: Interleaving String
 * Description:
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * For example, Given: s1 = "aabcc", s2 = "dbbca", 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */
class InterleavingString {
public:
    /* 
     * Time complexity: O(n^2) Space complexity: O(n^2) 
     * Analysis:
     * 设f[i][j]表示s1[0, i)和s2[0, j)匹配s3[0, i+j)的结果,如果s1的最后一个字符和s3的
     * 最后一个字符相同,则f[i][j] = f[i-1][j],如果s2的最后一个字符和s3的最后一个字符相同,
     * 则f[i][j] = f[i][j-1]. 则状态转移方程:
     * f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) || 
                 (s2[i - 1] == s3[i + j - 1] && f[i][j - 1])
     */
    bool CheckInterleavingString(string s1, string s2, string s3);
    
    /* 
     * DP + 滚动数组
     * Time complexity: O(n^2) Space complexity: O(n)
     */
    bool IsInterleavingString(string s1, string s2, string s3);
protected:

private:
    
};

/*
 * Title: Scramble String
 * Given a string s1, we may represent it as a binary tree by partitioning it to 
 * two non-empty substrings recursively. 
 * Below is one possible representation of s1 = "great":
         great
        /    \
       gr    eat
      / \    /  \
     g   r  e   at
    / \
   a   t
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 * For example, if we choose the node "gr" and swap its two children, it produces 
 * a scrambled string "rgeat".
        rgeat
       /    \
      rg    eat
     / \    /  \
    r   g  e   at
   / \
  a   t
 * We say that "rgeat" is a scrambled string of "great".
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it 
 * produces a scrambled string "rgtae".
        rgtae
       /    \
      rg    tae
     / \    /  \
    r   g  ta  e
   / \
  t   a
 * We say that "rgtae" is a scrambled string of "great".
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled 
 * string of s1.
 */
class ScrambleString {
public:
    /*
     * 递归 + 剪枝
     * Time complexity: O(n^n)? Space complexity: O(1)
     */
    bool IsScrambleStringOne(string s1, string s2);
    
    /*
     * Dynamic programming
     * Time complexity: O(n^3) Space complexity: O(n^3)
     * Analysis:
     * 设f[n][i][j]为长度为n,起点分别为s1[i]和s2[j]的字符串互为scramble,即得:
     * f[n][i][j] = f[k][i][j] && f[n - k][i + k][j + k] ||
     *              f[k][i][j + n - k] && f[n - k][i + k][j]
     */
    bool IsScrambleStringTwo(string s1, string s2);
protected:
    
private:

};

/*
 * Title: Minimum Path Sum
 * Given a m × n grid filled with non-negative numbers, find a path from top left 
 * to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time
 */
class MinimumPathSum {
public:
    /*
     * 备忘律法
     * Time complexity: O(m * n) Space complexity: O(m * n)
     */
    int GetMinimumPathSumOne(vector<vector<int>> matrix);
    /*
     * DP
     * Time complexity: O(m * n) Space complexity: O(m * n)
     * Analysis:
     * 设f[i][j]为top left到(i, j)的最小和,即得:
     * f[i][j] = min(f[i - 1][j], f[i][j - 1]) + matrix[i][j]
     */
    int GetMinimumPathSumTwo(vector<vector<int>> matrix);
    /*
     * DP + 滚动数组
     * Time complexity: O(m * n) Space complexity: O(n)
     */
    int GetMinimumPathSumThree(vector<vector<int>> matrix);
protected:
    
private:
    int dfs(vector<vector<int>> matrix, vector<vector<int>> &f, int m, int n);
    int GetOrUpdate(vector<vector<int>> matrix, vector<vector<int>> &f, int m, int n);
};

/*
 * Title: Edit Distance
 * Given two words word1 and word2, find the minimum number of steps required to
 * convert word1 to word2. (each operation is counted as 1 step.)
 * You have the following 3 operations permitted on a word:
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */
class EditDistance {
public:
    /*
     * DP
     * Time complexity: O(m * n) Space complexity: O(m * n)
     * Analysis:
     * 设f[i][j]表示word1[0, i]与word2[0, j]之间的最小步数, 设word1[0, i]为std2c, 
     * word2[0, j]为std2d, 根据三种操作可知:
     * 1. 若c == d, f[i][j] = f[i - 1]f[j - 1]
     * 2. 若c != d,
     *  a) 插入d, f[i][j] = f[i][j - 1] + 1;
     *  b) 删除c, f[i][j] = f[i - 1][j] + 1;
     *  c) 用d替代c, f[i][j] = f[i - 1][j - 1] + 1;
     *
     * 备注(优化): DP + 滚动数组 - Time: O(m * n), Space: O(n)
     */
    int CountSteps(string word1, string word2);
protected:
    
private:

};

/*
 * Title: Decode Ways
 * A message containing letters from A-Z is being encoded to numbers using the 
 * following mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways 
 * to decode it. For example, Given encoded message "12", it could be decoded as 
 * "AB" (1 2) or "L" (12). The number of ways decoding "12" is 2.
 */
class DecodeWays {
public:
    /* 
     * Time complexity: O(n) Space complexity: O(1) 
     * Analysis:
     * Count[i] means the number of ways for s[0, i)
     * Transformation function as:
     * Count[i] = Count[i-1]  if S[i-1] is a valid char
     *       or = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char.
     */
    int CountDecodeWays(string s);
protected:
    
private:
    bool check(char a) {
        return a != '0' ? true : false;
    }
    bool check(char a, char b) {
        return (a == '1' || (a == '2' && b <= '6')) ? true : false;
    }
};

/*
 * Title: Distinct Subsequences
 * Description:
 * Given a string S and a string T, count the number of distinct subsequences of 
 * T in S. A subsequence of a string is a new string which is formed from the 
 * original string by deleting some (can be none) of the characters without 
 * disturbing the relative positions of the remaining characters. 
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * Here is an example: S = "rabbbit", T = "rabbit", Return 3.
 */
class DistinctSubsequences {
public:
    /*
     * Time complexity: O(n * m) Space complexity: (n * m)
     * Analysis:
     * 设f[i][j]表示T[0 : j]在S[0 : i]中出现的次数, 即得状态方程:
     * f[i][j] = f[i - 1][j - 1], S[i] == T[j]
     * f[i][j] = f[i - 1][j], S[i] != T[j]
     */
    int NumberDistinctSubsequences(string S, string T);
    
    /*
     * DP + 滚动数组
     * Time complexity: O(n * m) Space complexity: (n)
     */
    int NumberDistinctSubsequencesOne(string S, string T);
protected:

private:

};

/*
 * Title: Word Break
 * Given a string s and a dictionary of words dict, determine if s can be 
 * segmented into a space-separated sequence of one or more dictionary words.
 * For example, given s = "leetcode", dict = ["leet", "code"].
 * Return true because "leetcode" can be segmented as "leet code".
 */
class WordBreak {
public:
    /* 
     * DP
     * Time complexity: (n^2) Space complexity: O(n)
     * Analysis:
     * 设f[i]表示s[0 : i)可以被分割, 即得:
     * 状态方程: f[i] = f[j] && (s[j, i) in dict), 0 =< j < i
     */
    bool CheckWordBreak(string s, unordered_set<string> dict);
protected:
    
private:

};

/*
 * Title: Word Break II
 * Given a string s and a dictionary of words dict, add spaces in s to construct 
 * a sentence where each word is a valid dictionary word. Return all such possible 
 * sentences. 
 * For example, given s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"].
 * A solution is ["cats and dog", "cat sand dog"].
 */
class WordBreakII {
public:
    /*
     * DP
     * Time complexity: (n^2) Space complexity: O(n)
     * Analysis:
     * 设f[i]表示s[0 : i)可以被分割, 即得:
     * 状态方程: f[i] = f[j] && (s[j, i) in dict), 0 =< j < i
     */
    vector<string> CheckWordBreak(string s, unordered_set<string> dict);
protected:
    
private:
    void dfs(vector<string> &results, vector<string> &path, string s,
             int start, vector<vector<bool>> status);
};

/************************************回溯法*************************************/

/************************************分支界限法**********************************/

/************************************图论***************************************/

/*
 * 1. 图可以用两个数组表示，一个数组存储顶点信息，一个二维数据存储边信息(邻接矩阵)
 * 2. 图也可以用邻接表表示
 * 3. 图的操作: 深度遍历，广度遍历，最短路径，最小生成树
 */

/* 
 * Title: Clone Graph
 * Clone an undirected graph. Each node in the graph contains a label and a list 
 * of its neighbors. OJ's undirected graph serialization: Nodes are labeled uniquely. 
 * We use # as a separator for each node, and , as a separator for node label and 
 * each neighbor of the node. 
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}. The graph has a 
 * total of three nodes, and therefore contains three parts as separated by #. 
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2. Second node 
 * is labeled as 1. Connect node 1 to node 2. Third node is labeled as 2. Connect 
 * node 2 to node 2 (itself), thus forming a self-cycle. Visually, the graph looks 
 * like the following: 
        1 
       / \ 
      /   \ 
     0 --- 2 
          / \ 
          \_/
 */

/* undirected graph node */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class CloneGraph {
public:
    /*
     * DFS
     * Time complexity: O(n) Space complexity: O(n)
     */
    UndirectedGraphNode *CloneGraphOne(UndirectedGraphNode *node);
    /*
     * BFS
     * Time complexity: O(n) Space complexity: O(n)
     */
    UndirectedGraphNode *CloneGraphTwo(UndirectedGraphNode *node);
protected:

private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node,
                             unordered_map<UndirectedGraphNode *,
                             UndirectedGraphNode *> &copied);
};

/**********************************细节实现题************************************/
/*
 * Title: Reverse Integer
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * Have you thought about this? Here are some good questions to ask before coding. 
 * Bonus points for you if you have already thought through this!
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * Did you notice that the reversed integer might overflow? Assume the input is 
 * a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle 
 * such cases? Throw an exception? Good, but what if throwing an exception is not 
 * an option? You would then have to re-design the function (ie, add an extra parameter).
 */
class ReverseInteger {
public:
    /* Time complexity: O(lgn) Space complexity: O(1) */
    int ReverseIntegerDigit(int x);
protected:

private:
    
};

/*
 * Title: Palindrome Number
 * Description:
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * If you are thinking of converting the integer to string, note the restriction 
 * of using extra space. You could also try reversing an integer. However, if you 
 * have solved the problem "Reverse Integer", you know that the reversed integer 
 * might overflow. How would you handle such case? There is a more generic way of
 * solving this problem.
 */
class PalindromeNumber {
public:
    bool CheckPalindromeNumber(int num);
protected:

private:
    
};

/*
 * Title: Insert Interval
 * Description:
 * Given a set of non-overlapping intervals, insert a new interval into the 
 * intervals (merge if necessary). You may assume that the intervals were initially 
 * sorted according to their start times.
 * Example 1: Given intervals [1, 3], [6, 9], insert and merge [2, 5] in [1, 5], [6, 9].
 * Example 2: Given [1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge
 * [4, 9] in as [1, 2], [3, 10], [12, 16]. This is because the new interval [4, 9]
 * overlaps with [3, 5], [6, 7], [8, 10].
 *
 * Title: Merge Intervals
 * Given a collection of intervals, merge all overlapping intervals. For example, 
 * Given [1, 3], [2, 6], [8, 10], [15, 18], return [1, 6], [8, 10], [15, 18].
 */

struct Interval {
    int left;
    int right;
    Interval(): left(0), right(0){}
    Interval(int a, int b): left(a), right(b){}
};

class InsertInterval {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    vector<Interval> Insert(vector<Interval> &intervals, Interval interval);
    /* Time complexity: O(n^2) Space complexity: O(1) */
    vector<Interval> MergeIntervals(vector<Interval> &intervals);
protected:

private:

};

/*
 * Title: Minimum Window Substring
 * Given a string S and a string T, find the minimum window in S which will contain 
 * all the characters in T in complexity O(n). For example, S = "ADOBECODEBANC" 
 * T = "ABC" Minimum window is "BANC". Note: If there is no such window in S that 
 * covers all characters in T, return the emtpy string "". If there are multiple 
 * such windows, you are guaranteed that there will always be only one unique 
 * minimum window in S.
 * Analysis:
 * 双指针,动态维护一个区间。尾指针不断往后扫,当扫到有一个窗口包含了所有 T 的字符后, 然后再收缩
 * 头指针,直到不能再收缩为止。最后记录所有可能的情况中窗口最小的
 */
class MinimumWindowSubstring {
public:
    /* Time complexity: O(n) Space complecity: O(1) */
    string MinimumWindow(string S, string T);
protected:
    
private:

};


/*
 * Title: Multiply Strings
 * Description:
 * Given two numbers represented as strings, return multiplication of the numbers 
 * as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 */
class MultiplyStrings {
public:
    /* Time complxity: O(m * n) Space complexity: O(m + n)*/
    string GetMultiplyString(string s1, string s2);
protected:

private:

};

/* 
 * Title: Substring with Concatenation of All Words
 * Description:
 * You are given a string, S, and a list of words, L, that are all of the same 
 * length. Find all starting indices of substring(s) in S that is a concatenation 
 * of each word in L exactly once and without any intervening characters.
 * For example, given: S: "barfoothefoobarman", L: ["foo", "bar"]
 * You should return the indices: [0,9]. (order does not matter).
 */
class Substring {
public:
    /* Time complexity: O(n * m) Space complexity: O(n) */
    vector<int> FindStartingIndices(string S, set<string> L);
protected:
    
private:
    
};

/*
 * Title: Pascal’s Triangle
 * Description:
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5, Return
  [
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
  ]
 
 * Title: Given an index k, return the kth row of the Pascal’s triangle.
 * For example, given k = 3, Return [1, 3, 3, 1].
 * Note: Could you optimize your algorithm to use only O(k) extra space?
 */
class PascalTriangle {
public:
    /* Time complexity: O(n^2) Space complexity: O(n^2) */
    vector<vector<int> > GeneratePascalTriangle(int num_rows);
    
    /* Time complexity: O(n^2) Space complexity: O(n) */
    vector<int> GenerateRow(int num_rows);
protected:
    
private:
    
};

/*
 * Title: Spiral Matrix
 * Given a matrix of m x n elements (m rows, n columns), return all elements of 
 * the matrix in spiral order.
 * For example, Given the following matrix:
 [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
 ]
 * You should return [1,2,3,6,9,8,7,4,5].
 *
 * Title II: Spiral Matrix II
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 
 * in spiral order.
 * For example, Given n = 3, You should return the following matrix:
 [
    [ 1, 2, 3 ],
    [ 8, 9, 4 ],
    [ 7, 6, 5 ]
 ]
 */
class SpiralMatrix {
public:
    /* Time complexity: O(n^2) Space complexity: O(n^2) */
    vector<int> SpiralOrder(vector<vector<int>> matrix);
    
    /* Time complexity: O(n^2) Space complexity: O(n^2) */
    vector<vector<int>> GenerateMatrix(int n);
protected:

private:
    
};

/*
 * Title: ZigZag Conversion
 * Description:
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
 * of rows like this: (you may want to display this pattern in a fixed font for 
 * better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR". Write the code that will take a 
 * string and make this conversion given a number of rows:
    string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
class ZigzagConversion {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    string Conversion(string s, int n);
protected:
    
private:

};

/*
 * Title: Divide Two Integers
 * Divide two integers without using multiplication, division and mod operator.
 */
class Divide {
public:
    /* Time complexity: O(logn) Space complexity: O(1) */
    long long DivideTwoIntegers(int dividend, int divisor);
protected:
    
private:


};


/*
 * Title: Text Justification
 * Description:
 * Given an array of words and a length L, format the text such that each line 
 * has exactly L characters and is fully (left and right) justified. You should 
 * pack your words in a greedy approach; that is, pack as many words as you can 
 * in each line. Pad extra spaces ' ' when necessary so that each line has exactly
 * L characters. Extra spaces between words should be distributed as evenly as 
 * possible. If the number of spaces on a line do not divide evenly between words, 
 * the empty slots on the left will be assigned more spaces than the slots on the 
 * right. For the last line of text, it should be left justified and no extra 
 * space is inserted between words.
 * For example, 
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16. Return the formatted lines as:
 [
    "This    is    an",
    "example  of text",
    "justification.  "
 ]
 * Note: Each word is guaranteed not to exceed L in length.
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you 
 * do in this case? In this case, that line should be left-justified.
 */
class TextJustification {
public:
    /* 
     * Time complexity: O(n) Space comlexity: O(n)
     * Analysis:
     * 题意：把一个集合的单词按照每行L个字符放，每行要两端对齐，如果空格不能均匀分布在所有间隔中，
     * 那么左边的空格要多于右边的空格，最后一行靠左对齐。
     * 思路：没有什么特别算法，就是模拟，主要分情况判断。首先分两大类，末行和非末行；然后末行所有
     * 单词间放一个空格，最后面补充空格；非末行再分两类，如果只有一个单词就靠左放，右边补空格；
     * 如果有多个单词，即计算有几个间隔num和几个多余的空格extra(除每两个单词间一个空格外多余的),
     * 每个间隔再多方extra/num个，前extra%num个间隔再多放个空格。
     */
    vector<string> function(vector<string> text, int length);
protected:

private:
    string connect(vector<string> text, int begin, int end, int len, int length,
                   bool last_line);
};

/*
 * Title: Max Points on a Line
 * Description:
 * Given n points on a 2D plane, find the maximum number of points that lie on 
 * the same straight line.
 */
struct Point {
    int x;
    int y;
    Point() {x = 0; y = 0;}
    Point(int a, int b) : x(a), y(b) {}
};

class MaxPoints {
public:
    /* 
     * Time complexity: O(n^3) Space complexity: O(1)
     * 以边为中心，暴力枚举法
     */
    int GetMaxPoints(vector<Point> &points);
    
    /*
     * Time complexity: O(n^2) Space complexity: O(1)
     * 以点为中心，暴力枚举法
     */
    int GetMaxPointsTwo(vector<Point> &points);
protected:
    
private:

};







#endif /* algorithm_operation_h */
