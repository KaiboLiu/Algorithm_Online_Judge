//LeetCode - 523_Continuous_Subarray_Sum.h
//35ms  62.66%

/*
Instruction: LeetCode 523 - Continuous Subarray Sum - [M]
Developer: lrushx
Process Time: Apr 14, 2017
*/
 
/*
Total Accepted: 7063
Total Submissions: 32846

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/

//判断非负序列中是否有连续子串和为k的倍数
//先计算s[i]=0..i的和，再遍历j作为区间尾，i=0~j-2作为区间头，判断s[j]-s[i]是否为k倍数
//注意：k可以为0，所以%d之前要先判断；s[j]-s[i]为0也是答案，因为和=nk中n可以是0
//当k>s中间数时，用二分法求出>=k的第一个s值。避免j遍历过小的区间和。


    int bisearch(vector<int>& a, int k){
        int l = 0;
        int r = a.size()-1;
        while (l < r){
            int mid = (r-l)/2+l;
            if (a[mid] < k) l = mid + 1;
            else if (a[mid] > k) r = mid - 1;
            else return mid;
        }
        return l;        
        }
        
    bool checkSubarraySum(vector<int>& nums, int k) {
        int l = nums.size();

        if (k == 0){
            for (int i=1;i<l;i++)
                if (nums[i] == 0 && nums[i-1] == 0) return true;
            return false;            
            }
        
        vector<int> s=nums;
        for (int i=1;i<l;i++){
            if (nums[i] == 0 && nums[i-1] == 0) return true;
            s[i] += s[i-1];
            }
        
        int j;
        if (k >= s[l/3]){
            j = bisearch(s,k);
            if (j == 0) j++;
        } else j=1;
        
        for (;j<l;j++){
            if (s[j] % k == 0) return true;
            //if (s[j] >= k){
                for (int i=0;i<j-1;i++){
                    int temp = s[j]-s[i];
                    if (temp < k) break;
                    if (temp % k == 0) return true;                    
                    }
            //    }
            
            }
        return false;
        
    }

int main(){
    
    cout<<"523_Continuous_Subarray_Sum:check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k"<<endl;

    vector<int> a;
    a.push_back(23);
    a.push_back(2);
    a.push_back(0);
    a.push_back(0);
    a.push_back(8);
    
    if (checkSubarraySum(a,0)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
    }