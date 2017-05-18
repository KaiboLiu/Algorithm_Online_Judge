//010_Regular_Expression_Matching.h
//9ms	91.34%
//445 / 445 test cases passed.

/*
Total Accepted: 133552
Total Submissions: 557447
Instruction: LeetCode 010 - Wildcard Matching - [H]
Developer: lrushx
Process Time: May 17, 2017
*/


/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

//字符串匹配，模式串p中可以有.和*，.表示单个字符，c*表示c字符重复0次或多次(也可以.*表示可以有很多个.)，返回是否匹配
//DP，若s[i]==p[j]或者p[j]=='.'，则f[i][j]=f[i-1][j-1]；若p[j]=='*'，则f[i][j]=f[i][j-2] || f[i][j-1] || (f[i-1][j-1] && s[i] == p[j-1])  || (p[j-1] == '.' && f[i-1][j]);，分别表示c*匹配空串||匹配1个c||2个c||多个c。
//初始化时p开头的所有c*连续都要和s的第0位匹配。为了处理初始的空匹配空，把f中的下标都+1即可
//模式匹配时，s中不会有特殊字符*.，p中有*并且*都是跟在别的字符之后，可以有连续?但是没有连续*和第一个*，初始时要考虑


    bool isMatch(string s, string p) {
        // no such inputs: no */. in s; no "a**b","*b" in p
        int len1=s.size(),len2=p.size(),i,j=1;
        if (len2 == 0) return len1 == 0;
        if (len1 == 0) {
            len1++; len2++;
            s = "a"+s; p = "a"+p;
        }
        bool f[len1+1][len2+1] = {};
        f[0][0] = true;
        while (j < len2 && p[j] == '*') {
            f[0][j+1] = true;
            j += 2;
        }
        for (i=0;i<len1;i++)
            for (j=0;j<len2;j++)
                if (p[j] == '*') f[i+1][j+1] = f[i+1][j-1] || f[i+1][j] || (f[i][j] && s[i] == p[j-1])  || (p[j-1] == '.' && f[i][j+1]);
                // *=precceding*0 || *=precceding*1 || *=precceding*2 || * follows .
                else f[i+1][j+1] = f[i][j] && (s[i] == p[j] || p[j] == '.');
        //cout<<f[]
        return f[len1][len2];
    }
    }
    
    
int main(){
    string s = "aaabaaaababcbccbaab";
    string p = "c*c*.*c*a*..*c*";
    cout<< isMatch(s,p) <<endl;
    
}
