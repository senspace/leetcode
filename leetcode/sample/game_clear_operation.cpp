//
//  game_clear_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 4/22/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include "game_clear_operation.h"

using namespace std;

class GameClear {
public:
    
protected:
    
private:
    // 判断节点是否需要消除，若需要返回false
    bool IsLine(vector<vector<pair<int, bool>>> &matrix, int x, int y) {
        size_t n = matrix.size();
        size_t m = matrix[0].size();
        // six cases in total
        // first case:
        if (x - 1 >=0 && x + 1 < m && matrix[n][m - 1].first == matrix[n][m].first
            && matrix[n][m].first == matrix[n][m + 1].first) {
            return false;
        }
        return true;
    }
};


int count_clear_graph(vector<vector<pair<int, bool>>> &matrix, int x0, int y0, int x1, int y1) {
    int sum = 0;
    swap(matrix[x0][y0].first, matrix[x1][y1].first);
    
    return sum;
}

/*
 * count_test: 测试点数量(测试点的个数S <= 50)
 * n, m: 矩阵的大小(1 <= N, M <= 20)
 * T: 操作数(1 <= T <= 50)
 * num_operation: 操作类型([1, 7])
 * x0, y0, x1, y1: 表示玩家希望交换的两个相邻图形的坐标位置(x0, y0)以及(x1, y1).
 */
void game_clear_function(void) {
    int count_test;
    int n, m;
    int x0, y0, x1, y1;
    int element;
    vector<vector<pair<int, bool>>> matrix;
    vector<pair<int, bool>> line;
    cin >> count_test;
    while (count_test--) {
        cin >> n >> m;
        matrix.clear();
        for (int i = 0; i < n; ++i) {
            line.clear();
            for (int j = 0; j < m; ++j) {
                cin >> element;
                line.push_back(make_pair(element, true));
            }
            matrix.push_back(line);
        }
        cin >> x0 >>y0 >> x1 >> y1;
        int sum = count_clear_graph(matrix, x0, y0, x1, y1);
        cout << sum << endl;
    }
}


