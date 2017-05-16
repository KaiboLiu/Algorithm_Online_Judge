//424_Longest_Repeating_Character_Replacement.h
//16ms	53.52%

/*
Total Accepted: 10395
Total Submissions: 25119
Instruction: LeetCode 424 - Longest Repeating Character Replacement - [M]
Developer: lrushx
Process Time: May 15, 2017
*/


/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
Note:
Both the string's length and k will not exceed 104.

Example 1:
Input:
s = "ABAB", k = 2
Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/


//给一个字符串，和k，至多替换k个字符，使得某一连续串字符全相等，求这个连续串的最大可能长度
//用i,j表示起止位置，作为窗口往后移动，用l[0..25]作为hash table表示每个字母出现的次数，需要替换的次数是j-i-max(l)，每次j++，若这个替换次数>k，则i++



    int characterReplacement(string s, int k) {
        int len = s.size(),i=0,j=0,letter[26]={};
        while (j < len){
            letter[s[j++]-'A']++;
            if (j-i-*max_element(letter,letter+26) > k)
                letter[s[i++]-'A']--;
        }
        return j-i;
    }