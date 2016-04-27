//056_Merge_Intervals.h
//给一些区间，合并有重合的区间返回区间数组
//先排序，再通过后一个的start和当前区间的end的大小判断是否扩充当前区间
//580ms,Your runtime beats 98.17% of cpp coders.

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

void Qsort_n(vector<Interval>& a, int low, int high){
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    Interval key = a[first];
 
    while(first < last)
    {
        while(first < last && key.start <= a[last].start)
        {
            --last;
        }
 
        a[first] = a[last];
 
        while(first < last && a[first].start <= key.start)
        {
            ++first;
        }
         
        a[last] = a[first];    

    }
    a[first] = key;
    Qsort_n(a, low, first-1);
    Qsort_n(a, first+1, high);
}

    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if (len < 2) return intervals;
        //for(int i=0;i<len;i++)  cout<<"{"<<intervals[i].start<<","<<intervals[i].end<<"}"<<endl;
        Qsort_n(intervals, 0, len-1);
        //for(int i=0;i<len;i++)  cout<<"("<<intervals[i].start<<","<<intervals[i].end<<")"<<endl;
        vector<Interval> ans;
        int p,q;
        
        for (int i=0;i<len;i++){
            p = intervals[i].start;
            q = intervals[i].end;
            for (int j=i+1;j<=len;j++)
                if (j == len || intervals[j].start > q){
                    i = j-1;
                    break;
                }
                else {
                    q = max(intervals[j].end,q);
                }
            Interval tmp(p,q);
            ans.push_back(tmp);
        }
        return ans;
            
    }
    
    
int main(){
    cout<<"056_Merge Intervals:Input n and {a,b}*n to form a collection of n intervals, merge all overlapping intervals."<<endl;
    int n;
//    cout<<int(log10(7815.1))<<" "<<int(10.9)<<endl;
    vector<Interval> nums,a;
    cin>>n;
    while(n >0){
        nums.clear();
        Interval tmp;
        nums.resize(n);
        for(int i=0;i<n;i++) {
            cin>>tmp.start>>tmp.end;
            nums[i] = tmp;
        }
        //for(int i=0;i<nums.size();i++)  cout<<"[["<<nums[i].start<<","<<nums[i].end<<"]]"<<endl;
        a = merge(nums);
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++)  cout<<"["<<a[i].start<<","<<a[i].end<<"]"<<endl;
        
        cin>>n;
    }
    
    return 0;
}
