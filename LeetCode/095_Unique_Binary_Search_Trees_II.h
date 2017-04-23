//95_Unique_Binary_Search_Trees_II.h
//16ms  94.28%

/*
Total Accepted: 78505
Total Submissions: 253558
Instruction: LeetCode 095 - Unique Binary Search Trees II - [M]
Developer: lrushx
Process Time: Apr 22, 2017
*/

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//求节点为1..n的所有二分查找树的方案，存成vector
//"DP或者recursive，用dp(m,n)表示从m..n的范围内所有方案，返回一个vector，
//遍历k生成当前节点root，分治dp(m,k-1)和dp(k+1,n)，根据结果是否为空来增加root的左右子数然后将本数添加到vector中用于返回"

//"当节点root已生成，光是更改root->left并没有生成新的root而是更新了原来root。要成为新方案加入结果，需要新生成root来赋值。"


    vector<TreeNode*> generate(int m,int n){
        vector<TreeNode*> ans;
        if (m > n) return ans;
        
        TreeNode* root;
        if (m == n) {
            root = new TreeNode(m);
            ans.push_back(root);
            return ans;
        }
        
        for (int k=m;k<=n;k++){
            vector<TreeNode*> left = generate(m,k-1);
            vector<TreeNode*> right = generate(k+1,n);
            if (left.size() == 0){
                for (int j=0;j<right.size();j++){
                    root = new TreeNode(k);
                    root->right = right[j];
                    ans.push_back(root);
                }
            }else if (right.size() == 0){
                for (int i=0;i<left.size();i++){
                    root = new TreeNode(k);
                    root->left = left[i];
                    ans.push_back(root);
                }
            }
            else for (int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
        
    }
