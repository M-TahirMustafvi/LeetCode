//There are two soultion provided for subarray with sum K problem, one of which is 
//1- burte force using nested loop usses a sum variable, which counts each subarray with sum K
//and stores the best one.
//The other is optimal approach explained just above that very funciton!!


#include <bits/stdc++.h>
using namespace std;



class Solution
{
    public:

	//TC = O(N^2)
	//SC = O(1)
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
		int sum = 0, len =0;
		for(int i = 0; i<N; i++)
		{
			sum = 0;
			for(int j = i; j<N; j++)
			{
				sum += A[j];
				if(sum == K)
					len = max(len, j - i + 1); 
			}
		}
		return len;
	}

	//Longest subarray with sum K, optimal approach, uses a simple idea, prefix sum, stores every unique prefix 
	//sum in hashMap, moves on to the array, if there is a cuurent sum "s" found where "sum - k" is in hashmap, it
	//means there is another subbarray with sum "k" b/w current index and that "sum - k" index on hash map, so we campare
	//length and maximze it, in this way all possiple subarrays are encountered and one with max lenghts is used!!

	//TC = O(N * LOGN) ordered map
	//SC = O(N)
	int lenOfLongSubarrOptimal(int A[], int N, int K)
	{
		map<int, int> hashMap;
		int sum = 0, maxLen = 0;
		for(int i = 0; i < N; i++)
		{
			sum += A[i];
			if(sum == K)
				maxLen = max(maxLen, i+1);
			
			int rem = sum - K;

			if(hashMap.find(rem) != hashMap.end())
			{
				int len = i - hashMap[rem];
				maxLen = max(maxLen, len);
			}

			if(hashMap.find(sum) == hashMap.end())
				hashMap[sum] = i;

		}
		return maxLen;
	}
};



int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarrOptimal(a, n , k)<< endl;
	    
	}
	
	return 0;
}
