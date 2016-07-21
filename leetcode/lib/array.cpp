//
//  array.cpp
//  leetcode
//
//  Created by NoteFAN on 3/16/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>            // std::stack - LIFO
#include "stdio.h"
#include "math.h"
#include "array.h"

using namespace std;

/* Number One: Remove Duplicates from Sorted Array */
int RemoveDuplicatesFromSortedArray::RemoveDuplicates(int arr[], int length) {
    if(length == 0) {
        return 0;
    }
    int index = 0;
    for(int i = 1; i < length; ++i) {
        if(!(arr[index] == arr[i])) {
            arr[++index] = arr[i];
        }
    }
    return ++index;
}

int RemoveDuplicatesFromSortedArray::RemoveDuplicatesBasedOnSTLOne(int arr[],
                                                                   int length) {
    return int(distance(arr, unique(arr, arr + length)));
}

int RemoveDuplicatesFromSortedArray::RemoveDuplicatesAdvanced(int arr[],
                                                              int length) {
    int index = 2;
    if(length <= 2) {
        return length;
    }
    for(int i = 2; i < length; ++i) {
        if(arr[i] != arr[index - 2]) {
            arr[index++] = arr[i];
        }
    }
    return index;
}

int SearchRotatedSortedArray::SearchArray(int arr[], int length, int target) {
    int first = 0;
    int last = length - 1;
    if(target == arr[first]) {
        return first;
    }
    if(target == arr[last]) {
        return last;
    }
    while(first != last) {
        int middle = (first + last) / 2;
        if(target == arr[middle]) {
            return middle;
        }
        if(arr[first] < arr[middle]) {
            if(arr[first] < target && target < arr[middle]) {
                last = middle;
            } else {
                first = middle;
            }
        } else {
            if(arr[middle] < target && target < arr[last]) {
                first = middle;
            } else {
                last = middle;
            }
        }
    }
    return -1;
}

int SearchRotatedSortedArray::SearchArrayAdvanced(int arr[], int length,
                                                  int target) {
    int first = 0;
    int last = length - 1;
    if(target == arr[first]) {
        return first;
    }
    if(target == arr[last]) {
        return last;
    }
    while(first != last) {
        int middle = (first + last) / 2;
        if(target == arr[middle]) {
            return middle;
        }
        if(arr[first] < arr[middle]) {
            if(arr[first] < target && target < arr[middle]) {
                last = middle;
            } else {
                first = middle;
            }
        } else if(arr[first] > arr[middle]){
            if(arr[middle] < target && target < arr[last]) {
                first = middle;
            } else {
                last = middle;
            }
        } else {
            ++first;
        }
    }
    return -1;
}

double MedianOfTwoSortedArrays::FindMedianSortedArrays(int A[], int m,
                                                       int B[], int n) {
    int total = m + n;
    /* odd or even */
    if(total & 0x01) {
        return FindKth(A, m, B, n, total / 2 + 1);
    } else {
        return (FindKth(A, m, B, n, total / 2) +
                FindKth(A, m, B, n, total / 2 + 1)) / 2.0;
    }
}

int MedianOfTwoSortedArrays::FindKth(int A[], int m,
                                     int B[], int n, int k) {
    // always assume that m is equal or smaller than n
    if(m > n) {return FindKth(B, n, A, m, k);}
    if(m == 0) {return B[k-1];}
    if(k == 1) {return min(A[0], B[0]);}
    
    // divide k into two parts
    int index_a = min(m, k / 2);
    int index_b = k - index_a;
    if(A[index_a - 1] < B[index_b - 1]) {
        return FindKth(A + index_a, m - index_a, B, n, k - index_a);		
    } else if(A[index_a - 1] > B[index_b - 1]) {
        return FindKth(A, m, B + index_b, n - index_b, k - index_b);
    } else {
        return A[index_a - 1];
    }
}

/*
 * 如果允许 O(n log n) 的复杂度,那么可以先排序;
 * 由于序列里的元素是无序的, 又要求 O(n), 首先要想到用哈希表;
 * 用一个哈希表 unordered_map<int, bool> used 记录每个元素是否使用, 对每个元素,
 * 以该元素为中心, 往左右扩张, 直到不连续为止, 记录下最长的长度。
 */
int LongestConsecutiveSequence::FindLongestConsecutiveSequence(const vector<int> &num) {
    unordered_map<int, bool> used;
    int longest = 0;
    for (auto i : num) {
        used[i] = false;
    }
    for (auto i : num) {
        if (used[i]) continue;
        int length = 0;
        used[i] = true;
        for (int j = i + 1; used.find(j) != used.end(); ++j) {
            used[j] = true;
            ++length;
        }
        for (int j = i - 1; used.find(j) != used.end(); --j) {
            used[j] = true;
            ++length;
        }
        longest = max(longest, length);
    }
    return longest;
}

/*
 * Hash Table:用一个哈希表,存储每个数对应的下标. 时间复杂度 O(n),空间复杂度 O(n)
 */
vector<int> TwoSum::FindIndexsForTwoSum(const vector<int> &sum, int target) {
    unordered_map<int, int> mapping;
    vector<int> result;
    for (int i = 0; i < sum.size(); i++) {
        mapping[sum[i]] = i;
    }
    for (int i = 0; i < sum.size(); i++) {
        int gap = target - sum[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
        }
    }
    return result;
}

/*
 * 先排序,然后左右夹逼,时间复杂度 O(n^2),空间复杂度 O(1)
 */
vector<vector<int>> ThreeSum::FindIndexsForThreeSum(vector<int> &sum,
                                                    const int target) {
    vector<vector<int>> result;
    if (sum.size() < 3) {
        return result;
    }
    sort(sum.begin(), sum.end());
    auto last = sum.end();
    for (auto a = sum.begin(); a < prev(last, 2); ++a) {
        auto b = next(a);
        auto c = prev(last);
        while (b < c) {
            if (*a + *b + *c < target) {
                ++b;
            } else if (*a + *b + *c > target) {
                --c;
            } else {
                result.push_back({*a, *b, *c});
                ++b;
                --c;
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int ThreeSum::FindSumClosest(vector<int> &sum, const int target) {
    int result = 0;
    // assuming: 10000 >> the gap between the sum of the three elements and target
    int min_gap = 10000;
    sort(sum.begin(), sum.end());
    for (auto a = sum.begin(); a < prev(sum.end(), 2); ++a) {
        auto b = next(a);
        auto c = prev(sum.end());
        while (b < c) {
            const int total = *a + *b + *c;
            const int gap = abs(total - target);
            if (gap < min_gap) {
                result = total;
                min_gap = gap;
            }
            if (total < target) {
                ++b;
            } else if (total > target) {
                --c;
            } else {
                return result;
            }
        }
    }
    return result;
}

/*
 * 先排序,然后左右夹逼,时间复杂度 O(n^3),空间复杂度 O(1)
 */
vector<vector<int>> FourSum::FindIndexsForFourSumOne(vector<int> &sum,
                                                     const int target) {
    vector<vector<int>> results;
    if (sum.size() < 4) {
        return results;
    }
    sort(sum.begin(), sum.end());
    for (auto a = sum.begin(); a < prev(sum.end(), 3); ++a) {
        for (auto b = next(a); b < prev(sum.end(), 2); ++b) {
            auto c = next(b);
            auto d = prev(sum.end());
            while (c < d) {
                if (*a + *b + *c + *d < target)  {
                    ++c;
                } else if (*a + *b + *c + *d > target)  {
                    --d;
                } else {
                    results.push_back({*a, *b, *c, *d});
                    ++c;
                    --d;
                }
            }
        }
    }
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());
    return results;
}

/*
 * "map 做缓存"
 * 用一个 hashmap 先缓存两个数的和
 * 时间复杂度,平均 O(n^2),最坏 O(n^4),空间复杂度 O(n^2)
 */
vector<vector<int>> FourSum::FindIndexsForFourSumTwo(vector<int> &sum,
                                                     const int target) {
    vector<vector<int>> results;
    if (sum.size() < 4) {
        return results;
    }
    sort(sum.begin(), sum.end());
    unordered_map<int, vector<pair<int, int>>> cache;
    for (vector<int>::size_type a = 0; a < sum.size(); ++a) {
        for (vector<int>::size_type b = a + 1; b < sum.size(); ++b) {
            cache[sum[a] + sum[b]].push_back(pair<int, int>(a, b));
        }
    }
    for (vector<int>::size_type c = 0; c < sum.size(); ++c) {
        for (vector<int>::size_type d = c + 1; d < sum.size(); ++d) {
            const int key = target - sum[c] - sum[d];
            if (cache.find(key) == cache.end()) {
                continue;
            } else {
                for (auto it = cache[key].begin(); it < cache[key].end(); ++it) {
                    if (c <= it->second) {
                        continue;
                    } else {
                        results.push_back({sum[it->first], sum[it->second],
                                           sum[c], sum[d]});
                    }
                }
            }
        }
    }
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());
    return results;
}

/*
 * "multimap"
 * 用一个 hashmap 先缓存两个数的和
 * 时间复杂度,平均 O(n^2),空间复杂度 O(n^2)
 */
vector<vector<int>> FourSum::FindIndexsForFourSumThree(vector<int> &sum,
                                                     const int target) {
    vector<vector<int>> results;
    if (sum.size() < 4) {
        return results;
    }
    sort(sum.begin(), sum.end());
    unordered_multimap<int, pair<int, int>> cache;
    for (vector<int>::size_type i = 0; i < sum.size(); ++i) {
        for (vector<int>::size_type j = i + 1; j < sum.size(); ++j) {
            cache.insert(make_pair(sum[i] + sum[j], make_pair(i, j)));
        }
    }
    for (auto i = cache.begin(); i != cache.end(); ++i) {
        int gap = target - i->first;
        auto range = cache.equal_range(gap);
        for (auto j = range.first; j  != range.second; ++j) {
            auto a = i->second.first;
            auto b = i->second.second;
            auto c = j->second.first;
            auto d = j->second.second;
            if (a != c && a != d && b != c && b != d) {
                vector<int> result = { sum[a], sum[b], sum[c], sum[d] };
                sort(result.begin(), result.end());
                results.push_back(result);
            }
            
        }
    }
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());
    
    return results;
}

/*
 * 时间复杂度 O(n),空间复杂度 O(1)
 */
int RemoveElement::RemoveElementInstacesOne(int a[], int length, int instance) {
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (a[i] != instance) {
            a[index] = a[i];
            ++index;
        }
    }
    return index;
}

/*
 * 使用remove()接口, 时间复杂度 O(n),空间复杂度 O(1)
 */
int RemoveElement::RemoveElementInstacesTwo(int a[], int length, int instance) {
    return int(distance(a, remove(a, a + length, instance)));
}

/*
 * 时间复杂度 O(n^2),空间复杂度 O(1)
 */
bool ValidSudoku::IsValidSudoku(const vector<vector<char>>& board) {
    bool used[9];
    
    for (int i = 0; i < 9; ++i) {
        // check the row
        fill(used, used + 9, false);
        for (int j = 0; j < 9; ++j) {
            if (!check(board[i][j], used)) {
                return false;
            }
        }
        // check the column
        fill(used, used + 9, false);
        for (int j = 0; j < 9; ++j) {
            if (!check(board[j][i], used)) {
                return false;
            }
        }
    }
    // check the 9 sub-boxes
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fill(used, used + 9, false);
            for (int r = 3 * i; r < 3 * (i + 1); ++r) {
                for (int c = 3 * j; c < 3 * (j + i); ++c) {
                    if (!check(board[r][c], used)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool ValidSudoku::check(char ch, bool used[9]) {
    if (ch == '.') {
        return true;
    }
    if (used[ch - '1']) {
        return false;
    }
    used[ch - '1'] = true;
    return true;
}

/* method one: 时间复杂度O(n), 空间复杂度O(n) */
int TrappingRainWater::ComputeTrapWaterOne(vector<int>& num) {
    int sum = 0;
    int length = int(num.size());
    vector<int> max_left(length, 0);
    vector<int> max_right(length, 0);
    for (int i = 1; i < length; ++i) {
        max_left[i] = max(max_left.at(i - 1), num.at(i - 1));
        max_right[length - i - 1] = max(max_right.at(length - i), num.at(length - i));
    }
    
    for (int i = 1; i < length - 1; ++i) {
        int height = min(max_left.at(i), max_right.at(i));
        if (height > num.at(i)) {
            sum += height - num.at(i);
        }
    }
    return sum;
}

/* method two: 时间复杂度O(n), 空间复杂度O(1) */
int TrappingRainWater::ComputeTrapWaterTwo(vector<int>& num) {
    int sum = 0;
    int max = 0;
    // find the largest element and divide it into two parts
    for (int i = 1; i < num.size(); ++i) {
        if (num[i] > num[max]) {
            max = i;
        }
    }
    for (int i = 0, peak = 0; i < max; ++i) {
        if (num.at(i) < peak) {
            sum += peak - num.at(i);
        } else {
            peak = num.at(i);
        }
    }
    for (int i = int(num.size()) - 1, peak = 0; i > max; --i) {
        if (num.at(i) < peak) {
            sum += peak - num.at(i);
        } else {
            peak = num.at(i);
        }
    }
    return sum;
}

/* 
 * method three: 时间复杂度O(n), 空间复杂度O(n) 
 * 用一个栈辅助,小于栈顶的元素压入,大于等于栈顶就把栈里所有小于或等于当前值的元素全部出栈处理掉。
 * Since stacks are last-in first-out containers, the top element is the last 
 * element inserted into the stack.
 */
int TrappingRainWater::ComputeTrapWaterThree(vector<int>& num) {
    stack<int> s;
    int water = 0;
    s.push(0);
    
    for (int i = 0; i < num.size(); ++i) {
        if (num.at(i) > num[s.top()]) {
            int bottom = num.at(s.top());
            s.pop();
            while (!s.empty() && num.at(i) >= num[s.top()]) {
                water += (num[s.top()] - bottom) * (i - s.top() - 1);
                bottom = num.at(s.top());
                s.pop();
            }
            if (!s.empty()) {
                water += (num.at(i) - bottom) * (i - s.top() - 1);
            }
        }
        s.push(i);
    }
    
    return water;
}

/* 首先沿着副对角线翻转一次,然后沿着水平中线翻转一次 */
void RotateImage::RotateImageOne(vector<vector<int>>& matrix) {
    int length = int(matrix.size());
    
    // first step: 副对角线翻转一次
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            swap(matrix[i][j], matrix[length - i - 1][length - j - 1]);
        }
    }
    // second step: 水平中线翻转一次
    for (int i = 0; i < length / 2; ++i) {
        for (int j = 0; j < length; ++j) {
            swap(matrix[i][j], matrix[length - i - 1][j]);
        }
    }
}

/* 首先沿着水平中线翻转一次,然后沿着主对角线翻转一次 */
void RotateImage::RotateImageTwo(vector<vector<int>>& matrix) {
    int length = int(matrix.size());
    
    // first step: 水平中线翻转一次
    for (int i = 0; i < length / 2; ++i) {
        for (int j = 0; j < length; ++j) {
            swap(matrix[i][j], matrix[length - 1 - i][j]);
        }
    }
    
    // second step: 主对角线翻转一次
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

/* Time complexity: O(m*n) Space complexity: O(m+n) */
void SetMatrixZeroes::SetMatrixZeroesOne(vector<vector<int>>& matrix) {
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);
    
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (size_t i = 0; i < m; ++i) {
        if (row[i]) {
            fill(&matrix[i][0], &matrix[i][0] + n, 0);
        }
    }
    for (size_t j = 0; j < n; ++j) {
        if (col[j]) {
            for (size_t i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}

/* Time complexity: O(m*n) Space complexity: O(1) */
void SetMatrixZeroes::SetMatrixZeroesTwo(vector<vector<int>> &matrix) {
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    bool row_has_zero = false;
    bool col_has_zero = false;
    
    for (size_t i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            col_has_zero = true;
            break;
        }
    }
    for (size_t j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            row_has_zero = true;
            break;
        }
    }
    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (col_has_zero) {
        for (size_t i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (row_has_zero) {
        for (size_t i = 0; i < n; ++i) {
            matrix[0][i] = 0;
        }
    }
}

/* Time complexity: O(n) Space complexity: O(1) */
int GasStation::CanCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int index = -1;
    int sum = 0;
    int total = 0;
    for (int i = 0; i < gas.size(); ++i) {
        sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (sum < 0) {
            index = i + 1;
            sum = 0;
        }
    }
    return total >= 0 ? index : -1;
}

/* Time complexity: O(n) Sapce complexity: O(n) */
int Candy::MinimumCandyOne(vector<int>& rating) {
    int sum = 0;
    int n = int(rating.size());
    vector<int> num (n, 1);
    for (int i = 1; i < n; ++i) {
        if (rating.at(i) > rating.at(i - 1)) {
            num[i] = num.at(i - 1) + 1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (rating.at(i) > rating.at(i + 1)) {
            num[i] = max(num[i], num.at(i + 1) + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        sum += num.at(i);
    }
    return sum;
}

/* Time complexity: O(n) Sapce complexity: O(n) */
int Candy::MinimumCandyTwo(vector<int>& rating) {
    int sum = 0;
    vector<int> f(rating.size());
    for (int i = 0; i < rating.size(); ++i) {
        sum += solve(rating, f, i);
    }
    return sum;
}

int Candy::solve(vector<int> &rating, vector<int> &f, int i) {
    if (f[i] == 0) {
        f[i] = 1;
        if (i > 0 && rating[i] > rating[i - 1]) {
            f[i] = max(f[i], solve(rating, f, i - 1) + 1);
        }
        if (i < rating.size() && rating[i] > rating[i + 1]) {
            f[i] = max(f[i], solve(rating, f, i + 1) + 1);
        }
    }
    
    return f[i];
}



