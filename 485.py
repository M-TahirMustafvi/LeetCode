# Right Rotate an array by K places, where k is non negative!
from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count: int = 0
        maxi: int = 0

        for i in nums:
            if i == 1:
                count+=1
                maxi = max(maxi, count)
            else:
                count = 0
        return maxi

def main():
    sol = Solution()
    arr = list(map(int, input("Input a number :").split()))
    print(sol.findMaxConsecutiveOnes(arr))

if __name__ == "__main__":
     main()