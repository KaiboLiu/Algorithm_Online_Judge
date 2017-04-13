//179_Largest_Number.h
//[M]
//4ms 100%
//AC:Submission=4:14

//给一串数字，求直接相连形成的最大数字
//若为8486和84，则应该补足为8486和8484，参与排序，从大到小构造答案数列,从最高位开始比较，当长度为1时再从最左边取数比较



/*
 //此算法通过数字两两比较（重点是不同长度补足算法）排序，再统一构造答案
 //选择排序+数字比大小AC成绩16ms
 //快速排序+数字比大小AC成绩4ms（排名最高）
 //快速排序+字符串比大小AC成绩48ms（呵呵）
    bool smaller_n(int a,int b){
        bool swapflag=false;
        int len_a,len_b,k=0,cut=1,a1;
        if (b == 0) return false;
        if (a == 0) return true;        
        len_a = int(log10(a));
        len_b = int(log10(b));
        if (len_a == len_b) return (a < b);
        if (len_a < len_b) { swapflag = true; swap(a,b);}//此后a的长度比b长
        while (k < abs(len_a - len_b)){cut *= 10; k++;}
        a1 = a / cut;
        if (a1 != b) return (swapflag ^ (a1 < b));//a1<b和是否交换进行异或
        return (swapflag ^smaller_n((a % cut),b));
    }
    
void Qsort_n(vector<int>& a, int low, int high){
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];//用字表的第一个记录作为枢轴
 
    while(first < last)
    {
        while(first < last && !smaller_n(a[last],key))
        {
            --last;
        }
 
        a[first] = a[last];//将比第一个小的移到低端
 
        while(first < last && !smaller_n(key,a[first]))
        {
            ++first;
        }
         
        a[last] = a[first];    

    }
    a[first] = key;
    Qsort_n(a, low, first-1);
    Qsort_n(a, first+1, high);
}
    string largestNumber(vector<int>& nums) {
        string ans;
        int len = nums.size();
        if (len == 0) return ans;
        Qsort_n(nums,0,len-1);
        for (int i=len-1;i>=0;i--){
            char str[15]={'\0'};
            sprintf(str,"%d",nums[i]);
            ans += str;
        }
        if (nums[len-1] == 0) return "0";
        return ans;
    }
    
*/    
    
    bool smaller_s(string a,string b){//包括小于等于
        int len1 = a.size(),len2 = b.size();
        
        for (int i=0;i<len1*len2;i++)//比较121和12时，后者循环到第3位时两者相等，此时会判错，所以需要继续往后循环，直到位数为两者公倍数
            if (a[i % len1] > b[i % len2]) return false;
            else if (a[i % len1] < b[i % len2]) return true;
        return true;
            
    }
    
    void Qsort_s(vector<string>& a, int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    string key = a[first];//用字表的第一个记录作为枢轴
 
    while(first < last)
    {
        while(first < last && smaller_s(key,a[last]))
        {
            --last;
        }
    cout<<"1:"<<first<<last<<endl;
        a[first] = a[last];//将比第一个小的移到低端
 
        while(first < last && smaller_s(a[first],key))
        {
            ++first;
        }
    cout<<"2:"<<first<<last<<endl;     
        a[last] = a[first];
//将比第一个大的移到高端
    }
    a[first] = key;//枢轴记录到位
    cout<<a[0]<<" "<<a[1]<<endl;
    Qsort_s(a, low, first-1);
    Qsort_s(a, first+1, high);
}


    string largestNumber(vector<int>& nums) {
        
        string ans;
        int len = nums.size(),k=0;
        if (len == 0) return ans;
        
        vector<string> numc;
        vector<int> numl;
        numc.resize(len);
        //memset(numc,sizeof(numc),'\0');
        
        for (int i=0;i<len;i++) {
            char str[15];
            sprintf(str,"%d",nums[i]);
            numc[i] = str;
        }
        Qsort_s(numc,0,len-1);
        for (int i=len-1;i>=0;i--) ans+=numc[i];
        if (ans[0]=='0') return "0";
        return ans;
    }
    
int main(){
    cout<<"179_Largest Number:Input n and {an}, arrange them to form the largest number."<<endl;
    int n;
//    cout<<int(log10(7815.1))<<" "<<int(10.9)<<endl;
    vector<int> nums;
    cin>>n;
    while(n >0){
        
        nums.resize(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        
        cout<<largestNumber(nums)<<endl;
        
        cin>>n;
    }
    
    return 0;
}
