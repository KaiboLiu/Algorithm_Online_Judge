//082_Remove_Duplicates_from_Sorted_List_II.h 
//删除已排序链表中的重复项,若有重复项全部删除，不保留。
//和83相比，存在head节点重复需要删除的情况

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head,*node,*nodego;
        int tmp;
        bool flag = false;
        if (ans == NULL) return ans;
        if (ans->next == NULL) return ans;
        while (ans->next != NULL){//找到第一个未重复过的节点当做链表头ans
            flag = false;
            while (ans->val == ans->next->val) {
                flag = true;//开头有重复
                ans = ans->next;
                if (ans->next == NULL) break;
            }
            if (flag) ans = ans->next; else break;
            if (ans == NULL) break;
        }
        
        if (ans == NULL) return ans;
        
        node = ans;
//        cout<<node->val<<" ";
        while (node->next != NULL){
            nodego = node->next;
            
            while (nodego->next != NULL && nodego->val == nodego->next->val){
                tmp = nodego->val;
                while (nodego->next != NULL && nodego->next->val == tmp){
                    nodego = nodego->next;
                }
                nodego = nodego->next;
                if (nodego == NULL) break;//此句不加，在链表尾处的while循环判断会报错
            }
            node->next = nodego;
            if (nodego == NULL) break;
            node = node->next;
//            cout<<node->val<<" ";
        }
        return ans;
        
    }
    
    
    int main(){
 
        cout<<"082_Remove Duplicates from Sorted List II:Input array n and {an},delete all nodes that have duplicate numbers."<<endl;
        
        ListNode *head,*node,*node1;
        int n;
        cin>>n;
        if (n != -1){
            head = new ListNode(n);
        }
        node = head;
        cin>>n;
        while (n != -1){
            node1 = new ListNode(n);
            node->next = node1;
            node = node->next;
            cin>>n;
        }

/*
        node = head;
        cout<<"You input:";
        while (node != NULL){
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
 */       
        node = deleteDuplicates(head);
        
        cout<<endl<<"Ouput:";
        while (node != NULL){
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
        
        return 0;
    }
    
