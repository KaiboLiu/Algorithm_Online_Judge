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
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:
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