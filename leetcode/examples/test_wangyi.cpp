//
//  test_wangyi.cpp
//  leetcode
//
//  Created by NoteFAN on 8/1/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

size_t Number(size_t n, size_t s, size_t L) {
    size_t result = 0;
    size_t number_songs = (L + 1) / (s + 1);
    if (number_songs % 13 == 0) {
        number_songs -= 1;
    }
    result = n / number_songs;
    if (n % number_songs != 0) {
        result += 1;
    }
    return result;
}

int main(void) {
    size_t n, s, L;
    cin >> n >> s >> L;
    size_t result = Number(n, s, L);
    cout << result << endl;
    return 0;
}

