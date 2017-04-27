//477_Total_Hamming_Distance.h
//59ms  88.2%

/*
Total Accepted: 12884
Total Submissions: 27763
Instruction: LeetCode 477 - Total Hamming Distance - [M]
Developer: lrushx
Process Time: Apr 26, 2017
*/


/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Now your job is to find the total Hamming distance between all pairs of the given numbers.
*/

//给一个数组，求两两之间的汉明距
//可不能两两取数。把几个数转成2进制对齐看一下可知，某一位的总汉明距为num[0]*num[1]，所以只要统计每个数字的二进制在各位上对0/1个数的贡献，再最后相乘求和即可。
//如果找到最大数用>>得到数列中最长的二进制数作为总位数，而不是用31，反而会变慢。


    int totalHammingDistance(vector<int>& nums) {
        int l=nums.size();
        if (l < 2) return 0;
        int digit[31][2],i,dist=0;
        memset(digit,0,62*sizeof(int));
        for (i=0;i<l;i++){
            for (int k=0;k<31;k++){
                digit[k][nums[i] & 1]++;
                nums[i] = nums[i]>>1;
            }
        }
        for (i=0;i<31;i++)
            dist += digit[i][0] * digit[i][1];
        return dist;
    }
