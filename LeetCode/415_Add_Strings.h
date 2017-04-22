//415_Add_Strings.h
//6ms 99.37%

/*
Total Accepted: 29559
Total Submissions: 71837
Instruction: LeetCode 415 - Add Strings - [E]
Developer: lrushx
Process Time: Apr 21, 2017
*/

//高精度加法，没啥好说的


    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        if (l1<l2) {
            swap(num1,num2);
            swap(l1,l2);
        }
        int d = l1-l2;
        //string ans = num1;
        bool extend = false;
        for (int i=l2-1;i>=0;i--){
            int temp = num1[i+d]-'0'+num2[i]-'0';
            if (temp > 9){
                num1[i+d] = '0'+temp-10;
                if ((i+d)==0) extend = true;
                else num1[i+d-1] += 1;
            }else num1[i+d] = '0'+temp;
        }
        for (int i=d-1;i>0;i--)
            if (num1[i] > '9'){
                num1[i] = '0';
                num1[i-1] += 1;
            }
        if (num1[0] > '9'){
            extend = true;
            num1[0] = '0';
        }
        
        if (extend) num1 = '1'+num1;
        return num1;
    }
