//449_Serialize_and_Deserialize_BST.h
//22ms	96.52%

/*
Total Accepted: 10960
Total Submissions: 26029
Instruction: LeetCode 449 - Serialize and Deserialize BST - [M]
Developer: lrushx
Process Time: May 10, 2017
*/

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
The encoded string should be as compact as possible.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

//给一个BST，转成字符串再转回BST
//可以用先序遍历，root+','+{左}+{右}存成字符串；
//恢复时，先把字符串根据','位置都转成数组元素，然后递归区间[l0,r0]，
//对第一个元素a[l0]在后面范围[l0+1,r0]内二分查找，找到的分割点把此范围分成左右子树，递归返回节点即可
//还是要快速分析出二分查找



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string s;
    vector<int> num;
    TreeNode* ROOT;
    bool flag = false;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (root == NULL) return "";
        if (!flag) {ROOT = root; flag = true;}
        return (to_string(root->val)+","+serialize(root->left)+serialize(root->right));
    }

    // Decodes your encoded data to tree.
    TreeNode* deseri(int l0,int r0){
        if (l0 > r0) return NULL;
        TreeNode* root = new TreeNode(num[l0]);
        if (l0 == r0) return root;
        int l=l0+1,r=r0,mid;
        while (l <= r){
            mid = (r-l)/2 + l;
            if (num[mid] > num[l0]) r = mid - 1;
            else l = mid + 1;
        }
        //if (l0+1 <= r) 
        root->left = deseri(l0+1,r);
        //if (r+1 <= r0) 
        root->right = deseri(r+1,r0);
        return root;
    }
    
    
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        int count = std::count(data.begin(),data.end(),','),i,j,k;
        vector<int> a(count,0);
        std::size_t found = 0,start=0;
        for (i=0;i<count;i++){
             found = data.find(',',found);
             k = 0;
             for (j=start;j<found;j++) k = k*10 + (data[j]-'0');
             a[i] = k;
             start = ++found;
        }
        //for (i=0;i<count;i++) cout<<a[i]<<" "; cout<<endl;
        num = a;
        return deseri(0,count-1);
        
        //cout<<mycount<<endl;
        //return ROOT;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
