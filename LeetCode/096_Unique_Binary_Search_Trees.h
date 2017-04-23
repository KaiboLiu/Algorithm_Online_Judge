//96_Unique_Binary_Search_Trees.h
//0ms  100%

/*
Total Accepted: 115335
Total Submissions: 285880
Instruction: LeetCode 096 - Unique Binary Search Trees - [M]
Developer: lrushx
Process Time: Aug 06, 2015
*/

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//求节点为1..n的所有二分查找树的方案数
//不是求通解，而是递推，n个节点的解f(n)可以由i个左+1个父+(n-1-i)个右组成，解数为f(i)*f(n-1-i),遍历i相加即可，其中f(0)=1
//一直在想通解，甚至想到了n个节点，2子点数为i，1子点数为n-2i-1，0子点/叶数为(i+1)…然并卵

    int numTrees(int n) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=n;i++){
            ans.push_back(0);
            for(int j=0;j<i;j++)
                ans[i]+=ans[j]*ans[i-1-j];
        }

        return ans[n];
    }
