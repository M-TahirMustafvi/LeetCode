// Finds repeteation the number that comes once in array, which contains numbers in pairs!

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Simply uses Hash_Map to counts frequncy and returns the one with freq= 1
int singleNumber(vector<int>& nums)
{
    unordered_map<int, int> mpp;

    for(int i = 0; i< nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for(auto i:mpp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    return -1;
}


//Xor the whole array as Xor only makes those arrays one, which is not repeated
int singleNumberXor(vector<int>& nums)
{
    int ch = 0;
    for(int i:nums)
        ch ^= i;
    return ch;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    cout<< singleNumberXor(arr);
}