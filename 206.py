# Reverse Linked List, very simple logic based on three pointers!

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


def main():
    h = ListNode(1)
    h.next = ListNode(2)
    h.next.next = ListNode(3)
    h.next.next.next = ListNode(4)
    h.next.next.next.next = ListNode(5)

    temp = h
    while temp:
        print(temp.val, end=' ')
        temp = temp.next

    s1 = Solution()
    temp = s1.reverseList(h)
    print('\n')
    while temp:
        print(temp.val, end=' ')
        temp = temp.next


main()

