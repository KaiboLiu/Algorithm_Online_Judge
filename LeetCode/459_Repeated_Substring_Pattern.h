//459_Repeated_Substring_Pattern.h
//33ms	77.69%

/*
Total Accepted: 26298
Total Submissions: 68320
Instruction: LeetCode 459 - Repeated Substring Pattern - [E]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Input: "abab"   Output: True
*/

//给一个字符串，判断是否可以等分成>=2个相同数列
//2种思路：
//一是从2~size遍历等分数（份数），若能整除就挨个判断后面的子串是否等于第一个子串，判断的复杂度是O(size)，再算上遍历份数，复杂度接近O(n^2)，但是由于是easy题，数据不复杂，最终时间和高级方法竟然一样短。
//二是用(s+s)[1..-1].find(s)，非常巧妙：假设可以等分，最小单位是s0，份数是k(>1)，那么把s加倍，成为2k个s0，掐头去尾记为s2，等效包含2k-2个s0，只要判断新串是否包含s(k个s0)即可


//solution 1
//33ms	77.69%

    bool repeatedSubstringPattern(string s) {
        
        int len = s.size();
        if (len < 1) return false;

        int seg,sublen,i,j,base;
        bool flag;
        for (seg=2;seg<=len;seg++)
            if (len % seg == 0){
                sublen = len / seg;
                flag = true;
                for (i=1;i<seg;i++){
                    base = i*sublen;
                    for (j=0;j<sublen;j++)
                        if (s[j+base] != s[j]){
                            flag = false;
                            break;
                        }
                    if (!flag) break;
                }
                if (flag) return true;
            }
        return false;
    }
    
    
//solution 2
//33ms	77.69%

    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        return (s+s).substr(1,len+len-2).find(s) == string::npos ? false:true;
    }