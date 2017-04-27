//557_Reverse_Words_in_a_String_III.h
//19ms	100.00%

/*
Total Accepted: 11049
Total Submissions: 17877
Instruction: LeetCode 557 - Reverse Words in a String III - [E]
Developer: lrushx
Process Time: Apr 25, 2017
*/


/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

//给一句话，有单词和空格，反转交换每个词内部的字母，单词顺序不变
//因为不需要考虑多余空格，于是直接在原字符串+" "，然后循环blank=find(" ",blank+1)，把start到blank之间的字符逆序替换。
//不要生成ans字符串，复制原串再替换所需更快。

    string reverseWords(string s) {
        string ans=s;
        size_t blank=0;
        int start,len = s.size(),sublen;
        if (len == 1 && s[0] == ' ') return ans;
        s = s + " ";
        while (blank <= len){
            start = blank;
            blank = s.find(" ",blank);
            sublen = start+blank-1;
            for (int i=blank-1;i>=start;i--)
                ans[sublen-i] = s[i];
            blank++;
        }
        return ans;
    }
