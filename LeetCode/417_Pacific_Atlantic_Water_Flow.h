//417_Pacific_Atlantic_Water_Flow.h
//46ms	91.03%

/*
Total Accepted: 12954
Total Submissions: 39019
Instruction: LeetCode 417 - Pacific Atlantic Water Flow - [M]
Developer: lrushx
Process Time: Jun 02, 2017
*/

/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/


//solution1, with vector and push_back
//46ms	91.03%
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        int h = matrix.size();
        int w = h? matrix[0].size() : 0;
        if ((h && w)==0) return res;
        
        int move[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<pair<int, int>> BFS_map_p,BFS_map_a;
        bool flag_p[h][w] = {0};
        bool flag_a[h][w] = {0};
        memset(flag_p,0,sizeof(flag_p));
        memset(flag_a,0,sizeof(flag_a));
        
        int i,j,i1,j1,m,start=-1,end=h+w-2;
        
        for (i = 0; i < h; i++){
            BFS_map_p.push_back(make_pair(i,0));
            BFS_map_a.push_back(make_pair(i,w-1));
            flag_p[i][0] = true;
            flag_a[i][w-1] = true;
        }
        for (j = 1; j < w; j++){
            BFS_map_p.push_back(make_pair(0,j));
            BFS_map_a.push_back(make_pair(h-1,w-1-j));
            flag_p[0][j] = true;
            flag_a[h-1][w-1-j] = true;
        }
        //cout<<h<<w<<endl;
        //for (i = 0; i < h+w-1; i++)    cout<<BFS_map_p[i].first<<BFS_map_p[i].second<<" "; cout<<endl;
        //for (i = 0; i < h+w-1; i++)    cout<<BFS_map_a[i].first<<BFS_map_a[i].second<<" "; cout<<endl;

        while (start++ < end){
            i = BFS_map_p[start].first;
            j = BFS_map_p[start].second;
            //cout<<i<<j<<" ";
            for (m = 0; m < 4; m++){
                i1 = i+move[m][0];
                j1 = j+move[m][1];
                if (i1 >= 0 && i1 < h && j1 >= 0 && j1 < w && (!flag_p[i1][j1]) && matrix[i1][j1] >= matrix[i][j]){
                    flag_p[i1][j1] = true;
                    BFS_map_p.push_back(make_pair(i1,j1));
                    end++;
                }
            }
        }
        end = h+w-2;
        start = -1;
        while (start++ < end){
            i = BFS_map_a[start].first;
            j = BFS_map_a[start].second;
            //cout<<i<<j<<" ";
            if (flag_p[i][j]) res.push_back(make_pair(i,j));
            for (m = 0; m < 4; m++){
                i1 = i+move[m][0];
                j1 = j+move[m][1];
                if (i1 >= 0 && i1 < h && j1 >= 0 && j1 < w && (!flag_a[i1][j1]) && matrix[i1][j1] >= matrix[i][j]){
                    //cout<<"+("<<i1<<j1<<") ";
                    flag_a[i1][j1] = true;
                    BFS_map_a.push_back(make_pair(i1,j1));
                    end++;
                }
            }
        }
        return res;
    }
};


//soluton2, with pair<> BFS[w*h] and indexing
//49ms  73.88%
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        int h = matrix.size();
        int w = h? matrix[0].size() : 0;
        if ((h && w)==0) return res;
        
        int move[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        pair<int, int> BFS_map[h*w];
        bool flag_p[h][w] = {0};
        bool flag_a[h][w] = {0};
        memset(flag_p,0,sizeof(flag_p));
        memset(flag_a,0,sizeof(flag_a));
        
        int i,j,i1,j1,m,start=-1,end=0;
        
        for (i = 0; i < h; i++){
            BFS_map[end++] = make_pair(i,0);
            flag_p[i][0] = true;
        }
        for (j = 1; j < w; j++){
            BFS_map[end++] = make_pair(0,j);
            flag_p[0][j] = true;
        }
        end--;

        while (start++ < end){
            i = BFS_map[start].first;
            j = BFS_map[start].second;
            //cout<<i<<j<<" ";
            for (m = 0; m < 4; m++){
                i1 = i+move[m][0];
                j1 = j+move[m][1];
                if (i1 >= 0 && i1 < h && j1 >= 0 && j1 < w && (!flag_p[i1][j1]) && matrix[i1][j1] >= matrix[i][j]){
                    flag_p[i1][j1] = true;
                    BFS_map[++end] = make_pair(i1,j1);
                }
            }
        }
        
              
        start = -1;
        end = 0;
        for (i = 0; i < h; i++){
            BFS_map[end++] = make_pair(i,w-1);
            flag_a[i][w-1] = true;
        }
        for (j = 0; j < w-1; j++){
            BFS_map[end++] = make_pair(h-1,j);
            flag_a[h-1][j] = true;
        }
        end--;  
        
        while (start++ < end){
            i = BFS_map[start].first;
            j = BFS_map[start].second;
            //cout<<i<<j<<" ";
            if (flag_p[i][j]) res.push_back(make_pair(i,j));
            for (m = 0; m < 4; m++){
                i1 = i+move[m][0];
                j1 = j+move[m][1];
                if (i1 >= 0 && i1 < h && j1 >= 0 && j1 < w && (!flag_a[i1][j1]) && matrix[i1][j1] >= matrix[i][j]){
                    //cout<<"+("<<i1<<j1<<") ";
                    flag_a[i1][j1] = true;
                    BFS_map[++end] = make_pair(i1,j1);
                }
            }
        }
        return res;
    }
    

