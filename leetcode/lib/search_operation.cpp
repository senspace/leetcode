//
//  search_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 6/1/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include "search_operation.h"

using namespace std;

/* 二分法(STL): Time complexity: O(logn) Space complexity: O(1) */
vector<int> SearchForRange::SearchRangeOne(vector<int> &num, int target) {
    vector<int>::iterator left = lower_bound(num.begin(), num.end(), target);
    // not found
    if (*left != target) {
        return vector<int> {-1, -1};
    }
    vector<int>::iterator right = upper_bound(num.begin(), num.end(), target);
    vector<int> result;
    result.push_back(int(left - num.begin()));
    result.push_back(int(right - num.begin()) - 1);
    return result;
}

/* 二分法: Time complexity: O(logn) Space complexity: O(1) */
vector<int> SearchForRange::SearchRangeTwo(vector<int> &num, int target) {
    vector<int>::iterator left = get_lower_bound(num.begin(), num.end(), target);
    if (*left != target) {
        return vector<int> {-1, -1};
    }
    vector<int>::iterator right = get_upper_bound(num.begin(), num.end(), target);
    return vector<int> {int(distance(num.begin(), left)),
                        int(distance(num.begin(), prev(right)))};
}

/* Time complexity: O(log(m*n)) Space complexity: O(1) */
bool SearchMatrix::Search2DMatrix(vector<vector<int>> &num, int target) {
    size_t row = num.size();
    size_t column = num.front().size();
    size_t first = 0, last = row * column;
    while (first < last) {
        size_t middle = first + (last - first) / 2;
        int value = num.at(middle / column).at(middle % column);
        if (value == target) {
            return true;
        } else if (value < target) {
            first = ++middle;
        } else {
            last = middle;
        }
    }
    return false;
}

/* 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n) */
vector<vector<int>> Subsets::FindSubsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> results;
    vector<int> path;
    results.push_back(path);
    FindSubsets(S, path, 0, results);
    return results;
}

void Subsets::FindSubsets(vector<int> &S, vector<int> &path, size_t step,
                          vector<vector<int>> &results) {
    for (size_t i = step; i < S.size(); ++i) {
        path.push_back(S.at(i));
        results.push_back(path);
        FindSubsets(S, path, i + 1, results);
        path.pop_back();
    }
}

/* 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n) */
vector<vector<int>> Subsets::FindSubsetsOne(vector<int> &S) {
    vector<vector<int>> results;
    sort(S.begin(), S.end());
    unsigned long long max_num = pow(2, S.size()) - 1;
    for (int num = 0; num <= max_num; ++num) {
        results.push_back(FindSubsetsOne(S, num));
    }
    return results;
}

vector<int> Subsets::FindSubsetsOne(vector<int> &S, unsigned long long num) {
    vector<int> path;
    int index = 0;
    while (num) {
        if (num & 0x01) {
            path.push_back(S[index]);
        }
        num = num >> 1;
        ++index;
    }
    return path;
}

/*
 * Iteratively
 * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n)
 */
vector<vector<int>> Subsets::FindSubsetsTwo(vector<int> &S) {
    vector<vector<int>> results;
    vector<int> path;
    results.push_back(path);
    sort(S.begin(), S.end());
    for (size_t i  = 0; i < S.size(); ++i) {
        size_t length = results.size();
        for (size_t j = 0; j < length; ++j) {
            path = results[j];
            path.push_back(S[i]);
            results.push_back(path);
        }
    }
    return results;
}

/*
 * Iteratively
 * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
 * Note: 集合的元素不超过 unsigned long long 位数
 */
vector<vector<int>> Subsets::FindSubsetsThree(vector<int> &S) {
    vector<vector<int>> results;
    vector<int> path;
    int index = 0;
    unsigned long long max_num = pow(2, S.size()) - 1;
    for (size_t i = 0; i <= max_num; ++i) {
        size_t num = i;
        path.clear();
        index = 0;
        while (num) {
            if (num & 0x01) {
                path.push_back(S[index]);
            }
            num = num >> 1;
            ++index;
        }
        results.push_back(path);
    }
    return results;
}

/*
 * Recursively
 * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n)
 */
vector<vector<int>> SubsetsII::FindSubsets(vector<int> &S) {
    vector<vector<int>> results;
    vector<int> path;
    results.push_back(path);
    sort(S.begin(), S.end());
    FindSubsetsWithDuplicates(S, 0, path, results);
    return results;
}

void SubsetsII::FindSubsetsWithDuplicates(vector<int> &S, size_t start,
                                          vector<int> &path,
                                          vector<vector<int>> &subsets) {
    for (size_t index = start; index < S.size(); ++index) {
        if (index > start && S[index] == S[index - 1]) {
            continue;
        }
        path.push_back(S[index]);
        subsets.push_back(path);
        FindSubsetsWithDuplicates(S, index + 1, path, subsets);
        path.pop_back();
    }
}

/*
 * Recursively
 * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
 */
vector<vector<int>> SubsetsII::FindSubsetsOne(vector<int> &S) {
    vector<vector<int>> results;
    set<vector<int>> subsets;
    unsigned long long max_num = pow(2, S.size()) - 1;
    for (unsigned long long num = 0; num <= max_num; ++num) {
        subsets.insert(FindSubsetsOne(S, num));
    }
    copy(subsets.begin(), subsets.end(), back_inserter(results));
    return results;
}

vector<int> SubsetsII::FindSubsetsOne(vector<int> &S, unsigned long long num) {
    vector<int> path;
    for (size_t i = 0; i < S.size(); ++i) {
        if (num & 1 << i) {
            path.push_back(S[i]);
        }
    }
    return path;
}

/*
 * Iteratively
 * 增量构造法/深搜 Time complexity: O(2^n) Space complexity: O(n)
 */
vector<vector<int>> SubsetsII::FindSubsetsTwo(vector<int> &S) {
    vector<vector<int>> results(1);
    sort(S.begin(), S.end());
    for (size_t index = 0; index < S.size(); ++index) {
        size_t length = results.size();
        for (size_t j = 0; j < length; ++j) {
            if (index == 0 || S[index] != S[index - 1] || j >= length / 2) {
                results.push_back(results[j]);
                results.back().push_back(S[index]);
            }
        }
    }
    return results;
}

/*
 * Iteratively
 * 位向量法/深搜 Time complexity: O(2^n) Space complexity: O(n)
 */
vector<vector<int>> SubsetsII::FindSubsetsThree(vector<int> &S) {
    vector<vector<int>> results;
    vector<int> path;
    // use set to remove duplicates
    set<vector<int>> subsets;
    for (size_t i = 0; i < 1U << S.size(); ++i) {
        for (size_t j = 0; j < S.size(); ++j) {
            if (i & 1 << j) {
                path.push_back(S[j]);
            }
        }
        subsets.insert(path);
        path.clear();
    }
    copy(subsets.begin(), subsets.end(), back_inserter(results));

    return results;
}

/*
 * using function: "next_permutation"
 * Time complexity: O(n!) Space complexity: O(1)
 */
vector<vector<int>> Permutations::GetPermutations(vector<int> &num) {
    vector<vector<int>> results;
    sort(num.begin(), num.end());
    do {
        results.push_back(num);
    
    } while (next_permutation(num.begin(), num.end()));
    return results;
}

/*
 * Iteratively 深搜,增量构造法
 * Time complexity: O(n!) Space complexity: O(1)
 */
vector<vector<int>> Permutations::GetPermutationsOne(vector<int> &num) {
    vector<vector<int>> results;
    if (num.empty()) {
        return results;
    }
    results.push_back(vector<int>(1, num[0]));
    for (size_t i = 1; i < num.size(); ++i) {
        size_t length = results.size();
        for (size_t j = 0; j < length; ++j) {
            for (size_t index = 0; index < results[j].size(); ++index) {
                vector<int> path = results[j];
                path.insert(path.begin() + index, num[i]);
                results.push_back(path);
            }
            results[j].push_back(num[i]);
        }
    }
    return results;
}

/*
 * Recursively 深搜,增量构造法
 * Time complexity: O(n!) Space complexity: O(1)
 */
vector<vector<int>> Permutations::GetPermutationsTwo(vector<int> &num) {
    vector<vector<int>> results;
    if (num.empty()) {
        return results;
    }
    vector<int> path;
    vector<bool> used(num.size(), false);
    FindPermutations(num, used, path, results);
    return results;
}

void Permutations::FindPermutations(vector<int> &num, vector<bool> used,
                                    vector<int> &path,
                                    vector<vector<int>> &results) {
    if (path.size() == num.size()) {
        results.push_back(path);
        return;
    }
    for (size_t i = 0; i < num.size(); ++i) {
        if (used[i]) continue;
        path.push_back(num[i]);
        used[i] = true;
        FindPermutations(num, used, path, results);
        used[i] = false;
        path.pop_back();
    }
}

/*
 * Using function: "next_permutations"
 * Time complexity: O(n!) Space complexity: O(1)
 */
vector<vector<int>> PermutationsII::GetPermutations(vector<int> &num) {
    vector<vector<int>> results;
    sort(num.begin(), num.end());
    do {
        results.push_back(num);
    } while (next_permutation(num.begin(), num.end()));
    return results;
}

/*
 * using set to remove duplicates
 * Time complexity: O(n!) Space complexity: O(1)
 */
vector<vector<int>> PermutationsII::GetPermutationsOne(vector<int> &num) {
    vector<vector<int>> results;
    if (num.empty()) {
        return results;
    }
    
    results.push_back(vector<int>(1, num[0]));
    sort(num.begin(), num.end());
    for (size_t i = 1; i < num.size(); ++i) {
        size_t length = results.size();
        for (size_t j = 0; j < length; ++j) {
            for (size_t index = 0; index < results[j].size(); ++index) {
                vector<int> path = results[j];
                path.insert(path.begin() + index, num[i]);
                results.push_back(path);
            }
            results[j].push_back(num[i]);
        }
    }

    set<vector<int>> permutations;
    for (vector<vector<int>>::iterator it = results.begin(); it != results.end(); ++it) {
        permutations.insert(*it);
    }
    results.clear();
    copy(permutations.begin(), permutations.end(), back_inserter(results));

    return results;
}

/*
 * Recursively 深搜,增量构造法
 * Time complexity: O(n!) Space complexity: O(1)
 */
vector<vector<int>> PermutationsII::GetPermutationsTwo(vector<int> &num) {
    vector<vector<int>> results;
    vector<int> path;
    vector<bool> used = vector<bool>(num.size(), false);
    sort(num.begin(), num.end());
    FindPermutations(num, used, path, results);
    return results;
}

void PermutationsII::FindPermutations(vector<int> &num, vector<bool> used,
                                      vector<int> &path,
                                      vector<vector<int>> &results) {
    if (path.size() == num.size()) {
        results.push_back(path);
        return;
    }
    for (size_t i = 0; i < num.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && num[i] == num[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        path.push_back(num[i]);
        FindPermutations(num, used, path, results);
        used[i] = false;
        path.pop_back();
    }
}

/*
 * Recursively
 * Time complexity: O(n!) Space complexity: O(n)
 */
vector<vector<int>> Combinations::GetCombinations(int n, int k) {
    vector<vector<int>> results;
    vector<int> path;
    FindCombinations(n, 1, k, path, results);
    return results;
}

void Combinations::FindCombinations(int n, int start, int k, vector<int> &path, vector<vector<int>> &results) {
    if (k == 0) {
        results.push_back(path);
        return;
    }
    for (int i = start; i <= n - k + 1; ++i) {
        path.push_back(i);
        FindCombinations(n, i + 1, k - 1, path, results);
        path.pop_back();
    }
}

/*
 * Iteratively: 
 * Time complexity: O((n-k)!) Space complexity: O(n)
 */
vector<vector<int>> Combinations::GetCombinationsOne(int n, int k) {
    vector<vector<int>> results;
    vector<int> values(n);
    iota(values.begin(), values.end(), 1);
    vector<bool> select(n, false);
    fill_n(select.begin(), k, true);
    do {
        vector<int> path;
        for (int i = 0; i < n; ++i) {
            if (select[i]) {
                path.push_back(values[i]);
            }
        }
        results.push_back(path);
    }while (prev_permutation(select.begin(), select.end()));

    return results;
}

/*
 * Recursively
 * Time complexity: O(3^n) Space complexity: O(n)
 */
vector<string> LetterCombinationsOfPhoneNumber::LetterCombinationsOne(string digits) {
    vector<string> letter_combinations;
    string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string combinations(digits.size(), '\0');
    FindLetterCombinations(digits, 0, dict, combinations, letter_combinations);
    return letter_combinations;
}

void LetterCombinationsOfPhoneNumber::FindLetterCombinations(
                                    string &digits, int index, string dict[],
                                    string &combinations,
                                    vector<string> &letter_combinations) {
    if (index == digits.size()) {
        letter_combinations.push_back(combinations);
        return;
    }
    
    string letters = dict[digits[index] - '0'];
    for (size_t i = 0; i < letters.size(); ++i) {
        combinations[index] = letters[i];
        FindLetterCombinations(digits, index + 1, dict,
                               combinations, letter_combinations);
    }
}

/*
 * Iteratively
 * Time complexity: O(3^n) Space complexity: O(1)
 */
vector<string> LetterCombinationsOfPhoneNumber::LetterCombinationsTwo(string digits) {
    vector<string> letter_combinations;
    string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letter_combinations.push_back("");
    for (size_t i = 0; i < digits.size(); ++i) {
        size_t length = letter_combinations.size();
        string letter = dict[digits[i] - '0'];
        for (size_t index = 0; index < length; ++index) {
            for (size_t j = 1; j < letter.size(); ++j) {
                string combination = letter_combinations[index];
                combination.push_back(letter[j]);
                letter_combinations.push_back(combination);
            }
            letter_combinations[index].push_back(letter[0]);
        }
    }
    return letter_combinations;
}

/***********************************广度优先搜索*********************************/
int WordLadder::WordLadderLength(string start, string end,
                                 unordered_set<string> &dict) {
    dict.insert(end);
    queue<pair<string, int>> path;
    path.push(make_pair(start, 1));
    while (!path.empty()) {
        string word = path.front().first;
        int step = path.front().second;
        if (word == end) {
            return step;
        }
        path.pop();
        vector<string> neighbors = FindNeighbors(word, dict);
        for (vector<string>::iterator it = neighbors.begin();
             it != neighbors.end(); ++it) {
            path.push(make_pair(*it, step + 1));
        }
    }
    return 0;
}

/* 
 * 遍历当前单词的每个字符x，将其改变成a~z中除x外的任意一个，形成一个新的单词，在字典
 * 中判断是否存在。复杂度为：26*w，w为单词长度。
 */
vector<string> WordLadder::FindNeighbors(string s, unordered_set<string> &dict) {
    vector<string> neighbors;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        for (size_t j = 0; j < 26; ++j) {
            if (c == 'a' + j) continue;
            s[i] = 'a' + j;
            if (dict.find(s) != dict.end()) {
                neighbors.push_back(s);
                dict.erase(s);
            }
        }
        s[i] = c;
    }
    return neighbors;
}

/* Time complexity: O(n) Space complexity: O(n) */
vector<vector<string>> WordLadder::WordLadderLengthII(string start, string end,
                                                      unordered_set<string> &dict) {
    vector<vector<string>> pathes;
    pathes.clear();
    dict.insert(start);
    dict.insert(end);
    vector<string> prev;
    unordered_map<string, vector<string>> traces;
    for (unordered_set<string>::const_iterator it = dict.begin(); it != dict.end(); ++it) {
        traces[*it] = prev;
    }
    vector<unordered_set<string>> layers(2);
    int cur = 0;
    int pre = 1;
    layers[cur].insert(start);
    while (true) {
        cur = !cur;
        pre = !pre;
        for (unordered_set<string>::const_iterator it = layers[pre].begin();
             it != layers[pre].end(); ++it) {
            dict.erase(*it);
        }
        layers[cur].clear();
        for (unordered_set<string>::const_iterator it = layers[pre].begin();
             it != layers[pre].end(); ++it) {
            for (int index = 0; index < it->size(); ++index) {
                string word = *it;
                for (int i = 0; i < 26; ++i) {
                    if ('a' + i == (*it).at(index)) continue;
                    word[index] = 'a' + i;
                    if (dict.find(word) != dict.end()) {
                        traces[word].push_back(*it);
                        layers[cur].insert(word);
                    }
                }
            }
        }
        if (layers[cur].size() == 0) {
            return pathes;
        }
        if (layers[cur].find(end) != layers[cur].end()) {
            break;
        }
        
    }
    vector<string> path;
    BuildPath(traces, pathes, path, end);
    return pathes;
}

void WordLadder::BuildPath(unordered_map<string, vector<string>> &traces,
                           vector<vector<string>> &pathes,
                           vector<string> &path, string &end) {
    if (traces[end].empty()) {
        path.push_back(end);
        vector<string> current_path = path;
        reverse(current_path.begin(), current_path.end());
        pathes.push_back(current_path);
        path.pop_back();
        return;
    }
    
    path.push_back(end);
    vector<string> words = traces[end];
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
        BuildPath(traces, pathes, path, *it);
    }
    path.pop_back();
}

/*
 * BFS, Time complexity: O(n) Space complexity: O(n)
 * Solution:
 * 连通区域必须至少一个元素是在四边，那么一开始直接从四边开始扫描就好了，所以无法connect到
 * 得元素都是应该被清除的。所以，算法如下：
 * 1. 从四条边上的O元素开始BFS，所有相连的O都赋个新值，比如‘Y’
 * 2. 扫描整个数组，所有现存的O元素全部置为X，所有Y元素置为O
 */
void SurroundedRegions::Regions(vector<vector<char>> &board) {
    if (board.empty()) return;
    size_t row = board.size();
    size_t column = board[0].size();
    for (size_t i = 0; i < row; ++i) {
        dfs(board, i, 0);
        dfs(board, i, column - 1);
    }
    for (size_t j = 0; j < column; ++j) {
        dfs(board, 0, j);
        dfs(board, row - 1, j);
    }
    // traverse the board
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'R') {
                board[i][j] = 'O';
            }
        }
    }
}

void SurroundedRegions::dfs(vector<vector<char>> &board, size_t row, size_t column) {
    queue<pair<size_t, size_t>> q;
    if (board[row][column] == 'O') {
        q.push(make_pair(row, column));
    }
    while (!q.empty()) {
        pair<size_t, size_t> element = q.front();
        q.pop();
        size_t i = element.first;
        size_t j = element.second;
        board[i][j] = 'R';
        // check the element around
        if (j > 0 && board[i][j - 1] == 'O') {
            q.push(make_pair(i, j - 1));
            board[i][j - 1] = 'R';
        }
        if (j < (board[0].size() - 1)  && board[i][j + 1] == 'O') {
            q.push(make_pair(i, j + 1));
            board[i][j + 1] = 'R';
        }
        if (i > 0 && board[i - 1][j] == 'O') {
            q.push(make_pair(i - 1, j));
            board[i - 1][j] = 'R';
        }
        if (i < (board.size() - 1) && board[i + 1][j] == 'O') {
            q.push(make_pair(i + 1, j));
            board[i + 1][j] = 'R';
        }
    }
}

/***********************************深度优先搜索*********************************/
/* Time complexity: O(2^n) Space complexity: O(n) */
vector<vector<string>> PalindromePartitioning::Partition(string s) {
    vector<vector<string>> palindromes;
    vector<string> palindrome;
    if (s.empty()) return palindromes;
    int end = int(s.size()) - 1;
    DFS(s, palindromes, palindrome, 0, end);
    return palindromes;
}

bool PalindromePartitioning::IsPalindrome(string s, int start, int end) {
    while (start < end && s[start] == s[end]) {
        ++start;
        --end;
    }
    return (start >= end);
}

void PalindromePartitioning::DFS(string s, vector<vector<string>> &palindromes,
                                 vector<string> &palindrome,
                                 int start, int end) {
    if (start > end) {
        palindromes.push_back(palindrome);
        return;
    }
    
    for (int i = start; i <= end; ++i) {
        if (IsPalindrome(s, start, i)) {
            palindrome.push_back(s.substr(start, i - start + 1));
            DFS(s, palindromes, palindrome, i + 1, end);
            palindrome.pop_back();
        }
    }
}

/*
 * Dynamic programming
 * Time complexity: O(n^2) Space complexity: O(n^2)
 */
vector<vector<string>> PalindromePartitioning::PartitionDynamic(string s) {
    int length = int(s.size());
    vector<vector<bool>> sign(length, vector<bool>(length, false));
    // check palindrome
    for (int i = length - 1; i >= 0; --i) {
        for (int j = i; j < length; ++j) {
            sign[i][j] = (s[i] == s[j] && (i > j - 2 || sign[i + 1][j - 1]));
        }
    }
    // get palindrome partitions
    // partition s[i, n - 1] such that every substring of partition is a palindrome.
    vector<vector<vector<string>>> palindromes(length);
    for (int i = length - 1; i >= 0; --i) {
        for (int j = i; j < length; ++j) {
            if (sign[i][j]) {
                string substring = s.substr(i, j - i + 1);
                if (j + 1 < length) {
                    for (vector<vector<string>>::iterator it = palindromes[j + 1].begin();
                         it != palindromes[j + 1].end(); ++it) {
                        vector<string> temp_substring = *it;
                        temp_substring.insert(temp_substring.begin(), substring);
                        palindromes[i].push_back(temp_substring);
                    }
                } else {
                    palindromes[i].push_back(vector<string>{substring});
                }
            }
        }
    }
    return palindromes[0];
}

/*
 * DFS
 * Time complexity: O(n^4) Space complexity: O(n)
 */
int UniquePaths::UniquePathsOne(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    return UniquePathsOne(m - 1, n) + UniquePathsOne(m, n - 1);
}

/*
 * DFS + 缓存
 * Time complexity: O(n^2) Space complexity: O(n^2)
 */
int UniquePaths::UniquePathsTwo(int m, int n) {
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));
    return dfs(m, n);
}

/*
 * DP(Dynamic Programming)
 * Solution:
 *  dp[i][j]表示从起点到位置(i, j)的路径总数。DP题目定义好状态后，接下去有两个任务：
 * 找通项公式，以及确定计算的方向。
 *  1. 由于只能向右和左走，所以对于(i, j)来说，只能从左边或上边的格子走下来：
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *  2. 对于网格最上边和最左边，则只能从起点出发直线走到，dp[0][j] = dp[i][0] = 1
 *  3. 计算方向从上到下，从左到右即可。可以用滚动数组实现。
 * Time complexity: O(n * m) Space complexity: O(n)
 */
int UniquePaths::UniquePathsThree(int m, int n) {
    if (m < 1 || n < 1) return 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1] + dp[j];
        }
    }
    return dp[n - 1];
}

/*
 * A mathematical formula
 * Solution：
 * 一个 m 行,n 列的矩阵,机器人从左上走到右下总共需要的步数是 m + n − 2,其中向下走的
 * 步数是 m − 1,因此问题变成了在 m + n − 2 个操作中,选择 m–1 个时间点向下走,选择方式
 * 有多少种, 即C_m+n−2^m-1
 * Time complexity: O(n * m) Space complexity: O(n)
 */
int UniquePaths::UniquePathsFour(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    return factor(m + n - 2, min(m - 1, n - 1));
}

int UniquePaths::factor(int n, int k) {
    long long int ret = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        ret *= i;
    }
    for (int i = 1; i <= k; ++i) {
        ret /= i;
    }
    return int(ret);
}

/*
 * DP(Dynamic Programming)
 * Time complexity: O(n * m) Space complexity: O(n)
 */
int UniquePathsII::UniquePaths(vector<vector<bool>> &obstacles_grids) {
    int row = int(obstacles_grids.size());
    int column = int(obstacles_grids.front().size());
    if (row == 0 || column == 0 || obstacles_grids[0][0]) return 0;
    vector<int> pathes(obstacles_grids.front().size(), 0);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (i != 0 && j != 0) {
                if (obstacles_grids[i][j]) {
                    pathes[j] = 0;
                } else {
                    pathes[j] += pathes[j - 1];
                }
            } else if (i == 0 && j == 0) {
                pathes[j] = 1;
            } else if(i == 0) {
                if (obstacles_grids[i][j]) {
                    pathes[j] = 0;
                } else {
                    pathes[j] = pathes[j - 1];
                }
            } else if(j == 0) {
                if (obstacles_grids[i][j]) {
                    pathes[j] = 0;
                } else {
                    pathes[j] = pathes[j];
                }
            }
        }
    }
    return pathes[column - 1];
}

/*
 * DFS + 剪枝: Get all distinct N-Queen solutions
 * @param n: The number of queens
 * @return: All distinct solutions
 * For example, A string '...Q' shows a queen on forth position
 */
vector<vector<string>> NQueens::SolveNQueens(int n) {
    // 每行皇后占据的列
    vector<int> columns;
    vector<vector<string>> results;
    dfs(results, columns, n);
    return results;
}

bool NQueens::IsValid(vector<int> columns, int column) {
    int row = int(columns.size());
    for (int i = 0; i < row; ++i) {
        // same column
        if (columns.at(i) == column) {
            return false;
        }
        // main diagonal: left-top to right-bottom
        if (columns.at(i) + row - i == column) {
            return false;
        }
        //deputy diagonal: right-top to left-bottom
        if (columns.at(i) - (row - i) == column) {
            return false;
        }
    }
    return true;
}

vector<string> NQueens::DrawChessBoard(vector<int> columns) {
    vector<string> result;
    for (int i = 0; i < int(columns.size()); ++i) {
        result.push_back("");
        for (int j = 0; j < int(columns.size()); ++j) {
            if (j != columns[i]) {
                result[i].push_back('.');
            } else {
                result[i].push_back('Q');
            }
        }
    }
    return result;
}

void NQueens::dfs(vector<vector<string>> &results,
                  vector<int> &columns, int n) {
    if (columns.size() == n) {
        results.push_back(DrawChessBoard(columns));
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!IsValid(columns, i)) {
            continue;
        }
        columns.push_back(i);
        dfs(results, columns, n);
        columns.pop_back();
    }
}

/* Time complexity: O(n^4) Space complexity: O(n) */
vector<string> RestoreAddresses::RestoreIPAddress(string s) {
    vector<string> results;
    vector<string> result;
    if (s.empty()) return results;
    dfs(results, result, s, 0);
    return results;
}

void RestoreAddresses::dfs(vector<string> &results, vector<string> &result,
                           string s, int start) {
    int length = int(s.size());
    if (result.size() == 4 && start == length) {
        results.push_back(result[0] + '.' + result[1] + '.' + result[2] + '.' + result[3]);
        return;
    } else if (result.size() == 4 || start == length) {
        return;
    }
    
    int num = 0;
    for (int i = start; i < length; ++i) {
        num = 10 * num + s[i] - '0';
        // to eliminate cases like "00", "01"(不允许前缀为零，但允许单个零）
        // and which is not between 0 and 255
        if (num > 255 || (s[start] == '0' && i != start)) return;
        result.push_back(s.substr(start, i - start + 1));
        dfs(results, result, s, i + 1);
        result.pop_back();
    }
}

vector<vector<int>> CombinationsSum::FindCombinations(vector<int> nums, int target) {
    vector<vector<int>> results;
    vector<int> result;
    sort(nums.begin(), nums.end());
    dfs(results, result, nums, 0, target);
    return results;
}

void CombinationsSum::dfs(vector<vector<int>> &results, vector<int> &result,
                          vector<int> nums, int start, int target) {
    if (target == 0) {
        results.push_back(result);
        return;
    }
    for (int i = start; i < int(nums.size()); ++i) {
        if (nums.at(i) > target) return;
        result.push_back(nums.at(i));
        dfs(results, result, nums, i, target - nums.at(i));
        result.pop_back();
    }

}

vector<vector<int>> CombinationsSum::FindCombinationsII(vector<int> nums, int target) {
    vector<vector<int>> results;
    vector<int> result;
    sort(nums.begin(), nums.end());
    dfsII(results, result, nums, 0, target);
    return results;
}

void CombinationsSum::dfsII(vector<vector<int>> &results, vector<int> &result,
                            vector<int> nums, int start, int target) {
    if (target == 0) {
        results.push_back(result);
        return;
    }
    int previous = -1;
    for (int i = start; i < int(nums.size()); ++i) {
        if (nums.at(i) > target) return;
        // 相邻元素相同时，确保只用一次，去掉重复
        if (previous == nums[i]) {
            continue;
        }
        previous = nums[i];
        result.push_back(nums.at(i));
        dfsII(results, result, nums, i + 1, target - nums.at(i));
        result.pop_back();
    }
    
}

vector<string> GenerateParentheses::Parentheses(int n) {
    vector<string> results;
    string result;
    dfs(n, 0, 0, results, result);
    return results;
}

void GenerateParentheses::dfs(int n, int left, int right,
                              vector<string> &results,
                              string result) {
    if (left == n) {
        results.push_back(result.append(n - right, ')'));
        return;
    }
    
    dfs(n, left + 1, right, results, result + '(');
    if (left > right) {
        dfs(n, left, right + 1, results, result + ')');
    }
}

/* Time complexity: O(9^4) Space complexity: O(1) */
bool SudokuSolver::SolveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                for (int k = 0; k < 9; ++k) {
                    board[i][j] = k + '1';
                    if (IsValid(board, i, j) && SolveSudoku(board)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
    }
    return true;
}


bool SudokuSolver::IsValid(vector<vector<char>> &board, int x, int y) {
    // check row
    for (int i = 0; i < 9; ++i) {
        if (i != y && board[x][i] == board[x][y]) {
            return false;
        }
    }
    // check column
    for (int i = 0; i < 9; ++i) {
        if (i != x && board[i][y] == board[x][y]) {
            return false;
        }
    }
    // check 9*9 board
    for (int i = x / 3 * 3; i < (x / 3 + 1) * 3; ++i) {
        for (int j = y / 3 * 3; j < (y / 3 + 1) * 3; ++j) {
            if ((i != x || j != y) && board[i][j] == board[x][y]) {
                return false;
            }
        }
    }
    return true;
}

bool WordSearch::ExistWord(vector<vector<char> > board, string word) {
    int row = int(board.size());
    int column = int(board[0].size());
    vector<vector<bool> > visited(row, vector<bool>(column, false));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
           if(dfs(board, word, 0, i, j, visited)) return true;
        }
    }
    return false;
}


bool WordSearch::dfs(vector<vector<char> > board, string word,
                     int index, int x, int y, vector<vector<bool> > &visited) {
    if (index == word.size()) {
        return true;
    }
    // 剪枝
    if (x < 0 || x >= board.size()) return false;    // 越界
    if (y < 0 || y >= board[x].size()) return false;     // 越界
    if (visited[x][y] || board[x][y] != word[index]) return false;  // 已访问或不等
    
    visited[x][y] = true;
    bool ret = dfs(board, word, index + 1, x - 1, y, visited) ||    // up
            dfs(board, word, index + 1, x + 1, y, visited) ||   // down
            dfs(board, word, index + 1, x, y - 1, visited) ||   // left
            dfs(board, word, index + 1, x, y + 1, visited);     // right
    visited[x][y] = false;
    
    return ret;
}

















