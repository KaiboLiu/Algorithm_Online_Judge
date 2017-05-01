//520_Detect_Capital.h
//

/*
Total Accepted: 20107
Total Submissions: 38290
Instruction: LeetCode 520 - Detect Capital - [E]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
*/


//给一个字符串判断是否合法单词：全有字母组成，全大写/全小写/只有第一个大写
//没啥好说的，简单题


    int lettercase(char c){
        if (c-'A'>= 0 && c-'A' <26) return 1;
        if (c-'a'>= 0 && c-'a' <26) return 0;
        else return -1;
    }
    
    bool detectCapitalUse(string word) {
        int count=0,len = word.size(),tmp;
        for (int i=0;i<len;i++){
            tmp = lettercase(word[i]);
            if (tmp < 0) return false;
            count += tmp;
        }
        if (count == len || count == 0) return true;
        if (count == 1 && lettercase(word[0]) > 0) return true;
        return false;
    }