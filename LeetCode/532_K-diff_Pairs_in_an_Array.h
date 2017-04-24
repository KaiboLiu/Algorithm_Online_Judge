//532_K-diff_Pairs_in_an_Array.h
//29ms  99.01%


/*
Total Accepted: 10367
Total Submissions: 37776
Instruction: LeetCode 532 - K-diff Pairs in an Array - [E]
Developer: lrushx
Process Time: Apr 23, 2017
*/


/*
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
*/

//给一个数组和一个数k，求数组中多少个数对，他们的差绝对值为k
//先排序，然后一个for循环遍历后一个数nums[i]，然后在nums[0]..nums[i-1]中找值为nums[i]-k的数
//找nums[i]-k当然不能直接找，此处用的二分，在0..i-1中找第一个值>=nums[k]的索引即可，复杂度nlogn
//注意：题目要求不同的数对，所以对于k>0，重复数无意义，而对于k==0只有重复数有意义；k<0时返回0。
//此题的python解法特别巧妙，k==0时返回sum(v>1 for v in collections.Counter(nums).values())，把集合中每个值计数，次数>2的用bool(v>1)求和；
//k>0时返回len(set(nums)&set(n+k for n in nums))，用nums和nums+k构造2个set然后求交集输出长度。




    int bisearch(vector<int>& nums, int i,int j,int t){
        //return the index that the first one >= t 
        int l = i,r = j,mid;
        while (l <= r){
            mid = (r-l)/2+l;
            if (nums[mid] < t) l = mid+1;
            else r = mid - 1;
        }
        return l;
        
    }
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2 || k < 0) return 0;
        
        sort(nums.begin(),nums.end());
        int start,target,ans=0;
        //k = abs(k);
        
        if (k == 0) {
            for (int i=1;i<len;i++)
                if (nums[i] == nums[i-1]){
                    ans++;
                    while (i < (len-1) && nums[i] == nums[i+1]) i++;
                }
            return ans;
        }
        //for (int i=0;i<len;i++) cout<<nums[i]<<' '; cout<<endl;
        for (int i=1;i<len;i++){
            if (nums[i] == nums[i-1]) continue;
            target = nums[i] - k;
            start = bisearch(nums,0,i-1,target);
            //cout<<start<<endl;
            if (start < i && start >=0)
                if(nums[start] == target){
                    ans++;
                }
        }
        return ans;
    }