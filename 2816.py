# Doubles numbers represented as linked list, containing non-negative integers,
# first reverses the list
# iterates through each node multiplies each node, the same way we did in elementary maths
# manges carry efficiently

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return
        elif not head.next:
            return head
        back = None
        curr = head
        forward = head.next
        while forward:
            curr.next = back
            back = curr
            curr = forward
            forward = forward.next
        curr.next = back
        head = curr
        return head

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        h = self.reverseList(head)
        temp = h
        carry = 0
        num = 0
        while temp:
            num = temp.val * 2 + carry
            if num % 10 >= 0:
                temp.val = num % 10
                carry = num // 10
            else:
                temp.val = num
                carry = 0
            if carry and not temp.next:
                node = ListNode(carry)
                temp.next = node
                break
            temp = temp.next

        res = self.reverseList(h)
        return res


def main():
    h = ListNode(5)
    # h.next = ListNode(9)
    # h.next.next = ListNode(9)
    s1 = Solution()
    doubled = s1.doubleIt(h)
    temp = doubled
    while temp:
        print(temp.val, end=' ')
        temp = temp.next


main()
