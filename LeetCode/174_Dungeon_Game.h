//174_Dungeon_Game.h
//6ms	100.00%

/*
Total Accepted: 37643
Total Submissions: 160781
Instruction: LeetCode 174 - Dungeon Game - [H]
Developer: lrushx
Process Time: May 14, 2017
*/


/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
-2(K)	-3	    3
-5	    -10 	1
10  	30  	-5(P)

Notes:
The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/


//给一个矩阵，标上分值(可正负)，路过时就要加上这个值来改变HP。从最左上到最右下，找一个最小起始HP，走对应的最优路径使得路径上每格的HP都>0(包括起止2个位置)
//一开始用从头到尾的DP，分别储存当前HP和当前状态需要的起始oHP，后来发现这样不对，因为每个格子的状态由左边和上面格子确定，如果只选oHP小的那个，那么当前格子的下一个并不一定能得到最优值(举例:HP/oHP,左边1/4,上面4/5,当前是0,若下一个是-3，则选上面变成1/5,选左边变成1/7,实则选上面更优，虽然上面的点oHP更大一些)
//后来分析了错误数据后发现可以从后往前，右下到左上，只需要储存一个二维数组HP[i][j]表示这个点到右下需要的最小起始HP,其值为max{下方-自己所需,1}和max{右方-自己所需,1}中的较小值
//提示是DP+二分，但我没用二分就做到100%



    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n = (m==0)?0:dungeon[0].size();
        if (n*m == 0) return 0;
        vector<vector<int>> HP = dungeon;
        HP[m-1][n-1] = HP[m-1][n-1]<0? 1-HP[m-1][n-1]:1;
        int i,j;
        //int tmp;
        for (i=m-2;i>=0;i--){
            HP[i][n-1] = max(HP[i+1][n-1] - HP[i][n-1],1);
        }
        for (j=n-2;j>=0;j--){
            HP[m-1][j] = max(HP[m-1][j+1] - HP[m-1][j],1);
        }
        for (i=m-2;i>=0;i--)
            for (j=n-2;j>=0;j--){
                HP[i][j] = min(max(HP[i][j+1]-HP[i][j],1),max(HP[i+1][j]-HP[i][j],1));
                //cout<<endl<<i<<","<<j<<" type:"<<endl;for (int i1=0;i1<m;i1++){for (int j1=0;j1<n;j1++) cout<<HP[i1][j1]<<"  "; cout<<endl;}
            }
        return HP[0][0];
    }
/*
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n = (m==0)?0:dungeon[0].size();
        if (n*m == 0) return 0;
        vector<vector<int>> oHP = dungeon;
        vector<vector<int>> HP = dungeon;
        oHP[0][0] = HP[0][0]<0? 1-HP[0][0]:1;
        HP[0][0] += oHP[0][0];
        int i,j,tmphp,tmpHP,tmpoHP,tmpoHP2;
        //int tmp;
        for (i=1;i<m;i++){
            tmphp = HP[i-1][0] + HP[i][0];
            if (tmphp <= 0){
                oHP[i][0] = oHP[i-1][0] + 1 - tmphp;
                HP[i][0] = 1;
            }else {
                oHP[i][0] = oHP[i-1][0];
                HP[i][0] = tmphp;
            }
        }
            
        for (j=1;j<n;j++){
            tmphp = HP[0][j-1] + HP[0][j];
            if (tmphp <= 0){
                oHP[0][j] = oHP[0][j-1] + 1 - tmphp;
                HP[0][j] = 1;
            }else {
                oHP[0][j] = oHP[0][j-1];
                HP[0][j] = tmphp;
            }
        }
        //for (i=0;i<m;i++){for (j=0;j<n;j++) cout<<HP[i][j]<<"/"<<oHP[i][j]<<"  "; cout<<endl;}
        
        for (i=1;i<m;i++)
            for (j=1;j<n;j++){
                tmphp = HP[i][j-1] + HP[i][j];
                if (tmphp <= 0){
                    tmpoHP = oHP[i][j-1] + 1 - tmphp;
                    tmpHP = 1;
                    //tmp = 1;
                }else {
                    tmpoHP = oHP[i][j-1];
                    tmpHP = tmphp;
                    //tmp = 2;
                }
                //choose1 = true;
                tmphp = HP[i-1][j] + HP[i][j];
                if (tmphp <= 0){
                    tmpoHP2 = oHP[i-1][j] + 1 - tmphp;
                    if (tmpoHP2 < tmpoHP) {
                        //choose1 = false;
                        tmpoHP = tmpoHP2;
                        tmpHP = 1;
                        //tmp = 3;
                    }
                }else {
                    tmpoHP2 = oHP[i-1][j];
                    if (tmpoHP2 < tmpoHP) {
                        //choose1 = false;
                        tmpoHP = tmpoHP2;
                        tmpHP = tmphp;
                        //tmp = 4;
                    }
                }
                oHP[i][j] = tmpoHP;
                HP[i][j] = tmpHP;
                //cout<<endl<<i<<","<<j<<" type:"<<tmp<<endl;for (int i1=0;i1<m;i1++){for (int j1=0;j1<n;j1++) cout<<HP[i1][j1]<<"/"<<oHP[i1][j1]<<"  "; cout<<endl;}
            }
        //for (i=0;i<m;i++){for (j=0;j<n;j++) cout<<HP[i][j]<<"/"<<oHP[i][j]<<"  "; cout<<endl;}
        return oHP[m-1][n-1];
        
    }
    */