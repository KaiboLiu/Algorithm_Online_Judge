//088_Merge_Sorted_Array.h
//合并两个排序数列到第一个中（第一个空间足够）
//已知两个数列有效元素个数，就知道了结果序列的长度，用两个数列的两个pointer，从后往前放大的元素

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n;
        int p=m-1,q=n-1,i;
        for (i=len-1;i>=0;i--){
            if (q < 0) break;                       //nums2数列已经都存到nums1的右侧中，nums1左边剩余元素不用变
            if (p < 0) {nums1[i]=nums2[q]; q--;}    //nums1数列所有元素都移到了右侧，左边空缺由nums2填补
            else if (nums1[p]>nums2[q]) {nums1[i]=nums1[p]; p--;}
            else {nums1[i]=nums2[q]; q--;}
        }
        return;
    }

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
  
  
    
int main(){
    
    Interval a; 
    a->
    cout<<"088_Merge Sorted Array:Input m,{am},n,{bn}, merge {bn} into {am} as one sorted array."<<endl;
    int m,n,i;
    vector<int> nums1,nums2;
    cout<<"Input m and n:";
    cin>>m>>n;
    while(m > 0 && n > 0){        
        nums1.resize(m+n);
        cout<<"Input {am} and {bn}:";
        for(i=0;i<m;i++) cin>>nums1[i];        
        nums2.resize(n);
        for(i=0;i<n;i++) cin>>nums2[i];
        
        merge(nums1,m,nums2,n);
        for(i=0;i<m+n;i++) cout<<nums1[i]<<" ";   
        cout<<endl;       
      
        cout<<"Input m and n:";
        cin>>m>>n;
    }
    
    return 0;
}
    
