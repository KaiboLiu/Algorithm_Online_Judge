//079_Word_Search.h
//16ms	70.96%

/*
Total Accepted: 119145
Total Submissions: 456666
Instruction: LeetCode 079 - Word Search - [M]
Developer: lrushx
Process Time: Apr 30, 2017
*/


/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[ ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


//给一个字母矩阵和一个字符串，求是否可以在矩阵中按照邻位移动组成给定的字符串
//DFS即可，参数加一个visited的bool，按照word字符逐位递归，传入下一个坐标
//一开始用BFS，写了半天发现有错误，因为并不是求字母之间最短距离，如果单词是ABCA，那么A在第一步就被染色，无法在第4个字母处找到合适的位置，所以应该是DFS

    bool flag = false;
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word,int k,int h, int w,int i,int j){
        if (k == word.size()) {
            flag = true;
            return;
        }
        if (flag) return;
        if (i-1 >= 0 && board[i-1][j] == word[k] && !visited[i-1][j]){
            visited[i-1][j] = true;
            dfs(board,visited,word,k+1,h,w,i-1,j);
            if (flag) return;
            visited[i-1][j] = false;
        }
        if (i+1 < h && board[i+1][j] == word[k] && !visited[i+1][j]){
            visited[i+1][j] = true;
            dfs(board,visited,word,k+1,h,w,i+1,j);
            if (flag) return;
            visited[i+1][j] = false;
        }
        if (j-1 >= 0 && board[i][j-1] == word[k] && !visited[i][j-1]){
            visited[i][j-1] = true;
            dfs(board,visited,word,k+1,h,w,i,j-1);
            if (flag) return;
            visited[i][j-1] = false;
        }        
        if (j+1 < w && board[i][j+1] == word[k] && !visited[i][j+1]){
            visited[i][j+1] = true;
            dfs(board,visited,word,k+1,h,w,i,j+1);
            if (flag) return;
            visited[i][j+1] = false;
        }
            
            
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return false;
        int h = board.size();
        if (h < 1) return false;
        int w = board[0].size();
        if (w < 1) return false;
        
        int i,j;
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        for (i=0;i<h;i++){
            for (j=0;j<w;j++)
                if (board[i][j] == word[0]){
                    visited[i][j] = true;
                    dfs(board,visited,word,1,h,w,i,j);
                    if (flag) break;
                    visited[i][j] = false;
                }
            if (flag) break;
        }
        if (flag) return true;
        else return false;
    }