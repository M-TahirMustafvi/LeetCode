
//Right rotate an array by K indices, using condurrent reversals, in three chunks,
//First whole array, then first part K, then second part from k to end
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& purpose, int start, int end)
    {
            while(start <= end)
            {
                auto temp = purpose[start];
                purpose[start] = purpose[end];
                purpose[end] = temp;
                start ++;
                end --;
            }
    }

    void rightRotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if (k == 0) return;
        reverse(nums, 0, size - 1);
        reverse(nums, 0,  k - 1);
        reverse(nums, k, size - 1);
    }
};


int main()
{
    Solution s1;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    s1.rightRotate(arr, 2);
    for (int i:arr)
        cout<<i<<" ";

}
