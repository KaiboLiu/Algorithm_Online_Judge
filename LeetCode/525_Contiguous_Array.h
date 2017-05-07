//525_Contiguous_Array.h
//148ms	60.89%


/*
Total Accepted: 6959
Total Submissions: 19106
Instruction: LeetCode 525 - Contiguous Array - [M]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/


//给一个二进制数组，求一个最大连续子串，使得其中0,1个数相等，返回这个长度
//通过列公式，这个子串的元素和*2==子串长，则有2*s[i]-i==2*s[j]-j，生成这个新数组，然后用hash map储存这个值，往后遍历
//若这个值出现过，就计算长度试图更新结果，若没出现过，则hash table就储存第一次出现的对应索引
//一开始把新数组排序，在连续新值中找最大的坐标差，成绩44%



//solution1, new array is 2*s[i]-i, sort than compare the same 2*s[i]-i, find the maxium difference in their index
//155ms	47.07%
    struct newarray{
        int diff;
        int index;
    };
    
    struct myclass {
        bool operator() (const newarray& i,const newarray& j) { 
            return (i.diff < j.diff);
        }
    } mycmp;
    
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        vector<newarray> s(len,newarray());
        int i,res=0,l,r,k;
        s[0].diff = nums[0];
        s[0].index = 0;
        for (i=1;i<len;i++){
            s[i].diff = s[i-1].diff + nums[i];
            if (s[i].diff * 2 == i+1) res = i+1;
            s[i].index = i;
        } 
        //for(i=0;i<len;i++) cout<<"["<<s[i].diff<<","<<s[i].index<<"]"; cout<<endl;
        for (i=0;i<len;i++) s[i].diff = 2*s[i].diff - i;
        sort(s.begin(),s.end(),mycmp);
        //for(i=0;i<len;i++) cout<<"["<<s[i].diff<<","<<s[i].index<<"]"; cout<<endl;
        k = 0;
        while (k < len){
            l = s[k].index;
            r = s[k].index;
            while (k < len-1 && s[k+1].diff==s[k].diff){
                k++;
                if (s[k].index > r) r = s[k].index;
                else if (s[k].index < l) l = s[k].index;
            }
            if (r-l > res) res = r-l;
            k++;
        }
        return res;
        
        
    }
    
    
//solution2, check 2*s[i]==i+1 or 2*s[i]-i == 2*s[j]-j  
//149ms	55.72%
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        
        int i,res=-1,l,r,k;
        for (i=1;i<len;i++){
            nums[i] += nums[i-1];
            if (nums[i] * 2 == i+1) res = i;
        } 
        
        unordered_map<int,int> m;
        for (i=0;i<len;i++) {
            nums[i] = 2*nums[i] - i;
            if (m[nums[i]] > 0){
                if (i - m[nums[i]] > res) res = i - m[nums[i]];
            }
            else m[nums[i]] = i+1;
        }
        return res+1;
        
    }
    
    
//solution3, change 0 to -1, check s[i]==0 or s[i] == s[j]
//148ms	60.89%
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        
        int i,res=-1,l,r,k;
        if (nums[0] == 0) nums[0] = -1;
        for (i=1;i<len;i++){
            if (nums[i] == 0) nums[i] = nums[i-1]-1;
            else nums[i] = nums[i-1]+1;
            if (nums[i] == 0) res = i;
        } 
        
        unordered_map<int,int> m;
        for (i=0;i<len;i++) {
            if (m[nums[i]] > 0){
                if (i - m[nums[i]] > res) res = i - m[nums[i]];
            }
            else m[nums[i]] = i+1;
        }
        return res+1;
        
    }