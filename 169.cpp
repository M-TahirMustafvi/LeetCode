//majority element i.e, element occuring more than n/2 times - created by moon on 2/12/2024
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:

    //A simple Nested Loop, counts frequency for every element, yes and if more than n/2 returns it! O(n^2)
    int majorityElementNaive(vector<int> nums) {
        int size=nums.size();
        
        for(int i = 0; i < size; i++) {
            int count =0;
            for(int j = 0; j < size; j++) {
                if(nums[i] == nums[j])
                    count++;
            }

            if(count > size / 2)
                return nums[i];
        }
        return -1;
    }

    //Uses sorting, after sorting middle element is always the majority element! O(NlogN)
    int majorityElementBetter(vector<int> nums) {
        int size=nums.size();
        sort(nums.begin(), nums.end());
        return nums[size/2];
    }

    //What counting reminds you of? yes! Hashing TC :O(nlogn)!
    int majorityElementHashing(vector<int> nums) {
        unordered_map <int, int> hashMap;
        int size = nums.size();

        for(int i = 0; i < size; i++)
            hashMap[nums[i]]++;

        for(auto i:hashMap)
            if(i.second > size / 2)
                return i.first;

        return -1;
    }

    //Moore's voting Algo
    int majorityElementMoore(vector<int> nums) {
        int count = 0, curr = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if(count == 0) {
                curr = nums[i];
                count++;
            }
            else if(curr == nums[i])
                count++;
            else
                count--;
        }
        return curr;
    }
};

int main()
{
    Solution s1;
    cout<<s1.majorityElementMoore({2,2,1,1,1,2,2})<<endl;
}