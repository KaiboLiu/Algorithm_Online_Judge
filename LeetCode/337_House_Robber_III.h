//337_House_Robber_III.h
//9ms	100.00%

/*
Total Accepted: 40476
Total Submissions: 94870
Instruction: LeetCode 337 - House Robber III - [M]
Developer: lrushx
Process Time: May 10, 2017
*/


/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/



//给一个二叉树，不能取相邻数，求取数最大和为多少
//对于每个点，有yes/no表示取/不取，如果当前节点yes，则左右子节点必须不取；而当前节点no，则左右子节点可以取或者不取，选较大值。
//如果直接递归，每个节点会从父节点展开2个状态，会重复访问(1849ms)，所以有个好方法是用pair<int,int>返回2个数，表示这个节点的取/不取的结果，这样每个节点只访问一次(9ms)。
//要返回2个值，可以用pair<int,int>和make_pair(a,b)



//solution 1, direct recursion
//1849 ms   1.21%

    int deeper(TreeNode* root,bool choose){
        if (root == NULL) return 0;
        int res = choose?root->val:0;
        if (choose){
            res += deeper(root->left,!choose) + deeper(root->right,!choose);
        }else{
            res+= max(deeper(root->left,!choose), deeper(root->left,choose));
            res+= max(deeper(root->right,!choose), deeper(root->right,choose));
        }
        return res;
        
        
    }
    int rob(TreeNode* root) {
        return max(deeper(root,true),deeper(root,false));
    }
    
    
    
//solution 2, use pair to store 2 results to avoid duplicated recursion
//9ms	100.00%

    pair<int,int> deeper(TreeNode* root){
        if (root == NULL) return make_pair(INT_MIN,0);
        int yes, no;
        pair<int,int> l,r;
        l = deeper(root->left);
        r = deeper(root->right);
        yes = root->val + l.second + r.second;
        no = max(l.first,l.second) + max(r.first,r.second);
        return make_pair(yes,no);
        
    }
    int rob(TreeNode* root) {
        pair<int,int> x = deeper(root);
        return max(x.first,x.second);
    }