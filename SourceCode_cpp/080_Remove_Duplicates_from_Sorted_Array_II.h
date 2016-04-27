//080_Remove_Duplicates_from_Sorted_Array_II.h

//给一个排序数列，删除所有2次以上的重复数字只留1个或者2个重复，返回新长度并且更新数组，将所有满足条件的数排序放前面，之后的元素无所谓
//类似026计算重复个数d,若和前一个相等则d++，否则赋值f(i-d)=f(i)，添加一个计数变量dup

    int removeDuplicates(vector<int>& nums) {
        int d = 0,len = nums.size(),ans = 0;
        if (len == 0) return ans;
        int dd = 0;
        for (int i=1;i<len;i++)
            if (nums[i] == nums[i-1]) { 
                dd++;
                if (dd <= 1){
                    ans = i-d;
                    nums[ans] = nums[i];
                } else d++;
                
            }
            else {
                dd = 0;
                ans = i - d;
                nums[ans] = nums[i];
            }
            
        return (ans+1);
        
    }
    
    
    int main(){
 
        cout<<"080_Remove Duplicates from Sorted Array II:Input array n and {an},Remove the duplicates in place such duplicates are allowed at most twice and return the new length"<<endl;
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
    
