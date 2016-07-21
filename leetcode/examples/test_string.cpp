//
//  test_string.cpp
//  leetcode
//
//  Created by NoteFAN on 4/21/16.
//  Copyright © 2016 NoteFAN. All rights reserved.
//
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <math.h>
#include "basic_string_operation.h"

int main(int argc, char *argv[])
{
    clock_t start, finish;
    double total_time;
    start = clock();
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    cout << "Test: Number Zero" << endl;
    string string_one("A man, a plan, a canal: Panama");
    ValidPalindrome valid_palindrome;
    if (valid_palindrome.IsValidPolindrome(string_one)) {
        cout << "The string is a valid palindrome." << endl;
    } else {
        cout << "The string is not a valid palindrome." << endl;
    }
    
    cout << "\nTest: Number One" << endl;
    const char haystack[] = "check the result, the result of phone test.";
    const char needle[] = "result";
    ImplementStr implement_str;
    char *p_one = implement_str.FirstOccurrenceOne(haystack, needle);
    char *pp_one = implement_str.FirstOccurrenceTwo(haystack, needle);
    if (p_one) {
        cout << "The result(one):" << *p_one << endl;
    } else {
        cout << "No occurrence." << endl;
    }
    if (pp_one) {
        cout << "The result(two):" << *pp_one << endl;
    } else {
        cout << "No occurrence." << endl;
    }
    
    cout << "\nTest: Number Two" << endl;
    const char *str_two = "-12345x213";
    StringToInteger string_to_integer;
    int result_two = string_to_integer.atoi(str_two);
    cout << "Result: " << result_two << endl;
    
    cout << "\nTest: Number Three" << endl;
    string one = "1111111";
    string two = "101010";
    AddBinary add_binary;
    string result_three = add_binary.AddBinaryOne(one, two);
    cout << "result: " << result_three << endl;
    
    cout << "\nTest: Number Four" << endl;
    
    cout << "\nTest: Number Five" << endl;
    string s_five = "aab";
    string p_five = "c*a*b";
    RegularExpressionMatching regular_expression_matching;
    bool result_five = regular_expression_matching.IsMatch(s_five, p_five);
    cout << "result:" << result_five << endl;
    
    cout << "\nTest: Number Six" << endl;
    string s_six = "aab";
    string p_six = "c*a*b";
    WildcardMatching wildcard_matching;
    bool result_six = wildcard_matching.IsMatchTwo(s_six, p_six);
    cout << "result:" << result_six << endl;
    
    cout << "\nTest: Number Seven" << endl;
    string s_seven = "abcdedcbsawffgff";
    LongestPalindromicSubstring longest_palindromic_substring;
    string result_seven = longest_palindromic_substring.LongestPalindromicSubstringThree(s_seven);
    cout << "result:" << result_seven << endl;
    
    cout << "\nTest: Number Eight" << endl;
    string s_eight = " 0.1 ";
    string ss_eight = "1 a";
    string sss_eight = "2e10";
    ValidNumber valid_number;
    cout << "result one:" << valid_number.IsNumberOne(s_eight) << " ";
    cout << valid_number.IsNumberOne(ss_eight) << " ";
    cout << valid_number.IsNumberOne(sss_eight) << endl;
    cout << "result two:" << valid_number.IsNumberTwo(s_eight) << " ";
    cout << valid_number.IsNumberTwo(ss_eight) << " ";
    cout << valid_number.IsNumberTwo(sss_eight) << endl;
    
    cout << "\nTest: Number Nine" << endl;
    IntegerToRoman integer_to_roman;
    string result_nine = integer_to_roman.IntToRoman(3999);
    cout << "result:" << result_nine <<endl;
    RomanToInteger roman_to_integer;
    int result_nine_other = roman_to_integer.RomanToInt(result_nine);
    cout << "result:" << result_nine_other << endl;
    result_nine_other = roman_to_integer.RomanToIntOne(result_nine);
    cout << "result:" << result_nine_other << endl;
    
    cout << "\nTest: Number Ten" << endl;
    CountSay count_say;
    for (int i = 1; i <= 5; ++i) {
        string result_ten = count_say.CountAndSay(i);
        cout << "result:" << result_ten << endl;
    }
    
    cout << "\nTest: Number Eleven" << endl;
    vector<string> strs;
    strs.push_back("jiangfna");
    strs.push_back("jiangfan");
    strs.push_back("jangifan");
    strs.push_back("fan");
    strs.push_back("fna");
    Anagrams anagrams;
    unordered_map<string, vector<string>> result_eleven = anagrams.GetAnagrams(strs);
    for (unordered_map<string, vector<string>>::iterator it = result_eleven.begin();
         it != result_eleven.end(); ++it) {
        cout << "The key:" << it->first << endl;
        for (vector<string>::iterator element = it->second.begin();
             element != it->second.end(); ++element) {
            cout << "   " << *element << endl;
        }
    }
    
    cout << "\nTest: Number Twelve" << endl;
    SimplifyPath simiplity;
    string result_twelve = simiplity.GetSimplityPath("/a/./b/../../c/");
    cout << "result:" << result_twelve << endl;
    
    cout << "\nTest: Number Thirteen" << endl;
    string str_thirteen = "Hello World";
    LengthOfLastWord length_of_last_word;
    size_t result_thirteen = length_of_last_word.GetLengthOfLastWordOne(str_thirteen);
    cout << "result:" << result_thirteen << endl;
    result_thirteen = length_of_last_word.GetLengthOfLastWordTwo(str_thirteen);
    cout << "result:" << result_thirteen << endl;
    
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
    finish = clock();
    total_time = double(finish - start) * 1000 / CLOCKS_PER_SEC; // unit: ms
    cout << "\n\nTime:" << total_time << " ms" << endl;
    
    return 0;
}




