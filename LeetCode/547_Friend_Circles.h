//547_Friend_Circles.h
//19ms	99.04%

/*
Total Accepted: 5209
Total Submissions: 10591
Instruction: LeetCode 547 - Friend Circles - [M]
Developer: lrushx
Process Time: May 04, 2017
*/


/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2

N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/

//给一个邻接矩阵表示朋友关系，求一共多少个朋友圈
//染色问题，设一个color数组初始为0，按行遍历若该行color为0则颜色设为++c，然后dfs该行，找出所有是朋友并且color为0的j，染色后继续从j开始dfs
//并查集？


    void dfscolor(vector<vector<int>>& M,vector<int>& color,int k,int n){
        for (int j=0;j<n;j++)
            if (M[k][j] && color[j]==0){
                color[j] = color[k];
                dfscolor(M,color,j,n);
            }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(),i,c=0;
        //int color[n];
        //memset(color,0,n*sizeof(int));
        vector<int> color(n,0);
        for (i=0;i<n;i++){
            if (color[i] == 0) color[i] = ++c;
            dfscolor(M,color,i,n);
        }
        return c;
    }