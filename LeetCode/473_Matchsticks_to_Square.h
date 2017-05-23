//473_Matchsticks_to_Square.h
//3ms	100.00%

/*
Total Accepted: 7407
Total Submissions: 21536
Instruction: LeetCode 473 - Matchsticks to Square - [M]
Developer: lrushx
Process Time: May 20, 2017
*/


/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
Example 1:
Input: [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
*/


//给一个数组代表若干火柴长度，判断这些能否拼成一个正方形，火柴数量<=15
//因为数量少，可以用回溯DFS来求。先算出数组和L，若非4倍数则false，然后将这数列排序，用标号的方法来求DFS(L/4,len-1)，从大到小取数，每次取了该数i则标记为true，若失败则改回false，下一轮DFS(l-a[i],i-1)
//有小贪心的思路在里面，也就是从大到小选数，避免本该分配到4条边的小数合到同一条边使得之后无解
//如果下一步不是本次取数往前而是从头开始，会从3ms慢成246ms


    vector<bool> used;
    bool res;
    
    void DFS(int L, int j, vector<int>& nums){
        if (L == 0) {
            res = true;
            return;
        }
        for (int i=j;i>=0;i--){
            if (res) return;
            if (used[i] || nums[i] > L) continue;
            used[i] = true;
            DFS(L-nums[i],i-1,nums);
            if (!res) used[i] = false;
        }
        return;
    }
    
    bool makesquare(vector<int>& nums) {
        int len = nums.size();
        if (len < 4) return false;
        int L=0,i;
        for (i=0;i<len;i++) L += nums[i];
        if (L % 4) return false;
        used.resize(len,false);
        res = true;
        L /= 4;
        sort(nums.begin(),nums.end());
        for (i = 0; i < 3; i++){
            res = false;
            DFS(L,len-1,nums);
            if (!res) return res;
        }
        return res;
    }
