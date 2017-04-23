//467_Unique_Substrings_in_Wraparound_String.h
//9ms 98.94%

/*
Total Accepted: 5504
Total Submissions: 17538
Instruction: LeetCode 467 - Unique Substrings in Wraparound String - [M]
Developer: lrushx
Process Time: Apr 22, 2017
*/

/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.
Note: p consists of only lowercase English letters and the size of p might be over 10000.
*/



//给一个长字符串p，判断多少不同子串是无穷串"a..zabc..zabc"的一部分（字串）
//先用dp[i]=dp[i-1]+1,if(p[i]-p[i-1])%26==0.求出从p[0]到p[i]包含i的字串满足条件的最大长度
//把p[i]映射到0..25之间k,len[k]=dp[i]，代表每个字母/k结尾的长为len[k]的子串，则答案为求和k*len[k]。
//"有很多懊恼小错误。substring是连续子串；subsequence可以不连续"



    int findSubstringInWraproundString(string p) {
        int i,j,k,len=p.size();
        if (len < 1) return 0;
        
        int dp[len];
        int l[26];
        memset(l,0,26*sizeof(int));

        for (i = 0;i<len;i++){
            dp[i] = 1;
            l[p[i]-'a'] = 1;
        }
        for (i = 1;i<len;i++){
            if ((25+p[i]-p[i-1])%26 == 0){
                k = p[i]-'a';
                dp[i] = dp[i-1] + 1;
                if (dp[i] > l[k]) l[k] = dp[i];
            }
        }
        int ans = 0;
        for (i=0;i<26;i++)
            ans += l[i];
        return ans;
    }
