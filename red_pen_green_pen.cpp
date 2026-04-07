/*
6. Red Pen Green Pen
Problem: You are a teacher creating an engaging  math activity for your students by writing N numbers on the classroom whiteboard. You use a green pen for odd numbers and a red pen for even numbers. Your task is to find and return an integer value representing the number of times you need to switch from the green pen to the red pen while writing these numbers.Mathematics

Input Specification:

input1: An integer value N
input2: An integer array representing the numbers to be written
Output Specification: Return an integer value representing the number of times you need to switch from the green pen to the red pen while writing these numbers.

Example 1:

input1: 5
Input2: (1,2,1,6,10,9)
Output: 2
Explanation: The given sequence which he has to write is 1->2->1->6->10->9 Below is the sequence of pen, the teacher has to use:

Green pen to write 1
Red pen to write 2
Green pen to write 1
Red pen to write 6 and 10
Green pen to write 9
Therefore, we need to change from green pen to red twice. Hence, 2 is returned as output.

Example 2:

input1: 6
input2: (70,23,13,26,72,19)
Output: 1
Explanation: The given sequence which he has to write is 70->23->13->26->72->19
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countSwitches(int N, vector<int>& arr) {
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if ((arr[i - 1] % 2 != 0) && (arr[i] % 2 == 0)) {
            cnt++;
        }
    }
    return cnt;
}
int main () {
    int N = 6;
    vector<int> arr = {1,2,1,6,10,9};
    cout << countSwitches(N, arr);
    return 0;
}
/*
TC:O(n)
SC:O(1)
*/