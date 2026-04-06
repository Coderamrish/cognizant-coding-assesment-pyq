/*
1. Minimum Sum
Problem: You are given two integer arrays A and B of length N on which you have to perform below operation: In one operation, you can swap any two elements of 'A' or any two elements of 'B'Programming

Your task is to find and return an integer value representing the minimum possible sum of A[i]*B[i] after performing the above operation any number of times. Note: The operation can also be performed 0 number of times.

Input Specification:

input1: An integer value N representing the size of arrays.
input2: An integer array A
input3: An integer array B
Output Specification: Return an integer value representing the minimum possible sum of A[i]*B[i] after performing the above operation any number of times.

Example 1:

input1: 4
input2: {1,4,1,6}
input3: {1,4,3,4}
Output: 25
Explanation: Here A = {1,4,3,2} and B = {1,4,3,4}. To minimize the sum, we can swap the first two elements of A i.e., 4 and 1. The array will now become (4,1,3,2). The sum obtained will be 25, which is the minimum. Hence, 25 is returned as the output.

Example 2:

input1: 3
input2: (4,1,6)
input3: (3,1,2)
Output: 17
Explanation: Here, A = (4,1,6) and B= (3,1,2). To minimize the sum, we can swap the first two elements of A. i.e., 4 and 1 and the last two elements of B i.e., 1 and 2. The array A and B will now become (1,4,6) and (3,2,1) respectively. The sum obtained will be 17, which is the minimum. Hence, 17 is returned as the output.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minimumSum(int N, vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }
    return result;
}
int main () {
    int N = 4;
    vector<int> A = {1,4,1,6};
    vector<int> B = {1,4,3,4};
    cout << minimumSum(N, A, B);
    return 0;
}
/*
TC: o(n log n)
sc:o(1)
*/