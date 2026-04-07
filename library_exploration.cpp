/*
Problem: There is a library having N shelves in it. Each shelf is labeled from 1 to N and is stocked with A[i]  books on each shelf. You have to select books only from shelves that have prime-numbered labels. Additionally, there is a limit of K books that you can select from each shelf.

Your task is to find and return an integer value representing the maximum number of books you can collect during a single visit to the library.

Note: Assume 1-based indexing.

Input Specification:

input1: An integer value N representing the number of shelves in the library.
input2: An integer value K representing the maximum number of books you can collect from each shelf.
input3: An integer array A representing the number of books on each shelf.
Output Specification: Return an integer value representing the maximum number of books that you can collect during a single visit to the library.

Example 1:

input1: 2
input2: 4
input3: [10, 2]
Output: 2
Explanation:
Here, the given value of K is 4, which is the maximum number of books we can select from each shelf. Since we only have to select books from prime-numbered shelves, that is the shelf with index 2, and this shelf contains 2 books. So, we collect all books from it. Therefore, 2 is returned as the output.Books & Literature

Example 2:

input1: 4
input2: 5
input3: [3, 7, 5, 6]
Output: 10
*/
#include <iostream>
#include <vector>
using namespace std;
vector <bool> sieve(int N) {
    vector <bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
if(isPrime[i]) {
    for (int j = i * i; j <= N; j+= i) {
        isPrime[j] = false;
    }
}
    }
    return isPrime;
}
int maxBooks(int N, int K, vector<int>& A) {
    vector <bool> isPrime = sieve(N);
    int total = 0;
    for (int i = 2; i <= N; i++) {
        if(isPrime[i]) {
            total += min(A[i - 1], K);
        }
    }
    return total;
}
int main() {
    int N = 4, K = 5;
    vector<int>A = {3,7,5,6};
    cout << maxBooks(N, K, A);
    return 0;
}
/*
TC:O(N log log N) 
SC: O(N)
*/