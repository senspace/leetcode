//
//  matrix_operation.h
//  leetcode
//
//  Created by NoteFAN on 4/21/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

/******************************************************************************
 网易互娱2017实习生招聘游戏研发工程师在线笔试第二场
 题目1 : 图像处理
 时间限制:10000ms
 单点时限:1000ms
 内存限制:256MB
 
 描述
 灰度图像是每个像素只有一个采样颜色的图像。灰度图像与黑白图像不同，它在黑色与白色之间还有许多级的颜色深度。
 灰度图像的每个像素通常用8 bits的非线性尺度来保存，这样可以有256种灰度（8bits就是2的8次方=256）。
 每个像素的范围为[0...255]。每个灰度图像可以用一个矩阵表示，每个矩阵元素对应灰度图像的灰度值.
 
 图像处理中，包含了各种各样的操作，其中，我们定义了以下的7种操作：
 
 操作类型1：顺时针旋转90度。
 
 操作类型2：逆时针旋转90度。
 
 操作类型3：垂直旋转。
 
 操作类型4：水平旋转。
 
 操作类型5：区域灰度值增加。区域内的所有像素增加指定的灰度值。如果增加后像素值大于255，则保持为255。
 
 操作类型6：区域灰度值减少。区域内的所有像素减少指定的灰度值。如果减少后像素值小于0，则保持为0。
 
 操作类型7：区域裁剪。
 
 给出图像对应的初始矩阵以及包含多个操作的序列。我们想知道当所有操作完成后，最后的矩阵的是怎么样的。
 
 输入
 每个输入数据包含多个测试点。
 
 输入数据的第一行为S(S <= 10)，表示测试数据有S个测试点。
 
 测试点的第一行为N, M (1 <= N, M <= 100)，表示矩阵的大小。之后N行，每行包含M个数字，表示对应的像素值，数字的范围在[0...255]。
 
 之后一行是数T(1 <= T <= 50)。之后T行，每行表示一个操作。每行的第一个数表示操作类型。
 
 其中，对于操作类型5和6，该行还会包括5个数x0, y0, x1, y1, value(0 < value <= 255)。
    分别表示区域左上角(x0, y0)以及区域右下角(x1, y1)，该区域中所有像素值增加/减少value。
    对于操作类型7，该行还会包括4个数x0, y0, x1, y1，表示裁剪的区域左上角(x0, y0)和区域右下角(x1, y1)。
 
 保证所有操作均合法，操作中指定的区域一定是矩阵中的合法区域。保证最后的矩形一定非空。
 
 输出
 对应每个测试点输出一行，包括四个数字，分别表示最后矩阵的大小，左上角(0, 0)的像素大小，以及所有像素值的总和。
 
 样例输入
 2
 3 4
 1 2 3 4
 5 6 7 8
 9 0 1 2
 3
 1
 7 1 0 3 1
 5 1 0 1 1 5
 2 2
 7 8
 7 2
 1
 1
 
 样例输出
 3 2 0 34
 2 2 7 24
 
 ******************************************************************************/

#ifndef MATRIX_OPERATION_H
#define MATRIX_OPERATION_H

using namespace std;

class ImageOperation {
public:
    // one: 顺时针旋转90度
    void image_one(vector<vector<int>> &matrix);
    // two: 逆时针旋转90度
    void image_two(vector<vector<int>> &matrix);
    // three: 垂直旋转
    void image_three(vector<vector<int>> &matrix);
    // four: 水平旋转
    void image_four(vector<vector<int>> &matrix);
    // five: 区域灰度值增加。区域内的所有像素增加指定的灰度值。如果增加后像素值大于255，则保持为255
    void image_five(vector<vector<int>> &matrix,
                    int x0, int y0, int x1, int y1, int value);
    // six: 区域灰度值减少。区域内的所有像素减少指定的灰度值。如果减少后像素值小于0，则保持为0
    void image_six(vector<vector<int>> &matrix,
                   int x0, int y0, int x1, int y1, int value);
    // seven: 区域裁剪
    void image_seven(vector<vector<int>> &matrix, int x0, int y0, int x1, int y1);
protected:
    
private:
    
};

void matrix_function(void);

#endif /* matrix_operation_h */
