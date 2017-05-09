//438_Find_All_Anagrams_in_a_String.h
//33ms	94.60%

/*
Total Accepted: 27330
Total Submissions: 81783
Instruction: LeetCode 438 - Find All Anagrams in a String - [E]
Developer: lrushx
Process Time: May 09, 2017
*/


/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/


//给一个字符串s和p，在s中找连续子串t，使得t是p的重排，返回所有t在s中的第一个下标
//因为全部为小写字母，可以用hash table，p中所有字母的统计加入hash table中，而s中每一段里的字母将table中的计数-1，
//若table中所有计数为0，则匹配；往后遍历时，只要考虑当前t的尾和t之前的一个字符，若相等则计数不变，若不等则更新表中统计
//自己优化了一下，42ms->33ms

    int check(vector<int> a){
        int i,res=0;
        for (i=0;i<26;i++)
            res += abs(a[i]);
        return res;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int len1=s.size(),len2=p.size();
        vector<int> res;
        if (len1 < len2) return res;
        int i,tmp;
        int flag;
        vector<int> letter(26,0);
        for (i=0;i<len2;i++) {
            letter[p[i]-'a']++;
            letter[s[i]-'a']--;
        }
        flag = check(letter);
        if (flag == 0) res.push_back(0);
        for (i=1;i<=len1-len2;i++){
            if (flag){
                tmp = letter[s[i-1]-'a']++;
                if (tmp < 0) flag--; else flag++;
                tmp = letter[s[i+len2-1]-'a']--;
                if (tmp > 0) flag--; else flag++;
                if (flag == 0) res.push_back(i);
            }else{
                if (s[i-1] == s[i+len2-1]){
                    res.push_back(i);
                }else {
                    flag += 2;
                    letter[s[i-1]-'a']++;
                    letter[s[i+len2-1]-'a']--;
                }
            }
        }
        return res;
    }