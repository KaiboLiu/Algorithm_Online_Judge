## 141_Linked_List_Cycle.py
## 82ms   50%

'''
Total Accepted:233.8K
Total Submissions:
Instruction: LeetCode 141 - Linked List Cycle [E]
Developer: lrushx
Process Time: Feb 23, 2018
'''

'''
Given a linked list, determine if it has a cycle in it.
'''
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None: return False
        fast, slow = head.next, head
        while fast != slow:
            for _ in range(2):
                if fast is None: return False
                fast = fast.next
            slow = slow.next
        return True
