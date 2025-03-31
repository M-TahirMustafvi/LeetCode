//Alternatively merge 2 strings, very simple approach.
#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        string result;
        int i = 0, j = 0;

        // Merging Alternately
        while(i < s1 && j < s2) {
            result.push_back(word1[i++]);
            result.push_back(word2[j++]);
        }

        // Left Over Loop for s1
        while(i < s1) {
            result.push_back(word1[i]);
            i++;
        }

         // Left Over Loop for s2
        while(j < s2) {
            result.push_back(word2[j]);
            j++;
        }

        return result;
    }
};

int main() {

    Solution solution;

    // Test case 1
    string word1 = "abc";
    string word2 = "pqr";
    cout << "Merged string (Test case 1): " << solution.mergeAlternately(word1, word2) << endl;

    // Test case 2
    word1 = "ab";
    word2 = "pqrs";
    cout << "Merged string (Test case 2): " << solution.mergeAlternately(word1, word2) << endl;

    // Test case 3
    word1 = "abcd";
    word2 = "pq";
    cout << "Merged string (Test case 3): " << solution.mergeAlternately(word1, word2) << endl;

    return 0;
}