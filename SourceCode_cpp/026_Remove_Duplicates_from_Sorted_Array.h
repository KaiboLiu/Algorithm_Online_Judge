//026_Remove_Duplicates_from_Sorted_Array.h
//给一个排序数列，删除所有重复数只留一个，返回新长度并且更新数组，将所有不重复数排序放前面，之后的元素无所谓
//计算重复个数d,若和前一个相等则d++，否则赋值f(i-d)=f(i)

    int removeDuplicates(vector<int>& nums) {
        int d = 0,len = nums.size(),ans = 0;
        if (len == 0) return ans;
        for (int i=1;i<len;i++)
            if (nums[i] == nums[i-1]) d++;
            else {
                ans = i - d;
                nums[ans] = nums[i];
            }
            
        return (ans+1);
        
    }
    
    
    int main(){
 
        cout<<"026_Remove Duplicates from Sorted Array:Input array n and {an},Remove the duplicates in place such that each element appear only once and return the new length"<<endl;
        vector<int> arr;
        int n;
        cin>>n;
        arr.resize(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<removeDuplicates(arr)<<endl;
        
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
        
        return 0;
    }
    
