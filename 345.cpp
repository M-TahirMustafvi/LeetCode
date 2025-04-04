// Just Reverse Vowels in a string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool isVowel(char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
    
        string reverseVowels(string s) {
            int left = 0, right = s.length() - 1;
    
            while (left < right) {
                while (left < right && !isVowel(s[left])) left++;   // Move left to a vowel
                while (left < right && !isVowel(s[right])) right--; // Move right to a vowel
    
                if (left < right) {
                    swap(s[left], s[right]);  // Swap vowels
                    left++;
                    right--;
                }
            }
    
            return s;
        }
};

int main() {
    Solution solution;
    string input = "hello";
    string result = solution.reverseVowels(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;
    return 0;
}