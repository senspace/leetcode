//
//  array.h
//  leetcode
//
//  Created by NoteFAN on 3/16/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <vector>
#include "math.h"

using namespace std;

/*
 * Number One: Remove Duplicates from Sorted Array
 * Description:
 * 	   Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this
 * in place with constant memory. For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 *
 * Advanced: Remove Duplicates from Sorted Array II
 * Description:
 *	   Follow up for "Remove Duplicates": What if duplicates are allowed
 * at most twice? For example, Given sorted array A = [1,1,1,2,2,3],
 * Your function should return length = 5, and A is now [1,1,2,2,3]
 */
class RemoveDuplicatesFromSortedArray {
public:
    // Time complexity: O(n) Space complexity: O(1)
    int RemoveDuplicates(int arr[], int length);
    // Time complexity: O(n) Space complexity: O(1)
    int RemoveDuplicatesBasedOnSTLOne(int arr[], int length);
    // Time complexity: O(n) Space complexity: O(1)
    int RemoveDuplicatesBasedOnSTLTwo(int arr[], int length) {
        return int(RemoveDuplicatesBasedOnSTLTwo(arr, arr + length, arr) - arr);
    }
    template<typename InIt, typename OutIt>
    OutIt RemoveDuplicatesBasedOnSTLTwo(InIt first, InIt last, OutIt output) {
        while(first != last) {
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        return output;
    }
    /* Anvanced: Time complexity: O(n) Space complexity: O(1) */
    int RemoveDuplicatesAdvanced(int arr[], int length);
    
protected:
    
private:
    
};

/*
 * Number Two: Search in Rotated Sorted Array
 * Description:
 *	   Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1. You may assume no duplicate exists in the array.
 *
 * Advanced: Search in Rotated Sorted Array II
 * Description:
 *	   Follow up for "Search in Rotated Sorted Array": What if duplicates are
 * allowed? Would this affect the run-time complexity? How and why?
 */
class SearchRotatedSortedArray {
public:
    /* Time complexity: O(log n) Space complexity: O(1) */
    int SearchArray(int arr[], int length, int target);
    /* Time complexity: O(n) Space complexity: O(1) */
    int SearchArrayAdvanced(int arr[], int length, int target);
protected:
    
private:
    
};

/*
 * Number Three: Median of Two Sorted Arrays
 * Description:
 *	   There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays.
 * Note: The overall run time complexity should be O(log(m + n)).
 */
class MedianOfTwoSortedArrays {
public:
    /* Time complexity: O(log(m + n)) Space complexity: O(log(m + n)) */
    double FindMedianSortedArrays(int A[], int m, int B[], int n);
protected:
    
private:
    static int FindKth(int A[], int m, int B[], int n, int k);
};

/*
 * Number Four: Longest Consecutive Sequence
 * Description:
 *	   Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence. For example, Given [100, 4, 200, 1, 3, 2].
 * The longest consecutive elements sequence is [1, 2, 3, 4].
 * Return its length: 4. Your algorithm should run in O(n) complexity.
 */
class LongestConsecutiveSequence {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    int FindLongestConsecutiveSequence(const vector<int> &num);
protected:
    
private:
    
};


/*
 * Number Five: Two Sum
 * Description:
 *	   Given an array of integers, find two numbers such that they add up 
 * to a specific target number. The function twoSum should return indices 
 * of the two numbers such that they add up to the target, where index1 must 
 * be less than index2.
 * For example, Input: numbers={2, 7, 11, 15},
 * target=9, Output: index1=1, index2=2
 */
class TwoSum {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    vector<int> FindIndexsForTwoSum(const vector<int> &sum, int target);
protected:
    
private:
    
};

/*
 * Number Six: Three Sum
 * Description:
 *      Given an array S of n integers, are there elements a,b,c in S such that
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * • Elements in a triplet (a, b, c) must be in non-descending order. 
 *   (ie, a ≤ b ≤ c) 
 * • The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4}.
 * A solution set is: (-1, 0, 1) and (-1, -1, 2)
 */
class ThreeSum {
public:
    /* Time complexity: O(n^2) Space complexity: O(1) */
    vector<vector<int>> FindIndexsForThreeSum(vector<int> &sum,
                                              const int target);
    /* 
     * Given an array S of n integers, find three integers in S such that 
     * the sum is closest to a given number, target. Return the sum of the 
     * three integers.
     * Time complexity: O(n^2) Space complexity: O(1) 
     */
    int FindSumClosest(vector<int> &sum, const int target);
protected:
    
private:
    
};

/*
 * Number Seven: Four Sum
 * Description:
 *      Given an array S of n integers, are there elements a, b, c, and d in S 
 * such that a + b + c + d = target? Find all unique quadruplets in the array 
 * which gives the sum of target.
 * Note:
 * • Elements in a quadruplet (a, b, c, d) must be in non-descending order. 
 *   (ie, a ≤ b ≤ c ≤ d)
 * • The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:(-1,  0, 0, 1)(-2, -1, 1, 2)(-2,  0, 0, 2)
 */
class FourSum {
public:
    /* Time complexity: O(n^3) Space complexity: O(1) */
    vector<vector<int>> FindIndexsForFourSumOne(vector<int> &sum,
                                                const int target);
    vector<vector<int>> FindIndexsForFourSumTwo(vector<int> &sum,
                                                const int target);
    vector<vector<int>> FindIndexsForFourSumThree(vector<int> &sum,
                                                  const int target);
    vector<vector<int>> FindIndexsForFourSumFour(vector<int> &sum,
                                                 const int target);
protected:
    
private:
    
};

/*
 * Number Eigth: Remove Element
 * Description:
 *      Given an array and a value, remove all instances of that value in place 
 * and return the new length. The order of elements can be changed. It doesn’t 
 * matter what you leave beyond the new length.
 */
class RemoveElement {
public:
    int RemoveElementInstacesOne(int a[], int length, int instance);
    int RemoveElementInstacesTwo(int a[], int length, int instance);
    
    
protected:
    
private:
    
};

/*
 * Number Nine: Next Permutation
 * Description:
 * Implement next permutation, which rearranges numbers into the lexicographically 
 * next greater permutation of numbers. If such arrangement is not possible, it 
 * must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory. 
 *     Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *     1,2,3 → 1,3,2
 *     3,2,1 → 1,2,3
 *     1,1,5 → 1,5,1
 * 算法思想：举例如下
 * 输入：1 4 6 5 3 2
 * step1：从右往左找到第一个破坏升序(非严格)的元素，此例中为4.记下标为 i
 * step2: 依然从右往左,找到第一个大于4的元素，此例中5，交换4和5.
 * step3：从i+1到最右端，逆置。6 4 3 2 to 2 3 4 6
 * so,1 5 2 3 4 6 即为所求。
 */
class NextPermutation {
public:
    /* 时间复杂度 O(n),空间复杂度 O(1) */
    void GetNextPermutation(vector<int> &num) {
        next_permutation(num.begin(), num.end());
    }
    
    template<typename BiDiIt>
    bool next_permutation(BiDiIt first, BiDiIt last) {
        // get the reversed range to simplify reversed traversal
        const auto rfirst = reverse_iterator<BiDiIt>(last);
        const auto rlast = reverse_iterator<BiDiIt>(first);
        
        // begin from the second last element to the first element
        auto pivot = next(rfirst);
        // find 'pivot' which is the first element that is no less than its successor
        while (pivot != rlast && *pivot >= *prev(pivot)) {
            ++pivot;
        }
        // if no element found
        if (pivot == rlast) {
            reverse(rfirst, rlast);
            return false;
        }
        // if one element found, scan from right to left and find the first element
        // that is greater than 'pivot'.
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*pivot, *change);
        reverse(rfirst, pivot);
        return true;
    }
    
    /* Permutation Sequence:
     * The set [1,2,3,⋯,n] contains a total of n! unique permutations.
     * By listing and labeling all of the permutations in order, We get the 
     * following sequence (ie, for n = 3): "123"、"132"、"213"、"231"、"312"、
     * "321". Given n and k, return the kth permutation sequence. 
     * Note: Given n will be between 1 and 9 inclusive.
     */
    /* Method one:采用暴力枚举法:
     * 调用 k − 1 次 next_permutation(). 暴力枚举法会把前k个排列都求出来，比较浪费 */
    string GetPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; ++i) {
            s[i] += i + 1;
        }
        for (int i = 0; i < k; ++i) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
    /* 
     * Method two:采用康托编码: 时间复杂度O(n), 空间复杂度O(1) 
     * 康托展开：全排列到一个自然数的映射X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[2]*1!+a[1]*0!
     * a[i]为整数，并且0 <= a[i] < i(1 <= i <= n), 适用范围：没有重复元素的全排列
     */
    
    string KthGetPermutation(int n, int k) {
        string s(n, '0');
        string result;
        for (int i = 0; i < n; ++i) {
            s[i] += i + 1;
        }
        return kth_permutation(s, k);
    }
protected:
    
private:
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    
    template<typename Sequence>
    Sequence kth_permutation(const Sequence &seq, int k) {
        const int n = int(seq.size());
        Sequence S(seq);
        Sequence result;
        int base = factorial(n - 1);
        --k;    //康托编码从0开始
        
        for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
            auto a = next(S.begin(), k / base);
            result.push_back(*a);
            S.erase(a);
        }
        
        result.push_back(S[0]);
        return result;
    }
};

/*
 * Number Ten: Valid Sudoku
 * Description:
 *     Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules:
 * 1. Each row must have the numbers 1-9 occuring just once.
 * 2. Each column must have the numbers 1-9 occuring just once.
 * 3. And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
 * Note: The Sudoku board could be partially filled, where empty cells are 
 * filled with the character '.'.
 */
class ValidSudoku {
public:
    /* 时间复杂度O(n^2), 空间复杂度O(1) */
    bool IsValidSudoku(const vector<vector<char>>& board);
    bool check(char ch, bool used[9]);
protected:
    
private:

};

/*
 * Number Eleven: Trapping Rain Water
 * Description:
 *     Given n non-negative integers representing an elevation map where the 
 * width of each bar is 1, compute how much water it is able to trap after raining.
 * For example, Given [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.
 * 算法详解：
 * 对于每个柱子,找到其左右两边最高的柱子,该柱子能容纳的面积:min(mac_left, mac_right) - height
 */
class TrappingRainWater {
public:
    /* method one: 时间复杂度O(n), 空间复杂度O(n) */
    int ComputeTrapWaterOne(vector<int>& num);
    /* method two: 时间复杂度O(n), 空间复杂度O(1) */
    int ComputeTrapWaterTwo(vector<int>& num);
    /* method three: 时间复杂度O(n), 空间复杂度O(n) */
    int ComputeTrapWaterThree(vector<int>& num);
protected:
    
private:
    
};


/*
 * Number Twelve: Rotate Image
 * Description:
 *     You are given an n × n 2D matrix representing an image. Rotate the image 
 * by 90 degrees (clockwise). Follow up: Could you do this in-place?
 * 算法详解：
 * Method one: 首先沿着副对角线翻转一次,然后沿着水平中线翻转一次;
 * Method two: 首先沿着水平中线翻转一次,然后沿着主对角线翻转一次.
 */
class RotateImage {
public:
    /* Time complexity: O(n^2) Space complexity: O(1) */
    void RotateImageOne(vector<vector<int>>& matrix);
    /* Time complexity: O(n^2) Space complexity: O(1) */
    void RotateImageTwo(vector<vector<int>>& matrix);
protected:
    
private:

};

/*
 * Number Thirteen: Plus One
 * Description:
 *     Given a number represented as an array of digits, plus one to the number.
 */
class PlusOne {
public:
    vector<int> PlusOneMethodOne(vector<int>& digits) {
        add(digits, 1);
        return digits;
    }
protected:
    
private:
    /* 
     * Time complexity: O(n) Space complexity: O(1)
     * Note: 1 <= digit <= 9
     */
    void add(vector<int>& digits, int digit) {
        int c = digit;  // carry, 进位
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }
        if (c > 0) {
            digits.insert(digits.begin(), 1);
        }
    }
};

/*
 * Number Fourteen: Climbing Stairs
 * Description:
 *     You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can 
 * you climb to the top?
 * 算法分析:（斐波那契数列）
 * 假设梯子有n层，那么如何爬到第n层呢，因为每次只能怕1或2步，那么爬到第n层的方法要么是
 * 从第n-1层一步上来的，要不就是从n-2层2步上来的，所以递推公式非常容易的就得出了：
 * dp[n] = dp[n-1] + dp[n-2]
 * 如果梯子有1层或者2层，dp[1] = 1, dp[2] = 2
 */
class ClimbingStairs {
public:
    /* 迭代算法: Time complexity: O(n) Space complexity: O(1) */
    int ClimbStairsOne(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        int pre = 1;
        int num = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = num;
            num += pre;
            pre = temp;
        }
        return num;
    }
    
    /*
     * 数学公式, 斐波那契数列的通项公式:
     * {[（1＋√5）/2]^n － [（1－√5）/2]^n }/√5 （注：√5表示根号5）
     * Time complexity: O(1) Space complexity: O(1)
     */
    int ClimbStairsTwo(int n) {
        const double s = sqrt(5);
        return floor((pow((1 + s) / 2, n + 1) - pow((1 - s) / 2, n + 1)) / s + 0.5);
    }
protected:
    
private:
    
};


/*
 * Number Fifteen: Gray Code
 * Description:
 *     The gray code is a binary numeral system where two successive values 
 * differ in only one bit. Given a non-negative integer n representing the 
 * total number of bits in the code, print the sequence of gray code. A gray 
 * code sequence must begin with 0. 
 * For example, given n = 2, return [0, 1, 3, 2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * • For a given n,agray code sequence is not uniquely defined.
 * • For example, [0, 2, 3, 1] is also a valid gray code sequence 
     according to the above definition.
 * • For now, the judge is able to judge based on one instance of 
     gray code sequence. Sorry about that.
 */
class GrayCode {
public:
    
protected:
    
private:

};


/*
 * Number Sixteen: Set Matrix Zeroes
 * Description:
 *     Given a m × n matrix, if an element is 0, set its entire row and column 
 * to 0. Do it in place. 
 * Follow up: Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */
class SetMatrixZeroes {
public:
    /* Time complexity: O(m*n) Space complexity: O(m+n) */
    void SetMatrixZeroesOne(vector<vector<int>>& matrix);
    /* Time complexity: O(m*n) Space complexity: O(1)  */
    void SetMatrixZeroesTwo(vector<vector<int>>& matrix);
protected:
    
private:
    
};

/*
 * Number Seventeen: Gas Station
 * Description:
 *     There are N gas stations along a circular route, where the amount of gas 
 * at station i is gas[i]. You have a car with an unlimited gas tank and 
 * it costs cost[i] of gas to travel from station i to its next station (i+1). 
 * You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station’s index if you can travel around the circuit 
 * once, otherwise return -1. 
 * Note: The solution is guaranteed to be unique.
 * 算法详解：
 *    O(N)的解法是,设置两个变量,sum判断当前的指针的有效性;
 * total则判断整个数组是否有解,有就返回通过sum得到的下标,没有则返回-1。
 */
class GasStation {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int CanCompleteCircuit(vector<int>& gas, vector<int>& cost);
protected:
    
private:
    
};

/*
 * Number Eighteen: Candy
 * Description:
 *     There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements: 
 * • Each child must have at least one candy.
 * • Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
class Candy {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    int MinimumCandyOne(vector<int>& rating);
    /* Time complexity: O(n) Space complexity: O(n) */
    int MinimumCandyTwo(vector<int>& rating);
    int solve(vector<int>& rating, vector<int>& f, int i);
protected:
    
private:
    
};

/*
 * Number nineteen: 
 * Single Number I
 * Description:
 *     Given an array of integers, every element appears twice except for one. 
 * Find that single one.
 * Single Number II
 * Description:
 *     Given an array of integers, every element appears three times except 
 * for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
 * 算法详解：
 *     利用位运算中的异或：x^x = 0, x^0 = x, 并且异或有交换律：1^1^0 = 0 = 1^0^1.
 * 所以如果将全部数字进行异或运算，所有重复元素都会被消除，最后的结果便是那个唯一的数.
 */
class SingleNumber {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    int SingleNumberOne(int num[], int n) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= num[i];
        }
        return result;
    }
    /* Time complexity: O(n) Space complexity: O(1) */
    int SingleNumberTwo(int num[], int n) {
        int result = 0;
        vector<int> count (sizeof(int) * 8, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < sizeof(int) * 8; ++j) {
                count[j] += (num[i] >> j) & 1;
            }
        }
        for (int j = 0; j < sizeof(int) * 8; ++j) {
            int bit = count[j] % 3;
            if (bit) {
                result += bit << j;
            }
        }
        return result;
    }
protected:
    
private:

};

#endif /* array_h */
