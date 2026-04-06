/*
3. Knowledge Enhancement
Problem: Alex is a high school student who loves reading and has a summer break coming up. He has a list of books he wants to read, with each book's estimated reading time stored in an array A. Alex has N hours available during the break for reading. Your task is to help Alex determine the maximum number of books he can read without exceeding his total available reading hours.

Input Specification:

input1: An integer array A, where each element represents the estimated time to read each book.
input2: An integer N, representing the total number of hours Alex has available for reading.
input3: An integer size, representing the size of the array A.
Output Specification: Return an integer value representing the maximum number of books Alex can read without exceeding his total available reading hours.Books & Literature

Example 1:

input1: [4, 2, 3, 1]
input2: 5
input3: 4
Output: 2
Explanation: Here N=5 and Alex has 4 books with reading times of 4, 2, 3, and 1 respectively then

The optimal way to utilize the 5 hours is to read the books with reading times of 2 and 1 hour.
If he starts reading the book within 3 hours, then it will exceed the time limit. The maximum number of books that can be read is 2.
Hence, 2 is returned as output.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxBooks(vector<int>& A, int N) {
    sort(A.begin(), A.end());
    int cnt  = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (sum + A[i] <= N) {
            sum += A[i];
            cnt++;
        } else {
            break;
        }
    }
    return cnt;
}
int main() {
    vector<int> A = {4,2,3,1};
    int N = 5;
    cout << maxBooks(A, N);
    return 0;
}
/*
TC:O(n log n)
SC:O(1)
if we need more optimal solution then we can use the countinng algo tc:O(n) sc :o(1)

if the interviewer told us to not use the sort function the we can uise the min heap to solve it with the priority queue
tc:o(n log n)
SC:O(N)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int maxBooks(vector<int>& A, int N) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : A) {
        pq.push(x);
    }
    int sum = 0, count = 0;
    while (!pq.empty()) {
        int smallest = pq.top();
        pq.pop();
        if (sum + smallest <= N) {
            sum += smallest;
            count++;
        } else {
            break;
        }
    }
    return count;
}
int main() {
    vector<int> A = {4, 2, 3, 1};
    int N = 5;
    cout << maxBooks(A, N);
    return 0;
}