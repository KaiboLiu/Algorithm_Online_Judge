//072_Edit_Distance
//[H]
//20ms,96.16%

//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//You have the following 3 operations permitted on a word:
//a) Insert a character
//b) Delete a character
//c) Replace a character
//给2个单词，求多少次操作可以使两者相等，操作包括插入1个/删除1个/替换1个


//abc和de的答案为3，也就是答案最大可能为word长度中较大者
//用f[i][j]做DP，表示word1[0~i]和word2[o~j]中的匹配答案，只比较word1[i]和word2[j]；
//递推思路为，若1[i]和2[j]相等，则可以是f[i-1,j-1]不操作得到f[i,j],也可以f[i-1,j]的答案多一个删除word1[i]的操作，也可以是f[i,j-1]答案多一个删除word2[j]的操作；
//所以递推公式为：若相等，则为f[i,j]=f[i-1,j-1],f[i-1,j]+1,f[i,j-1]+1中的最小值，若不想等，则为f[i-1,j-1]+1,f[i-1,j]+1,f[i,j-1]+1中的最小值；
//注意边界条件f[0,j]和f[i,0]。举例解释f[0,j]，若word2[j]及其之前有==word1[0]，则f[0,j]=j，否则为j+1；公式为f[0][j]=(word1[0] == word2[j])? j:f[0][j-1]+1;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(),l2 = word2.length(),tmp;
        if ((l1 && l2) == 0) return l1+l2;
        int f[500][500];
        f[0][0] = (word1[0] == word2[0])? 0 : 1;
        for (int i=1;i<l1;i++) f[i][0] = (word1[i] == word2[0])? i:f[i-1][0]+1;
        for (int j=1;j<l2;j++) f[0][j] = (word1[0] == word2[j])? j:f[0][j-1]+1;
        for (int i=1;i<l1;i++){
            for (int j=1;j<l2;j++){
                if (word1[i] == word2[j]) tmp = 0;else tmp = 1;
                f[i][j] = min(f[i-1][j-1]+tmp,f[i-1][j]+1);
                f[i][j] = min(f[i][j],f[i][j-1]+1);
            }
        }
        return f[l1-1][l2-1];
    }
};
