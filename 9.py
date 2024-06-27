

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        temp = x
        result = 0
        curr = 0
        while temp!=0:
            curr = temp % 10
            result = (result * 10) + curr
            temp = temp//10
        return result == x

def main():
    num:int = int(input("Please Enter a number"))
    s1 = Solution()
    print(s1.isPalindrome(num))

if __name__ == "__main__":
    main()