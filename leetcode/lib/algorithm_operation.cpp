//
//  algorithms.cpp
//  leetcode
//
//  Created by NoteFAN on 6/14/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include "algorithm_operation.h"

using namespace std;

double Pow::GetPow(double x, int n) {
    if (n < 0) {
        return Power(x, -n);
    }
    return Power(x, n);
}

double Pow::Power(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    double result = Power(x, n / 2);
    return result * result * Power(x, n % 2);
}

/*
 * 二分查找
 * Time complexity: O(logn) Space complexity: O(1)
 */
int Sqrt::GetSqrt(int x) {
    int left = 1, right = x;
    while (left + 1 < right) {
        int middle = (right - left) / 2 + left;
        // 不要用 middle * middle < x, 会溢出
        if (x / middle > middle) {
            left = middle;
        } else if (x / middle < middle) {
            right = middle;
        } else {
            return middle;
        }
    }
    if (x / right >= right) return right;
    return left;
}

/* 
 * Time complexity: O(n) Space complexity: O(1)
 * 思路一:正向,从0出发,一层一层往上跳,看最后能不能超过最高层,能超过,说明能到达,否则不能到达。
 */
bool JumpGame::CheckJumpOne(vector<int> A) {
    int length = int(A.size());
    int reach = 1; // The highest step
    for (int i = 0; i < reach && reach < length; ++i) {
        reach = max(reach, i + 1 + A[i]);
    }
    return reach >= length;
}

/* 
 * Time complexity: O(n) Space complexity: O(1) 
 * 思路二:逆向,从最高层下楼梯,一层一层下降,看最后能不能下降到第 0 层。
 */
bool JumpGame::CheckJumpTwo(vector<int> A) {
    int reach = int(A.size());
    for (int i = int(A.size()) - 2; i >= 0; --i) {
        if (reach <= i + 1 + A[i]) {
            reach = i + 1;
        }
    }
    return reach == 1;
}

/* 
 * Time complexity: O(n) Space complexity: O(1) 
 * DP: 设状态为f[i]，表示从0层出发,走到A[i]时剩下的最大步数.
 * f[i] = max(f[i - 1], A[i - 1]) - 1 (i > 0)
 */
bool JumpGame::CheckJumpThree(vector<int> A) {
    vector<int> f(A.size(), 0);
    f[0] = 0;
    for (int i = 1; i < int(A.size()); ++i) {
        f[i] = max(f[i - 1], A[i - 1]) - 1;
        if (f[i] < 0) {
            return false;
        }
    }
    return true;
}

/*
 * Time complexity: O(n) Space complexity: O(1)
 */
int JumpGameII::CheckJump(vector<int> A) {
    int step = 0, left = 0, right = 0;
    int length = int(A.size());
    if (length == 1) return 0;
    while (left <= right) {
        int old_right = right;
        ++step;
        for (int i = left; i <= old_right; ++i) {
            int new_right = i + A[i];
            if (new_right >= length - 1) {
                return step;
            }
            else if (right < new_right) {
                right = new_right;
            }
        }
        left = old_right + 1;
    }
    return 0;
}

/* Time complexity: O(n) Space complexity: O(1) */
double BestTimeToBuyAndSellStockI::GetMaximumProfit(vector<double> prices) {
    if (prices.size() == 0) return 0;
    double profit = 0;
    double min_price = prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
        profit = max(profit, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }
    return profit;
}

/* Time complexity: O(n) Space complexity: O(1) */
double BestTimeToBuyAndSellStockII::GetMaximumProfit(vector<double> prices) {
    double profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        double diff = prices[i] - prices[i - 1];
        if (diff > 0) {
            profit += diff;
        }
    }
    return profit;
}

/* Time complexity: O(n) Space complexity: O(1) */
int LongestSubstringWithoutRepeatingCharacters::GetLongestSubstring(string s) {
    int length = int(s.size());
    vector<int> position(26, -1);
    int start = 0;
    int max_distance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (position[s[i] - 'a'] >= start) {
            max_distance = max(max_distance, i - start);
            start = position[s[i] - 'a'] + 1;
        }
        position[s[i] - 'a'] = i;
    }
    return max(max_distance,  length - start);
}

/* Time complexity: O(n) Space complexity: O(1) */
int ContainerWithMostWater::GetMostWater(vector<int> height) {
    int start = 0, end = int(height.size()) - 1;
    int container = 0;
    while (start < end) {
        container = max(container, min(height[start], height[end]) * (end - start));
        if (height[start] > height[end]) {
            --end;
        } else {
            ++start;
        }
    }
    return container;
}

/************************************动态规划***********************************/
/*
 * Time complexity: O(n^2) Space complexity: O(1)
 * Solution: Dynamic Programming
 * 设f(i, j)表示从i, j出发的最小路径之和，即可知：
 * f(i, j) = min(f(i + 1, j), f(i + 1, j + 1)) + (i, j)
 */
int Triangle::GetMinimumPathSum(vector<vector<int>> &numbers) {
    for (int i = int(numbers.size()) - 2; i >= 0 ; --i) {
        for (int j = 0; j <= i; ++j) {
            numbers[i][j] += min(numbers[i + 1][j], numbers[i + 1][j + 1]);
        }
    }
    return numbers[0][0];
}

/* Time complexity: O(n) Space complexity: O(1) */
int Subarray::MaximumSubarray(vector<int> numbers) {
    int length = int(numbers.size());
    if (length == 0) return 0;
    int f = numbers[0];
    int result = numbers[0];
    for (int i = 1; i < length; ++i) {
        f = max(f + numbers[i], numbers[i]);
        result = max(f, result);
    }
    return result;
}

/*
 * Analysis:(DP)
 * 设f(i)表示[i, n - 1]之间的最小分割数，则获得状态转换方程:
 * f(i) = min(f(i), f(j + 1) + 1), i < j < n 且[i, j]之间为回文字符串.
 * 同时设p(i, j)表示[i, j]之间是否为回文字符串,false表示不是,true表示是.
 * Time complexity: O(n^2) Time complexity: O(n^2)
 */
int PalindromePartitioningII::MinimumCut(string s) {
    int length = int(s.size());
    vector<vector<bool> > p(length, vector<bool>(length, false));
    vector<int> f(length, 0);
    for (int i = 0; i <= length; ++i) {
        f[i] = length - 1 - i;
    }
    for (int i = length - 1; i >= 0; --i) {
        for (int j = i; j < length; ++j) {
            if (s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1])) {
                p[i][j] = true;
                f[i] = min(f[i], f[j + 1] + 1);
            }
        }
    }
    return f[0];
}

/*
 * Analysis:
 * 1. 转换矩阵: dp[i][j]就是当前的第j列 - 从上到第i行连续1的个数。
 * 2. 题目求解即转换成: 求柱状图的最大矩形面积
 * Time complexity: O(n^2) Space complexity: O(n)
 */
int MaximalRectangle::GetMaximalRectangleOne(vector<vector<int> > &matrix) {
    int ret = 0;
    int row = int(matrix.size());
    if (row == 0) return 0;
    int column = int(matrix[0].size());
    // step one
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = i == 0 ? 1 : matrix[i - 1][j] + 1;
            }
        }
    }
    
    // step two
    for (int i = 0; i < row; ++i) {
        stack<int> stk;
        for (int j = 0; j < column; ++j) {
            while (!stk.empty() && matrix[i][j] < matrix[i][stk.top()]) {
                int height = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    ret = max(ret, (j - stk.top() - 1) * matrix[i][height]);
                } else {
                    ret = max(ret, j * matrix[i][height]);
                }
                
            }
            stk.push(j);
        }
        
        if (!stk.empty()) {
            int length = stk.top();
            while (matrix[i][stk.top()] > 0) {
                int height = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    ret = max(ret, (length - stk.top()) * matrix[i][height]);
                } else {
                    ret = max(ret, (length + 1) * matrix[i][height]);
                    break;
                }
            }
        }

        
    }
    return ret;
}

/*
 * Analysis:
 * 1. 转换矩阵: dp[i][j]就是当前的第j列 - 从上到第i行连续1的个数。
 * 2. 题目求解即转换成: 求柱状图的最大矩形面积
 * Time complexity: O(n^2) Space complexity: O(n)
 */
int MaximalRectangle::GetMaximalRectangleTwo(vector<vector<int> > &matrix) {
    if (int(matrix.size() == 0)) return 0;
    int row = int(matrix.size());
    int column = int(matrix[0].size());
    int result = 0;
    vector<int> height(column, 0);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (matrix[i][j]) {
                ++height[j];
            } else {
                height[j] = 0;
            }
        }
        stack<int> stk;
        for (int j = 0; j <= column; ++j) {
            int h = j != column ? height[j] : -1;
            while (!stk.empty() && h < height[stk.top()]) {
                int m = stk.top();
                stk.pop();
                int area = stk.empty() ? j * height[m] : (j - stk.top() - 1) * height[m];
                result = max(area, result);
            }
            stk.push(j);
        }
    }
    return result;
}

/* Time complexity: O(n) Space complexity: O(n) */
double BestTimeBuyAndSellStockIII::MaximumProfit(vector<double> prices) {
    if (int(prices.size()) < 2) return 0;
    int n = int(prices.size());
    vector<double> f(n, 0);
    vector<double> g(n, 0);
    double profit = 0;
    double price = prices[0];
    for (int i = 1; i < n; ++i) {
        price = min(price, prices[i]);
        f[i] = max(f[i - 1], prices[i] - price);
    }
    price = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        price = max(price, prices[i]);
        g[i] = max(g[i + 1], price - prices[i]);
    }
    for (int i = 0; i < n; ++i) {
        profit = max(profit, f[i] + g[i]);
    }
    return profit;
}

/* 
 * Time complexity: O(n^2) Space complexity: O(n^2) 
 * 状态转移方程:
 * f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) ||
             (s2[i - 1] == s3[i + j - 1] && f[i][j - 1])
 */
bool InterleavingString::CheckInterleavingString(string s1, string s2, string s3) {
    int n1 = int(s1.size());
    int n2 = int(s2.size());
    int n3 = int(s3.size());
    if (n1 + n2 != n3) return false;
    vector<vector<bool>> f(n1 + 1, vector<bool>(n2 + 1, true));
    for (int i = 1; i <= n1; ++i) {
        f[i][0] = s1[i - 1] == s3[i - 1] && f[i - 1][0];
    }
    for (int j = 1; j <= n2; ++j) {
        f[0][j] = s2[j - 1] == s3[j - 1] && f[0][j - 1];
    }
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) ||
                      (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
        }
    }
    return f[n1][n2];
}

/*
 * DP + 滚动数组
 * Time complexity: O(n^2) Space complexity: O(n)
 */
bool InterleavingString::IsInterleavingString(string s1, string s2, string s3) {
    int n1 = int(s1.size());
    int n2 = int(s2.size());
    int n3 = int(s3.size());
    if (n1 + n2 != n3) return false;
    if (n1 > n2) {
        return IsInterleavingString(s2, s1, s3);
    }
    vector<bool> f(n1 + 1, true);
    for (int i = 1; i <= n1; ++i) {
        f[i] = f[i - 1] && s1[i - 1] == s3[i - 1];
    }
    for (int i = 1; i <= n2; ++i) {
        f[0] = s2[i - 1] == s3[i - 1] && f[0];
        for (int j = 1; j <= n1; ++j) {
            f[j] = (s1[j - 1] == s3[i + j - 1] && f[j - 1]) ||
                   (s2[i - 1] == s3[i + j - 1] && f[j]);
        }
    }
    return f[n1];
}

/*
 * 递归 + 剪枝
 * Time complexity: O(n^n)? Space complexity: O(1)
 */
bool ScrambleString::IsScrambleStringOne(string s1, string s2) {
    int length1 = int(s1.size());
    int length2 = int(s2.size());
    if (length1 != length2) return false;
    // 剪枝
    vector<int> numbers(26, 0);
    for (int i = 0; i < length1; ++i) {
        ++numbers[s1[i] - 'a'];
        --numbers[s2[i] - 'a'];
    }
    for (int i = 0; i < length1; ++i) {
        if (numbers[i] != 0) {
            return false;
        }
    }
    if (length1 == 1) return true;
    for (int i = 1; i < length1; ++i) {
        bool result = (IsScrambleStringOne(s1.substr(0, i), s2.substr(0, i)) &&
            IsScrambleStringOne(s1.substr(i, length1 - i), s2.substr(i, length1 - i))) ||
            (IsScrambleStringOne(s1.substr(0, i), s2.substr(length1 - i, i)) &&
            IsScrambleStringOne(s1.substr(length1 - i, i), s2.substr(0, i)));
        if (result) return true;
    }
    return false;
}

/*
 * Dynamic programming
 * Time complexity: O(n^3) Space complexity: O(n^3)
 * Analysis:
 * 设f[n][i][j]为长度为n,起点分别为s1[i]和s2[j]的字符串互为scramble,即得:
 * f[n][i][j] = f[k][i][j] && f[n - k][i + k][j + k] ||
 *              f[k][i][j + n - k] && f[n - k][i + k][j](1 <= k <= n - 1)
 */
bool ScrambleString::IsScrambleStringTwo(string s1, string s2) {
    int length1 = int(s1.size());
    int length2 = int(s2.size());
    if (length1 != length2) return false;
    vector<vector<vector<bool>>>f(length1 + 1,
                                  vector<vector<bool>>(length1,
                                                       vector<bool>(length1, false)));
    for (int i = 0; i < length1; ++i) {
        for (int j = 0; j < length1; ++j) {
            f[1][i][j] = s1[i] == s2[j];
        }
    }
    for (int n = 2; n <= length1; ++n) {
        for (int i = 0; i <= length1 - n; ++i) {
            for (int j = 0; j <= length1 - n; ++j) {
                for (int k = 1; k < n; ++k) {
                    if ((f[k][i][j] && f[n - k][i + k][j + k]) ||
                        (f[k][i][j + n - k] && f[n - k][i + k][j])) {
                        f[n][i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    return f[length1][0][0];
}

/*
 * 备忘录法
 * Time complexity: O(m * n) Space complexity: O(m * n)
 */
int MinimumPathSum::GetMinimumPathSumOne(vector<vector<int>> matrix) {
    int m = int(matrix.size());
    if (m == 0) return INT_MAX;
    int n = int(matrix[0].size());
    vector<vector<int>> f(m, vector<int>(n, -1));
    return dfs(matrix, f, m - 1, n - 1);
}

int MinimumPathSum::dfs(vector<vector<int>> matrix, vector<vector<int>> &f,
                        int m, int n) {
    if (m < 0 || n < 0) return INT_MAX;
    if (m == 0 && n == 0) return matrix[0][0];
    
    f[m][n] = min(GetOrUpdate(matrix, f, m - 1, n),
                  GetOrUpdate(matrix, f, m, n - 1)) + matrix[m][n];
    return f[m][n];
}

int MinimumPathSum::GetOrUpdate(vector<vector<int>> matrix,
                                vector<vector<int>> &f,
                                int m, int n) {
    if (m < 0 || n < 0) return INT_MAX;
    if (f[m][n] < 0) {
        f[m][n] = dfs(matrix, f, m, n);
    }
    return f[m][n];
}

/*
 * DP
 * Time complexity: O(m * n) Space complexity: O(m * n)
 * Analysis:
 * 设f[i][j]为top left到(i, j)的最小和,即得:
 * f[i][j] = min(f[i - 1][j], f[i][j - 1]) + matrix[i][j]
 */
int MinimumPathSum::GetMinimumPathSumTwo(vector<vector<int>> matrix) {
    int m = int(matrix.size());
    if (m == 0) return INT_MAX;
    int n = int(matrix[0].size());
    vector<vector<int>> f(m, vector<int>(n, 0));
    f[0][0] = matrix[0][0];
    for (int i = 1; i < m; ++i) {
        f[i][0] = f[i - 1][0] + matrix[i][0];
    }
    for (int j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + matrix[0][j];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + matrix[i][j];
        }
    }
    return f[m - 1][n - 1];
}

/*
 * DP + 滚动数组
 * Time complexity: O(m * n) Space complexity: O(n)
 */
int MinimumPathSum::GetMinimumPathSumThree(vector<vector<int>> matrix) {
    int m = int(matrix.size());
    if (m == 0) return INT_MAX;
    int n = int(matrix[0].size());
    vector<int> f(n, 0);
    f[0] = matrix[0][0];
    for (int i = 1; i < n; ++i) {
        f[i] = f[i - 1] + matrix[0][i];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            f[j] = j == 0 ? f[j] + matrix[i][j] : min(f[j - 1], f[j]) + matrix[i][j];
        }
    }
    return f[n - 1];
}

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
 */
int EditDistance::CountSteps(string word1, string word2) {
    int m = int(word1.size());
    int n = int(word2.size());
    vector<vector<int>> f(m, vector<int>(n, 0));
    if (word1[0] != word2[0]) {
        f[0][0] = 1;
    }
    for (int i = 1; i < m; ++i) {
        f[i][0] = f[i - 1][0] + 1;
    }
    for (int j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (word1[i] == word2[j]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
            }
        }
    }
    return f[m - 1][n - 1];
}

/*
 * Time complexity: O(n) Space complexity: O(n)
 * Analysis:
 * Count[i] means the number of ways for s[0, i]
 * Transformation function as:
 * Count[i] = Count[i-1]  if S[i-1] is a valid char
 *       or = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char.
 */
int DecodeWays::CountDecodeWays(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int n = int(s.size());
    vector<int> f(n, 0);
    f[0] = 1;
    if (n == 1) return f[0];
    if (check(s[1])) f[1] += f[0];
    if (check(s[0], s[1])) f[1] += 1;
    for (int i = 2; i < n; ++i) {
        if (check(s[i])) f[i] += f[i - 1];
        if (check(s[i - 1], s[i])) f[i] += f[i - 2];
        if (f[i] == 0) return 0;
    }
    return f[n - 1];
}

/*
 * Time complexity: O(n * m) Space complexity: (n * m)
 * Analysis:
 * 设f[i][j]表示T[0 : j)在S[0 : i)中出现的次数, 即得状态方程:
 * f[i][j] = f[i - 1][j - 1], S[i] == T[j]
 * f[i][j] = f[i - 1][j], S[i] != T[j]
 */
int DistinctSubsequences::NumberDistinctSubsequences(string S, string T) {
    int n = int(S.size());
    int m = int(T.size());
    if (n < m) return 0;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j > i) break;
            f[i][j] = f[i - 1][j];
            if (S[i - 1] == T[j - 1]) {
                f[i][j] += f[i - 1][j - 1];
            }
        }
    }
    return f[n][m];
}

/*
 * DP + 滚动数组
 * Time complexity: O(n * m) Space complexity: (m)
 */
int DistinctSubsequences::NumberDistinctSubsequencesOne(string S, string T) {
    int n = int(S.size());
    int m = int(T.size());
    if (n < m) return 0;
    vector<int> f(m + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, m); j > 0; --j) {
            if (S[i - 1] == T[j - 1]) {
                f[j] += f[j - 1];
            }
        }
    }
    return f[m];
}

/*
 * DP
 * Time complexity: (n^2) Space complexity: O(n)
 */
bool WordBreak::CheckWordBreak(string s, unordered_set<string> dict) {
    int length = int(s.size());
    vector<bool> f(length + 1, false);
    f[0] = true;
    for (int i = 1; i <= length; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                f[i] = true;
                break;
            }
        }
    }
    return f[length];
}

/*
 * DP
 * Time complexity: (n^2) Space complexity: O(n)
 * Analysis:
 * 设f[i]表示s[0 : i)可以被分割, 即得:
 * 状态方程: f[i] = f[j] && (s[j, i) in dict), 0 =< j <= i
 */
vector<string> WordBreakII::CheckWordBreak(string s, unordered_set<string> dict) {
    int length = int(s.size());
    vector<bool> f(length + 1, false);
    f[0] = true;
    vector<vector<bool>> status(length + 1, vector<bool>(length + 1, false));
    for (int i = 1; i <= length; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                f[i] = true;
                status[j][i] = true;
            }
        }
    }
    // DFS遍历树, 生成路径
    vector<string> results;
    vector<string> path;
    dfs(results, path, s, 0, status);
        
    return results;
}

void WordBreakII::dfs(vector<string> &results, vector<string> &path, string s,
                      int start, vector<vector<bool>> status) {
    int length = int(s.size());
    if (start >= length) {
        string sentence = path[0];
        for (int k = 1; k < int(path.size()); ++k) {
            sentence += " " + path[k];
        }
        results.push_back(sentence);
    }
    for (int i = 1; i <= length; ++i) {
        if (status[start][i]) {
            path.push_back(s.substr(start, i - start));
            dfs(results, path, s, i, status);
            path.pop_back();
        }
    }
}

/************************************图论***************************************/

/*
 * 邻接表: DFS
 * Time complexity: O(n) Space complexity: O(n)
 */
UndirectedGraphNode *CloneGraph::CloneGraphOne(UndirectedGraphNode *node) {
    if (node == nullptr) return nullptr;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> copied;
    dfs(node, copied);
    return copied[node];
}

UndirectedGraphNode *CloneGraph::dfs(UndirectedGraphNode *node,
                                     unordered_map<UndirectedGraphNode *,
                                     UndirectedGraphNode *> &copied) {
    if (copied.find(node) != copied.end()) return copied[node];
    
    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    copied[node] = new_node;
    for (vector<UndirectedGraphNode *>::iterator it = node->neighbors.begin();
         it != node->neighbors.end(); ++it) {
        new_node->neighbors.push_back(dfs(*it, copied));
    }
    return new_node;
}

/*
 * 邻接表: BFS
 * Time complexity: O(n) Space complexity: O(n)
 */
UndirectedGraphNode *CloneGraphTwo(UndirectedGraphNode *node) {
   if (node == nullptr) return nullptr;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> copied;
    queue<UndirectedGraphNode *> q;
    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    copied[node] = new_node;
    q.push(new_node);
    while (!q.empty()) {
        UndirectedGraphNode *temp_node = q.front();
        q.pop();
        for (vector<UndirectedGraphNode *>::iterator it = temp_node->neighbors.begin();
             it != temp_node->neighbors.end(); ++it) {
            if (copied.find(*it) == copied.end()) {
                UndirectedGraphNode *new_node = new UndirectedGraphNode((*it)->label);
                copied[*it] = new_node;
                copied[temp_node]->neighbors.push_back(new_node);
                q.push(*it);
            } else {
                copied[temp_node]->neighbors.push_back(copied[*it]);
            }
        }
    }
    return copied[node];
}

/**********************************细节实现题************************************/
int ReverseInteger::ReverseIntegerDigit(int x) {
    int rct = 0;
    while (x) {
        int next_rct = rct * 10 + x % 10;
        if (next_rct / 10 != rct) {
            return -1;
        }
        x /= 10;
        rct = next_rct;
    }
    return rct;
}

bool PalindromeNumber::CheckPalindromeNumber(int num) {
    if (num < 0) return false;
    int up = 1, down = 10;
    while (num / up >= 10) {
        up *= 10;
    }
    while (num / up == num % down) {
        if (up / down <= 100) {
            return true;
        }
        num = num - num / up * up;
        num /= down;
        up /= 100;
    }
    return false;
}

/* Time complexity: O() Space complexity: O() */
vector<Interval> InsertInterval::Insert(vector<Interval> &intervals, Interval interval) {
    vector<Interval>::iterator it = intervals.begin();
    while (it != intervals.end()) {
        if (interval.right < it->left) {
            intervals.insert(it, interval);
            return intervals;
        } else if (interval.left > it->right) {
            ++it;
        } else {
            interval.left = min(interval.left, it->left);
            interval.right = max(interval.right, it->right);
            it = intervals.erase(it);
        }
    }
    intervals.push_back(interval);
    return intervals;
}

/* Time complexity: O(n^2) Space complexity: O(1) */
vector<Interval> InsertInterval::MergeIntervals(vector<Interval> &intervals) {
    vector<Interval> results;
    for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++it) {
        Insert(results, *it);
    }
    return results;
}

string MinimumWindowSubstring::MinimumWindow(string S, string T) {
    if (S.empty()) return "";
    if (S.size() < T.size()) return "";
    size_t start = 0, end = 0, appear = 0;
    size_t min_width = INT_MAX, min_start = 0;
    vector<int> expected_count(256, 0);
    vector<int> appeared_count(256, 0);
    for (string::iterator it = T.begin(); it != T.end(); ++it) {
        ++expected_count[*it];
    }
    for (end = 0; end < S.size(); ++end) {
        if (expected_count[S[end]] > 0) {
            ++appeared_count[S[end]];
            if (appeared_count[S[end]] <= expected_count[S[end]]) {
                ++appear;
            }
            if (appear == T.size()) {
                while (appeared_count[S[start]] > expected_count[S[start]] ||
                       expected_count[S[start]] == 0) {
                    --appeared_count[S[start]];
                    ++start;
                }
                if (min_width > end - start + 1) {
                    min_width = end - start + 1;
                    min_start = start;
                }
            }
        }
    }
    if (min_width == INT_MAX) return "";
    return S.substr(min_start, min_width);
}

/* Time complxity: O(m * n) Space complexity: O(m + n)*/
string MultiplyStrings::GetMultiplyString(string s1, string s2) {
    int length1 = int(s1.size());
    int length2 = int(s2.size());
    if (length1 == 0 || length1 == 0) {
        return "0";
    }
    vector<int> number(length1 + length2, 0);
    for (int i = 0; i < length1; ++i) {
        int num1 = int(s1[length1 - 1 - i] - '0');
        int carry = 0;
        for (int j = 0; j < length2; ++j) {
            int num2 = int(s2[length2 - 1 - j] - '0');
            int sum = num1 * num2 + carry + number[i + j];
            number[i + j] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            number[i + length2] += carry;
        }
    }
    int end = length1 + length2 - 1;
    while (number[end] == 0) {
        --end;
    }
    if (end == -1) return "0";
    string result;
    for (int i = end; i >= 0; --i) {
        result.push_back(char(number[i] + '0'));
    }
    return result;
}

vector<int> Substring::FindStartingIndices(string S, set<string> L) {
    vector<int> results;
    if (S.empty() || L.empty() || S.size() < L.begin()->size()) return results;
    int length = int(L.begin()->size());
    int s_length = int(S.size());
    int index = 0, start = 0;
    bool rct = false;
    while (index < s_length - length + 1) {
        if (L.find(S.substr(index, length)) != L.end()) {
            if (!rct) start = index;
            rct = true;
            index += length;
        } else {
            ++index;
            if (rct) {
                rct = false;
                results.push_back(start);
            }
        }
    }
    return results;
}

/* Time complexity: O(n^2) Space complexity: O(n^2) */
vector<vector<int> > PascalTriangle::GeneratePascalTriangle(int num_rows) {
    vector<vector<int> > results;
    if (num_rows == 0) return results;
    results.push_back(vector<int>(1, 1));
    for (int i = 1; i < num_rows; ++i) {
        vector<int> temp(i + 1, 1);
        const vector<int> &result = results[i - 1];
        for (int j = 1; j < i; ++j) {
            temp[j] = result[j - 1] + result[j];
        }
        results.push_back(temp);
    }
    return results;
}

/* Time complexity: O(n^2) Space complexity: O(n) */
vector<int> PascalTriangle::GenerateRow(int num_rows) {
    vector<int> result;
    if (num_rows == 0) return result;
    result.push_back(1);
    for (int i = 1; i < num_rows; ++i) {
        result.insert(result.begin(), 1);
        for (int j = 1; j < i; ++j) {
            result[j] += result[j + 1];
        }
    }
    return result;
}

/* Time complexity: O(n^2) Space complexity: O(n^2) */
vector<int> SpiralMatrix::SpiralOrder(vector<vector<int>> matrix) {
    vector<int> result;
    if (matrix.empty() || matrix[0].size() == 0) return result;
    size_t begin_x = 0, begin_y = 0;
    size_t end_x = matrix.size() - 1, end_y = matrix[0].size() - 1;
    while (true) {
        // four situations
        if (begin_x > end_x || begin_y > end_y) {
            break;
        } else if (begin_x == end_x && begin_y == end_y) {
            result.push_back(matrix[begin_x][begin_y]);
            break;
        } else if (begin_x == end_x){
            for (size_t j = begin_y; j <= end_y; ++j) {
                result.push_back(matrix[begin_x][j]);
            }
            break;
        } else if (begin_y == end_y) {
            for (size_t i = begin_x; i <= end_x; ++i) {
                result.push_back(matrix[i][begin_y]);
            }
            break;
        }
        
        // from left to right
        for (size_t j = begin_y; j <= end_y; ++j) {
            result.push_back(matrix[begin_x][j]);
        }
        // from top to end
        for (size_t i = begin_x + 1; i <= end_x; ++i) {
            result.push_back(matrix[i][end_y]);
        }
        // from right to left
        for (int j = int(end_y - 1); j >= int(begin_y); --j) {
            result.push_back(matrix[end_x][j]);
        }
        // from bottom to top
        for (size_t i = end_x - 1; i > begin_x; --i) {
            result.push_back(matrix[i][begin_y]);
        }
        begin_x += 1;
        begin_y += 1;
        end_x -= 1;
        end_y -= 1;
    }

    return result;
}

/* Time complexity: O(n^2) Space complexity: O(n^2) */
vector<vector<int>> SpiralMatrix::GenerateMatrix(int n) {
    vector<vector<int> > results(n, vector<int>(n, 0));
    if (n == 0) return results;
    int begin_x = 0, begin_y = 0;
    int end_x = n - 1, end_y = n - 1;
    int index = 1;
    while (true) {
        if (begin_x > end_x || begin_y > end_y) {
            break;
        } else if (begin_x == end_x && begin_y == end_y) {
            results[begin_x][begin_y] = index;
            break;
        } else if (begin_x == end_x) {
            for (int j = begin_y; j <= end_y; ++j) {
                results[begin_x][j] = index;
                ++index;
            }
            break;
        } else if (begin_y == end_y) {
            for (int i = begin_x; i <= begin_y; ++i) {
                results[i][begin_y] = index;
                ++index;
            }
            break;
        }
        
        for (int j = begin_y; j <= end_y; ++j) {
            results[begin_x][j] = index;
            ++index;
        }
        for (int i = begin_x + 1; i <= end_x; ++i) {
            results[i][end_y] = index;
            ++index;
        }
        for (int j = end_y - 1; j >= begin_y; --j) {
            results[end_x][j] = index;
            ++index;
        }
        for (int i = end_x - 1; i > begin_x; --i) {
            results[i][begin_y] = index;
            ++index;
        }
        begin_x += 1;
        begin_y += 1;
        end_x -= 1;
        end_y -= 1;
        
    }
    return results;
}


/* Time complexity: O(n) Space complexity: O(n) */
string ZigzagConversion::Conversion(string s, int n) {
    int length = int(s.size());
    if (n <= 1 || length <= 1) return s;
    string result;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, index = i; index < length; ++j, index = (2 * n - 2) * j + i) {
            result.push_back(s[index]);
            if (i == 0 || i == n - 1) continue;
            if (index + (n - i - 1) * 2 < length) {
                result.push_back(s[index + (n - i - 1) * 2]);
            }
        }
    }
    return result;
}

/* Time complexity: O(logn) Space complexity: O(1) */
long long Divide::DivideTwoIntegers(int dividend, int divisor) {
    // if divedend is INT_MIN, then -divident will overflow, so need to use long long
    long long a = dividend >= 0 ? (long long)dividend : -(long long)dividend;
    long long b = divisor >= 0 ? (long long)divisor : -(long long)divisor;
    long long result = 0;
    while (a >= b) {
        long long c = b;
        for (int i = 0; a >= c; ++i, c <<= 1) {
            a -= c;
            result += 1 << i;
        }
    }
    return ((dividend^divisor)>>31) ? (-result) : (result);
}

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
vector<string> TextJustification::function(vector<string> text, int length) {
    int num = int(text.size());
    vector<string> result;
    if (length == 0) return result;
    int len = 0, begin = 0;
    for (int i = 0; i < num; ++i) {
        if (len + int(text[i].size()) + i - begin > length) {
            result.push_back(connect(text, begin, i - 1, len, length, false));
            begin = i;
            len = 0;
        }
        len += int(text[i].size());
    }
    result.push_back(connect(text, begin, num - 1, len, length, true));
    return result;
}

string TextJustification::connect(vector<string> text, int begin, int end,
                                  int len, int length, bool last_line) {
    string result = text[begin];
    if (last_line) {
        for (int i = begin + 1; i <= end; ++i) {
            result += " " + text[i];
        }
        for (int i = 0; i < length - len - (end - begin); ++i) {
            result += " ";
        }
    } else {
        if (begin == end) {
            for (int i = 0; i < length - len; ++i) {
                result += " ";
            }
        } else {
            int basic_gap = (length - len) / (end - begin);
            int add_gap = (length - len) % (end - begin);
            for (int i = begin + 1; i <= begin + add_gap; ++i) {
                for (int j = 0; j < basic_gap + add_gap; ++j) {
                    result += " ";
                }
                result += text[i];
            }
            for (int i = begin + add_gap + 1; i <= end; ++i) {
                for (int j = 0; j < basic_gap; ++j) {
                    result += " ";
                }
                result += text[i];
            }
        }
    
    }
    return result;
}

int MaxPoints::GetMaxPoints(vector<Point> &points) {
    int num = int(points.size());
    if (num <= 2) return num;
    int a = 0, b = 0, c = 0;
    int result = 0;
    for (int i = 0; i < num - 1; ++i) {
        for (int j = i + 1; j < num; ++j) {
            bool sign = false;
            if (points[j].x == points[i].x) {
                sign = true;
            } else {
                a = points[j].x - points[i].x;
                b = points[j].y - points[i].y;
                c = a * points[i].y - b * points[i].x;
            }
            int count = 0;
            for (int k = 0; k < num; ++k) {
                if ((sign && points[k].x == points[i].x) ||
                    (!sign && (a * points[k].y - b * points[k].x) == c)) {
                    ++count;
                }
            }
            result = max(result, count);
        }
    }
    return result;
}

int MaxPoints::GetMaxPointsTwo(vector<Point> &points) {
    int num = int(points.size());
    if (num <= 2) return num;
    int result = 0;
    unordered_map<double, int> slope_count;
    for (int i = 0; i < num; ++i) {
        int points_max = 1; // 与i同线最大点数
        int point_num = 0;  // 与i垂直做大点数
        int same_point_num = 0; // 与i重合点数
        int slope = 0;
        slope_count.clear();
        for (int j = i + 1; j < num; ++j) {
            if (points[i].x == points[j].x) {
                if (points[i].y == points[j].y) {
                    ++same_point_num;
                } else {
                    ++point_num;
                }
                continue;
            } else {
                slope = (points[j].y - points[i].y) / (points[j].x - points[i].x);
                if (slope_count.find(slope) != slope_count.end()) {
                    ++slope_count[slope];
                } else {
                    slope_count[slope] = 2;
                }
                if (points_max < slope_count[slope]) {
                    points_max = slope_count[slope];
                }
            }
        }
        result = max(result, (points_max > point_num ? points_max : point_num) + same_point_num);
    }
    return result;
}















