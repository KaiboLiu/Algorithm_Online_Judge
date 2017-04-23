//513_Find_Bottom_Left_Tree_Value.h
//12ms  85.74%

/*
Total Accepted: 12859
Total Submissions: 23085
Instruction: LeetCode 513 - Find Bottom Left Tree Value - [M]
Developer: lrushx
Process Time: Apr 22, 2017
*/

/*
Given a binary tree, find the leftmost value in the last row of the tree.
Input:
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
Output:
7
*/

//给一棵二叉树，求最深一层里最左边的元素
//先写个函数求树深度D，再DFS先序遍历找到深度==D的第一个输出即可。



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    bool flag=false;
    
    int depth(TreeNode* root){
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left == NULL) return depth(root->right)+1;
        if (root->right == NULL) return depth(root->left)+1;
        return max(depth(root->right),depth(root->left))+1;
    }
    
    void findwithdepth(TreeNode* root, int dep, int D){
        if (flag) return;
        
        if (dep == D) {
            ans = root->val;
            flag = true;
            return;
        }
        
        if (root->left != NULL) findwithdepth(root->left,dep+1,D);
        if (root->right != NULL) findwithdepth(root->right,dep+1,D);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        findwithdepth(root,1,depth(root));
        return ans;
        
    }
};
