//173_Binary_Search_Tree_Iterator.h
//19ms	88.97%

/*
Total Accepted: 87102
Total Submissions: 215018
Instruction: LeetCode 173 - Binary Search Tree Iterator - [M]
Developer: lrushx
Process Time: May 27, 2017
*/

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/


//给一个BST，设计数据结构，每次访问后返回下一个最小值，用O(1)时间和O(h)空间
//用stack储存树节点，一开始把所有左子节点依次入栈，访问时直接取栈顶节点的值即可，随后要弹出这个元素，并且压入其右节点r，和r往下的所有左节点；判断是否有next只要判断栈是否为空即可


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> Stree;
    
public:
    BSTIterator(TreeNode *root) {
        TreeNode *node = root;
        while (node){
            Stree.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !Stree.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        TreeNode * node = Stree.top();
        Stree.pop();
        int res = node->val;
        node = node->right;
        while (node){
            Stree.push(node);
            node = node->left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
