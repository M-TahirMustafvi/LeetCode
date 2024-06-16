# Minimum increment to make array unique
# Sorts the array, starts from 1 index, checks if less than or equal to prev index, increments it,
# makes it greater than prev and counts # of increments, returns them in the end
from typing import List


class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        count = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                count += nums[i - 1] - nums[i] + 1
                nums[i] = nums[i - 1] + 1  # makes curr 1 larger than prev
        return count


def main():
    arr = list(map(int, input("Input array :").split()))
    s1 = Solution()
    ans = s1.minIncrementForUnique(arr)
    print(ans)


if __name__ == "__main__":
    main()
