//081_Search_in_Rotated_Sorted_Array_II.h

//一个升序数列，有相同元素，按两个区间{a}{b}交换位置后{b}{a}，搜索一个值返回下标,033为序列不重复，081为可重复
//二分法，从154的找最小算法，找到{b}与{a}的交界，即最小数。再根据target和序列首元素的大小比较，确定target位于{a}还是{b}中
//再二分查找


    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l,r,mid;
        l = 0; r = len -1;
        while (l < r-1)
        {
            while (l<r && nums[l]==nums[l+1]) l++;
            while (l<r && nums[r]==nums[r-1]) r--;
            mid = (l+r) / 2;
            cout<<l<<":"<<mid<<":"<<r<<endl;
            if (nums[mid] >= nums[r]) l = mid;
            else r = mid;
        }
        if (nums[0] <= nums[r]) return 0;
        else return r;
    }

    int search(vector<int>& nums, int target) {
        int m,l,r,mid;
        m = findMin(nums);
        cout<<"min_index:"<<m<<endl;
        if (target == nums[0]) return 0;
        if (m == 0) { l = 0;   r = nums.size() - 1;}//原来就排序好，最小值是第一个
        else if (target > nums[0]) { l = 0;   r = m - 1;}
        else { l = m;   r = nums.size()-1;}
        mid = l;
        
        while (l < r)
        {
            mid = (l+r)/2;
            if (nums[mid]>target) r = mid - 1;
            else if (nums[mid]<target) l = mid + 1;
            else break;
        }
        if (nums[mid] == target) return mid;
        if (nums[l] == target) return l;
        else return (-1);
    }
    
int main(){
    cout<<"081_Search in Rotated Sorted Array II:Input n and {an} and target, return the index of target in {an}."<<endl;
    int n,target;
    vector<int> nums;
    cin>>n;
    while(n >0){        
        nums.resize(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cin>>target;
        cout<<search(nums,target)<<endl;       
      
        cin>>n;
    }
    
    return 0;
}
    
