//611_Valid_Triangle_Number.h
//
//LeetCode Contest 36

/*
Total Accepted: 406
Total Submissions: 852
Instruction: LeetCode 611 - Valid Triangle Number - [M]
Developer: lrushx
Process Time: June 10, 2017
*/

/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

//给一个数组，求多少组合可以构成三角形三条边
//一开始3个for循环超时，后来第3重用二分就过了O(n2logn)
//二分不熟练啊 还有输入为0的情况

    int bisearchr(vector<int>& nums,int a,int b,int key){
        int mid,i=a,j=b;
        while (i <= j){
            mid = (j-i)/2+i;
            if (nums[mid] >= key) j=mid-1;
            else i=mid+1;
        }
        return j;
    }
    
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return 0;
        sort(nums.begin(),nums.end());
        int i,j,l,r,count=0;
        for (i = 0;i<len-2;i++){
            if (nums[i] == 0) continue;
            for (j = i+1;j<len-1;j++){
                r = bisearchr(nums,j+1,len-1,nums[j]+nums[i]);
                count += (r-j);
            }
        }
        return count;
    }
