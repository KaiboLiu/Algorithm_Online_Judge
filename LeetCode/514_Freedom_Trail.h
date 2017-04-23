//514_Freedom_Trail.h
//12ms  98.42%


/*
Total Accepted: 2219
Total Submissions: 6433
Instruction: LeetCode 514 - Freedom Trail - [H]
Developer: lrushx
Process Time: Apr 22, 2017
*/

/*
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
*/

//给一个圆形拨盘带一个固定指针，圆盘每次转一格，盘上每格有字母，给一个字符串key，求拨盘逐个拨到key相应位置需要最少步数。
//可等效为2个字符串key和ring，在逐个遍历key时找其在ring上的对应位置，要求每次到新位置走过的距离最小（此处ring的位置是首尾相连的）。

//dp，遍历key[i]，记录key[i]在dial上所有对应位置pos[i][1..k]，dp[i][j]表示key[i]指向dial[j]需要的最少步数，dp[i][j]=min{dp[i-1][pos[i-1][k]]+dist(pos[i-1][k],j)}
//动态二维数组不好弄，设计了个pos[i][j],其中pos[i][0]为该行有效元素，对应dial位置存在pos[i][1]~pos[i][pos[i][0]]中。
//注意数组初始化即可。


    int dist(int i,int j,int n){
        return min((n+i-j)%n,(n+j-i)%n);
    }
    
    int findRotateSteps(string ring, string key) {
        int len_r = ring.size();
        int len_k = key.size();
        int pos[26][len_r+1];
        int i,j,p,tmp,tmp0,tmp2,len,ans;
        
        memset(pos,0,26*(len_r+1)*sizeof(int));

        for (i=0;i<len_r;i++){
            tmp = ring[i]-'a';
            pos[tmp][0] += 1;
            pos[tmp][pos[tmp][0]] = i;
        }
            
        int dp[len_k][len_r] = {0};

        for (i=0;i<len_k;i++)
            for (j=0;j<len_r;j++)
                dp[i][j] = 10000;

        tmp = key[0]-'a';
        for (p=1;p<=pos[tmp][0];p++)
            dp[0][pos[tmp][p]] = dist(0,pos[tmp][p],len_r);

        for (i=1;i<len_k;i++){
            tmp0 = key[i]-'a';
            for (j=1;j<=pos[tmp0][0];j++){
                tmp = key[i-1]-'a';
                for (p=1;p<=pos[tmp][0];p++){
                    tmp2 = dp[i-1][pos[tmp][p]]+dist(pos[tmp][p],pos[tmp0][j],len_r);
                    if (tmp2 < dp[i][pos[tmp0][j]])
                        dp[i][pos[tmp0][j]] = tmp2;
                    }
            }
        }
                            
        tmp = key[len_k-1]-'a';
        ans = 10000;
        for (p=1;p<=pos[tmp][0];p++)
            if (dp[len_k-1][pos[tmp][p]] < ans)
                ans = dp[len_k-1][pos[tmp][p]];
        ans += len_k;

        return ans;
        
    }
