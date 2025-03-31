// Count Vowel String in Ranges

#include<bits/stdc++.h>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to count vowels in a given range of a string
int countVowelsInRange(const string& s, int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isVowel(s[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    // Input string
    string s = "hello world";

    // Input range
    int start = 0, end = 4; // Example: range [0, 4] corresponds to "hello"

    // Count vowels in the range
    int vowelCount = countVowelsInRange(s, start, end);

    // Output the result
    cout << "Number of vowels in the range [" << start << ", " << end << "] is: " << vowelCount << endl;

    return 0;
}