//617_Merge_Two_Binary_Trees.h
//
//LeetCode Contest 36

/*
Total Accepted: 1086
Total Submissions: 1141
Instruction: LeetCode 617 - Merge Two Binary Trees - [M]
Developer: lrushx
Process Time: June 10, 2017
*/

/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
*/

//给2个二叉树，相应位置求和后返回新的树，一个为空一个非空就保留非空
//递归做t1,t2返回node，按照都为空；t1空；t2空；都不空来确定node的值和两个子树

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        TreeNode* root = new TreeNode(0);
        if (t1) root->val += t1->val;
        if (t2) root->val += t2->val;
        
        if (t1 == NULL){
            root->left = mergeTrees(NULL,t2->left);
            root->right = mergeTrees(NULL,t2->right);
        }else if (t2 == NULL){
            root->left = mergeTrees(t1->left,NULL);
            root->right = mergeTrees(t1->right,NULL);
        }else{
            root->left = mergeTrees(t1->left,t2->left);
            root->right = mergeTrees(t1->right,t2->right);
        }
        return root;
        
    }
