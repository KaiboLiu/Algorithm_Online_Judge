# -*- coding:utf-8 -*-
'''
Challenge: KthNode.py
Total Acceptence: 23.69%
Developer: lrushx
Process Time: Apr 06, 2018
https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
'''

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回对应节点TreeNode
    def KthNode2(self, pRoot, k):
        # write code here
        def _kth(root,t):    # root, target is the ith in the subtree of root
            if root is None: return 0, None    # return number of nodes down from root, ith value
            left = _kth(root.left,t)    
            if left[0]+1 == t: return -2, root
            if left[1] is not None: return -2, left[1]
            right = _kth(root.right,t-left[0]-1)
            if right[1] is not None: return -2, right[1]
            return left[0]+right[0]+1, None
        if pRoot is None or k == 0: return None
        n, v = _kth(pRoot, k)
        return v

    def KthNode(self, pRoot, k):
        def _kth(root):
            if root is None: return
            if len(res) >= k: return
            _kth(root.left)
            res.append(root)
            _kth(root.right)
        if pRoot is None or k == 0: return None
        res = []
        _kth(pRoot)
        print(res)
        return res[k-1] if k <= len(res) else None

l = [8,6,10,5,7,9,11]
n = [TreeNode(x) for x in l]
#print([(x.val,x.left,x.right) for x in n])
for i,x in enumerate(n):
    if (i+1<<1)-1 < len(n):
        x.left = n[(i+1<<1)-1]
    if (i+1<<1) < len(n):
        x.right = n[(i+1<<1)]
#print([(x.val,x.left,x.right) for x in n])
s = Solution()
print(s.KthNode(n[0],1))
