//445_Add_Two_Numbers_II.h
//42ms	91.11%
//1563 / 1563 test cases passed.

/*
Total Accepted: 19250
Total Submissions: 41724
Instruction: LeetCode 445 - Add Two Numbers II - [M]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/


//高精度加法，只不过用链表储存两个加数，返回也是链表
//把链表转成数组再用高精度加法，最后转回到链表即可



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        while (l1){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        vector<int> v2;
        while (l2){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int len1=v1.size(),len2=v2.size(),i,j;
        if (len1<len2){
            swap(v1,v2);
            swap(len1,len2);
        }
        v1.insert(v1.begin(),0);
        len1++;
        for (i=0;i<len2;i++){
            v1[len1-1-i] += v2[len2-1-i];
            if (v1[len1-1-i] > 9){
                v1[len1-1-i] -= 10;
                v1[len1-2-i] += 1;
            }
        }
        j = len1-len2-1;
        while (v1[j] > 9){
            v1[j] -= 10;
            v1[--j] += 1;
        }
        //for(i=0;i<len1;i++) cout<<v1[i]<<" "; cout<<endl;
        if (v1[0] == 0) i = 1;
        else i = 0;
        
        ListNode* res = new ListNode(v1[i++]);
        ListNode* res1 = res;
        for (;i<len1;i++){
            ListNode* res2 = new ListNode(v1[i]);
            res1->next = res2;
            res1 = res1->next;
        }
        return res;
    }