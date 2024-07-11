#  1752. Checks if the array is sorted and rotated, goes on to check for one rotaion point
# which means at most there will be one point where the sequennce will be broken, i.e, rotation point
# so we check for rotation point throughout the array, if it is found more then once it means array is
# corrupt and ------ we need to check last element with the first element also for possilblse test case,
# use % for this ---------
from typing import List

class Solution:
    def check(self, nums: List[int]) -> bool:
        count: int = 0
        for i in range(len(nums)):
            if nums[i] > nums[(i + 1) % len(nums)]:
                count += 1
            if count > 1:
                return False
        
        return True



def main():
    nums = list(map(int, input("Input Values :").split()))
    sol = Solution()
    print(sol.check(nums))

if __name__ == "__main__":
    main()
