//023_Merge_k_Sorted_Lists.h
//26ms	97.93%

/*
Total Accepted: 145469
Total Submissions: 543439
Instruction: LeetCode 023 - Merge k Sorted Lists - [M]
Developer: lrushx
Process Time: May 28, 2017
*/


/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/


//给k个排好序的链表，合成1个有序链表
//本来用的是逐个遍历所给链表当前位置，生成当前最小元素驾到res链表中，相应链表往后移一位，这样的结果是525ms
//之后直接无耻做法，所有链表元素复制到一个vector中，然后排序，再加到res链表中。26ms
//可以想想更高效的方法


//solution 1
//525ms
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int len = lists.size(),i,i0,value=0;
        ListNode* node0 = new ListNode(0);
        ListNode* node = node0;
        while (value != INT_MAX){
            value = INT_MAX;
            for (i = 0;i<len;i++)
                if (lists[i] && lists[i]->val < value){
                    i0 = i;
                    value = lists[i]->val;
                }
            if (value == INT_MAX) break;
            ListNode* node1 = new ListNode(value);
            node->next = node1;
            node = node1;
            lists[i0] = lists[i0]->next;
        }
        return node0->next;
    }


//solution 2
//26ms	97.93%
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int len = lists.size(),i,i0,value=0;
        for (i = 0;i<len;i++){
            while (lists[i]){
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        len = v.size();
        if (len == 0) return NULL;
        sort(v.begin(),v.end());
        ListNode* node0 = new ListNode(v[0]);
        ListNode* node = node0;
        for (i = 1;i<len;i++){
            ListNode* node1 = new ListNode(v[i]);
            node->next = node1;
            node = node1;
        }
        return node0;
    }