/*
4. The Distance
Problem: Jim has a password represented by a string S consisting of lowercase English letters (a-z) and digits (0-9). The distance between two characters is defined as the absolute difference between their indices in the string. Your task is to find and return the maximum distance between two non-similar characters within the given password S.

Note: The distance between two adjacent characters is 1.

Input Specification:

input1: A string S containing lowercase English letters (a-z) and digits (0-9).
Output Specification: Return an integer representing the maximum distance between two non-similar characters within the given password S.

Example 1:

Input: abc10
Output: 4
Explanation: In the string abc10, the maximum distances between non-similar characters are:

Between a and 0 (indices 0 and 4): Distance is 4.
Between b and 0 (indices 1 and 4): Distance is 3.
Other combinations yield a shorter distance. Therefore, the maximum distance between two non-similar characters is 4.

Example 2:

Input: bbbb
Output: 0
Explanation: In the string bbbb, all characters are the same, so there are no two non-similar characters to compare. Thus, the maximum distance between two non-similar characters is 0.
*/
#include <iostream>
using namespace std;
int maxDistance(string S) {
    int n = S.size();
    if (S[0] != S[n - 1]) {
        return n - 1;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (S[i] != S[0]) {
            ans = max(ans, i); 
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (S[i] != S[n - 1]) {
            ans = max(ans, n - 1 - i);
            break;
        }
    }
    return ans;
}
int main() {
    string S = "abc10";
    cout << maxDistance(S);
    return 0;
}
/*
TC:O(n)
SC:O(1)
*/