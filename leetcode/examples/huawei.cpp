//
//  huawei.cpp
//  leetcode
//
//  Created by NoteFAN on 8/19/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int cal(vector<vector<char> > &matrix, int x, int y, int row, int column) {
    int result = 0;
    int rows = 0, columns = column;
    for (int i = x; i < row; ++i) {
        if (matrix[i][y] == '0') break;
        ++rows;
        int temp = 0;
        for (int j = y; j < column; ++j) {
            if (matrix[i][j] == '1') {
                ++temp;
            } else {
                columns = min(columns, temp);
                result = max(result, columns * rows);
                break;
            }
        }
    }
    return result;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    int row = int(matrix.size());
    if (row == 0) return 0;
    int column = int(matrix[0].size());
    int result = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (matrix[i][j] == '1') {
                int temp = cal(matrix, i, j, row, column);
                result = max(result, temp);
            }
        }
    }
    return result;
}



int main() {

    
  /*
    vector<vector<char>> data(1, vector<char>(1, '1'));
    int result = maximalRectangle(data);
    cout << result << endl;
   */
    return 0;
}



// operation: false - no delete / true - delete
int Distance(string s1, string s2, bool operation) {
    int result = 0;
    int length1 = int(s1.size());
    int length2 = int(s2.size());
    if (length1 == 0) {
        result = length2 + 2;
        return result;
    }
    if (s1[0] == s2[0]) {
        // delete
        if (operation) {
            result =  min(Distance(s1.substr(1, length1 - 1), s2, true),
                          Distance(s1.substr(1, length1 - 1), s2.substr(1, length2 - 1), false));
            
        } else {
            result = min(Distance(s1.substr(1, length1 - 1), s2, true),
                         Distance(s1.substr(1, length1 - 1), s2.substr(1, length2 - 1), false)) + 2;

        }
    } else {
        if (operation) {
            result = Distance(s1.substr(1, length1 - 1), s2, true);
        } else {
            result = Distance(s1.substr(1, length1 - 1), s2, true) + 2;
        }
    }
    return result;
}


int test3() {
    int T;
    cin >> T;
    vector<string> data;
    for (int i = 0; i < 2 * T; ++i) {
        string element;
        cin >> element;
        data.push_back(element);
    }
    for (int i = 0; i < T; ++i) {
        cout << Distance(data[2 * i], data[2 * i + 1], false) << endl;
    }
    
    return 0;
}

























int test0() {
    string s;
    while (cin >> s) {
        int result = 0;
        int length = int(s.size());
        for (int i = 0; i < length; ++i) {
            if (s[i] == 'A') {
                break;
            } else if (s[i] == '(') {
                ++result;
            } else {
                --result;
            }
        }
        cout << result <<endl;
    }
    return 0;
}






int test() {
    // insert code here...
    int m;
    int left_sum = 0, right_sum = 0;
    vector<int> things(10, 0);
    
    while (cin >> things[0] >> things[1] >> things[2] >> things[3] >> things[4] >> \
           things[5] >> things[6] >> things[7] >> things[8] >> things[9]) {
        cin >> m;
        vector<int> elements;
        for (int i = 10 - m; i < 10; ++i) {
            elements.push_back(things[i]);
        }
        for (int i = 0; i < 10 - m; ++i) {
            elements.push_back(things[i]);
        }
        for (int i = 0; i < m; ++i) {
            left_sum += elements[i];
        }
        for (int i = 10 - m; i < 10; ++i) {
            right_sum += elements[i];
        }
        for (int i = 0; i < 10; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
        cout << left_sum << " " << right_sum << endl;
    }
    
    return 0;
}


bool CompareDiff(string s1, string s2) {
    int length = int(s1.size());
    int length1 = int(s2.size());
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length1; ++j) {
            if (s1[i] == s2[j]) {
                return false;
            }
        }
    }
    return true;
}

bool CompareSame(string s1, string s2) {
    int length = int(s1.size());
    int length1 = int(s2.size());
    if (length == length1) {
        for (int i = 0; i < length; ++i) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int test1() {
    int T;
    cin >> T;
    vector<string> data;
    for (int i = 0; i < 2 * T; ++i) {
        string element;
        cin >> element;
        data.push_back(element);
    }
    for (int i = 0; i < T; ++i) {
        int result = 3000;
        if (CompareDiff(data[2 * i], data[2 * i + 1])) {
            int length = int(data[2 * i + 1].size());
            cout << length + 4 << endl;
            continue;
        } else if (CompareSame(data[2 * i], data[2 * i + 1])) {
            cout << 0 << endl;
        } else {
            int length1 = int(data[2 * i].size());
            int length2 = int(data[2 * i + 1].size());
            result = min(length2 + 4, result);
            for (int i = 1; i < min(length1, length2); ++i) {
                if (data[2 * i][length1 - i] == data[2 * i + 1][i - 1]) {
                    result = min(length2 - i + 4, result);
                } else {
                    break;
                }
            }
            cout << result << endl;
        }
        
    }
    
    return 0;
}
















vector<int> function_one() {
    int N, element;
    cin >> N;
    vector<int> things;
    
    for (int i = 0; i < N; ++i) {
        cin >> element;
        things.push_back(element);
    }
    return things;
}