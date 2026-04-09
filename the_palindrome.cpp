/*
12. Valid Palindromes
Problem: You are given a string s containing blanks ('_') and an integer n. Your task is to count the total number of ways to fill the blanks such that the resultant string becomes a valid palindrome. Since the result can be large, return the answer modulo n.

Input:

s (String): The string containing blanks and other characters.
n (Integer): The modulus value.
Output: Return the number of valid palindromes that can be formed by filling the blanks, modulo n.

Constraints:

1 <= |s| <= 10^5 (Length of the string).
The string contains only lowercase alphabets and '_' representing blanks.
Example 1:

Input: s = "a_b_a", n = 1000000007
Output: 26
Explanation: The string is "a_b_a". To make this a palindrome, we can replace the blank with any letter (b), so there are 26 possible valid palindromes.

Example 2:

Input: s = "a\_a_", n = 1000000007
Output: 676
Explanation: The string is "a\_a_". The two blanks at the start and the end can each be filled with any letter (26 choices). The middle blanks must match their corresponding characters to form a palindrome. Hence, the total possible palindromes are 26 * 26 = 676.
*/

#include <bits/stdc++.h>
using namespace std;
int countValidPalindromes(string s, int mod) {
    int n = s.size();
    long long ways = 1;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i == j) {
            if (s[i] == '_') {
                ways = (ways * 26) % mod;
            }
        } else {
            if (s[i] == '_' && s[j] == '_') {
                ways = (ways * 26) % mod;
            }
            else if (s[i] == '_' || s[j] == '_') {
            }
            else {
                if (s[i] != s[j]) {
                    return 0; 
                }
            }
        }
        i++;
        j--;
    }
    return ways % mod;
}
int main() {
    string s;
    int mod;
    cin >> s >> mod;
    cout << countValidPalindromes(s, mod) << endl;
    return 0;
}
/*
TC:O(n)
SC:O(1)
*/