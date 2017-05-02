//522_Longest_Uncommon_Subsequence_II.h
//3ms	100.00%

/*
Total Accepted: 2567
Total Submissions: 8900
Instruction: LeetCode 522 - Longest Uncommon Subsequence II - [M]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
*/


//给一组字符串，求其中一个串的非连续子串，但不是另外所有串的非连续子串时，子串的最大长度
//比521麻烦一些，个数很多可以比较的也变多了，并不是只考虑最大长度那一堆就可以的；
//在最大长度那一堆里，如果有一个unique，那么就返回他的长度，如果都有重复，那就把这些最大长度的串去掉多余重复的放到一个不重复的新数组S中；
//从稍短一些长度开始，只要是unique的串，就要比较是否是现有S中任意元素串的子串，如果是，就不满足，存入新数组；另一方面如果不unique的话只存一份到S中；
//分析到最后一个，如果还没有(unique并且非更长串的子串)，则返回-1

//一开始以为是3个比较，那就手动来，但是没有考虑S1,S1,T1(长度S1>T1并且T1不是S1子串)的情况，可以返回T1长度
//!!被自己写的sort里的cmp坑了！(虽然别的题AC了)返回的新数组却元素！还不如自己写比较排序(因为元素个数<=50)！
//这题M一点都不M，虽然是我想多了，但是情况还挺复杂
//通过率28.8%的M


    bool bigger(string s, string t){
        int len = s.size();
        for (int i=0;i<len;i++)
            if (s[i] > t[i]) return true;
            else if (s[i] < t[i]) return false;
        return true;
    }
    
    bool issub(string s, string t){
        int len = s.size();
        size_t find=0;
        for (int i=0;i<len;i++){
            find = t.find(s[i],find);
            if (find == std::string::npos) return false;
            find++;
        }
        return true;
    }
    
    
    // s1,s1,t1
    // s1,s2,t1 (len:s1==s2>t1)
    // s1,s1,s2,s2,t1,t2,k1
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) return strs[0].size();
        if (n == 0) return 0;
        int i,j,same=1;
        
        for (i=0;i<n-1;i++)
            for (j=i+1;j<n;j++)
                if (strs[i].size() < strs[j].size()) swap(strs[i],strs[j]);
                else if (strs[i].size() == strs[j].size() && bigger(strs[j],strs[i]))
                    swap(strs[i],strs[j]);
                    
        int len = strs[0].size();
        i = 0;
        vector<string> uniqeS;
        bool flag;        
        while (i < n-1){
            if (strs[i] == strs[i+1]) same++;
            else { if (same == 1){
                if (strs[i].size() == len) return len;
                flag = true;
                for (j=0;j<uniqeS.size();j++)
                    if (issub(strs[i],uniqeS[j])) {
                        flag = false;
                        break;
                    }
                if (flag) return strs[i].size();
                }
                uniqeS.push_back(strs[i]);
                same = 1;
            }
            i++;
        }
        if (same == 1){
            flag = true;
            for (j=0;j<uniqeS.size();j++)
                if (issub(strs[n-1],uniqeS[j])) {
                    flag = false;
                    break;
                }
            if (flag) return strs[n-1].size();    
        }
        return -1;
        
        /*
        
        
        
        longs.push_back(strs[0]);
        for (i=1;i<n;i++) 
            if (strs[i] != strs[i-1]) longs.push_back(strs[i]);
        bool flag;
        while (i < n-1){
            if (strs[i+1].size() != len){
                len = strs[i].size();
                continue;
            } 
            if (strs[i] == strs[i+1]) dif++;
            else if (dif == 1){
                flag = true;
                for (j=0;j<longs.size();j++)
                    if (issub(strs[i],longs[j])) {
                        flag = false;
                        break;
                    }
                if (flag) return len;
            } else dif = 1;
            i++;
        }
        for (i=1;i<n;i++){
            if (strs[i].size() != len){
                len = strs[i].size();
                continue;
            } 
            if (equal(strs[i],strs[i-1])) dif++;
            else if (dif == 1) return len;
            else dif = 1;
        }
        if (dif == 1) return len;
        return -1;
        */
    }