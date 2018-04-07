# -*- coding:utf-8 -*-
'''
Challenge: FindPath.py
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
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        def _find(node, restSum):
            if node is None: return
            path.append(node.val)
            if node.val == restSum and node.left is None and node.right is None:
                res.append([x for x in path])
            restSum -= node.val
            _find(node.left, restSum)
            _find(node.right, restSum)
            path.pop()

        path = []
        res = []
        _find(root, expectNumber)
        return res


#l = [8,6,10,5,7,9,11]
l = [10,5,12,4,7]
n = [TreeNode(x) for x in l]
#print([(x.val,x.left,x.right) for x in n])
for i,x in enumerate(n):
    if (i+1<<1)-1 < len(n):
        x.left = n[(i+1<<1)-1]
    if (i+1<<1) < len(n):
        x.right = n[(i+1<<1)]
#print([(x.val,x.left,x.right) for x in n])
s = Solution()
print(s.FindPath(n[0],22))
