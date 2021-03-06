//287_Find_the_Duplicate_Number.h
//3种方法最优为12ms 100%

//给n+1个整数大小区间[1,n]只有1个数字重复但是重复次数不定，找出这个数。要求O(1)空间和<O(n2)的时间复杂度
/*
Total Accepted: 26713 Total Submissions: 68842 Difficulty: Hard
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

//方法1 不听题目要求，开O(n)的bool数组
//16ms 68.29%
    int findDuplicate1(vector<int>& nums) {
        int l = nums.size();  //l=n+1
        vector<bool> flag;
        flag.resize(l);
        for (int i=0;i<l;i++)
            if (!flag[nums[i]]) flag[nums[i]]=true;
            else return nums[i];
        return 0;
    }

//方法2 抽屉原理，用二分法求重复数，mid=n/2，统计<=mid的个数n1，若n1>mid则前半部分有重复，否则后半部分有重复
//20ms 58.89%
    int findDuplicate2(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len-1;  //length=n+1
        while (l <= r){
            int mid = l + (r-l)/2,cnt=0;
            for (int i=0;i<len;i++)
                if (nums[i] <= mid) cnt++;
            if (cnt > mid) r = mid - 1;// 前半部分有重复
            else l = mid + 1;
        }
        return l;
    }

//方法3：下标映射法==>找环，从0开始，以nums[0]作为新下标，找nums[nums[0]]，以此类推，产生一个链表，若有重复最后会必然成环，找到环的起点。
//找环起点的方法类似Linked List Cycle II用速度为1和2的2个下标遍历即可，slow步长1，fast步长2，直线长l环长度r，当slow走了l刚进环，fast共走2l且在环内走了l，
//此后fast开始追slow，追击距离n*r-l(可能fast多走了好多圈所以是n*r-l但是可简化为n=1)，因为速度差为1，所以slow在环中走n*r-l步后被追上，两者重合即slow==fast
//此后，如果slow继续走l步，则会回到环起点，这l步可以让第三个游标p从头和slow同时走l步，当p==slow时即为环起点
//12ms 100%
    int findDuplicate3(vector<int>& nums) {
        int slow,fast,p;
		slow = nums[0];
		fast = nums[slow];
		while (slow != fast){
			slow = nums[slow];
			fast = nums[nums[fast]];			
		}
		p = 0;
		while (p != slow){
			slow = nums[slow];
			p = nums[p];
		}
		return p;
    }
	
	
	int main(){
    cout<<"287_Find_the_Duplicate_Number:Input n and {an}, return find the duplicate one."<<endl;
    int n;
//    cout<<int(log10(7815.1))<<" "<<int(10.9)<<endl;
    vector<int> nums;
    cin>>n;
    while(n >0){        
        nums.resize(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        
        cout<<findDuplicate3(nums)<<endl;        
        cin>>n;
    }
    
    return 0;
}
