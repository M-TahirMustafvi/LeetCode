#include <iostream>
#include <string>
//#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    string filtered;
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }

    int left = 0, right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << boolalpha; // Print bools as true/false
    cout << "Example 1: " << isPalindrome(s1) << endl; // Output: true
    cout << "Example 2: " << isPalindrome(s2) << endl; // Output: false
    cout << "Example 3: " << isPalindrome(s3) << endl; // Output: true

    return 0;
}