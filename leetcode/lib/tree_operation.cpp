//
//  tree_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 5/12/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include "tree_operation.h"

/* 递归解法 -> Time complexity: O(n) Space complexity: O(n) */
vector<int> BinaryTree::BinaryTreePreorderTraversalOne(TreeNode *root) {
    vector<int> all_nodes_values;
    PreorderTraversal(root, all_nodes_values);
    return all_nodes_values;
}

void BinaryTree::PreorderTraversal(TreeNode *root, vector<int> &all_nodes_values) {
    if (root == nullptr) {
        return;
    }
    all_nodes_values.push_back(root->val);
    PreorderTraversal(root->left, all_nodes_values);
    PreorderTraversal(root->right, all_nodes_values);
}

/* 迭代解法 -> Time complexity: O(n) Space complexity: O(n) */
vector<int> BinaryTree::BinaryTreePreorderTraversalTwo(TreeNode *root) {
    vector<int> all_nodes_values;
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty()) {
        if (cur == nullptr) {
            cur = stk.top();
            stk.pop();
        }
        all_nodes_values.push_back(cur->val);
        if (cur->right != nullptr) {
            stk.push(cur->right);
        }
        cur = cur->left;
    }
    return all_nodes_values;
}

/* Morris traversal 先序遍历 -> Time complexity: O(n) Space complexity: O(1) */
vector<int> BinaryTree::BinaryTreePreorderTraversalThree(TreeNode *root) {
    vector<int> all_nodes_values;
    TreeNode *cur = root;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            all_nodes_values.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode *node = cur->left;
            while (node->right != nullptr && node->right != cur) {
                node = node->right;
            }
            if (node->right == nullptr) {
                node->right = cur;
                all_nodes_values.push_back(cur->val);
                cur = cur->left;
            } else {
                node->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return all_nodes_values;
}

/* 递归解法 -> Time complexity: O(n) Space complexity: O(n) */
vector<int> BinaryTree::BinaryTreeInorderTraversalOne(TreeNode *root) {
    vector<int> all_nodes_values;
    InorderTraversal(root, all_nodes_values);
    return all_nodes_values;
}

void BinaryTree::InorderTraversal(TreeNode *root, vector<int> &all_nodes_value) {
    if (root == nullptr) {
        return;
    }
    InorderTraversal(root->left, all_nodes_value);
    all_nodes_value.push_back(root->val);
    InorderTraversal(root->right, all_nodes_value);
}

/* 迭代解法 -> Time complexity: O(n) Space complexity: O(n) */
vector<int> BinaryTree::BinaryTreeInorderTraversalTwo(TreeNode *root) {
    vector<int> all_nodes_value;
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty()) {
        if (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            all_nodes_value.push_back(cur->val);
            stk.pop();
            cur = cur->right;
        }
    }
    return all_nodes_value;
}

/* Morris traversal 中序遍历 -> Time complexity: O(n) Space complexity: O(1) */
vector<int> BinaryTree::BinaryTreeInorderTraversalThree(TreeNode *root) {
    vector<int> all_nodes_values;
    TreeNode *cur = root;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            all_nodes_values.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode * node = cur->left;
            while (node->right != nullptr && node->right != cur) {
                node = node->right;
            }
            if (node->right == nullptr) {
                node->right = cur;
                cur = cur->left;
            } else {
                node->right = nullptr;
                all_nodes_values.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return all_nodes_values;
}

/* 递归解法 -> Time complexity: O(n) Space complexity: O(n) */
vector<int> BinaryTree::BinaryTreePostorderTraversalOne(TreeNode *root) {
    vector<int> all_nodes_values;
    PostorderTraversal(root, all_nodes_values);
    return all_nodes_values;
}

void BinaryTree::PostorderTraversal(TreeNode *root, vector<int> &all_nodes_values) {
    if (root == nullptr) {
        return;
    }
    PostorderTraversal(root->left, all_nodes_values);
    PostorderTraversal(root->right, all_nodes_values);
    all_nodes_values.push_back(root->val);
}


/* 迭代解法 -> Time complexity: O(n) Space complexity: O(n) */
vector<int> BinaryTree::BinaryTreePostorderTraversalTwo(TreeNode *root) {
    vector<int> all_nodes_values;
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;
    do {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            if (cur->right == nullptr || cur->right == prev) {
                all_nodes_values.push_back(cur->val);
                prev = cur;
            } else {
                stk.push(cur);
                cur = cur->right;
                break;
            }
        }
        
    } while (!stk.empty());
    
    return all_nodes_values;
}

/* Morris 后序遍历 -> Time complexity: O(n) Space complexity: O(1) */
vector<int> BinaryTree::BinaryTreePostorderTraversalThree(TreeNode *root) {
    vector<int> all_nodes_values;
    TreeNode dump(-1);
    dump.left = root;
    TreeNode *cur = &dump, *prev = nullptr;
    while (cur) {
        if (cur->left == nullptr) {
            cur = cur->right;
        } else {
            prev = cur->left;
            while (prev->right != nullptr && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = cur;
                cur = cur->left;
            } else {
                GetReverse(cur->left, prev, all_nodes_values);
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return all_nodes_values;
}

// print the reversed tree nodes 'from' -> 'to'.
void BinaryTree::GetReverse(TreeNode *from, TreeNode *to, vector<int> &all_nodes_value) {
    Reverse(from, to);
    TreeNode *p = to;
    while (true) {
        all_nodes_value.push_back(p->val);
        if (p == from) {
            break;
        }
        p = p->right;
    }
    Reverse(to, from);
}

// reverse the tree nodes 'from' -> 'to'.
void BinaryTree::Reverse(TreeNode *from, TreeNode *to) {
    if (from == to) {
        return;
    }
    TreeNode *x = from, *y = from->right, *z;
    while (x != to) {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}

/* 递归版: Time complexity: O(n) Space complexity: O(n) */
vector<vector<int>> BinaryTree::BinaryTreeLevelOrderTraversalOne(TreeNode *root) {
    vector<vector<int>> result;
    Traverse(root, 1, result);
    return result;
}

void BinaryTree::Traverse(TreeNode *root, int level, vector<vector<int>> &result) {
    if (root == nullptr) {
        return;
    }
    if (level > result.size()) {
        result.push_back(vector<int>());
    }
    result[level - 1].push_back(root->val);
    Traverse(root->left, level + 1, result);
    Traverse(root->right, level + 1, result);
}

/* 迭代版: Time complexity: O(n) Space complexity: O(1) */
vector<vector<int>> BinaryTree::BinaryTreeLevelOrderTraversalTwo(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
        return result;
    }
    queue<TreeNode *> current, next;
    vector<int> level;
    current.push(root);
    while (!current.empty()) {
        while (!current.empty()) {
            TreeNode *p = current.front();
            current.pop();
            level.push_back(p->val);
            if (p->left != nullptr) {
                next.push(p->left);
            }
            if (p->right != nullptr) {
                next.push(p->right);
            }
        }
        result.push_back(level);
        level.clear();
        swap(current, next);
    }
    return result;
}

/* 递归版: Time complexity: O(n) Space complexity: O(n) */
vector<vector<int>> BinaryTree::BinaryTreeLevelOrderTraversalThree(TreeNode *root) {
    vector<vector<int>> result;
    TraverseII(root, 1, result);
    reverse(result.begin(), result.end());
    return result;
}

void BinaryTree::TraverseII(TreeNode *root, int level, vector<vector<int>> &result) {
    if (root == nullptr) {
        return;
    }
    if (level > result.size()) {
        result.push_back(vector<int>());
    }
    result[level - 1].push_back(root->val);
    TraverseII(root->left, level + 1, result);
    TraverseII(root->right, level + 1, result);
}

/* 迭代版: Time complexity: O(n) Space complexity: O(1) */
vector<vector<int>> BinaryTree::BinaryTreeLevelOrderTraversalFour(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> current, next;
    vector<int> level;
    
    current.push(root);
    while (!current.empty()) {
        while (!current.empty()) {
            TreeNode *node = current.front();
            current.pop();
            level.push_back(node->val);
            if (node->left != nullptr) {
                next.push(node->left);
            }
            if (node->right != nullptr) {
                next.push(node->right);
            }
        }
        result.push_back(level);
        level.clear();
        swap(current, next);
    }
    reverse(result.begin(), result.end());
    return result;
}

/* 递归版 Time complexity: O(n) Space complexity: O(n) */
vector<vector<int>> BinaryTree::BinaryTreeZigzagLevelOrderTraversalOne(TreeNode *root) {
    vector<vector<int>> result;
    ZigzagLevelTraversal(root, 1, result, true);
    return result;
}
void BinaryTree::ZigzagLevelTraversal(TreeNode *root, int level,
                                      vector<vector<int>> &result,
                                      bool left_to_right) {
    if (root == nullptr) {
        return;
    }
    if (level > result.size()) {
        result.push_back(vector<int>());
    }
    if (left_to_right) {
        result[level - 1].push_back(root->val);
    } else {
        result[level - 1].insert(result[level - 1].begin(), root->val);
    }
    ZigzagLevelTraversal(root->left, level + 1, result, !left_to_right);
    ZigzagLevelTraversal(root->right, level + 1, result, !left_to_right);
}

/* 迭代版 Time complexity: O(n) Space complexity: O(1) */
vector<vector<int>> BinaryTree::BinaryTreeZigzagLevelOrderTraversalTwo(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
        return result;
    }
    bool left_to_right = true;
    queue<TreeNode *> q, next;
    vector<int> level;
    q.push(root);
    while (!q.empty()) {
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != nullptr) {
                next.push(node->left);
            }
            if (node->right != nullptr) {
                next.push(node->right);
            }
        }
        if (left_to_right) {
            result.push_back(level);
        } else {
            reverse(level.begin(), level.end());
            result.push_back(level);
        }
        left_to_right = !left_to_right;
        level.clear();
        swap(q, next);
    }
    return result;
}

/* Time complexity: O(n) Space complexity: O(n) */
void BinarySearchTree::RecoverBinarySearchTreeOne(TreeNode *root) {
    vector<TreeNode *> list;
    vector<int> vals;
    // Inorder traversal
    TreeNode *cur = root;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            list.push_back(cur);
            vals.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode *node = cur->left;
            while (node->right != nullptr && node->right != cur) {
                node = node->right;
            }
            if (node->right == nullptr) {
                node->right = cur;
                cur = cur->left;
            } else {
                list.push_back(cur);
                vals.push_back(cur->val);
                node->right = nullptr;
                cur = cur->right;
            }
        }
    }
    sort(vals.begin(), vals.end());
    for (size_t i = 0; i < list.size(); ++i) {
        list[i]->val = vals[i];
    }
}

/* Time complexity: O(n) Space complexity: O(1) */
void BinarySearchTree::RecoverBinarySearchTreeTwo(TreeNode *root) {
    pair<TreeNode *, TreeNode *> broken;
    TreeNode *current = root, *prev = nullptr;
    // Inorder travelsal
    while (current != nullptr) {
        if (current->left == nullptr) {
            DetectBroken(broken, prev, current);
            prev = current;
            current = current->right;
        } else {
            TreeNode *node = current->left;
            while (node->right != nullptr && node->right != current) {
                node = node->right;
            }
            if (node->right == nullptr) {
                node->right = current;
                current = current->left;
            } else {
                DetectBroken(broken, prev, current);
                node->right = nullptr;
                current = current->right;
            }
        }
    }
    swap(broken.first->val, broken.second->val);
}

void BinarySearchTree::DetectBroken(pair<TreeNode *, TreeNode *> &broken,
                                    TreeNode *prev, TreeNode *current) {
    if (prev != nullptr && prev->val > current->val) {
        if (broken.first == nullptr) {
            broken.first = prev;
        }
        broken.second = current;
    }
}

/* 递归版 Time complexity: O(n) Space complexity: O(logn) */
bool SameBinaryTree::CheckSameBinaryTreeOne(TreeNode *root_one, TreeNode *root_two) {
    if (!root_one && !root_two) return true;
    if (!root_one || !root_two) return false;
    return (root_one->val == root_two->val)
            && CheckSameBinaryTreeOne(root_one->left, root_two->left)
            && CheckSameBinaryTreeOne(root_one->right, root_two->right);
}

/* 迭代版 Time complexity: O(n) Space complexity: O(logn) */
bool SameBinaryTree::CheckSameBinaryTreeTwo(TreeNode *root_one, TreeNode *root_two) {
    stack<TreeNode *> stk;
    stk.push(root_one);
    stk.push(root_two);
    while (!stk.empty()) {
        TreeNode *p = stk.top();
        stk.pop();
        TreeNode *q = stk.top();
        stk.pop();
        if (!p && !q) continue;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        stk.push(p->left);
        stk.push(q->left);
        stk.push(p->right);
        stk.push(q->right);
    }
    return true;
}

/* Recursively -> Time complexity: O(n) Space complexity: O(logn) */
bool SymmetricTree::IsSymmetricTreeOne(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    return CheckSameBinaryTree(root->left, root->right);
}

bool SymmetricTree::CheckSameBinaryTree(TreeNode *root_one, TreeNode *root_two) {
    if (!root_one && !root_two) {
        return true;
    }
    if (!root_one || !root_two) {
        return false;
    }
    return (root_one->val == root_two->val)
            && CheckSameBinaryTree(root_one->left, root_two->right)
            && CheckSameBinaryTree(root_one->right, root_two->left);
}

/* Iteratively -> Time complexity: O(n) Space complexity: O(logn) */
bool SymmetricTree::IsSymmetricTreeTwo(TreeNode *root) {
    if (!root) {
        return true;
    }
    stack<TreeNode *> stk;
    stk.push(root->left);
    stk.push(root->right);
    while (!stk.empty()) {
        TreeNode *p = stk.top();
        stk.pop();
        TreeNode *q = stk.top();
        stk.pop();
        if (!p && !q) continue;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        stk.push(p->left);
        stk.push(q->right);
        stk.push(p->right);
        stk.push(q->left);
    }
    return true;
}

/* Time complexity: O(n) Space complexity: O(n) */
bool BalancedBinaryTree::IsBalancedBinaryTree(TreeNode *root) {
    return BalancedHeight(root) > -1;
}


/* return the height of 'root' if root is a balanced tree, otherwise return -1 */
int BalancedBinaryTree::BalancedHeight(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int left = BalancedHeight(root->left);
    int right = BalancedHeight(root->right);
    
    if (left == -1 || right == -1 || abs(left - right) > 1) {
        return -1;
    }
    return max(left, right) + 1;
}

/* Recursively one -> Time complexity: O(n) Space complexity: O(logn) */
void FlattenBinaryTreetoLinkedList::FlattenBinaryTreeOne(TreeNode *root) {
    if (root == nullptr) return;
    FlattenBinaryTreeOne(root->left);
    FlattenBinaryTreeOne(root->right);
    if (root->left == nullptr) return;
    // combine root, left-subtree and right-subtree
    TreeNode *p = root->left;
    while (p->right) {
        p = p->right;
    }
    p->right = root->right;
    root->right = root->left;
    root->left = nullptr;
}

/* Iteratively -> Time complexity: O(n) Space complexity: O(logn) */
void FlattenBinaryTreetoLinkedList::FlattenBinaryTreeTwo(TreeNode *root) {
    if (root == nullptr) return;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *node = stk.top();
        stk.pop();
        if (node->right != nullptr) {
            stk.push(node->right);
        }
        if (node->left != nullptr) {
            stk.push(node->left);
        }
        node->left = nullptr;
        if (!stk.empty()) {
            node->right = stk.top();
        }
    }
}

/* Recursively -> Time complexity: O(n) Space complexity: O(1) */
void PopulatingNextRightPointersInEachNodeII::PopulatingNextRightPointersOne(TreeLinkNode *root) {
    if (root == nullptr) return;
    TreeLinkNode dummy(-1);
    for (TreeLinkNode *current = root, *prev = &dummy; current != nullptr; current = current->next) {
        if (current->left != nullptr) {
            prev->next = current->left;
            prev = prev->next;
        }
        if (current->right != nullptr) {
            prev->next = current->right;
            prev = prev->next;
        }
    }
    PopulatingNextRightPointersOne(dummy.next);
}

/* Iteratively -> Time complexity: O(n) Space complexity: O(1) */
void PopulatingNextRightPointersInEachNodeII::PopulatingNextRightPointersTwo(TreeLinkNode *root) {
    while (root != nullptr) {
        TreeLinkNode *previous = nullptr;
        TreeLinkNode *next = nullptr;
        
        for (; root; root = root->next) {
            if (next == nullptr) {
                next = root->left != nullptr ? root->left : root->right;
            }
            if (root->left != nullptr) {
                if (previous != nullptr) {
                    previous->next = root->left;
                } else {
                    previous = root->left;
                }
            }
            if (root->right != nullptr) {
                if (previous != nullptr) {
                    previous->next = root->right;
                } else {
                    previous = root->right;
                }
            }
        }
        root = next;
    }
}

/* Recursively Time complexity: O(n) Space complexity: O(logn) */
template <typename InputIterator>
TreeNode *ConstructBinaryTree::BuildBinaryTreeOne(InputIterator preorder_begin,
                                                  InputIterator preorder_end,
                                                  InputIterator inorder_begin,
                                                  InputIterator inorder_end) {
    if (preorder_begin == preorder_end) return nullptr;
    if (inorder_begin == inorder_end) return nullptr;
    TreeNode *root = new TreeNode(*preorder_begin);
    // find the position of root in the inorder traversal
    InputIterator position = find(inorder_begin, inorder_end, *preorder_begin);
    size_t length = distance(inorder_begin, position);
    root->left = BuildBinaryTreeOne(next(preorder_begin), next(preorder_begin, length + 1),
                                    inorder_begin, next(inorder_begin, length));
    root->right = BuildBinaryTreeOne(next(preorder_begin, length + 1), preorder_end,
                                     next(position), inorder_end);
    return root;
}


template <typename InputIterator>
TreeNode *ConstructBinaryTree::BuildBinaryTreeTwo(InputIterator inorder_begin,
                                                  InputIterator inorder_end,
                                                  InputIterator postorder_begin,
                                                  InputIterator postorder_end) {
    if (inorder_begin == inorder_end) return nullptr;
    if (postorder_begin == postorder_end) return nullptr;
    TreeNode *root = new TreeNode(*prev(postorder_end));
    InputIterator position = find(inorder_begin, inorder_end, *prev(postorder_end));
    size_t length = distance(inorder_begin, position);
    root->left = BuildBinaryTreeTwo(inorder_begin, position,
                                    postorder_begin, next(postorder_begin, length));
    root->right = BuildBinaryTreeTwo(next(position), inorder_end,
                                     next(postorder_begin, length), prev(postorder_end));
    return root;
}

int UniqueBinarySearchTrees::GetNumberUniqueBinaryTrees(int n) {
    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            f[i] += f[j] * f[i - j - 1];
        }
    }
    return f[n];
}

/* Time complexity: O(n^2) Space complexity: O(n) */
vector<TreeNode *> UniqueBinarySearchTrees::GenerateTree(int start, int end) {
    vector<TreeNode *> binary_search_trees;
    if (start > end) {
        binary_search_trees.push_back(nullptr);
        return binary_search_trees;
    }
    
    for (int k = start; k <= end; ++k) {
        vector<TreeNode *> left = GenerateTree(start, k - 1);
        vector<TreeNode *> right = GenerateTree(k + 1, end);
        for (TreeNode *left_subtree : left) {
            for (TreeNode *right_subtree : right) {
                TreeNode *root = new TreeNode(k);
                root->left = left_subtree;
                root->right = right_subtree;
                binary_search_trees.push_back(root);
            }
        }
    }
    
    return  binary_search_trees;
}

/* Time complexity: O(n) Space complexity: O(logn) */
bool ValidateBinarySearchTree::IsValidBST(TreeNode *root, int lower, int uppper) {
    if (root == nullptr) return true;
    return (root->val > lower) && (root->val < uppper)
            && IsValidBST(root->left, lower, root->val)
            && IsValidBST(root->right, root->val, uppper);
}

template<typename RandomAccessIterator>
TreeNode *ConvertSortedArrayToBinarySearchTree::SortedArrayToBST(RandomAccessIterator begin,
                                                                 RandomAccessIterator end) {
    size_t length = distance(begin, end);
    if (length <= 0) return nullptr;
    TreeNode *root = new TreeNode(*next(begin, length / 2));
    root->left = SortedArrayToBST(begin, next(begin, length / 2));
    root->right = SortedArrayToBST(next(begin, length / 2 + 1), end);
    return root;
}


TreeNode *ConvertSortedListToBinarySearchTree::SortedListToBST(ListNode *head,
                                                               int length) {
    if (length <= 0) return nullptr;
    ListNode *node = GetElement(head, (length + 1) / 2);
    TreeNode *root = new TreeNode(node->val);
    root->left = SortedListToBST(head, (length + 1) / 2 - 1);
    root->right = SortedListToBST(GetElement(head, (length + 1) / 2 + 1), length / 2);
    return root;
}

TreeNode *ConvertSortedListToBinarySearchTree::SortedListToBSTBottomUp(ListNode *& head,
                                                                       int start,
                                                                       int end) {
    if (start > end) return nullptr;
    int middle = start + (end - start) / 2;
    TreeNode *left_subtree = SortedListToBSTBottomUp(head, start, middle - 1);
    TreeNode *root = new TreeNode(head->val);
    root->left = left_subtree;
    root->right = SortedListToBSTBottomUp(head->next, middle + 1, end);
    return root;
}

/* Time compleixity: O(n) Space complexity: (logn) */
int DepthOfBinaryTree::MinimumDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right != nullptr) {
        return 1 + MinimumDepth(root->right);
    } else if (root->left != nullptr && root->right == nullptr) {
        return 1 + MinimumDepth(root->left);
    } else {
        return min(1 + MinimumDepth(root->left), 1 + MinimumDepth(root->right));
    }
}

/* Time compleixity: O(n) Space complexity: (logn) */
int DepthOfBinaryTree::MinimumDepthOfBinaryTreeIteratively(TreeNode *root) {
    if (root == nullptr) return 0;
    int result = INT_MAX;
    stack<pair<TreeNode *, int>> stk;
    stk.push(make_pair(root, 1));
    while (!stk.empty()) {
        TreeNode *node = stk.top().first;
        int depth = stk.top().second;
        stk.pop();
        if (node->left == nullptr && node->right == nullptr) {
            result = min(result, depth);
        }
        if (node->left && depth < result - 1) {
            stk.push(make_pair(node->left, depth + 1));
        }
        if (node->right && depth < result - 1) {
            stk.push(make_pair(node->right, depth + 1));
        }
    }
    return result;
}

/* Time compleixity: O(n) Space complexity: (logn) */
int DepthOfBinaryTree::MaximumDepthOfBinaryTreeRecursively(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(MaximumDepthOfBinaryTreeRecursively(root->left),
               MaximumDepthOfBinaryTreeRecursively(root->right)) + 1;
}

/* Time complexity: O(n) Space complexity: O(logn) */
bool PathSum::HasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == sum;
    }
    return HasPathSum(root->left, sum - root->val)
            || HasPathSum(root->right, sum - root->val);

}

/* Time complexity: O(n) Space complexity: O(logn) */
void PathSum::GetPathSum(TreeNode *root, vector<vector<int>> &result,
                         vector<int> &path, int sum) {
    if (root == nullptr) return;
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == sum) {
            result.push_back(path);
        }
    }
    GetPathSum(root->left, result, path, sum - root->val);
    GetPathSum(root->right, result, path, sum - root->val);
    path.pop_back();
}

/* Time complexity: O(n) Space complexity: O(logn) */
int BinaryTreeMaximumPathSum::MaximumPathSum(TreeNode *root) {
    if (root == nullptr) return 0;
    int left = MaximumPathSum(root->left);
    int right = MaximumPathSum(root->right);
    int sum = root->val;
    if (left > 0) {
        sum += left;
    }
    if (right > 0) {
        sum += right;
    }
    max_sum_ = max(max_sum_, sum);
    return max(left, right) > 0 ? max(left, right) + root->val : root->val;
}

































