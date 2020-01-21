class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head, k) -> ListNode:
        if not head:
            return None
        if not head.next:
            return head
        p = head
        n = 1
        while  p.next:
            n += 1
            p = p.next
        p.next = head

        new_tail = head
        for i in range(n-k%n-1):
            new_tail = new_tail.next
        new_head = new_tail.next
        new_tail.next = None
        return new_head

l1 = ListNode(1)
l2 = ListNode(2);l1.next = l2
l3= ListNode(3); l2.next = l3
l4 = ListNode(4);l3.next = l4
p = l1
while p:
    print(p.val)
    p = p.next
sol = Solution()
head = sol.rotateRight(l1,2)
while head:
    print(head.val)
    head = head.next
