//556_Next_Greater_Element_III.h
//0ms	100.00%

/*
Total Accepted: 2955
Total Submissions: 10854
Instruction: LeetCode 556 - Next Greater Element III - [M]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
*/


//给一个int32整数n，求重排后比n大的最小int32数
//把数字变成字符串或者高精度数组d，从后往前找到(小大)组然后交换(可以不相邻)，记下(小)的pos，然后把d从pos+1到最后排序即可。

//27.2%的Medium
//"一开始看错成可以重复。。。后来被各种小问题困扰：
//sort函数的cmp问题、重排后超过int32的问题、用vector还是int[]问题、从后往前找左小右大用于交换时忽略了(小大中)的情况
//注意溢出的corner data，也注意用sort排序vector的一部分不能用offset"


    int nextGreaterElement(int n) {

        string s = to_string(n);
        int i=n,len=s.size(),max=0,pos=-1,j;
        int show[10];
        memset(show,0,10*sizeof(int));
        int digit[len];
        for (i = 0;i<len;i++) digit[i] = s[i] -'0';
        
        for (i = len-1;i>=0;i--)
            if (digit[i] < max){
                for (j = digit[i]+1;j<=max;j++)
                    if (show[j] >0){
                        swap(digit[i],digit[show[j]]);
                        pos = i;
                        break;
                    }
                break;
            }else {
                max = digit[i];
                show[max] = i;
            }
        if (pos == -1) return pos;
        sort(digit+pos+1,digit+len);
        if (len >= 10){
            int intmax[] = {2,1,4,7,4,8,3,6,4,7};
            for (i = 0;i<len;i++) 
                if (digit[i] < intmax[i]) break;
                else if (digit[i] > intmax[i]) return -1;
        }
        max = 0;
        for (i = 0;i<len;i++) max = max*10 + digit[i];
        return max;
    }