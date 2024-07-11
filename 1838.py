# Returns the frequency of maximum frequency element!
from typing import List
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        maxFreq = 1
        for i in nums:
            currFreq = 1
            for j in nums:
                if j - i > 0 and j - i <= k:
                    currFreq+=1
                    
            if currFreq > maxFreq:
                maxFreq = currFreq
        
        return maxFreq


def main():
    nums: List[int] = list(map(int, input("Input Frequency List :").split()))
    k: int = int(input("Input possible moves :"))
    solution =  Solution()
    result = solution.maxFrequency(nums, k)
    print(result)


if __name__ == '__main__':
    main()