//
//  main.cpp
//  leetcode
//
//  Created by NoteFAN on 3/16/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool FindElement(vector<int> numbers) {
    int length = int(numbers.size());
    if (length < 3) return false;
    int first = 0, second = 0, third = 0;
    for (int i = 0; i < length - 2; ++i) {
        first = numbers[i];
        for (int j = i + 1; j < length - 1; ++j) {
            second = numbers[j];
            if (second <= first) continue;
            for (int k = j + 1; k < length; ++k) {
                third = numbers[k];
                if (third > second) return true;
            }
        }
    }
    return false;
}


#define SIZE 1000
struct Node
{
    long key;
    char value[16];
    Node *next;
    Node(long k):key(k),next(nullptr){}
};

class HashMap {
public:
    Node **map;
    // hash table
    size_t hash(long key) {
        return key % SIZE;
    }
    
    HashMap() {
        map = new Node*[SIZE];
        for(size_t i=0; i < SIZE; i++) map[i] = NULL;
    }
    
    ~HashMap() {
        for(size_t i=0;i<SIZE;i++) {
            Node *p = map[i];
            while(p) {
                map[i]=p->next;
                delete p;
                p = map[i];
            }
        }
        delete[] map;
    }
    
    Node* find(long key) {
        Node *p = map[hash(key)];
        while(p) {
            if(p->key == key) break;
            p = p->next;
        }
        return p;
    }
    
    void insert(long k,char *val) {
        Node *f = find(k);
        if(f) {
            strcpy(f->value, val);//存在键则覆盖
            return;
        }
        Node *p = map[hash(k)];//确定地址链索引
        Node *q = new Node(k);//创建节点
        strcpy(q->value, val);
        while(p && p->next) p = p->next;//索引到地址链末端
        if(p) {
            p->next = q;
        } else {
            map[hash(k)]=q;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> > numbers = { {2, 4, 3, 6, 8, 10},
        {10, 2, 1, 2, 0, 1}, {8, 4, 9, 6, 0, 1},
        {8, 4, 3, 6, 8, 4}, {0, 9, 8, 7, 5, 2},
        {9, 4, 3, 6, 8, 10}, {1, 4, 3, 6, 8, 10},
        {2, 4, 3, 6, 8, 10}, {7, 4, 3, 6, 5, 2}};
    
    int length = int(numbers.size());
    for (int i = 0; i < length; ++i) {
        bool result = FindElement(numbers[i]);
        cout << "result: " << result << endl;
    }
    
    
    /********************test two*************************/
    HashMap sample;
    vector<long> keys = {1, 2, 3, 4, 5, 6, 7, 8};
    char a[16] = "test";
    int length1 = int(keys.size());
    for (int i = 0; i < length1; ++i) {
        sample.insert(keys[i], a);
    }
    Node *res = sample.find(1);
    cout << res->key << " " << res->value << endl;
    
    
    for (int i = 0; i < 32; i++) {
        int8_t a = static_cast<int8_t>(
                 static_cast<int>((rand() / static_cast<float>(RAND_MAX)) * 255));
        cout << a << endl;
    }
    
    return 0;
}






