//LeetCode - 456_132_Pattern.h
//26ms  80.73%

/*
Instruction: LeetCode 456 - 132 Pattern - [M]
Developer: lrushx
Process Time: Apr 14, 2017
*/
 
/*
Total Accepted: 7862
Total Submissions: 27758

Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]
Output: False
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: [-1, 3, 2, 0]
Output: True
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

//给一个数列，判断其中是否有小，大，中的三元子序列（没有连续要求）
//先用一个数列储存相邻差（也可以不用数列），求出当下等值（差）数列长度l，则方案数+l(l-1)/2，若差不相等，则更新差。
//然后超时。。。

//找了答案，发现可以用stack巧妙完成O(n),s1,s2,s3表示s1<s3<s2，即s3是中间数。
//用stack存比s3大的数，每次倒着遍历nums[i]入栈，在入栈前判断，若nums[i]比栈顶大就pop栈顶。
//如果nums[i]比s3小，则已经找到方案，此nums[i]为s1，栈中元素为s2，返回true。



/*
//	Time Limit Exceeded
    int max_ind(vector<int>& nums,int a,int b,int m=INT_MAX){
        int ans=a;
        for (int i=a+1;i<b;i++) 
            if (nums[i] > nums[ans] && nums[i] < m) ans = i;
        return ans;
    }

    int min_ind(vector<int>& nums,int a,int b){
        int ans=a;
        for (int i=a+1;i<b;i++) 
            if (nums[i] < nums[ans]) ans = i;
        return ans;
    }
    
    bool find132pattern(vector<int>& nums) {
        int l = nums.size();
        int mmax, lmin, rmax;
        while (l >= 3){
            mmax = max_ind(nums,0,l);
            cout<<endl<<mmax<<" "<<endl;
            for (int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
            if (mmax > 0 && mmax < l-1){
                lmin = min_ind(nums,0,mmax);
                rmax = max_ind(nums,mmax+1, l,nums[mmax]);
                if (nums[lmin] < nums[rmax] && nums[lmin] != nums[mmax] && nums[rmax] != nums[mmax]) return true;
            }
            nums.erase(nums.begin()+mmax);
            l--;
        }
        return false;
    }
*/

    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i=nums.size()-1;i>=0;i--){
            if (nums[i] < s3) return true;
            while (!st.empty() && st.top()<nums[i]){
                s3 = st.top();  st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }

    
int main(){
    
    cout<<"456_132_Pattern"<<endl;

    vector<int> a;
    a.push_back(-2);
    a.push_back(1);
    a.push_back(2);
    a.push_back(-2);
    a.push_back(1);
    a.push_back(2);
    //a.push_back(5);
    
    cout<<endl<<endl<<find132pattern(a)<<endl;
        
    }