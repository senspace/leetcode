#include <iostream>
#include <vector>

using namespace std;

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
        for(size_t i=0; i < SIZE; i++) {
            map[i] = nullptr;
        }
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
            strncpy(f->value, val, 16);
            return;
        }
        Node *p = map[hash(k)];
        Node *q = new Node(k);
        strncpy(q->value, val, 16);
        while(p && p->next) p = p->next;
        if(p) {
            p->next = q;
        } else {
            map[hash(k)]=q;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    HashMap sample;
    vector<long> keys = {1, 2, 3, 4, 5, 6, 7, 8};
    char a[16] = "test";
    int length1 = int(keys.size());
    for (int i = 0; i < length1; ++i) {
        sample.insert(keys[i], a);
    }
    Node *res = sample.find(1);
    cout << res->key << " " << res->value << endl;
    
    return 0;
}