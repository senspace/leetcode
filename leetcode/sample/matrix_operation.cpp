//
//  matrix_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 4/21/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "matrix_operation.h"

using namespace std;

// one: 顺时针旋转90度
void ImageOperation::image_one(vector<vector<int>> &matrix) {
    // 首先沿着水平中线翻转一次,然后沿着主对角线翻转一次
    vector<vector<int>> matrix_temp;
    vector<int> line;
    image_three(matrix);
    for (int j = 0; j < matrix[0].size(); ++j) {
        line.clear();
        for(int i = 0; i < matrix.size(); ++i) {
            line.push_back(matrix[i][j]);
        }
        matrix_temp.push_back(line);
    }
    matrix.clear();
    for(int i = 0; i < matrix_temp.size(); ++i) {
        matrix.push_back(matrix_temp[i]);
    }
}
// two: 逆时针旋转90度
void ImageOperation::image_two(vector<vector<int>> &matrix) {
    // 首先沿着水平中线翻转一次,然后沿着负对角线翻转一次
    vector<vector<int>> matrix_temp;
    vector<int> line;
    image_three(matrix);
    for (int j = int(matrix[0].size()) - 1; j >= 0 ; --j) {
        line.clear();
        for(int i = int(matrix.size()) - 1; i >= 0; --i) {
            line.push_back(matrix[i][j]);
        }
        matrix_temp.push_back(line);
    }
    matrix.clear();
    for(int i = 0; i < matrix_temp.size(); ++i) {
        matrix.push_back(matrix_temp[i]);
    }
}
// three: 垂直旋转
void ImageOperation::image_three(vector<vector<int>> &matrix) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m; ++j) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
    
}
// four: 水平旋转
void ImageOperation::image_four(vector<vector<int>> &matrix) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    // first step: 水平中线翻转一次
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            swap(matrix[i][j], matrix[i][m - 1 - j]);
        }
    }
}
// five: 区域灰度值增加。区域内的所有像素增加指定的灰度值。如果增加后像素值大于255，则保持为255
void ImageOperation::image_five(vector<vector<int>> &matrix,
                                int x0, int y0, int x1, int y1, int value) {
    for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
            matrix[i][j] += value;
            if (matrix[i][j] > 255) {
                matrix[i][j] = 255;
            }
        }
    }
}
// six: 区域灰度值减少。区域内的所有像素减少指定的灰度值。如果减少后像素值小于0，则保持为0
void ImageOperation::image_six(vector<vector<int>> &matrix,
                               int x0, int y0, int x1, int y1, int value) {
    for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
            matrix[i][j] -= value;
            if (matrix[i][j] < 0) {
                matrix[i][j] = 0;
            }
        }
    }
}
// seven: 区域裁剪
void ImageOperation::image_seven(vector<vector<int>> &matrix,
                                 int x0, int y0, int x1, int y1) {
    vector<vector<int>> matrix_temp;
    vector<int> line;
    for (int i = x0; i <= x1; ++i) {
        line.clear();
        for(int j = y0; j <= y1; ++j) {
            line.push_back(matrix[i][j]);
        }
        matrix_temp.push_back(line);
    }
    matrix.clear();
    for(int i = 0; i < matrix_temp.size(); ++i) {
        matrix.push_back(matrix_temp[i]);
    }
    
}


/*
 * count_test: 测试点数量
 * n, m: 矩阵的大小(1 <= N, M <= 100)
 * T: 操作数(1 <= T <= 50)
 * num_operation: 操作类型([1, 7])
 * x0, y0, x1, y1, value(0 < value <= 255): 分别表示区域左上角(x0, y0)以及区域右下角(x1, y1)，
 * 该区域中所有像素值增加/减少value.
 */
void matrix_function(void) {
    int count_test;
    int n, m;
    int element;
    int T;
    int num_operation;
    int x0, y0, x1, y1, value;
    vector<vector<int>> matrix;
    ImageOperation image_operation;
    cin >> count_test;
    for (int test_index = 0; test_index < count_test; ++test_index) {
        vector<int> line;
        cin >> n >> m;
        matrix.clear();
        for(int i = 0; i < n; ++i) {
            line.clear();
            for (int j = 0; j < m; ++j) {
                cin >> element;
                line.push_back(element);
            }
            matrix.push_back(line);
        }
        cin >> T;
        for (int index = 0; index < T; ++index) {
            cin >> num_operation;
            switch (num_operation) {
                case 1:
                    image_operation.image_one(matrix);
                    break;
                case 2:
                    image_operation.image_two(matrix);
                    break;
                case 3:
                    cout << "three" << endl;
                    image_operation.image_three(matrix);
                    break;
                case 4:
                    image_operation.image_four(matrix);
                    break;
                case 5:
                    cin >> x0 >> y0 >> x1 >> y1 >> value;
                    image_operation.image_five(matrix, x0, y0, x1, y1, value);
                    break;
                case 6:
                    cin >> x0 >> y0 >> x1 >> y1 >> value;
                    image_operation.image_six(matrix, x0, y0, x1, y1, value);
                    break;
                case 7:
                    cin >> x0 >> y0 >> x1 >> y1;
                    image_operation.image_seven(matrix, x0, y0, x1, y1);
                    break;
                default:
                    cout << "The number of operation is wrong!" << endl;
                    break;
            }
        }
        // get the result
        cout << matrix.size() << " " << matrix[0].size() << " " << matrix[0][0] << " ";
        int sum = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                sum += matrix[i][j];
            }
        }
        cout << sum << endl;
    }
    
}

