//
//  test_search_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 6/1/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

//
//  test_sort_operation.cpp
//  leetcode
//
//  Created by NoteFAN on 5/25/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//

#include "search_operation.h"

using namespace std;

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    cout << "\nTest: Number Zero" << endl;
    vector<int> num_zero = {5, 7, 7, 8, 8, 10};
    SearchForRange search_for_range;
    vector<int> result_zero = search_for_range.SearchRangeTwo(num_zero, 8);
    cout << "[ ";
    for (vector<int>::iterator it = result_zero.begin(); it != result_zero.end(); ++it) {
        cout << *it << " ";
    }
    cout << "]" << endl;
    
    cout << "\nTest: Number One" << endl;
    SearchInsertPosition search_insert_position;
    int result_one = search_insert_position.InsertPosition(num_zero, 9);
    cout << "Result: " << result_one << endl;
    
    cout << "\nTest: Number Two" << endl;
    vector<vector<int>> num_two = {{1, 3 ,5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    SearchMatrix search_matrix;
    bool result_two = search_matrix.Search2DMatrix(num_two, 3);
    cout << "Result: " << result_two << endl;
    
    cout << "\nTest: Number Three" << endl;
    vector<int> num_three = {1, 2, 3};
    Subsets subsets;
    vector<vector<int>> result_three = subsets.FindSubsets(num_three);
    for (size_t i = 0; i < result_three.size(); ++i) {
        cout << "Result " << i << ":";
        for (size_t j = 0; j < result_three[i].size(); ++j) {
            cout << result_three[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Four" << endl;
    vector<int> num_four = {1, 2, 2};
    SubsetsII subsets_II;
    vector<vector<int>> result_four = subsets_II.FindSubsetsOne(num_four);
    for (size_t i = 0; i < result_four.size(); ++i) {
        cout << "Result " << i << ":";
        for (size_t j = 0; j < result_four[i].size(); ++j) {
            cout << result_four[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "\nTest: Number Five" << endl;
    vector<int> num_five = {1, 2, 3};
    Permutations permutations;
    vector<vector<int>> results_five = permutations.GetPermutationsTwo(num_five);
    for (size_t i = 0; i < results_five.size(); ++i) {
        cout << "Result " << i << ":";
        for (size_t j = 0; j < results_five[i].size(); ++j) {
            cout << results_five[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Six" << endl;
    vector<int> num_six = {1, 1, 2, 2};
    PermutationsII permutations_II;
    vector<vector<int>> results_six = permutations_II.GetPermutationsTwo(num_six);
    for (size_t i = 0; i < results_six.size(); ++i) {
        cout << "Result " << i << ":";
        for (size_t j = 0; j < results_six[i].size(); ++j) {
            cout << results_six[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Seven" << endl;
    Combinations combinations;
    vector<vector<int>> result_seven = combinations.GetCombinationsOne(4, 2);
    for (size_t i = 0; i < result_seven.size(); ++i) {
        cout << "Result " << i << ":";
        for (size_t j = 0; j < result_seven[i].size(); ++j) {
            cout << result_seven[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Eight" << endl;
    LetterCombinationsOfPhoneNumber letter_combinations;
    string digits = "23";
    vector<string> result_eight = letter_combinations.LetterCombinationsTwo(digits);
    for (vector<string>::iterator it = result_eight.begin(); it != result_eight.end(); ++it) {
        cout << *it << endl;
    }
    
    cout << "\nTest: Number Nine" << endl;
    string start_nine = "hit";
    string end_nine = "cog";
    unordered_set<string> dict_nine({"hot","dot","dog","lot","log"});
    WordLadder word_latter;
    int result_nine = word_latter.WordLadderLength(start_nine, end_nine, dict_nine);
    cout << "result: " << result_nine << endl;
    
    cout << "\nTest: Number Ten" << endl;
    string start_ten = "hit";
    string end_ten = "cog";
    unordered_set<string> dict_ten({"hot","dot","dog","lot","log"});
    vector<vector<string>> results_ten = word_latter.WordLadderLengthII(start_ten,
                                                                         end_ten,
                                                                         dict_ten);
    for (size_t i = 0; i < results_ten.size(); ++i) {
        cout << "Result " << i << ":";
        for (size_t j = 0; j < results_ten[i].size(); ++j) {
            cout << results_ten[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Eleven" << endl;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    SurroundedRegions surrounded_regions;
    surrounded_regions.Regions(board);
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Twelve" << endl;
    string s_twelve = "aabbb";
    PalindromePartitioning palindrome_partitioning;
    // vector<vector<string>> results_twelve = palindrome_partitioning.Partition(s_twelve);
    vector<vector<string>> results_twelve = palindrome_partitioning.PartitionDynamic(s_twelve);
    for (size_t i = 0; i < results_twelve.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < results_twelve[i].size(); ++j) {
            cout << results_twelve[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Thirteen" << endl;
    UniquePaths unique_paths;
    int result_thirteen = unique_paths.UniquePathsOne(3, 7);
    cout << "Result: " << result_thirteen << endl;
    result_thirteen = unique_paths.UniquePathsTwo(3, 7);
    cout << "Result: " << result_thirteen << endl;
    result_thirteen = unique_paths.UniquePathsThree(3, 7);
    cout << "Result: " << result_thirteen << endl;
    result_thirteen = unique_paths.UniquePathsFour(3, 7);
    cout << "Result: " << result_thirteen << endl;
    
    cout << "\nTest: Number Fourteen" << endl;
    UniquePathsII unique_pathes_ii;
    vector<vector<bool> > obstacles_grids(3, vector<bool>(3, false));
    // obstacles_grids[0][1] = true;
    obstacles_grids[1][1] = true;
    // obstacles_grids[1][0] = true;
    int result_fourteen = unique_pathes_ii.UniquePaths(obstacles_grids);
    cout << "Result: " << result_fourteen << endl;
    
    cout << "\nTest: Number Fifteen" << endl;
    NQueens n_queues;
    vector<vector<string>> results_fifteen = n_queues.SolveNQueens(4);
    for (size_t i = 0; i < results_fifteen.size(); ++i) {
        cout << "[" << endl;
        for (size_t j = 0; j < results_fifteen[i].size(); ++j) {
            cout << " " <<results_fifteen[i][j] << endl;
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    cout << "\nTest: Number Sixteen" << endl;
    RestoreAddresses restore_addresses;
    string ip_address = "25525511135";
    vector<string> results_sixteen = restore_addresses.RestoreIPAddress(ip_address);
    cout << "[" << endl;
    for (size_t i = 0; i < results_sixteen.size(); ++i) {
        cout << results_sixteen[i] << " " << endl;
    }
    cout << "]" << endl;
    
    cout << "\nTest: Number Seventeen" << endl;
    vector<int> numbers_seventeen = {2,3,6,7};
    int target_seventeen = 7;
    CombinationsSum combinations_sum;
    vector<vector<int>> results_seventeen = combinations_sum.FindCombinations(numbers_seventeen,
                                                                              target_seventeen);
    for (size_t i = 0; i < results_seventeen.size(); ++i) {
        cout << "[ ";
        for (size_t j = 0; j < results_seventeen[i].size(); ++j) {
            cout << results_seventeen[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    numbers_seventeen = {10,1,2,7,6,1,5};
    target_seventeen = 8;
    results_seventeen = combinations_sum.FindCombinationsII(numbers_seventeen,
                                                            target_seventeen);
    for (size_t i = 0; i < results_seventeen.size(); ++i) {
        cout << "[ ";
        for (size_t j = 0; j < results_seventeen[i].size(); ++j) {
            cout << results_seventeen[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    cout << "\nTest: Number Eighteen" << endl;
    GenerateParentheses generate_parentheses;
    vector<string> results_eighteen = generate_parentheses.Parentheses(3);
    for (size_t i = 0; i < results_eighteen.size(); ++i) {
        cout << results_eighteen[i] << endl;
    }
    
    cout << "\nTest: Number Eighteen" << endl;
    vector<vector<char>> board_eighteen = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    SudokuSolver sudoku_solver;
    if (sudoku_solver.SolveSudoku(board_eighteen)) {
        for (size_t i = 0; i < board_eighteen.size(); ++i) {
            cout << "{ ";
            for (size_t j = 0; j < board_eighteen[i].size(); ++j) {
                cout << board_eighteen[i][j] << " ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }
    
    cout << "\nTest: Number Nineteen" << endl;
    vector<vector<char>> board_nineteen = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    // string word_nineteen = "ABCCED";
    string word_nineteen = "SFCS";
    // string word_nineteen = "ABCB";
    WordSearch word_search;
    cout << word_search.ExistWord(board_nineteen, word_nineteen) << endl;

    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




