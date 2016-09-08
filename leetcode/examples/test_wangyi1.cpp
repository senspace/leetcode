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

bool CheckNum(size_t num){
    size_t a = num % 10;
    num /= 10;
    size_t b = num % 10;
    num /= 10;
    size_t c = num % 10;
    num /= 10;
    size_t d = num % 10;
    if (a == b && b == c && c == d) {
        cout << d << c << b << a << " - " << d << c << b << a << " = " << "0000" << endl;
        return true;
    }
    return false;
}

void SortNum(size_t num, size_t a[]) {
    for (size_t i = 0; i < 4; ++i) {
        a[i] = num % 10;
        num /= 10;
    }
    sort(a, a + 4);
}

int main(void) {
    size_t num;
    cin >> num;
    if (CheckNum(num)) {
        return 0;
    }
    size_t a[4];
    while (num != 6174) {
        SortNum(num, a);
        num = 1000*a[3]+100*a[2]+10*a[1]+a[0] - (1000*a[0]+100*a[1]+10*a[2]+a[3]);
        cout << a[3] << a[2] << a[1] << a[0] << " - " << a[0] << a[1] << a[2] << a[3]
        << " = " << num/1000 << num%1000/100 << num%100/10 << num%10 << endl;
    }
    return 0;
}