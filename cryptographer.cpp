/*
9. Cryptographer
Problem: An ancient journal was found containing an encrypted message. The encryption used in the journal shifts each character one position forward in the alphabet. For example 'a' becomes 'b', 'b' becomes 'c', and so on. However, 'z' wraps around and becomes 'a'. Alex, a cryptographer, needs to decrypt this journal by reversing the shift. Your task is to return the decrypted string by shifting each character one position back in the alphabet. For example:

The letter 'b' becomes 'a', 'c' becomes 'b', and so on.
If the letter is 'a', it becomes 'z'.
Note: The journal contains only lowercase English letters.

Input Specification:

input1: A string value consisting of lowercase English letters
Output Specification: Return the decrypted string after shifting all the characters one position back

Example 1:

input1: bcd
Output: abc
*/
#include <iostream>
#include <string>
using namespace std;
string decrypt(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            s[i] = 'z';
        } else {
            s[i] = s[i] - 1;
        }
    }
    return s;
}
int main() {
    string s = "bcd";
    cout << decrypt(s);
    return 0;
}
/*
TC:O(n)
SC:O(1)
*/