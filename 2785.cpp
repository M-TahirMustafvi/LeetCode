#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='A' || c=='E' || c=='I'|| c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u') 
            return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char> vow;
        for(char i:s)
        {
            if(isVowel(i))
            {
                vow.push_back(i);
            }
        }
        sort(vow.begin(), vow.end());
        
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=vow[j];
                j++;
            }
        }
        return s;
    }
};
int main()
{
    Solution s1;
    string res=s1.sortVowels("lEetcOde");
    for(char i:res)
        cout<<i;
    cout<<endl;
}