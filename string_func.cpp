/*
Write a func on that takes a string as input and returns the string reversed
*/
#include <iostream>
#include <string>
using namespace std;
string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}
int main() {
    string str = "hello";
    cout << reverseString(str);
    return 0;
}
/*
TC:O(N)
SC:O(1)
*/