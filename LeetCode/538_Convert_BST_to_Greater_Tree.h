//538_Convert_BST_to_Greater_Tree.h
//36ms	92.86%

/*
Total Accepted: 6661
Total Submissions: 12597
Instruction: LeetCode 538 - Convert BST to Greater Tree - [M]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13
Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/


//给一个搜索二叉树，修改每个节点的值，使其加上所有比它大的节点值
//因为是BST，只要加上其右边所有值即可，有两种来源：右子树之和+右侧父节点的新值
//先一个DFS把所有节点加上其右子树的和，再一个DFS把本节点的新值连同右父的新值传递到左右子树中；
//因为左子树已经加过其子部分，如今只要加上本节点新值；右子树需要加上右边父的新值而不需要本节点的值。所以第二个DFS传递3个参量，(节点,父值,向下左右)"
//认为自己的处理挺巧妙的


    void addleft(TreeNode* root,int pvalue, int branch){ //branch==0:left; branch==1:right
        root->val += pvalue * branch;
        if (root->left != NULL){
            root->left->val += root->val;
            addleft(root->left,root->val,0);
        }
        if (root->right != NULL)
            addleft(root->right,pvalue,1);
    }
    
    int sumbelow(TreeNode* root){
        if (root->right != NULL) root->val += sumbelow(root->right);
        int ans = root->val;
        if (root->left != NULL) ans += sumbelow(root->left);

        return ans;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return root;
        int a = sumbelow(root);
        addleft(root,0,0);
        return root;
    }