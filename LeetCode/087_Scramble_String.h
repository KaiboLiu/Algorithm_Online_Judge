//087_Scramble_String.h
//6ms	64.94%

/*
Total Accepted: 61758
Total Submissions: 215054
Instruction: LeetCode 087 - Scramble String - [H]
Developer: lrushx
Process Time: May 17, 2017
*/


/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

//给2个字符串，第一个s1根据二叉树分割后，交换若干节点的左右顺序后拼回单词后若能和第二个s2相等则返回true，否则false
//分割字符串s1为前i个和后len-i个，前半段如果和s2的前i个是重排匹配，则递归(s1前i个,s2前i个)&&(s1后len-i个,s2后len-i个)；
//前半段如果和s2的后i个是重排匹配，则递归(s1前i个,s2后i个)&&(s1后len-i个,s2前len-i个)；
//这种二叉树本身就有分治的思想
//分治递归时可以传子串，也可以传本身串+索引，时间没影响

    bool match(unordered_map<char,int> a, unordered_map<char,int> b){
        unordered_map <char,int>::iterator it;
        for(it=a.begin();it!=a.end();it++)
            if (it->second != b[it->first]) return false;
        return true;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map<char,int> hash,h1,h2;
        int i,len = s1.size();
        if (len == 1) return s1[0] == s2[0]; 
        bool res;
        for (i=0;i<len-1;i++){
            hash[s1[i]]++;
            h1[s2[i]]++;
            h2[s2[len-i-1]]++;
            if (hash[s1[i]] == h1[s1[i]] && hash[s2[i]] == h1[s2[i]])
                if (match(hash,h1) ) res = isScramble(s1.substr(0,i+1),s2.substr(0,i+1)) && isScramble(s1.substr(i+1),s2.substr(i+1));
            if (res) return true;
            if (hash[s1[i]] == h2[s1[i]] && hash[s2[len-i-1]] == h2[s2[len-i-1]])
                if (match(hash,h2) ) res = isScramble(s1.substr(0,i+1),s2.substr(len-1-i,i+1)) && isScramble(s1.substr(i+1),s2.substr(0,len-i-1));
            if (res) return true;
        }
        return false;
    }