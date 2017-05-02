//395_Longest_Substring_with_At_Least_K_Repeating_Characters.h
//3ms	99.64%

/*
Total Accepted: 13088
Total Submissions: 36701
Instruction: LeetCode 395 - Longest Substring with At Least K Repeating Characters - [M]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
Example 1:
Input:
s = "aaabb", k = 3
Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:
Input:
s = "ababbc", k = 2
Output:
5
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/


//给一个字符串s和数字k，求s的连续子串，其中每个字母都至少出现k次
//有一个规律，若s中某个字母c小于k次，那这个字母肯定不能取，此字母任意位置pos，则答案在[0..pos-1]和[pos+1,size-1]中，可以递归/分治解决。
//虽然原来可能某个字母c1大于k次，但是被c隔开后两边的c1数量都不足k个，那么两边的子串都不能取c1，很有趣


    int longestSubstring(string s, int k) {
        vector<int> c(26,0);
        int pos[26];
        int i,a=0,b=0,len = s.size();
        for (i=0;i<len;i++){
            c[s[i]-'a']++;
            pos[s[i]-'a'] = i;
        }
        for (i=0;i<26;i++)
            if (c[i] > 0 && c[i] < k){
                if (pos[i] >= k) a = longestSubstring(s.substr(0,pos[i]),k);
                if (pos[i] <= (len-k)-1) b = longestSubstring(s.substr(pos[i]+1,len-pos[i]-1),k);
                return max(a,b);
            }
        return len;
    }