from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def get_number(self, head: Optional[ListNode]) -> int:
        num = 0
        multiplier = 1
        temp = head
        while temp:
            num += temp.val * multiplier
            multiplier *= 10
            temp = temp.next
        return num

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum = self.get_number(l1) + self.get_number(l2)
        head = ListNode()
        temp = head
        while 1:
            temp.val = sum % 10
            sum //= 10
            if sum:
                temp.next = ListNode()
                temp = temp.next
            else:
                break
        return head


def main() -> None:
    list1 = ListNode(9)
    list1.next = ListNode(9)
    # list1.next.next = ListNode(9)

    list2 = ListNode(1)
    list2.next = ListNode(9)
    list2.next.next = ListNode(4)

    s1 = Solution()
    sum = s1.addTwoNumbers(list1, list2)
    temp = sum
    while temp:
        print(temp.val, end=' ')
        temp = temp.next


main()
