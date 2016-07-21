//
//  test_binary_tree.cpp
//  leetcode
//
//  Created by NoteFAN on 5/12/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <math.h>
#include "tree_operation.h"

using namespace std;

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    cout << "Test: Number Zero" << endl;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);
    BinaryTree binary_tree;
    // Preorder Traversal
    vector<int> result_zero = binary_tree.BinaryTreePreorderTraversalThree(root);
    cout << "Preorder Traversal:" << endl;
    for (vector<int>::iterator it = result_zero.begin(); it != result_zero.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Inorder Traversal
    result_zero = binary_tree.BinaryTreeInorderTraversalThree(root);
    cout << "Inorder Traversal:" << endl;
    for (vector<int>::iterator it = result_zero.begin(); it != result_zero.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Postorder Traversal
    result_zero = binary_tree.BinaryTreePostorderTraversalThree(root);
    cout << "Postorder Traversal:" << endl;
    for (vector<int>::iterator it = result_zero.begin(); it != result_zero.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "\nTest: Number One" << endl;
    vector<vector<int>> result_one = binary_tree.BinaryTreeLevelOrderTraversalOne(root);
    for (size_t i = 0; i < result_one.size(); ++i) {
        for (size_t j = 0; j < result_one[i].size(); ++j) {
            cout << result_one[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest: Number Two" << endl;
    vector<vector<int>> result_two = binary_tree.BinaryTreeZigzagLevelOrderTraversalTwo(root);
    for (size_t i = 0; i < result_two.size(); ++i) {
        for (size_t j = 0; j < result_two[i].size(); ++j) {
            cout << result_two[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest: Number Three" << endl;
    TreeNode *root_three = new TreeNode(4);
    root_three->left = new TreeNode(2);
    root_three->right = new TreeNode(1);
    root_three->left->left = new TreeNode(5);
    root_three->left->right = new TreeNode(3);
    BinarySearchTree binary_search_tree;
    binary_search_tree.RecoverBinarySearchTreeTwo(root_three);
    vector<int> result_three = binary_tree.BinaryTreeInorderTraversalThree(root_three);
    for (vector<int>::iterator it = result_three.begin(); it != result_three.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "\nTest: Number Four" << endl;
    TreeNode *root_four = new TreeNode(4);
    root_four->left = new TreeNode(2);
    root_four->right = new TreeNode(1);
    root_four->left->left = new TreeNode(5);
    root_four->left->right = new TreeNode(3);
    BalancedBinaryTree balanced_binary_tree;
    bool result_four = balanced_binary_tree.IsBalancedBinaryTree(root_four);
    cout << "result four:" << result_four << endl;
    
    cout << "\nTest: Number Five" << endl;
    vector<int> root_five = {1, 2, 3, 4, 5};
    vector<int>::iterator it_five = find(root_five.begin(), root_five.end(), 4);
    size_t length_five = distance(root_five.begin(), it_five);
    size_t result_five = distance(root_five.begin(), root_five.end());
    cout << length_five << " " << result_five << endl;
    
    cout << "\nTest: Number Six" << endl;
    TreeNode *root_six = new TreeNode(4);
    root_six->left = new TreeNode(2);
    root_six->right = new TreeNode(1);
    root_six->left->left = new TreeNode(5);
    root_six->left->right = new TreeNode(3);
    DepthOfBinaryTree depth_of_binary_tree;
    int minimum_length = depth_of_binary_tree.MinimumDepthOfBinaryTreeRecursively(root_six);
    cout << "Result Recursively: " << minimum_length << endl;
    minimum_length = depth_of_binary_tree.MinimumDepthOfBinaryTreeIteratively(root_six);
    cout << "Result Iteratively: " << minimum_length << endl;
    int maximum_length = depth_of_binary_tree.MaximumDepthOfBinaryTreeRecursively(root_six);
    cout << "Result Recursively: " << maximum_length << endl;
    
    cout << "\nTest: Number Seven" << endl;
    TreeNode *root_seven = new TreeNode(4);
    root_seven->left = new TreeNode(2);
    root_seven->right = new TreeNode(1);
    root_seven->left->left = new TreeNode(5);
    root_seven->left->right = new TreeNode(3);
    root_seven->right->left = new TreeNode(7);
    root_seven->right->right = new TreeNode(6);
    PathSum path_sum;
    bool result_seven = path_sum.HasPathSum(root_seven, 11);
    cout << "result: " << result_seven << endl;
    vector<vector<int>> result_seven_one = path_sum.GetPathSum(root_seven, 11);
    for (size_t i = 0; i < result_seven_one.size(); ++i) {
        for (size_t j = 0; j < result_seven_one[0].size(); ++j) {
            cout << result_seven_one[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTest: Number Eight" << endl;
    TreeNode *root_eight = new TreeNode(4);
    root_eight->left = new TreeNode(2);
    root_eight->right = new TreeNode(1);
    root_eight->left->left = new TreeNode(5);
    root_eight->left->right = new TreeNode(3);
    root_eight->right->left = new TreeNode(7);
    root_eight->right->right = new TreeNode(6);
    BinaryTreeMaximumPathSum binary_tree_maximum_path_sum;
    binary_tree_maximum_path_sum.MaximumPathSum(root_eight);
    cout << "result: " << binary_tree_maximum_path_sum.GetMaximumSum() << endl;
    
    cout << "\nTest: Number Nine" << endl;
    SumRootToLeafNumbers sum_root_to_leaf_numbers;
    int result_nine = sum_root_to_leaf_numbers.SumNumbers(root_eight);
    cout << "result: " << result_nine << endl;
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




