## 652_Find_Duplicate_Subtrees[M].py
## 512ms   %

'''
Total Accepted: 12.9K
Total Submissions: 35K
Developer: lrushx
Process Time: Apr 14, 2018
https://leetcode.com/submissions/detail/150106004/
'''

'''
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.
'''

## 给一个二叉树，找到重复的子树，将这些重复子树的根节点存到list返回
## 看了Stefan的代码，高效简洁，做法是给节点编号, 
## id[root] = d[root, getid(root.left),getid(root.right)] nested赋值相当牛
## d = collections.defaultdict
## d.default_factory = d.__len__: 设置d的初始值为d的当前size，等效于给新元素编号



class Solution:
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        def getid(root):
            if root:
                idx = treeid[root.val, getid(root.left), getid(root.right)]
                trees[idx].append(root)
                return idx
        trees = collections.defaultdict(list)
        treeid = collections.defaultdict()
        treeid.default_factory = treeid.__len__
        getid(root)
        return [roots[0] for roots in trees.values() if roots[1:]]  # if roots[1:] is equivalent to len(roots) > 1
