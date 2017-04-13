//066_Plus_One.h
//给一个按位给数的序列（高精度数），加上1返回新值
//注意进位，最多位数加1


    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> ans;
        if (len == 0) return ans;
        
        bool flag = true;//判断数列是否为9...99
        for (int i=0;i<len;i++) if (digits[i] != 9) {flag = false; break;}
        if (flag){
            ans.resize(len+1);
            ans[0] = 1;
            //for (int i=1;i<=len;i++) ans[i] = 0;
        }else{
            ans = digits;
            ans[len-1] += 1;
            for (int i=len-1;i>0;i--){
                ans[i-1] = ans[i-1] + ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }
        return ans;
        
            
    }
    
    
    int main(){
 
        cout<<"066_Plus One:Input array n and {an},represented as an array of digits,plus one to the number and return(the most significant digit is at the head of the list)"<<endl;
        vector<int> arr,a;
        int n;
        cin>>n;
        arr.resize(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        a = plusOne(arr);
        
        for(int i=0;i<a.size();i++) cout<<a[i];
        cout<<endl;
        
        return 0;
    }
    
