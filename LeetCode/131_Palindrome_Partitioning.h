//131_Palindrome_Partitioning.h
//13ms	51.75%

/*
Total Accepted: 93392
Total Submissions: 289130
Instruction: LeetCode 131 - Palindrome Partitioning - [M]
Developer: lrushx
Process Time: May 28, 2017
*/


/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
[
  ["aa","b"],
  ["a","a","b"]
]
*/

//给一个字符串，输出所有分割方案，使得分割出来的元素都为回文
//DFS，分治或者说递归即可，传递当前分割方案到下一阶段(复制而不是引用)
//力求再快一点



    vector<vector<string>> res;
    string s0;
    int len;
    bool checkpali(int a,int b){
        for (int i=a;i<=(a+b)/2;i++)
            if (s0[i] != s0[a+b-i]) return false;
        return true;
    }
    
    void DFS(int a,vector<string> v){
        if (a == len) {
            res.push_back(v);
            return;
        }
        int last = v.size(),i=a+1;
        v.push_back(s0.substr(a,1));
        DFS(a+1,v);
        while (i < len && s0[i] == s0[a]){
            v[last] = s0.substr(a,i-a+1);
            DFS(++i,v);
        }
        i++;
        for (;i<len;i++){
            if (checkpali(a,i)){
                v[last] = s0.substr(a,i-a+1);
                DFS(i+1,v);
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        len = s.size();
        s0 = s;
        vector<string> v;
        DFS(0,v);
        return res;
    }