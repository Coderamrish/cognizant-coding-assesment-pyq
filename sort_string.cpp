/*
10. Sort String
Problem: You are a librarian in a bustling library where  books are arranged in a single line, each represented by a letter from A to Z. One day in a hurry you mistakenly arranged some books out of order. Given a string S of length N representing the books, your task is to find and return an integer value representing the minimum number of books (indices in the string) that need to be moved to sort the row alphabetically.Books & Literature

Input Specification:

input1: An integer value N representing the length of string.
input2: A string S representing the current order of the books.
Output Specification: Return an integer representing the minimum number of books (indices in the string) that needs to be moved to sort the row alphabetically.

Example 1:

input1: 5
input2: helco
Output: 3
Explanation: The given string is "helco". When the string is sorted, it becomes "cehlo". So, to sort the given string, characters at the indices 0, 2, and 3 are needed to be rearranged. Since there are 3 indices whose characters need to be rearranged to sort the string 3 is returned as the output.

Example 2:

input1: 4
input2: asdf
Output: 3
Explanation: The given string is "asdf". When the string is sorted, it becomes "adfs". So, to sort the given string, characters at indices 1, 2, and 3 needs to be rearranged. Since there are 3 indices whose characters need to be rearranged to sort the string, 3 is returned as the output.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int minMoves (string s) {
    string t = s;
    sort(t.begin(), t.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return n - dp[n][n];
}
int main() {
    string s = "helco";
    cout << minMoves(s) << endl;
    return 0;
}
/*
TC:O(N^2)
SC:O(N^2)
*/