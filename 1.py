# Two-Sum returns the two indexes that sum up to a target, uses dictionary to do in O(n)!
##### Brute Force ######
# for i in range(len(nums)):
#     for j in range(i + 1, len(nums)):
#         if nums[i] + nums[j] == target:
#             return [i, j]
##### Brute Force ######


from typing import List


class Solution:
    # Subtracts number from the target and looks for it in dictionary,
    # if found okay, else add the number to dictionary and look for next one
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookup = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in lookup:
                return [lookup[comp], i]
            else:
                lookup[nums[i]] = i

        return []


def main():
    arr = list(map(int, input("Input an array :").split()))
    target = int(input("Input Target :"))
    s1 = Solution()
    res = s1.twoSum(arr, target)
    print(res)


main()
