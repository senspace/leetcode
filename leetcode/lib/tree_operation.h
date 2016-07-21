//
//  tree_operation.hpp
//  leetcode
//
//  Created by NoteFAN on 5/12/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#ifndef TREE_OPERATION_H
#define TREE_OPERATION_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*************************************************************
 二叉树: 每个节点最多有两棵树，左子树和右子树，次序不可颠倒.
 性质:
    1. 非空二叉树的第n层至多有2^(n-1)个元素;
    2. 深度为h的二叉树至多有2^h-1个节点.
 满二叉树: 所有终端都在同一层次，且非终端节点的度数为2，在满二叉树中若其深度为h，则其包含的节点数必为2^h-1.
 完全二叉树: 除了最大的层次即为一棵满二叉树且最大层所有节点均向左靠齐，即集中在左面位置，不能有空结点.
 性质:
    1. 对于完全二叉树，设一个节点为i，则其父节点为i/2，2*i为其左节点， 2*i+1为其右节点.
 
 二叉树的遍历: 遍历即将树的所有结点访问且仅访问一次。按照根节点位置的不同分为前序遍历，中序遍历，后序遍历。
    1. 前序遍历：根节点->左子树->右子树
    2. 中序遍历：左子树->根节点->右子树
    3. 后序遍历：左子树->右子树->根节点
 
 Morris traversal
 http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
 *************************************************************/

/* the node of binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* 
 * Binary Tree Operations 
 * 1. Binary Tree Preorder Traversal
 * 2. Binary Tree Inorder Traversal
 * 3. Binary Tree Postorder Traversal
 * 4. Binary Tree Level Order Traversal I
 * 5. Binary Tree Level Order Traversal II
 * 6. Binary Tree Zigzag Level Order Traversal
 */
class BinaryTree {
public:
    /* 递归解法 -> Time complexity: O(n) Space complexity: O(n) */
    vector<int> BinaryTreePreorderTraversalOne(TreeNode *root);
    void PreorderTraversal(TreeNode *root, vector<int> &all_nodes_values);
    /* 迭代解法 -> Time complexity: O(n) Space complexity: O(n) */
    vector<int> BinaryTreePreorderTraversalTwo(TreeNode *root);
    /* Morris 先序遍历 -> Time complexity: O(n) Space complexity: O(1) */
    vector<int> BinaryTreePreorderTraversalThree(TreeNode *root);
    
    /* 递归解法 -> Time complexity: O(n) Space complexity: O(n) */
    vector<int> BinaryTreeInorderTraversalOne(TreeNode *root);
    void InorderTraversal(TreeNode *root, vector<int> &all_nodes_value);
    /* 迭代解法 -> Time complexity: O(n) Space complexity: O(n) */
    vector<int> BinaryTreeInorderTraversalTwo(TreeNode *root);
    /* Morris traversal 中序遍历 -> Time complexity: O(n) Space complexity: O(1) */
    vector<int> BinaryTreeInorderTraversalThree(TreeNode *root);
    
    /* 递归解法 -> Time complexity: O(n) Space complexity: O(n) */
    vector<int> BinaryTreePostorderTraversalOne(TreeNode *root);
    void PostorderTraversal(TreeNode *root, vector<int> &all_nodes_values);
    /* 迭代解法 -> Time complexity: O(n) Space complexity: O(n) */
    vector<int> BinaryTreePostorderTraversalTwo(TreeNode *root);
    /* 
     * Morris 后序遍历 -> Time complexity: O(n) Space complexity: O(1)
     * 算法思路:
     *    后续遍历稍显复杂，需要建立一个临时节点dump，令其左孩子是root。并且还需要一个子过程，
     * 就是倒序输出某两个节点之间路径上的各个节点。
     * 步骤:
     * 当前节点设置为临时节点dump。
     * 1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。
     * 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
     *    a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
     *    b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。倒序输出从当前节点的左孩子
     * 到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右孩子。
     */
    vector<int> BinaryTreePostorderTraversalThree(TreeNode *root);
    // get the reversed tree nodes 'from' -> 'to'.
    void GetReverse(TreeNode *from, TreeNode *to, vector<int> &all_nodes_value);
    // reverse the tree nodes 'from' -> 'to'.
    void Reverse(TreeNode *from, TreeNode *to);
    
    
    /*
     * Binary Tree Level Order Traversal I
     * Description:
     * Given a binary tree, return the level order traversal of its nodes' values. 
     * (ie, from left to right, level by level).
     * For example: Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
     return its level order traversal as:
     [
        [3],
        [9,20],
        [15,7]
     ]
     */
    /* 递归版: Time complexity: O(n) Space complexity: O(n) */
    vector<vector<int>> BinaryTreeLevelOrderTraversalOne(TreeNode *root);
    void Traverse(TreeNode *root, int level, vector<vector<int>> &result);
    /* 迭代版: Time complexity: O(n) Space complexity: O(1) */
    vector<vector<int>> BinaryTreeLevelOrderTraversalTwo(TreeNode *root);
    
    /*
     * Binary Tree Level Order Traversal II
     * Given a binary tree, return the bottom-up level order traversal of its 
     * nodes' values. (ie, from left to right, level by level from leaf to root).
     * For example: Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
     [15,7],
     [9,20],
     [3]
    ]
    */
    /* 递归版: Time complexity: O(n) Space complexity: O(n) */
    vector<vector<int>> BinaryTreeLevelOrderTraversalThree(TreeNode *root);
    void TraverseII(TreeNode *root, int level, vector<vector<int>> &result);
    /* 迭代版: Time complexity: O(n) Space complexity: O(1) */
    vector<vector<int>> BinaryTreeLevelOrderTraversalFour(TreeNode *root);
    
    /*
     * Binary Tree Zigzag Level Order Traversal
     * Description:
     * Given a binary tree, return the zigzag level order traversal of its 
     * nodes' values. (ie, from left to right, then right to left for the next 
     * level and alternate between).
     * For example: Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
     return its zigzag level order traversal as:
     [
        [3],
        [20,9],
        [15,7]
     ]
    */
    /* 递归版 Time complexity: O(n) Space complexity: O(n) */
    vector<vector<int>> BinaryTreeZigzagLevelOrderTraversalOne(TreeNode *root);
    void ZigzagLevelTraversal(TreeNode *root, int level,
                              vector<vector<int>> &result,
                              bool left_to_right);
    /* 迭代版 Time complexity: O(n) Space complexity: O(n) */
    vector<vector<int>> BinaryTreeZigzagLevelOrderTraversalTwo(TreeNode *root);
protected:
    
private:

};

/* 
 * Binary Search Tree 
 * 性质:
 *  1. 二叉搜索树的特点是，小的值在左边，大的值在右边;[left < root < right]
 *  2. 最大值(Maximum): 树的最右节点;
 *     最小值(minimum): 树的最左节点;
 *     某元素的前驱(Precursor): 左子树的最右;
 *     某元素的后继(Successor): 右子树的最左.
 *
 * 1. Recover Binary Search Tree
 * Description:
 *      Two elements of a binary search tree (BST) are swapped by mistake.
 *      Recover the tree without changing its structure.
 *      Note: A solution using O(n) space is pretty straight forward. Could you
 *      devise a constant space solution?
 * Solution: Inorder Traversal
 */
class BinarySearchTree {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    void RecoverBinarySearchTreeOne(TreeNode *root);
    /* Time complexity: O(n) Space complexity: O(1) */
    void RecoverBinarySearchTreeTwo(TreeNode *root);
    void DetectBroken(pair<TreeNode *, TreeNode *> &broken, TreeNode *prev, TreeNode *current);
protected:
    
private:

};

/* 
 * Title: Same Tree
 * Description:
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and 
 * the nodes have the same value.
 */
class SameBinaryTree {
public:
    /* 递归版 Time complexity: O(n) Space complexity: O(logn) */
    bool CheckSameBinaryTreeOne(TreeNode *root_one, TreeNode *root_two);
    /* 迭代版 Time complexity: O(n) Space complexity: O(logn) */
    bool CheckSameBinaryTreeTwo(TreeNode *root_one, TreeNode *root_two);
protected:
    
private:

};

/*
 * Title: Symmetric Tree
 * Description:
 * Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center).
 * For example, this binary tree is symmetric:
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
     1
    / \
   2   2
   \   \
   3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */
class SymmetricTree {
public:
    /* Recursively -> Time complexity: O(n) Space complexity: O(logn) */
    bool IsSymmetricTreeOne(TreeNode *root);
    bool CheckSameBinaryTree(TreeNode *root_one, TreeNode *root_two);
    
    /* Iteratively -> Time complexity: O(n) Space complexity: O(logn) */
    bool IsSymmetricTreeTwo(TreeNode *root);
protected:
    
private:

};

/*
 * Title: Balanced Binary Tree
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in 
 * which the depth of the two subtrees of every node never differ by more than 1.
 */
class BalancedBinaryTree {
public:
    /* Time complexity: O(n) Space complexity: O(n) */
    bool IsBalancedBinaryTree(TreeNode *root);
    /* return the height of 'root' if root is a balanced tree, otherwise return -1 */
    int BalancedHeight(TreeNode *root);
protected:
    
private:

};

/*
 * Title: Flatten Binary Tree to Linked List
 * Given a binary tree, flatten it to a linked list in-place.
 * For example, given
         1
        / \
       2   5
      / \   \
     3   4   6
 * The flattened tree should look like:
     1
      \
       2
        \
         3
          \
           4
            \
             5
              \
               6
 */
class FlattenBinaryTreetoLinkedList {
public:
    /* Recursively one -> Time complexity: O(n) Space complexity: O(logn) */
    void FlattenBinaryTreeOne(TreeNode *root);
    /* Iteratively -> Time complexity: O(n) Space complexity: O(logn) */
    void FlattenBinaryTreeTwo(TreeNode *root);
protected:
    
private:

};

/*
 * Title: Populating Next Right Pointers in Each Node II
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous solution still work?
 * Note: You may only use constant extra space.
 * For example,
 * Given the following binary tree,
        1
       /  \
      2    3
     / \    \
    4   5    7
 * After calling your function, the tree should look like:
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 */
class PopulatingNextRightPointersInEachNodeII {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    void PopulatingNextRightPointersOne(TreeLinkNode *root);
    /* Time complexity: O(n) Space complexity: O(1) */
    void PopulatingNextRightPointersTwo(TreeLinkNode *root);
protected:
    
private:

};

/*
 * Title one: Construct Binary Tree from Preorder and Inorder Traversal
 * Given preorder and inorder traversal of a tree, construct the binary tree. 
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Title two: Construct Binary Tree from Inorder and Postorder Traversal
 * Given inorder and postorder traversal of a tree, construct the binary tree. 
 * Note: You may assume that duplicates do not exist in the tree.
 */
class ConstructBinaryTree {
public:
    /* Recursively -> Time complexity: O(n) Space complexity: O(logn) */
    TreeNode *ConstructBinaryTreeFromPreorderAndInorderTraversal(vector<int>& preorder, vector<int>& inorder) {
        return BuildBinaryTreeOne(preorder.begin(), preorder.end(),
                         inorder.begin(), inorder.end());
    }

    template <typename InputIterator>
    TreeNode *BuildBinaryTreeOne(InputIterator preorder_begin, InputIterator preorder_end,
                                 InputIterator inorder_begin, InputIterator inorder_end);
    
    /* Recursively -> Time complexity: O(n) Space complexity: O(logn) */
    TreeNode *ConstructBinaryTreeFromInorderAndPostorderTraversal(vector<int>& inorder, vector<int>& postorder) {
        return BuildBinaryTreeTwo(inorder.begin(), inorder.end(),
                                  postorder.begin(), postorder.end());
    }

    template <typename InputIterator>
    TreeNode *BuildBinaryTreeTwo(InputIterator inorder_begin, InputIterator inorder_end,
                                 InputIterator postorder_begin, InputIterator postorder_end);
protected:
    
private:

};

/*
 * Title One: Unique Binary Search Trees
 * Given n, how many structurally unique BST's (binary search trees) that store 
 * values 1...n? For example, Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 *
 * Title Two: Unique Binary Search Trees II
 * Given n, generate all structurally unique BST's (binary search trees) that 
 * store values 1...n. For example, Given n = 3, your program should return all 
 * 5 unique BST's shown below.
    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
 */
class UniqueBinarySearchTrees {
public:
    /* 
     * Time complexity: O(n^2) Space complexity: O(n) 
     * Solution: 
     *    比如, 以 1 为根的树的个数,等于左子树的个数乘以右子树的个数,左子树是 0 个元素的树,
     * 右子树是 2 个元素的树。以 2 为根的树的个数,等于左子树的个数乘以右子树的个数,左子树是 
     * 1 个元素的树,右子树也是 1 个元素的树。依此类推。当数组为 1, 2, 3, ..., n 时,基于以
     * 下原则的构建的 BST 树具有唯一性:以 i 为根节点的树,其左子树由 [1, i-1] 构成,其右子树
     * 由 [i+1, n] 构成。定义 f (i) 为以 [1, i] 能产生的 Unique Binary Search Tree 
     * 的数目,则 如果数组为空,毫无疑问,只有一种 BST,即空树,f(0) = 1。 如果数组仅有一个元素 
     * 1,只有一种 BST,单个节点,f(1) = 1。如果数组有两个元素 1,2,那么有如下两种可能:
     * f(2) = f(0) * f(1) ,1 为根的情况 
     *      + f(1) ∗ f(0) ,2 为根的情况
     * 再看一看 3 个元素的数组,可以发现 BST 的取值方式如下:
     * f(3) = f(0) * f(2) ,1 为根的情况
     *      + f(1) ∗ f(1) ,2 为根的情况
     *      + f(2) ∗ f(0) ,3 为根的情况
     * 所以,由此观察,可以得出f的递推公式为: f(i) = ∑ f(k - 1) * f(i - k)[1 <= k <= i]
     */
    int GetNumberUniqueBinaryTrees(int n);
    
    /* Time complexity: O(n^2) Space complexity: O(n) */
    vector<TreeNode *> GenerateUniqueBinaryTrees(int n) {
        if (n == 0) return GenerateTree(1, 0);
        return GenerateTree(1, n);
    }
protected:
    
private:
    vector<TreeNode *> GenerateTree(int start, int end);

};

/*
 * Title: Validate Binary Search Tree
 * Given a binary tree, determine if it is a valid binary search tree (BST). 
 * Assume a BST is defined as follows:
 * • The left subtree of a node contains only nodes with keys less than the node’s key.
 * • The right subtree of a node contains only nodes with keys greater than the node’s key. 
 * • Both the left and right subtrees must also be binary search trees.
 */
class ValidateBinarySearchTree {
public:
    /* Time complexity: O(n) Space complexity: O(logn) */
    bool IsValidBST(TreeNode *root) {
        return IsValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool IsValidBST(TreeNode *root, int lower, int uppper);
protected:
    
private:

};

/*
 * Title: Convert Sorted Array to Binary Search Tree
 * Given an array where elements are sorted in ascending order, convert it to 
 * a height balanced BST.
 */
class ConvertSortedArrayToBinarySearchTree {
public:
    /* 
     * 分治法:
     * If we build BST from array, we can build it from top to bottom, like
     * 1. choose the middle one as root,
     * 2. build left sub BST via left part array
     * 3. build right sub BST via right part array
     * 4. do this recursively.
     * Time complexity: O(n) Space complexity: O(logn)
     */
    TreeNode *SortedArrayToBST(vector<int> &num) {
        if (num.empty()) {
            return nullptr;
        }
        return SortedArrayToBST(num.begin(), num.end());
    }
    
    template<typename RandomAccessIterator>
    TreeNode *SortedArrayToBST(RandomAccessIterator begin, RandomAccessIterator end);
protected:
    
private:

};

/*
 * Title: Convert Sorted List to Binary Search Tree
 * Given a singly linked list where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 */
class ConvertSortedListToBinarySearchTree {
public:
    /* 
     * 分治法,自顶向下:
     * Time complexity: O(NlogN) Space complexity: O(logn)
     */
    TreeNode *SortedListToBST(ListNode *head) {
        return SortedListToBST(head, ListLength(head));
    }

    TreeNode *SortedListToBST(ListNode *head, int length);
    
    /*
     * 自底而上:
     * Best Solution:
     *     As usual, the best solution requires you to think from another perspective.
     * In other words, we no longer create nodes in the tree using the top-down 
     * approach. We create nodes bottom-up, and assign them to its parents. The 
     * bottom-up approach enables us to access the list in its order while creating nodes.
     *     Below is the code for converting a singly linked list to a balanced BST. 
     * Please note that the algorithm requires the list’s length to be passed in 
     * as the function’s parameters. The list’s length could be found in O(N) time 
     * by traversing the entire list’s once. The recursive calls traverse the list 
     * and create tree’s nodes by the list’s order, which also takes O(N) time. 
     * Therefore, the overall run time complexity is still O(N).
     *
     * Time complexity: O(n) Space complexity: O(logn)
     */
    TreeNode *SortedListToBSTBottomUp(ListNode *head) {
        return SortedListToBSTBottomUp(head, 0, ListLength(head) - 1);
    }
    
    /*
     * C++中 *& 符号连用:
     * 指针的引用，指针它也是一个变量，*&就和普通变量的引用一样，也可以理解为指针变量的别名.
     * 如int*& a，那么在函数里面对a的值进行改变，那么在调用函数时传入的参数的指针值也会改变.
     */
    TreeNode *SortedListToBSTBottomUp(ListNode *& head, int start, int end);
    
protected:
    
private:
    int ListLength(ListNode *node) {
        int n = 0;
        while (node != nullptr) {
            node = node->next;
            ++n;
        }
        return n;
    }
    
    /* Get the nth node */
    ListNode *GetElement(ListNode *node, int n) {
        while (node && --n) {
            node = node->next;
        }
        return node;
    }
};

/*
 * Title One: Minimum Depth of Binary Tree
 * Given a binary tree, find its minimum depth. The minimum depth is the number 
 * of nodes along the shortest path from the root node down to the nearest leaf 
 * node.
 *
 * Title Two: Maximum Depth of Binary Tree
 * Given a binary tree, find its maximum depth. The maximum depth is the number 
 * of nodes along the longest path from the root node down to the farthest leaf node.
 */
class DepthOfBinaryTree {
public:
    /* Time compleixity: O(n) Space complexity: (logn) */
    int MinimumDepthOfBinaryTreeRecursively(TreeNode *root) {
        return MinimumDepth(root);
    }
    /* Time compleixity: O(n) Space complexity: (logn) */
    int MinimumDepthOfBinaryTreeIteratively(TreeNode *root);
    
    /* Time compleixity: O(n) Space complexity: (logn) */
    int MaximumDepthOfBinaryTreeRecursively(TreeNode *root);
protected:
    
private:
    int MinimumDepth(TreeNode *root);
};

/*
 * Title One: Path Sum
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
 * For example: Given the below binary tree and sum = 22,
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * Title Two: Path Sum II
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's 
 * sum equals the given sum. For example: Given the below binary tree and sum = 22,
         5
        / \
       4   8
      /   / \
     11  13  4
    /  \    / \
   7    2  5   1
 * return
    [
        [5,4,11,2],
        [5,8,4,5]
    ]
 */
class PathSum {
public:
    /* Time complexity: O(n) Space complexity: O(logn) */
    bool HasPathSum(TreeNode *root, int sum);
    
    /* Time complexity: O(n) Space complexity: O(logn) */
    vector<vector<int>> GetPathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        GetPathSum(root, result, path, sum);
        return result;
    }
    
protected:

private:
    void GetPathSum(TreeNode *root, vector<vector<int>> &result,
                    vector<int> &path, int sum);
};

/*
 * Title: Binary Tree Maximum Path Sum
 * Given a binary tree, find the maximum path sum. The path may start and end at 
 * any node in the tree.
 * For example: Given the below binary tree, Return 6.
     1
    / \
   2   3
 * Solution:
 * For each node like following, there should be four ways existing for max path:
 * 1. Node only
 * 2. L-sub + Node
 * 3. R-sub + Node
 * 4. L-sub + Node + R-sub
 * Keep trace the four path and pick up the max one in the end.
 */
class BinaryTreeMaximumPathSum {
public:
    /* Time complexity: O(n) Space complexity: O(logn) */
    int MaximumPathSum(TreeNode *root);
    int GetMaximumSum(void) {
        return max_sum_;
    }
protected:
    
private:
    int max_sum_ = INT_MIN;
};

/* 
 * Title: Populating Next Right Pointers in Each Node 
 * Given a binary tree
 * struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
   };
 * Populate each next pointer to point to its next right node. If there is no next 
 * right node, the next pointer should be set toNULL.
 * Initially, all next pointers are set to NULL.
 * Note:
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same 
 * level, and every parent has two children).
 * For example, Given the following perfect binary tree,
       1
      /  \
     2    3
    / \  / \
   4  5  6  7
 * After calling your function, the tree should look like:
       1 -> NULL
      /  \
     2 -> 3 -> NULL
    / \  / \
   4->5->6->7 -> NULL
 */
class PopulatingNextRightPointersInEachNode {
public:
    /* Time complexity: O(n) Space complexity: O(1) */
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode dummy(-1);
        for (TreeLinkNode *current = root, *prev = &dummy; current; current = current->next) {
            if (current->left != nullptr) {
                prev->next = current->left;
                prev = prev->next;
            }
            if (current->right != nullptr) {
                prev->next = current->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
protected:
    
private:

};

/* 
 * Title: Sum Root to Leaf Numbers
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
 * could represent a number. An example is the root-to-leaf path 1->2->3 which 
 * represents the number 123. Find the total sum of all root-to-leaf numbers.
 * For example,
    1
   / \
  2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 */
class SumRootToLeafNumbers {
public:
    /* Time complexity: O(n) Space complexity: O(logn) */
    int SumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
protected:
    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return sum;
        if (root->left == nullptr && root->right == nullptr) {
            return 10 * sum + root->val;
        }
        return dfs(root->left, 10 * sum + root->val) + dfs(root->right, 10 * sum + root->val);
    }
private:

};


#endif /* tree_operation_h */
