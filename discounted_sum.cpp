/*
11. Discounted Sum
Problem: You are given an array of integers and an integer n. Your task is to find the sum of the first n largest unique elements from the array. Subtract the largest element (from those n elements) from the sum (this is called a discount). Finally, return the result after applying the discount.

Input:

arr (List of integers): The array of integers.
n (Integer): The number of largest elements to sum.
Output: The resultant value after subtracting the largest element from the sum of the first n largest elements.

Constraints:

1 ≤ n ≤ length of arr.
If n is greater than the number of unique elements, the output should be 0.
Example 1:

Input: arr = [5, 2, 9, 1, 7, 4, 6], n = 3
Output: 13
Explanation: The largest unique elements are [9, 7, 6]. Sum of these is 9 + 7 + 6 = 22. After subtracting the largest element (9), the result is 22 - 9 = 13.

Example 2:

Input: arr = [5, 2, 9, 1, 7, 4, 6], n = 1
Output: 0
Explanation: The largest unique element is 9. After subtracting it from itself, the result is 9 - 9 = 0.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
long long discountedSum(std::vector<int>& arr, int n) {
    std::set<int> uniqueSet(arr.begin(), arr.end());
    if (n > uniqueSet.size()) {
        return 0;
    }
    std::vector<int> uniqueElements(uniqueSet.begin(), uniqueSet.end());
    long long sum = 0;
    int totalUnique = uniqueElements.size();
    for (int i = totalUnique - n; i < totalUnique - 1; ++i) {
        sum += uniqueElements[i];
    }
    return sum;
}
int main() {
    std::vector<int> arr1 = {5, 2, 9, 1, 7, 4, 6};
    int n1 = 3;
    std::cout << "Example 1 Output: " << discountedSum(arr1, n1) << std::endl; 
    std::vector<int> arr2 = {5, 2, 9, 1, 7, 4, 6};
    int n2 = 1;
    std::cout << "Example 2 Output: " << discountedSum(arr2, n2) << std::endl; 
    std::vector<int> arr3 = {1, 1, 1};
    int n3 = 2;
    std::cout << "Constraint Case Output: " << discountedSum(arr3, n3) << std::endl; 
    return 0;
}