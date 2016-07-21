//
//  search_operation.h
//  leetcode
//
//  Created by NoteFAN on 6/1/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef SEARCH_OPERATION_H
#define SEARCH_OPERATION_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * Title: Search for a Range
 * Description:
 * Given a sorted array of integers, find the starting and ending position of a 
 * given target value. Your algorithm's runtime complexity must be in the order 
 * of O(log n). If the target is not found in the array, return [-1, -1].
 * For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
 */
class SearchForRange {
public:
    /* 二分法(STL): Time complexity: O(logn) Space complexity: O(1) */
    vector<int> SearchRangeOne(vector<int> &num, int target);
    /* 二分法: Time complexity: O(logn) Space complexity: O(1) */
    vector<int> SearchRangeTwo(vector<int> &num, int target);
protected:
    
private:
    /* 
     * Realize the functions: lower_bound and upper_bound
     * Time complexity: O(logn) Space complexity: O(1) 
     */
    template<typename ForwardIterator, typename T>
    ForwardIterator get_lower_bound(ForwardIterator first,
                                    ForwardIterator end, T value) {
        while (first != end) {
            ForwardIterator middle = next(first, distance(first, end) / 2);
            if (*middle < value) {
                first = ++middle;
            } else {
                end = middle;
            }
        }
        return first;
    }
    
    template<typename ForwardIterator, typename T>
    ForwardIterator get_upper_bound(ForwardIterator first,
                                    ForwardIterator end, T value) {
        while (first != end) {
            ForwardIterator middle = next(first, distance(first, end) / 2);
            if (*middle > value) {
                end = middle;
            } else {
                first = ++middle;
            }
        }
        return first;
    }
};

/*
 * Title: Search Insert Position
 * Description:
 * Given a sorted array and a target value, return the index if the target is 
 * found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array. Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */
class SearchInsertPosition {
public:
    /* Time complexity: O(logn) Space complexity: O(1) */
    int InsertPosition(vector<int> &num, int target) {
        return int(lower_bound(num.begin(), num.end(), target) - num.begin());
    }
protected:
    
private:
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first,
                                ForwardIterator last, T value) {
        while (first != last) {
            ForwardIterator middle = next(first, distance(first, last) / 2);
            if (*middle < value) {
                first = ++middle;
            } else {
                last = middle;
            }
        }
        return first;
    }
};

/*
 * Title: Search a 2D Matrix
 * Description:
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * 1. Integers in each row are sorted from left to right.
 * 2. The first integer of each row is greater than the last integer of the previous row.
 * For example, Consider the following matrix:
 * [
 *  [1,   3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */
class SearchMatrix {
public:
    /* Time complexity: O(log(m*n)) Space complexity: O(1) */
    bool Search2DMatrix(vector<vector<int>> &num, int target);
protected:
    
private:

};

/*
 * Title: Subsets
 * Given a set of distinct integers, S, return all possible subsets.
 * Note:
 * 1. Elements in a subset must be in non-descending order.
 * 2. The solution set must not contain duplicate subsets.
 * For example, if S = [1,2,3], a solution is:
 * [
 *  [3],
 *  [1],
 *  [2],
 *  [1,2,3],
 *  [1,3],
 *  [2,3],
 *  [1,2],
 *  []
 * ]
 */
class Subsets {
public:
    /* 
     * Recursively
     * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n) 
     */
    vector<vector<int>> FindSubsets(vector<int> &S);
    /* 
     * Recursively 
     * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     * 由于S[0: n-1]组成的每一个subset，可以看成是对是否包含S[i]的取舍。S[i]只有两种状态，
     * 包含在特定subset内，或不包含。所以subset的数量总共有2^n个。所以可以用0~2^n-1的二进
     * 制来表示一个subset。二进制中每个0/1表示该位置的S[i]是否包括在当前subset中。
     * Note: 集合的元素不超过 unsigned long long 位数
     */
    vector<vector<int>> FindSubsetsOne(vector<int> &S);
    
    /*
     * Iteratively
     * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     * -> 添加数字构建subset
     * 起始subset集为：[]
     * 添加S0后为：[], [S0]
     * 添加S1后为：[], [S0], [S1], [S0, S1]
     * 添加S2后为：[], [S0], [S1], [S0, S1], [S2], [S0, S2], [S1, S2], [S0, S1, S2]
     * 显然规律为添加Si后，新增的subset为克隆现有的所有subset，并在它们后面都加上Si。
     */
    vector<vector<int>> FindSubsetsTwo(vector<int> &S);
    
    /*
     * Iteratively
     * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     * 由于S[0: n-1]组成的每一个subset，可以看成是对是否包含S[i]的取舍。S[i]只有两种状态，
     * 包含在特定subset内，或不包含。所以subset的数量总共有2^n个。所以可以用0~2^n-1的二进
     * 制来表示一个subset。二进制中每个0/1表示该位置的S[i]是否包括在当前subset中。
     * Note: 集合的元素不超过 unsigned long long 位数
     */
    vector<vector<int>> FindSubsetsThree(vector<int> &S);
protected:
    
private:
    void FindSubsets(vector<int> &S, vector<int> &path, size_t step,
                     vector<vector<int>> &results);
    vector<int> FindSubsetsOne(vector<int> &S, unsigned long long num);
};

/*
 * Title: Subsets II
 * Given a collection of integers that might contain duplicates, S, return all 
 * possible subsets.
 * Note:
 * 1. Elements in a subset must be in non-descending order.
 * 2. The solution set must not contain duplicate subsets.
 * For example, If S = [1,2,2], a solution is:
 * [
 *  [2],
 *  [1],
 *  [1,2,2],
 *  [2,2],
 *  [1,2],
 *  []
 * ]
 */
class SubsetsII {
public:
    /*
     * Recursively
     * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     * Note:
     * 1. 一定要先排序;
     * 2. 调用下一层递归时, 起始index一定是i+1, 而不能错写成start+1
     */
    vector<vector<int>> FindSubsets(vector<int> &S);
    /*
     * Recursively
     * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     */
    vector<vector<int>> FindSubsetsOne(vector<int> &S);
    
    /*
     * Iteratively
     * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     */
    vector<vector<int>> FindSubsetsTwo(vector<int> &S);
    /*
     * Iteratively
     * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
     */
    vector<vector<int>> FindSubsetsThree(vector<int> &S);
protected:
    
private:
    void FindSubsetsWithDuplicates(vector<int> &S, size_t start,
                                   vector<int> &path,
                                   vector<vector<int>> &subsets);
    vector<int> FindSubsetsOne(vector<int> &S, unsigned long long num);

};

/*
 * Title: Permutations
 * Given a collection of numbers, return all possible permutations.
 * For example, [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
class Permutations {
public:
    /* 
     * using function: "next_permutation"
     * Time complexity: O(n!) Space complexity: O(1)
     */
    vector<vector<int>> GetPermutations(vector<int> &num);
    
    /*
     * 深搜,增量构造法
     * Time complexity: O(n!) Space complexity: O(1)
     * Solution:
     * 与subset I的方法2很相近。以题中例子说明：
     * 当只有1时候：[1]
     * 当加入2以后：[2, 1], [1, 2]
     * 当加入3以后：[3, 2, 1], [2, 3, 1], [2, 1, 3], [3, 1, 2], [1, 3, 2], [1, 2, 3]
     * 前3个permutation分别对应将3插入[2, 1]的0, 1, 2的位置。同理后3个为插入[1, 2]的。
     * 因此可以用逐个插入数字来构造所有permutations。
     */
    vector<vector<int>> GetPermutationsOne(vector<int> &num);
    
    /*
     * Recursively 深搜,增量构造法
     * Time complexity: O(n!) Space complexity: O(1)
     */
    vector<vector<int>> GetPermutationsTwo(vector<int> &num);
protected:

private:
    void FindPermutations(vector<int> &num, vector<bool> used,
                          vector<int> &path, vector<vector<int>> &results);
};

/*
 * Title: Permutations II
 * Given a collection of numbers that might contain duplicates, return all 
 * possible unique permutations. For example, [1,1,2] have the following 
 * unique permutations:[1,1,2], [1,2,1], and [2,1,1].
 */
class PermutationsII {
public:
    /* 
     * Using function: "next_permutations"
     * Time complexity: O(n!) Space complexity: O(1)
     */
    vector<vector<int>> GetPermutations(vector<int> &num);
    /*
     * using set to remove duplicates
     * Time complexity: O(n!) Space complexity: O(1)
     */
    vector<vector<int>> GetPermutationsOne(vector<int> &num);
    /*
     * Recursively 深搜,增量构造法
     * Time complexity: O(n!) Space complexity: O(1)
     */
    vector<vector<int>> GetPermutationsTwo(vector<int> &num);
protected:
    
private:
    void FindPermutations(vector<int> &num, vector<bool> used,
                          vector<int> &path, vector<vector<int>> &results);
};

/*
 * Title: Combinations
 * Given two integers n and k, return all possible combinations of k numbers 
 * out of 1 ... n. For example, If n = 4 and k = 2, a solution is:
 * [
 *  [2,4],
 *  [3,4],
 *  [2,3],
 *  [1,2],
 *  [1,3],
 *  [1,4],
 * ]
 */
class Combinations {
public:
    /* 
     * Recursively
     * Time complexity: O(n!) Space complexity: O(n)
     */
    vector<vector<int>> GetCombinations(int n, int k);
    
    /*
     * Iteratively
     * Time complexity: O(n!) Space complexity: O(n)
     */
    vector<vector<int>> GetCombinationsOne(int n, int k);
protected:
    
private:
    void FindCombinations(int n, int start, int k, vector<int> &path,
                          vector<vector<int>> &results);
};

/*
 * Title: Letter Combinations of a Phone Number
 * Given a digit string, return all possible letter combinations that the number 
 * could represent. A mapping of digit to letters (just like on the telephone 
 * buttons) is given below.
 * Input: Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be 
 * in any order you want.
 */
class LetterCombinationsOfPhoneNumber {
public:
    /*
     * Recursively
     * Time complexity: O(3^n) Space complexity: O(n)
     */
    vector<string> LetterCombinationsOne(string digits);
    
    /*
     * Iteratively
     *  当已经获得digits[0:i-1]的所有letter combinations以后，加入digits[i]后
     * 新combinations为加入每个可能对应的字母加到之前的解集中。这里需要克隆多份之前的解集。
     * Time complexity: O(3^n) Space complexity: O(1)
     */
    vector<string> LetterCombinationsTwo(string digits);
protected:
    
private:
    void FindLetterCombinations(string &digits, int index, string dict[],
                                string &combinations,
                                vector<string> &letter_combinations);
};


/***********************************广度优先搜索*********************************/
/*
 * Word Ladder I
 * Given two words (start and end), and a dictionary, find the length of shortest 
 * transformation sequence from start to end, such that:
 * 1. Only one letter can be changed at a time
 * 2. Each intermediate word must exist in the dictionary
 * For example, Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * Note:
 * 1. Return 0 if there is no such transformation sequence.
 * 2. All words have the same length.
 * 3. All words contain only lowercase alphabetic characters.
 *
 *
 * Word Ladder II
 * Given two words (start and end), and a dictionary, find all shortest 
 * transformation sequence(s) from start to end, such that:
 * 1. Only one letter can be changed at a time
 * 2. Each intermediate word must exist in the dictionary
 * For example, Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 * [
 *  ["hit","hot","dot","dog","cog"],
 *  ["hit","hot","lot","log","cog"]
 * ]
 * Note:
 * 1. All words have the same length.
 * 2. All words contain only lowercase alphabetic characters.
 */
class WordLadder {
public:
    /*
     * BFS: Breadth-first search[solution]
     * BFS中有三个关键步骤需要实现:
     
     * 1. 如何找到与当前节点相邻的所有节点。
     * 这里可以有两个策略：
     * (1) 遍历整个字典，将其中每个单词与当前单词比较，判断是否只差一个字符。复杂度为：n*w，
     * n为字典中的单词数量，w为单词长度。
     * (2) 遍历当前单词的每个字符x，将其改变成a~z中除x外的任意一个，形成一个新的单词，在字典
     * 中判断是否存在。复杂度为：26*w，w为单词长度。这里可以和面试官讨论两种策略的取舍。对于
     * 通常的英语单词来说，长度大多小于100，而字典中的单词数则往往是成千上万，所以策略2相对较优。
     * [unordered_map or unordered_set: find complexity -> 
                                        Average case: constant.
                                        Worst case: linear in container size.]
     
     * 2. 如何标记一个节点已经被访问过，以避免重复访问。-> 可以将访问过的单词从字典中删除。
     
     * 3. 一旦BFS找到目标单词，如何backtracking找回路径？
     */
    
    /* Time complexity: O(n) Space complexity: O(n) */
    int WordLadderLength(string start, string end, unordered_set<string> &dict);
    
    /* Time complexity: O(n) Space complexity: O(n) */
    vector<vector<string>> WordLadderLengthII(string start, string end,
                                              unordered_set<string> &dict);
protected:
    
private:
    vector<string> FindNeighbors(string s, unordered_set<string> &dict);
    
    void BuildPath(unordered_map<string, vector<string>> &traces,
                   vector<vector<string>> &pathes, vector<string> &path,
                   string &end);
};

/*
 * Title: Surrounded Regions
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * For example,
    X X X X
    X O O X
    X X O X
    X O X X
 * After running your function, the board should be:
    X X X X
    X X X X
    X X X X
    X O X X
 */
class SurroundedRegions {
public:
    /* 
     * BFS, Time complexity: O(n) Space complexity: O(n)
     * Solution:
     * 连通区域必须至少一个元素是在四边，那么一开始直接从四边开始扫描就好了，所以无法connect到
     * 得元素都是应该被清除的。所以，算法如下：
     * 1. 从四条边上的O元素开始BFS，所有相连的O都赋个新值，比如‘Y’
     * 2. 扫描整个数组，所有现存的O元素全部置为X，所有Y元素置为O
     */
    void Regions(vector<vector<char>> &board);
    
protected:

private:
    void dfs(vector<vector<char>> &board, size_t row, size_t column);
};

/***********************************深度优先搜索*********************************/
/* 
 * Title: Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is 
 * a palindrome. Return all possible palindrome partitioning of s. For example, 
 * given s = "aab", Return [ ["aa","b"], ["a","a","b"] ]
 */
class PalindromePartitioning {
public:
    /* 
     * DFS
     * 在每一步都可以判断中间结果是否为合法结果,用回溯法。
     * 一个长度为 n 的字符串,有 n − 1 个地方可以砍断,每个地方可断可不断,因此复杂度为 O(2n−1) 
     * Time complexity: O(2^n) Space complexity: O(n)
     */
    vector<vector<string>> Partition(string s);
    /* 
     * Dynamic programming
     * Time complexity: O(n^2) Space complexity: O(n^2)
     */
    vector<vector<string>> PartitionDynamic(string s);
protected:
    
private:
    bool IsPalindrome(string s, int start, int end);
    void DFS(string s, vector<vector<string>> &palindromes,
             vector<string> &palindrome, int start, int end);
};

/* 
 * Titile: Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
 * the diagram below). The robot can only move either down or right at any point
 * in time. The robot is trying to reach the bottom-right corner of the grid 
 * (marked 'Finish' in the diagram below). How many possible unique paths are 
 * there? Above is a 3 x 7 grid. How many possible unique paths are there? 
 * Note: m and n will be at most 100.
 */
class UniquePaths {
public:
    /*
     * DFS: 小集合可以过,大集合会超时
     * Time complexity: O(n^4) Space complexity: O(n)
     */
    int UniquePathsOne(int m, int n);
    /*
     * DFS + 缓存
     * Time complexity: O(n^2) Space complexity: O(n^2)
     */
    int UniquePathsTwo(int m, int n);
    /*
     * DP(Dynamic Programming)
     * Time complexity: O(n * m) Space complexity: O(n)
     */
    int UniquePathsThree(int m, int n);
    /*
     * A mathematical formula
     * Solution：
     * 一个 m 行,n 列的矩阵,机器人从左上走到右下总共需要的步数是 m + n − 2,其中向下走的
     * 步数是 m − 1,因此问题变成了在 m + n − 2 个操作中,选择 m–1 个时间点向下走,选择方式
     * 有多少种。即 Cm−1 。 m+n−2
     * Time complexity: O(n * m) Space complexity: O(n)
     */
    int UniquePathsFour(int m, int n);
protected:
    
private:
    /* Two: DFS + cache */
    int dfs(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1 || n == 1) return 1;
        return dfs(m - 1, n) + dfs(m, n - 1);
    }
    
    int GetValue(int x, int y, vector<vector<int>> &cache) {
        if (cache[x][y] == 0) {
            return cache[x][y] = dfs(x, y);
        } else {
            return cache[x][y];
        }
    }
    
    /* A mathematical formula: C_n^k */
    int factor(int n, int k);

};

/*
 * Titile: Unique Paths II
 * Follow up for "Unique Paths": Now consider if some obstacles are added to the 
 * grids. How many unique paths would there be? An obstacle and empty space is 
 * marked as 1 and 0 respectively in the grid. For example, There is one obstacle 
 * in the middle of a 3x3 grid as illustrated below. 
 * [ [0,0,0], [0,1,0], [0,0,0] ] 
 * The total number of unique paths is 2. 
 * Note: m and n will be at most 100.
 */
class UniquePathsII {
public:
    /*
     * DP(Dynamic Programming)
     * Time complexity: O(n * m) Space complexity: O(n)
     */
    int UniquePaths(vector<vector<bool>> &obstacles_grids);
protected:

private:

};

/*
 * Title: N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
 * such that no two queens attack each other. Given an integer n, return all 
 * distinct solutions to the n-queens puzzle. Each solution contains a distinct 
 * board configuration of the n-queens' placement, where 'Q' and '.' both indicate 
 * a queen and an empty space respectively. 
 * For example, There exist two distinct solutions to the 4-queens puzzle: 
 * [ [".Q..", "...Q", "Q...", "..Q."],
 *   ["..Q.", "Q...", "...Q", ".Q.."] ]
 */
class NQueens {
public:
    /* 
     * DFS + 剪枝
     * Time complexity: O(n!) Space complexity: O(n)
     */
    vector<vector<string>> SolveNQueens(int n);
protected:
    
private:
    bool IsValid(vector<int> columns, int column);
    vector<string> DrawChessBoard(vector<int> columns);
    void dfs(vector<vector<string>> &results, vector<int> &columns, int column);
};

/*
 * Title: Restore IP Addresses
 * Given a string containing only digits, restore it by returning all possible 
 * valid IP address combinations.
 * For example:
 * Given "25525511135",
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * Note: 一个IP地址就是一个32位无符号整数
 */
class RestoreAddresses {
public:
    /* Time complexity: O(n^4) Space complexity: O(n) */
    vector<string> RestoreIPAddress(string s);
protected:
    
private:
    void dfs(vector<string> &results, vector<string> &result, string s, int start);
};

/*
 * Title: Combination Sum
 * Given a set of candidate numbers (C) and a target number (T), find all unique 
 * combinations in C where the candidate numbers sums to T. The same repeated 
 * number may be chosen from C unlimited number of times. 
 * Note: All numbers (including target) will be positive integers. Elements in a 
 * combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak). 
 * The solution set must not contain duplicate combinations. For example, given 
 * candidate set 2,3,6,7 and target 7, A solution set is: [7] [2, 2, 3]
 *
 * Title: Combination Sum II
 * Given a collection of candidate numbers (C) and a target number (T), find all 
 * unique combinations in C where the candidate numbers sums to T. Each number 
 * in C may only be used once in the combination. Note: All numbers (including 
 * target) will be positive integers. Elements in a combination (a1, a2, … , ak) 
 * must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak). The solution set must 
 * not contain duplicate combinations. 
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: [1, 7] [1, 2, 5] [2, 6] [1, 1, 6]
 */
class CombinationsSum {
public:
    /* Time complexity: O(n!) Space complexity: O(n) */
    vector<vector<int>> FindCombinations(vector<int> nums, int target);
    
    /* Time complexity: O(n!) Space complexity: O(n) */
    vector<vector<int>> FindCombinationsII(vector<int> nums, int target);
protected:

private:
    void dfs(vector<vector<int>> &results, vector<int> &result,
             vector<int> nums, int start, int target);
    void dfsII(vector<vector<int>> &results, vector<int> &result,
             vector<int> nums, int start, int target);
};


/*
 * Title: Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations 
 * of well-formed parentheses. For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 * Analysis:
 * 1. 当左括号个数小于n时，可以继续放新的左括号;
 * 2. 当右括号个数小于左括号时，可以继续放新的右括号;
 */
class GenerateParentheses {
public:
    /*  */
    vector<string> Parentheses(int n);
protected:

private:
    void dfs(int n, int left, int right, vector<string> &results, string result);
};

/*
 * Title: Sudoku Solver
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'. You may assume that there 
 * will be only one unique solution.
 */
class SudokuSolver {
public:
    /* Time complexity: O(9^4) Space complexity: O(1) */
    bool SolveSudoku(vector<vector<char>> &board);
protected:

private:
    bool IsValid(vector<vector<char>> &board, int x, int y);
};

/*
 * Title: Word Search
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where
 * "adjacent" cells are those horizontally or vertically neighboring. The same 
 * letter cell may not be used more than once.
 * For example, Given board =
 [
    ["ABCE"],
    ["SFCS"],
    ["ADEE"]
 ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */
class WordSearch {
public:
    /* Time complexity: O(n^2*m^2) Space complexity: O(n*m) */
    bool ExistWord(vector<vector<char> > board, string word);
protected:
    
private:
    bool dfs(vector<vector<char> > board, string word, int index, int x, int y,
             vector<vector<bool> > &visited);

};





















#endif /* search_operation_h */
