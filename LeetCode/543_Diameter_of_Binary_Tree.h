//LeetCode - 543_Diameter_of_Binary_Tree.h
//9ms	NA%

/**
 * Instruction：LeetCode 543 - Diameter of Binary Tree - [E]
 * Developer：lrushx
 * Process Time：Apr 13, 2017
 */
 
/*
Total Accepted: 8047
Total Submissions: 19146
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


//给一个二叉树，求任意两个节点之间的最大距离（按照边的数量计算）
//先写一个depth函数用于计算每个节点深度，再用另一个函数run来遍历这棵树，
//求run(node)=max(run(左),run(右),depth(左)+depth(右)+2)。
//只要注意单侧子节点时是max(run(左),depth(左)+1)



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
    
    int depth(TreeNode* root){
        //if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            root->val = 0;
            return 0;
        }
        if (root->left == NULL) root->val = depth(root->right)+1;
        else if (root->right == NULL) root->val = depth(root->left)+1;
        else root->val = max(depth(root->left),depth(root->right))+1;
        return root->val;
    }
    
    int finddiameter(TreeNode* root){
        //if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        if (root->left == NULL) return max(root->right->val+1,finddiameter(root->right));
        else if (root->right == NULL) return max(root->left->val+1,finddiameter(root->left));
        else {
            int sub = max(finddiameter(root->right),finddiameter(root->left));
            return max(sub,root->right->val + root->left->val +2);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        depth(root);
        return finddiameter(root);
    }
};