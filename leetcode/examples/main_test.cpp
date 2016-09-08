//
//  main.cpp
//  leetcode
//
//  Created by NoteFAN on 8/2/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void dfs(vector<int> &a, vector<int> &stk, int n, int start, int k, int d, long long &sum);


int main(int argc, const char * argv[]) {
    
    // insert code here...
    int n, element;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        a.push_back(element);
    }
    int k, d;
    cin >> k >> d;
    long long sum = 0;
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        stk.push_back(a[i]);
        k -= 1;
        for (int j = i + 1; j <= i + d; ++j) {
            dfs(a, stk, n, j, k, d, sum);
        }
        stk.pop_back();
        k += 1;
    }
    cout << sum << endl;
    return 0;
}

void dfs(vector<int> &a, vector<int> &stk, int n, int start, int k, int d, long long &sum) {
    if (k == 0 && start < n) {
        int length = int(stk.size());
        long long temp = 1;
        for (int i = 0; i < length; ++i) {
            temp *= stk[i];
        }
        sum = sum > temp ? sum : temp;
        return;
    } else if (start > n - 1) {
        return;
    }
    
    stk.push_back(a[start]);
    k -= 1;
    for (int j = start + 1; j <= start + d; ++j) {
        dfs(a, stk, n, j, k, d, sum);
        stk.pop_back();
    }
    
}

