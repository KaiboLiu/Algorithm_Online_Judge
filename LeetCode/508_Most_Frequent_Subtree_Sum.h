//508_Most_Frequent_Subtree_Sum.h
//16ms	89.02%

/*
Total Accepted: 10387
Total Submissions: 19976
Instruction: LeetCode 508 - Most Frequent Subtree Sum - [M]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
*/


//给一个二叉树，对每个节点求其子树和(包括自身)，统计中出现次数最多的一个或几个和
//调用一个求和的递归函数，在其过程中维护一个map<>从和到频次，并且记录一个最大频次
//在主程序中执行递归后，遍历map，匹配second==频次的，把first加入到结果数组中
//map的使用：查找if (m.find(key) == m.end())，遍历for(it=m.begin();it!=m.end();it++)，2个成员first和second

    unordered_map <int,int> m;
    int Freq = 0;
    
    int nodesum(TreeNode* root){
        int ans=root->val;
        if (root->left != NULL) ans += nodesum(root->left);
        if (root->right != NULL) ans += nodesum(root->right);
        if (m.find(ans) == m.end()) m[ans] = 1;
                else m[ans]++;
        if (m[ans] > Freq) Freq = m[ans];
        return ans;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        int tmp = nodesum(root);
        
        unordered_map <int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
            if (it->second == Freq)
                ans.push_back(it->first);
        return ans;
    }