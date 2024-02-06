#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> freq(26);
        
        for (char i : s) freq[i - 'a']++;
    
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};

int main()
{
    string st="loveleetcode";
    Solution s1;
    cout<<s1.firstUniqChar(st);
    return 0;
}