//044_Wildcard_Matching.h
//

/*
Total Accepted: 90235
Total Submissions: 459052
Instruction: LeetCode 044 - Wildcard Matching - [H]
Developer: lrushx
Process Time: May 17, 2017
*/


/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

//字符串匹配，模式串p中可以有?和*，?表示单个字符，*表示空或者任意多个字符，返回是否匹配
//DP，若s[i]==p[j]或者p[j]=='?'，则f[i][j]=f[i-1][j-1]；若p[j]=='*'，则f[i][j] = f[i][j-1] || f[i-1][j-1] || f[i-1][j]，分别表示*匹配空串||匹配1个字符||多个字符。
//为了处理初始的空匹配空，把f中的下标都+1即可
//模式匹配时，s中不会有特殊字符*?，但是p中可以有连续*或者?，初始时要考虑


    bool isMatch(string s, string p) {
        int len1=s.size(),len2=p.size(),i,j=0;
        if (len2 == 0) return len1 == 0;
        bool f[len1+1][len2+1] = {};
 
        while (j < len2 && p[j] == '*') f[0][++j] = true;
        f[0][0] = true;

        for (i=0;i<len1;i++)
            for (j=0;j<len2;j++)
                if (p[j] == '*') f[i+1][j+1] = f[i+1][j] || f[i][j] || f[i][j+1];
                // * matches empty:=f[x][y-1] || * matches single:=f[x-1][y-1] || * matches multiple:=f[x-1][y]
                else f[i+1][j+1] = f[i][j] && (s[i] == p[j] || p[j] == '?');
                // if p[j]==? or s[i] == p[j] :=f[x-1][y-1]
        return f[len1][len2];
    }