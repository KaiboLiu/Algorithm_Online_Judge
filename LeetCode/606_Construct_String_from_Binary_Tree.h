//606_Construct_String_from_Binary_Tree.h
//19ms
//LeetCode Contest 35

/*
Total Accepted: 1144
Total Submissions: 2107
Instruction: LeetCode 606 - Construct String from Binary Tree - [E]
Developer: lrushx
Process Time: June 03, 2017
*/

/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
*/


//给一个二叉树，用字符串的方式表达这棵树，先序遍历，用括号围住子树
//递归即可，如果左有右无，则右子树不需要用()表示，如果左无右有，左子树要用()表示

    string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        string ans = to_string(t->val);
        if (t->left == NULL && t->right == NULL) return ans;
        if (t->left == NULL) return ans+"()"+"("+tree2str(t->right)+")";
        if (t->right == NULL) return ans+"("+tree2str(t->left)+")";
        else return ans+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")";
    }
