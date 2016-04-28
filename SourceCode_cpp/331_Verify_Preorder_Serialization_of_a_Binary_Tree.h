//331_Verify_Preorder_Serialization_of_a_Binary_Tree.h

//给一个前序表示的二叉树，空节点用#表示，判断是否是合格二叉树
//经过判断，所有树的前序表示中，有val的节点数=空节点数-1，前序表示串的前部分表示树的左半部分，有个特点是（节点数>空节点数-1）。
//一旦前序遍历串还没完结但是（节点数<=空节点数-1），则不合格；一旦前序遍历串完结但是（节点数!=空节点数-1）,则不合格。
//空串和只有逗号的串 都为false

/*Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

    bool isValidSerialization(string preorder) {

        int pos_s=-1,pos_e,l=preorder.size();   //pos_s和pos_e均为前一个和后一个逗号的位置
        preorder += ',';
        int num_val=0,num_null=0;
        while(true){
            pos_e = preorder.find(",",pos_s+1);
            if (preorder[pos_e-1] == '#') num_null++;   //或者用preorder[pos_s+1] == '#'
            else num_val++;
            if (pos_e == l) break;
            else if (num_val <= num_null-1) return false;
            pos_s = pos_e;
        }
        
        if (num_val == num_null-1) return true;
        else return false;
    }

int main(){

    cout<<"331_Verify_Preorder_Serialization_of_a_Binary_Tree:Input a string, verify whether it is a correct preorder traversal serialization of a binary tree."<<endl;
    string s;
    cin>>s;
    while(s!= "-1"){
        if (isValidSerialization(s)) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        cin>>s;
    }
    
    return 0;
}
