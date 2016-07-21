//
//  main.cpp
//  leetcode
//
//  Created by NoteFAN on 3/16/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "matrix_operation.h"

using namespace std;


/*
 第一行：三个正整数N、T、M。
        N是物品的个数(1 <= N <= 20)，
        T是每个背包的容量体积(1 <= T <= 20)，
        M是背包个数(1 <= M <= 20)。
 第二行：N个数，a1……an表示每个物品的体积，同时，小萌也是按这个顺序拿物品的。
 
 算法分析：0，1背包问题 - 动态规划
 */

int count_num(vector<int> &things, vector<int> &positions, int T) {
    int sum = 0;
    int num = 0;
    for (int i = 0; i < things.size(); ++i) {
        sum = things[i];
        int j = i;
        while (sum <= T && j < things.size()) {
            sum += things[j];
            ++j;
        }
        if (j - i > num) {
            num = j - i;
            positions.clear();
            for (int position = i; position < j; ++position) {
                positions.push_back(position);
            }
        }
    }
    return num;
}


int function_one() {
    int N, T, M;
    int element;
    int sum = 0;
    cin >> N >> T >> M;
    vector<int> things;
    vector<int> positions;
    int num_bags = M;
    
    
    for (int i = 0; i < N; ++i) {
        cin >> element;
        things.push_back(element);
    }
    
    while (things.size() != 0 && num_bags--) {
        sum += count_num(things, positions, T);
        for (auto it = positions.begin(); it != positions.end(); ++it) {
            if (*it < things.size()) {
                things.erase(things.begin() + *it);
            }
        }
        positions.clear();
    }
    
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    // matrix_function();
    int sum = function_one();
    cout << sum << endl;
    return 0;
}
