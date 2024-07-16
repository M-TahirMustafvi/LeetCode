# Move Zeros to the end of array uses two pointer approach
from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i: int = 0
        j: int = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                break
            i+=1
        
        j = i + 1

        while( j < len(nums)):
            if(nums[i] == 0 and nums[j]!=0):
                temp: int = nums[i]
                nums[i] = nums[j]
                nums[j] = temp
                i+=1
                j+=1
            elif(nums[i] == 0 and nums[j]==0):
                j+=1
            elif(nums[i] != 0):
                i+=1

def main() -> None:
    s1 = Solution()
    arr = list(map(int, input("Enter Numbers :").split()))
    s1.moveZeroes(arr)
    print(arr)


if __name__ == '__main__':
    main()
