//117_Populating_Next_Right_Pointers_in_Each_Node_II.h
//26ms	88.63%

/*
Total Accepted: 94327
Total Submissions: 280156
Instruction: LeetCode 117 - Populating Next Right Pointers in Each Node II - [M]
Developer: lrushx
Process Time: May 28, 2017
*/


/*
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

//给一个二叉树，增加一个数结构成员next表示其右边的节点，和116不同的是不一定满节点，可能某节点的next在空很多位置的右侧
//按层构造，某点root的右侧有效Next为一直next直到其为空或者有子节点，那么root的子节点可以用next链接到Next的子节点上。若root双子节点，则左的next为右，右的next为Next的子(Next?(Next->left? Next->left : Next->right) : NULL)
//递归的顺序也很关键，若root有双子节点，要先递归右节点再左节点，因为是向右延伸，先右节点可以向右扩展，然后再递归左节点和右边连起来；若先左再右，因为右边部分都是空，左节点递归时的next还未遍历到，扩展出来的next很可能是空
//双子节点时的顺序很关键，我也是看了WA样例才发现。
//      2 -> 3 -> 2 -> 3 ->NULL
//     /           \    \
//    4->  ->   ->  5 -> 7 -> NULL


    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *Next = root->next;
        //connect(Next);
        
        while (Next && Next->left==NULL && Next->right==NULL) Next = Next->next;
        if (root->left && root->right){
            root->left->next = root->right;
            root->right->next = Next?(Next->left? Next->left : Next->right) : NULL;
            connect(root->right);
            connect(root->left);
        }else if (root->left){
            root->left->next = Next?(Next->left? Next->left : Next->right) : NULL;
            connect(root->left);
        }else if (root->right){
            root->right->next = Next?(Next->left? Next->left : Next->right) : NULL;
            connect(root->right);
        }
    }