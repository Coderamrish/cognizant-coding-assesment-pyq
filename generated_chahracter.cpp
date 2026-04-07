/*
8. Generated Numbers
Problem: You have a jar that initially contains N marbles. You can perform the following operations in any order and any number of times:

Remove A marbles from the jar.
Remove B marbles from the jar.
Your task is to find and return the number of unique positive values that can represent the number of marbles left in the jar after performing these operations. The initial number of marbles N should also be included in the count of unique values.

Note: The jar should never become empty during the operations.

Input Specification:

input1: An integer value N, representing the initial number of marbles.
input2: An integer value A, the number of marbles to be removed in the first operation.
input3: An integer value B, the number of marbles to be removed in the second operation.
Output Specification: Return an integer representing the number of unique positive values for the number of marbles left in the jar.

Example 1:

Input: N = 4, A = 1, B = 2
Output: 4
Explanation: Starting with 4 marbles:

Removing 1 marble leaves 3 marbles.
Removing 2 marbles leaves 2 marbles.
Removing 1 marble, then 2 marbles, leaves 1 marble.
The initial count of 4 marbles is also considered.
Unique values: {1, 2, 3, 4}. Therefore, the output is 4.

Example 2:

Input: N = 10, A = 2, B = 5
Output: 8
Explanation: Starting with 10 marbles:

Removing 2 marbles leaves 8 marbles.
Removing 5 marbles leaves 5 marbles.
Removing 2 marbles from 8 marbles leaves 6 marbles.
Removing 5 marbles from 6 marbles leaves 1 marble.
Removing 2 marbles from 6 marbles leaves 4 marbles.
Removing 5 marbles from 10 marbles leaves 5 marbles.
Removing 2 marbles from 4 marbles leaves 2 marbles.
Unique values: {1, 2, 3, 4, 5, 6, 8, 10}. Therefore, the output is 8.
*/
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
int countValues(int N, int A, int B) {
    unordered_set<int>visited;
    queue<int>q;
    q.push(N);
    visited.insert(N);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr - A > 0 && visited.find(curr - A) == visited.end()) {
            visited.insert(curr - A);
            q.push(curr - A);
        }
        if (curr - B > 0 && visited.find(curr - B) == visited.end()) {
            visited.insert(curr - B);
            q.push(curr - B);
        }
    }
    return visited.size();
}
int main () {
    int N  = 10, A = 2, B = 5;
    cout << countValues(N, A ,B);
    return 0;
}