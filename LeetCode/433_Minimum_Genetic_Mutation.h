//433_Minimum_Genetic_Mutation.h
//0ms	100.00%

/*
Total Accepted: 4770
Total Submissions: 15657
Instruction: LeetCode 433 - Minimum Genetic Mutation - [M]
Developer: lrushx
Process Time: May 02, 2017
*/


/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:
Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example:
start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
return: 3
*/


//给一个起始基因序列s和结束基因序列t，每次改变一位，要求改变后的序列出现在bank字符串数组中(valid)，所有基因长度相等，求最少需要改变多少次可以从s到t
//BFS，从起始到结束，以差别为1的标准扩充bfs数组，
//一个bfs[k]存中间状态的字符串bank[i]在bank中的下标i，一个mutate[i]表示字符串bank[i]是从s改变多少位得到
//挺有趣的bfs，通过率30.4%的M



    bool diffs1(string a, string b){
        int dif = 0;
        for (int i=0;i<8;i++)
            if (a[i] != b[i]) dif++;
        if (dif == 1) return true;
        return false;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int len = bank.size();
        if (len == 0) return -1;
        bank.push_back(start);
        len++;
        string curr;
        
        int bfs[len],l=-1,r=0,i;    //bsf[i] stores the index of strings in the bfs array, i increased by 1
        bfs[0] = len-1;
        int mutation[len];          //mutation[i] stores the mutation numbers of bank[i] from start + 1
        memset(mutation,0,len*sizeof(int));
        mutation[len-1] = 1;
        
        while (l < r){
            curr = bank[bfs[++l]];
            for (i = 0;i < len-1;i++)
                if (mutation[i] == 0 && diffs1(curr,bank[i])){
                    if (bank[i] == end) return mutation[bfs[l]];  //+1-1
                    mutation[i] = mutation[bfs[l]] + 1;
                    bfs[++r] = i;
                }
        }
        
        return -1;
    }