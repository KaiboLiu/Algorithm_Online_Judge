//565_Array_Nesting.h
//29ms	100.00%
//LeetCode Contest 34

/*
Total Accepted: 851
Total Submissions: 1789
Instruction: LeetCode 565 - Array Nesting - [M]
Developer: lrushx
Process Time: May 27, 2017
*/


/*
A zero-indexed array A consisting of N different integers is given. The array contains all integers in the range [0, N - 1].
Sets S[K] for 0 <= K < N are defined as follows:
S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
Sets S[K] are finite for each K and should NOT contain duplicates.
Write a function that given an array A consisting of N integers, return the size of the largest set S[K] for this array.

Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
Note:
N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of array A is an integer within the range [0, N-1].
*/

//给一个大小为n的数组，元素为0~n-1的重排，没有重复，不同i进行i->a[i]这一连串查找会构成环，求所有环中最大环的大小
//用while语句遍历i，用j=a[i]，然后挨个j=a[j]往后找即可，直到j被标记过或者j==i，记下个数跟新res
//注意while语句中起止状态，有+-1的差别要小心



    int arrayNesting(vector<int>& nums) {
        int len = nums.size(),res = 0,i=0,j,count;
        bool flag[len] = {0};
        while (i < len){
            j = nums[i];
            flag[i] = true;
            count = 1;
            while (j != i && !flag[j]){
                count++;
                j = nums[j];
            }
            res = max(res,count);
            i++;
            while (i < len && flag[i]) i++;
        }
        return res;
    }