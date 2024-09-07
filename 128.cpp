//Longest Consecutive SubSequence!Used 3 different approaches
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool lenSearch(int number, vector<int>& nums)
    {
        bool retVal = false;
        for(int i: nums)
            if(i == number)
                retVal = true;
        return retVal;
    }

public:

    //As Worst as it could, goes through the array, selects a number, linearly searches a number greater than that,if found, adds that to current look up now looks up for next greater, and so on, untill no greater found, or array ends, computes length, and prints maxLength!
    //TC: O(N*N)
    //SC: O(1)
    int longestConsecutiveBrute(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        for(int i = 0; i < n; i++)
        {
            int len = 1, curr = nums[i];
            while(lenSearch(curr+1, nums) == true)
            {
                curr+=1;
                len+=1;
            }

            maxLen = max(len, maxLen);
        }
        return maxLen;
    }

    //Better approach, Sorts the array first, now we know, largerst increasing subsequence is the one if next index is +1, add it to arsenal, instead restart the process, just calculate the length just before you free the arsenal, and then return maxLen in the end!
    //TC: O(NLogN)
    //SC: O(1)
    int longestConsectiveBetter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = nums[0], count = 1, maxCount = 1;
        int n = nums.size();

        for(int i = 1; i < n; i++)
        {
            if(last + 1 == nums[i])
            {
                last++;
                count++;
            }
            else
            {
                last = nums[i];
                count = 1;
            }

            maxCount = max(count, maxCount);
        }
        return maxCount;
    }

    //Optimal, Build up on the Brute Force, insert all elements to set, unordered, now look for the number with no -1, i.e, immediate smaller exists, use this number and look for the numbers larger than this, go ahead as far as you go, and find the max of all such steps, and bang, thats it!
    //TC: O(N)
    //SC: O(N)
    int longestConsectiveOptimal(vector<int>& nums) {
        unordered_set<int> distincts;
        int maxLen = 0;
        for(int i: nums)
            distincts.insert(i);
        
        for(auto it: distincts)
        {
            if(distincts.find(it-1) == distincts.end())
            {
                int Len = 1, curr = it;
                while(distincts.find(curr+1) != distincts.end())
                {
                    Len++;
                    curr++;
                }
                maxLen = max(Len, maxLen);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution s1;
    vector<int> nums= {100,4,200,1,3,2};
    cout<< s1.longestConsectiveOptimal(nums)<<endl;
}