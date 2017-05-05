//501_Find_Mode_in_Binary_Search_Tree.h
//16ms	87.20%

/*
Total Accepted: 12382
Total Submissions: 32247
Instruction: LeetCode 501 - Find Mode in Binary Search Tree - [E]
Developer: lrushx
Process Time: May 04, 2017
*/


/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].
*/

//给一个BST，求众数
//扁平化变成数组后用map统计数量即可


    vector<int> arr;
    void flatten(TreeNode* root){
        if (root == NULL) return;
        flatten(root->left);
        arr.push_back(root->val);
        flatten(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        flatten(root);
        vector<int> ans;
        int n = arr.size();
        if (n == 0) return ans;
        unordered_map <int,int> m;
        int mode=0;
        for (auto i:arr) {
            m[i]++;
            if (m[i] > mode) mode = m[i];
        }
        unordered_map <int,int>::iterator it;
        for (it = m.begin();it != m.end();it++)
            if (it->second == mode) ans.push_back(it->first);
        return ans;
    }