//564_Find_the_Closest_Palindrome.h
//3ms	100.00%

/*
Total Accepted: 891
Total Submissions: 6133
Instruction: LeetCode 564 - Find the Closest Palindrome - [H]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
Given an integer n, find the closest integer (not including itself), which is a palindrome.
The 'closest' is defined as absolute difference minimized between two integers.

Input: "123"    Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
*/

//给一个数字字符串，求离它最近的回文数字串(不包括本身)
//2种思路：
//考虑生成回文，无非是左半+1或者-1或者不变，然后回文复制给右半(左半的定义为奇数长则包括中间，偶数长则正好左半)，简称构造后的字符串为左半/左半+1/左半-1
//有很多特殊情况考虑:1.本身为回文 2.左半+1后长度增加 3.左半-1后长度减小
//从中间向两边辐射状按位成对比较，若左边大，则待选为(左半，左半-1)，若右边大，则待选为(左半+1，左半)，否则两边都一样大则输入为回文，需要的待选为(左半+1，左半-1)。待选表示为(n1,n2)
//再写一个高精度减法来比较待选和输入数之间的差，比较sub(n1,n)和(n,n2)谁小选谁，若相等选小的。

//通过率14.5%的Hard！！接近2个小时非常精细的字符串/高精度处理
//写了4个额外函数


    string midadd(string s){
        int len = s.size();
        int mid = (len+1)/2-1,i;
        s[mid]++;
        for (int i=mid;i>0;i--)
            if (s[i] > '9'){
                s[i] = '0';
                s[i-1]++;
            }else break;
        if (s[0] > '9'){
            s[0] = '0';
            s = "1"+s;
            len++;
        }
        for (i=0;i<=mid;i++) s[len-1-i] = s[i];
        return s;
    }
    
    string midsub(string s){
        int len = s.size();
        int mid = (len+1)/2-1,i;
        s[mid]--;
        for (int i=mid;i>0;i--)
            if (s[i] < '0'){
                s[i] = '9';
                s[i-1]--;
            }else break;
        if (s[0] == '0'){
            s[mid+1] = '9';
            s.erase(0,1);
            len--;
            mid--;
        }
        for (i=0;i<=mid;i++) s[len-1-i] = s[i];
        return s;
    }
    

    string midsame(string s){
        int len = s.size();
        int mid = len/2,i;
        for (i=0;i<mid;i++) s[len-1-i] = s[i];
        return s;
    }
    
    int stringsub(string n1,string n2){
        int len = n1.size(),ans=0;
        if (len > n2.size()) n2 = "0"+n2;
        for (int i=0;i<len;i++)
            ans = ans*10 + (n1[i] - n2[i]);
        return ans;
    }
    
    string nearestPalindromic(string n) {
        int len = n.size(),i;
        if (len == 1) {
            if (n[0] == '0') n[0]++;
            else n[0]--;
            return n;
        }
        string n1,n2;
        i = len/2-1;
        while (i >= 0 && n[i] == n[len-1-i])
            i--;
        if (i < 0){
            n1 = midadd(n);
            n2 = midsub(n);
        }else if (n[i] < n[len-1-i]){   // rise
            n1 = midadd(n);
            n2 = midsame(n);
        }else{
            n1 = midsame(n);
            n2 = midsub(n);
        }
        if (stringsub(n1,n) < stringsub(n,n2)) return n1;
        else return n2;
    }