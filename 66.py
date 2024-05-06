# Plus - one -> CONSIDERS ALL NUMBERS AT INDEXES AS COMPLETE NUMBER, AND ADD +1
# INTO IT, PRETTY BASIC PROBLEM WITH BASIC SOLUTION, CHECKS FOR EACH POSSIBLE C-
# ASE!


from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        digits[i] += 1
        if digits[i] % 10 == 0:
            for j in range(i, 0, -1):
                if digits[j] % 10 == 0 and digits[j] != 0:
                    digits[j] = 0
                    digits[j - 1] += 1
        if digits[0] == 10:
            digits[0] = 0
            digits.insert(0, 1)
        return digits


def main():
    s1 = Solution()
    nums = list(map(int, input("Input Numbers :").split()))
    ans = s1.plusOne(nums)
    print(ans)


main()
