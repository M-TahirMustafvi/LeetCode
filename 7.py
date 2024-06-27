# Reverses an integer which may be negative and fit the answer into 32-bit integer
# uses normal number breaking approach, checks forbound and manipulates through the
# number!
# Time Complexity O(log(x))

import math

class Solution:
    def reverse(self, x: int) -> int:
        Max_Int = 2**31 -1
        Min_Int = -2**31
        result = 0
        curr = x
        while x != 0:
            if x>=0:
                curr = x % 10
            else:
                curr = x % -10
            result = (result * 10) + curr
            if result > Max_Int or result < Min_Int:
                return 0
            x = math.trunc(x/10)
        return result
    

def main():
    num:int = int(input("Please Enter a number"))
    s1 = Solution()
    reversed = s1.reverse(num)
    print(reversed)


if __name__ == "__main__":
    main()