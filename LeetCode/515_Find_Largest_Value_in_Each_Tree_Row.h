//515_Find_Largest_Value_in_Each_Tree_Row.h
//

/*
Total Accepted: 12036
Total Submissions: 22305
Instruction: LeetCode 515 - Find Largest Value in Each Tree Row - [M]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
You need to find the largest value in each row of a binary tree.
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

//给一个二叉树，输出每行最大的数存入数组
//写一个depth函数，参数为root和dep，以层数为index维护结果数组，新增数据或者更新最大值，然后再递归到子节点


public:
    vector<int> ans;
    int depth(TreeNode* root, int d){
        if (ans.size() < d+1) 
            ans.push_back(root->val);
        else if (ans[d] < root->val) ans[d] = root->val;
        int left,right;            
        if (root->left != NULL) left = depth(root->left,d+1);
        if (root->right != NULL) right = depth(root->right,d+1);
        return left;
    }
    
    vector<int> largestValues(TreeNode* root) {
        if (root != NULL)  int d = depth(root,0);
        return ans;
    }

