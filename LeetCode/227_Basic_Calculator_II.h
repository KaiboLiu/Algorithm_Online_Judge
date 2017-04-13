//227_Basic_Calculator_II.h
//24ms	69.30%

/**
 * Instruction：LeetCode 227 - Basic Calculator II- [M]
 * Developer：lrushx
 * Process Time：May 9, 2016
 */
 
 /*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 */
 
//实现字符串的加减表达式计算操作，包含+、-、*、/、空格，题目确保输入合法,无负数

//方法一：36ms  42.71%
//用stack，申请1个栈stack_c，分别存数字和加减运算符，规则为：
//1、栈中push 0和1；
//2.1、遇到数字push；
//2.2、遇到+、-则记为sign，pop2个数字1个符号进行运算，push结果，并push这个sigh；
//2.3、遇到*、/则pop1个数字a，求取下一个数字b，根据本次符号运算a$b，push结果；
//3、栈中最后剩3个元素，取出来b,opt,a，运算得到结果；

//方法二：24ms  69.30%
//注意到方法一中stack_c最多存3个元素：2个数字1个符号（只有加减没有乘除），于是改用a、b存数字，sign存符号
//去除stack的入栈出栈操作后，优化12ms

    
    int calculate1(string s) {//全部都用栈，用1~2.4方法
		stack<int> stack_c;
        while (!stack_c.empty()) stack_c.pop();
		stack_c.push(0);
		stack_c.push(1);

		int a,b,sign,l=s.length();
		for (int i=0;i<l;i++){
            if (s[i]>='0' && s[i]<='9') {
                b = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){    
					b = b*10 + s[i++] - '0';
				}
                i--;
                stack_c.push(b);
            }else if (s[i] == '+') {
				b = stack_c.top();		stack_c.pop();
				sign = stack_c.top();	stack_c.pop();
				a = stack_c.top();		stack_c.pop();
				stack_c.push(a+sign*b);
				stack_c.push(1);
			}else if (s[i] == '-') {
				b = stack_c.top();		stack_c.pop();
				sign = stack_c.top();	stack_c.pop();
				a = stack_c.top();		stack_c.pop();
				stack_c.push(a+sign*b);
				stack_c.push(-1);
			}else if (s[i] == '*' || s[i] == '/'){ 
				char c = s[i++];
				while (i<l && s[i] == ' ') i++;		//确保*，/后面的空格不影响提取数字；
				a = stack_c.top();		stack_c.pop();
				b = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){    
					b = b*10 + s[i++] - '0';
                }
				i--;
				if (c == '*') stack_c.push(a*b);
				else stack_c.push(a/b);
            }
        }
		b = stack_c.top();		stack_c.pop();
		sign = stack_c.top();	stack_c.pop();
		a = stack_c.top();
        return a + sign*b;
    }




    int calculate2(string s) {//全部都用栈，用1~2.4方法

		int a=0,b,c,sign=1,l=s.length();
		for (int i=0;i<l;i++){
            if (s[i]>='0' && s[i]<='9') {
                b = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){    
					b = b*10 + s[i++] - '0';
				}
                i--;
            }else if (s[i] == '+') {
				a = a + sign*b;
				sign = 1;
			}else if (s[i] == '-') {
				a = a + sign*b;
				sign = -1;
			}else if (s[i] == '*'){ 
                i++;
                while (i<l && s[i] == ' ') i++;		//确保*，/后面的空格不影响提取数字；
				c = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){    
					c = c*10 + s[i++] - '0';
                }
				i--;
				b = b*c;
			}else if (s[i] == '/'){ 
				i++;
				while (i<l && s[i] == ' ') i++;		//确保*，/后面的空格不影响提取数字；
				c = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){    
					c = c*10 + s[i++] - '0';
                }
				i--;
				b = b/c;
            }
        }
        return a + sign*b;
    }


   
int main(){
    cout<<"227_Basic_Calculator_II:Input a string, output it's eval result."<<endl;
    string ss;

    cin>>ss;
    while(ss!= "-1"){
        cout<<calculate2(ss)<<endl;
        cin>>ss;
    }
    
    return 0;
}
