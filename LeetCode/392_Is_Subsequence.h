//LeetCode - 392_Is_Subsequence.h
//75ms  75%

/*
Total Accepted: 28263
Total Submissions: 63778
Instruction: LeetCode 392 - Is Subsequence - [M]
Developer: lrushx
Process Time: Apr 13, 2017
*/
 
/*
Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
*/

//判断s是否为t的子串，可以不连续

    bool isSubsequence(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        if (l1>l2) return false;
        int pos = 0;
        for (int i=0;i<l1;i++){
            bool flag = false;
            for (int j=pos;j<l2;j++){
                if (s[i] == t[j]){
                    flag = true;
                    pos = j+1;
                    break;
                }
            }
            if (!flag) return false;
                
        }
        return true;
    }
    
    
int main(){
    //string s = "acb";
    //string t = "ahbgdc";
    string s = "abc";
    string t = "ahbgdc";
    cout<<isSubsequence(s,t);
    
    }