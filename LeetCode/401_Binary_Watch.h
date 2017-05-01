//401_Binary_Watch.h
//0ms	100.00%

/*
Total Accepted: 26907
Total Submissions: 60166
Instruction: LeetCode 401 - Binary Watch - [E]
Developer: lrushx
Process Time: Apr 30, 2017
*/


/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
Input: n = 1   Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/


//用4个灯表示二进制的时(0-11)，6个灯表示二进制的分(0-59)，给亮灯的总个数，输出所有满足条件的时间
//n=n_hour+n_min，遍历两种灯的组合即可，关键是如何建立灯数(二进制时1的个数)和十进制数字的联系
//为了避免重复计算Bin到Dec生成，或者Dec到Bin判断，我直接建立数组LED[k][j]表示k个灯时能表达的数都在LED[k][1]~LED[k][j]中。
//对分0-59和时0-11分别建立这个数组LEDH和LEDM，这样遍历完n_hour和n_min后就可以访问LEDH[n_hour][i]和LEDM[n_min][j]，讲这2个数组成电子表计时格式

//感觉并不是easy级别，自认为方法挺好，避免了重复计算，像hash table


    string stringtime(int h,int m){
        string ans = to_string(h)+":";
        if (m < 10) ans += "0";
        ans += to_string(m);
        return ans;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        if (num > 8) return ans;

        vector<vector<int> > LEDH(4,vector<int>(1,0));
        vector<vector<int> > LEDM(6,vector<int>(1,0));
        int i,j,k,count,h,m,hmax;
        for (i=0;i<12;i++){
            k = i;
            count = 0;
            while (k > 0){
                count += k & 1;
                k = k >> 1;
            }
            LEDH[count].push_back(i);
            LEDH[count][0]++;
        }
        
        for (i=0;i<60;i++){
            k = i;
            count = 0;
            while (k > 0){
                count += k & 1;
                k = k >> 1;
            }
            LEDM[count].push_back(i);
            LEDM[count][0]++;
        }
        
        hmax = min(3,num);
        for (h = 0;h <= hmax; h++){
            m = num - h;
            if (m > 5) continue;
            for (i = 1;i<=LEDH[h][0];i++)
                for (j = 1;j<=LEDM[m][0];j++)
                    ans.push_back(stringtime(LEDH[h][i],LEDM[m][j]));
        }
        return ans;
             
    }