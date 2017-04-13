//031_Next_Permutation.h
//给一个数列，求从小到大开始全排列中的下一个排列方式，若为最大的，则输出第一个
//找一对升序的、小数最靠右的数字，将大的插入到小的左边，右边部分排序
//一开始的算法错误：最末一个，往左找第一个比他小的，插入到其左边，右边部分排序


    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len<=1) return;
        
        int a=-1,b,maxi,maxv;//a为下标，b为值
        maxi = len -1;
        for (int i=len-2;i>=0;i--){
            if(nums[i] < nums[maxi]){
                a = i;
                break;
            }else maxi = i;
        }
        if (a == -1) {
            sort(nums.begin(),nums.end());
            return;
        }
        else {
            b = maxi;
            for (int i=a+1;i<len;i++)
                if(nums[i]>nums[a] && nums[i]<nums[b]) b = i;//在比nums[a]大的数中找最小的，必定存在
            maxv = nums[b];
            for (int i=b;i>a;i--)
                nums[i] = nums[i-1];
            nums[a] = maxv;
            sort(nums.begin()+a+1,nums.end());
        }
        return;    
    
    }
    
    
int main(){
    cout<<"031_Next Permutation:Input n and {an}, return the lexicographically next greater permutation."<<endl;
    int n;
    vector<int> nums;
    cin>>n;
    while(n >0){
        
        nums.resize(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        
        nextPermutation(nums);
        
        for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        cout<<endl;
        
        cin>>n;
    }
    
    return 0;
}
