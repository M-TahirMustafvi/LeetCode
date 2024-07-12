# Brings the unique element at frount, and changes the remaining array, easy, uses two pointer
# approach and does every thing perfectly!, time complexity is O(N)
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow: int = 0
        fast: int = 1  
        count: int = 1
        while(fast < len(nums)):
            if(nums[slow] == nums[fast]):
                fast +=1
            else:
                nums[slow+1] = nums[fast]
                count+=1
                slow +=1
                fast +=1
        return count

def main():
    nums: List[int] = list(map(int, input("Input List :").split()))
    solution =  Solution()
    result = solution.removeDuplicates(nums)
    print(result)


if __name__ == '__main__':
    main()