# Two-Sum returns the two indexes that sum up to a target!

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]


def main():
    arr = list(map(int, input("Input an array :").split()))
    target = int(input("Input Target :"))
    s1 = Solution()
    res = s1.twoSum(arr, target)
    print(res)


main()
