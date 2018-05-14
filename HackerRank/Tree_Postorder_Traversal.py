#!/bin/python3
'''
Instruction: HackerRank - Tree: Postorder Traversal [E]
Success Rate: 
Max Score: 10
Difficulty: Easy
Submitted 89644  times
Developer: lrushx
Process Time: May 13, 2018
https://www.hackerrank.com/challenges/tree-postorder-traversal/problem
'''

'''
Using non-recursion to implement postorder traversal
'''

## 难的是非递归方法：类似前序/中序，但是节点需要反向访问2次(1次向右1次输出)，所以需要给每个进入stack的节点加一个状态项tag
## tag=0表示第一次入stack，出栈后应该改为tag=1再入栈，然后扩展到右节点，right项目置True
## tag=0表示第二次入stack，出栈后应该直接输出，并且right项目置False
## 非recursion，调试了一晚上才完成


"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""

# recursion version
def postOrder1(root):
    #Write your code here
    res = []
    def _dfs(node):
        if not node: return
        _dfs(node.left)
        _dfs(node.right)
        res.append(node.data)
    _dfs(root)
    print(" ".join(map(str,res)))
    
    
# non-recursion version
def postOrder(root):  
    res = []
    stack = []
    node, tag = root, 0
    right = True
    while node or stack:
        while node and right:
            stack.append((node,0))
            node = node.left
        if not stack: break
        node, tag = stack.pop()
        right = False
        if tag == 0:
            stack.append((node,1))
            node = node.right
            right = True
        else:
            res.append(node.data)
    print(" ".join(map(str, res))) 
