//LeetCode - 306_Additive_Number.h
//0ms	100%

/**
 * Instruction：LeetCode 306 - Additive Number - [M]
 * Developer：lrushx
 * Process Time：May 8, 2016
 */
 
/*
 * Total Accepted: 9982 Total Submissions: 38997 Difficulty: Medium
 * 
 * Additive number is a string whose digits can form additive sequence.
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

 * Follow up:
 * How would you handle overflow for very large input integers?
*/


//给一个阿拉伯数字组成的字符串，判断是否可以拆成斐波那契数列，头2个随意
//提示要注意数据溢出，所以需要高精度加法，注意到序列至少有3个数并且满足加法，则头2个数的位数为[1,(len-1)/2]和[1,min(l-2*i,(l-i)/2)]，可以就此来遍历搜索确定头2个数
//有了头2个数，计算其和，与剩下数字前部比较，若相等继续向后迭代，直到剩下数字=前2者和，则返回true
//bool judge(a,b,c)中可以剪枝，判断a+b的末尾是否在c的相应位置出现，若未出现则直接false
//*****要注意题目给的note， 19910011992不能拆成1991,001,1992


//	bool ans = false;
	stack<string> sta;	//输出完整答案 显示分割结果，提交时删除************************
	
	string addstring(string a,string b,int la,int lb){//字符串高精度加法
		bool carry=false;
		string ans;
		int i;
		if (la < lb){
			swap(la,lb);
			swap(a,b);
		}
		for (i=1;i<=lb;i++){
			int tmp = a[la-i]-'0'+b[lb-i]-'0';
			if (carry) tmp++;
			if (tmp > 9) { carry = true; tmp = tmp % 10; }
			else carry = false;
			a[la-i] = char(tmp + '0');
		}
		i = la-lb-1;
		while (carry && i>=0){
			if (a[i] == '9')	a[i] = '0';
			else {	a[i]++; carry = false;	}
			i--;
		}
		if (carry) a = "1"+a;
		return a;		
	}
	
	
	bool judge(string a,string b,string c){		
		int la = a.length(),lb = b.length(),lc = c.length();
		if (la > 1 && a[0] == '0') return false;	//避免出现1，2，03这种情况
		if (lb > 1 && b[0] == '0') return false;
		if (lc > 1 && c[0] == '0') return false;
		
		int lmax = la > lb ? la : lb;
		if (lc < lmax) return false;	//c长度不够a+b长度
		int tail = ((a[la-1]-'0')+(b[lb-1]-'0')) % 10;
		if (tail != (c[lmax-1]-'0') && (lc > lmax && tail != (c[lmax]-'0'))) return false;
		
		string sum = addstring(a,b,la,lb);
		int lsum = sum.length();
		if (lc < lsum) return false;
		
		for (int i=0;i<lsum;i++)
			if (sum[i] != c[i]) return false;
		if (lc == lsum) {
			sta.push(sum);//输出完整答案 显示分割结果，提交时删除************************
			return true;
		}
		bool ans = judge(b,sum,c.substr(lsum));//输出完整答案 显示分割结果，提交时删除************************
		if (ans) sta.push(sum);//输出完整答案 显示分割结果，提交时删除************************
		return ans;//输出完整答案 显示分割结果，提交时删除************************
		return judge(b,sum,c.substr(lsum));		
	}
	
	
    bool isAdditiveNumber(string num) {
		int l = num.length();
		for (int i=1;i<=(l-1)/2;i++)
			for (int j=1;j<=((l-i-i) < (l-i)/2 ? (l-i-i):(l-i)/2);j++){
				string a = num.substr(0,i);//复制num[0,i-1]
				string b = num.substr(i,j);//复制num[i,j+j-1]
				if (judge(a,b,num.substr(i+j))) {
					sta.push(b);	sta.push(a);	//输出完整答案 显示分割结果，提交时删除************************
					return true;
				}
			}
		return false;
    }
	
	
	
int main(){

    cout<<"306_Additive_Number:Input a string, output if it's an additive number."<<endl;
    string ss;
	while (!sta.empty()) sta.pop();

    cin>>ss;
    while(ss!= "-1"){
        if (isAdditiveNumber(ss)) {
			cout<<"true"<<endl;
			cout<<sta.top();
			sta.pop();
			while (!sta.empty()) {
				cout<<", "<<sta.top();
				sta.pop();
			}
			cout<<endl;
		}
        else cout<<"false"<<endl;
        cin>>ss;
    }
    
    return 0;
}
