//572_Subtree_of_Another_Tree.h
//23ms	66.66%

/*
Total Accepted: 1170
Total Submissions: 2810
Instruction: LeetCode 572 - Subtree of Another Tree - [E]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/


//LeetCode Contest 30
//给2个二叉树，判断第二个是否是第一个的子树(匹配开始后必须完全一样)，第一个下面多一个分支也不行
//递归即可，判断条件比较多，写的比较丑


    bool flag = false;
    bool cflag;
    bool check(TreeNode* s,TreeNode* t){
        if (!cflag) return false;
        if (t == NULL && s == NULL) return true;
        if (t == NULL || s == NULL) {cflag = false;return false;}
        if (s->val != t->val) {cflag = false;return false;}
        if ((s->left == NULL && s->left != NULL) || (s->left != NULL && s->left == NULL)) {cflag = false;return false;}
        if ((s->right == NULL && s->right != NULL) || (s->right != NULL && s->right == NULL)){cflag = false;return false;}
        return (check(s->left,t->left) && check(s->right,t->right));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == NULL && s == NULL) {flag = true; return true;}
        if (t == NULL || s == NULL) return false;
        if (flag) return true;
        if (s->val == t->val){
            cflag = true;
            if (check(s,t)){
                flag = true;
                return flag;
            }
        }
        if (s->left != NULL && isSubtree(s->left,t)){
            flag = true;
            return flag;
        }
        if (s->right != NULL && isSubtree(s->right,t)){
            flag = true;
            return flag;
        }
        return false;
    }