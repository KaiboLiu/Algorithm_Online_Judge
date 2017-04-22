//367_Valid_Perfect_Square.h
//0ms   100%

/*
Total Accepted: 38049
Total Submissions: 100492
Instruction: LeetCode 367 - Valid Perfect Square - [E]
Developer: lrushx
Process Time: Apr 21, 2017
*/

//给一个数字n，判断是否为平方数，不能用库函数
//二分法即可，注意别溢出，搜索范围为1~46340（INT_MAX的开方）


    bool isPerfectSquare(int num) {
        if (num == 1) return 1;
        int l=1,r=num/2;
        if (r > 46340) r = 46340;
        while (l <= r){
            int mid = (r-l)/2+l;
            int tmp = mid*mid;
            if (tmp > num) r = mid-1;
            else if (tmp < num) l = mid+1;
            else return true;
        }
        
        return false;
    }
    
