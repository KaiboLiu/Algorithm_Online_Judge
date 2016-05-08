//224_Basic_Calculator.h


/**
 * Instruction：LeetCode 224 - Basic Calculator - [H]
 * Developer：lrushx
 * Process Time：May 8, 2016
 */
 
 /*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/
//有没有2+(3)这样的表达式？
//实现字符串的加减表达式计算操作，包含括号、+、-、空格，题目确保输入合法,无负数
//用stack，申请2个栈stack_num和stack_opt，分别存数字和运算符，规则为
//1、前后加一组括号；
//2.1、遇到(则将下一个数字push到数字栈；
//2.2、遇到+、-则push到符号栈；
//2.3、遇到)则取出2个数字1个符号并pop，计算后入数字栈；
//2.4、遇到数字则取出1个数字1个符号并pop，和当前数字计算后入数字栈；

	int calc3(int a,int b,char c){
		if (c == '+') return a+b;
		else if (c == '-') return a-b;
		else if (c == '*') return a*b;
		else if (c == '/') return a/b;
		return 0;
	}

    int calculate(string s) {
        stack<int> stack_num;
		stack<char> stack_opt;
		while (!stack_num.empty()) stack_num.pop();
		while (!stack_opt.empty()) stack_opt.pop();
		
		string::size_type p = s.find(" ");
		while (p != string::npos){
			s.erase(p,1);//erase后第二个参数不写的话默认往后全部删除
			p = s.find(" ");
		}
		if (s[0] != '(') s = '('+s+')';
		int i=0,a,b,l=s.length();
		while (i < l){
			if (s[i] == '(') {											//2.1、遇到(则将下一个数字push到数字栈，注意可能有连续的(；
				while (i<l && s[i]=='(') i++;
				b = 0;
				while (i<l && s[i]>='0' && s[i]<='9'){	b = b*10+s[i]-'0';	i++;	}//Debug 还是直接判断是数字比较稳妥
				i--;
				stack_num.push(b);
			}else if (s[i]=='+' || s[i]=='-') stack_opt.push(s[i]);		//2.2、遇到+、-则push到符号栈；
			else if (s[i] == ')'){										//2.3、遇到)则取出2个数字1个符号并pop，计算后入数字栈,此处需要注意符号栈可能为空(表达式开始很多左括号)；
				if(!stack_opt.empty()){				
					b = stack_num.top();	
					stack_num.pop();
					a = calc3(stack_num.top(),b,stack_opt.top());
					stack_num.pop();
					stack_opt.pop();
					stack_num.push(a);
				}
			}
			else {		//2.4、遇到数字则取出1个数字1个符号并pop，和当前数字计算后入数字栈；
				b = 0;
				while (i<l && s[i]>='0' && s[i]<='9'){	b = b*10+s[i]-'0';	i++;	}//Debug 还是直接判断是数字比较稳妥
				i--;
				a = calc3(stack_num.top(),b,stack_opt.top());
				stack_num.pop();
				stack_opt.pop();
				stack_num.push(a);				
			}
			i++;
		}
		return stack_num.top();
    }
	
	
	
int main(){

    cout<<"224_Basic_Calculator:Input a string, output it's eval result."<<endl;
    string ss;

    cin>>ss;
    while(ss!= "-1"){
        cout<<calculate(ss)<<endl;
        cin>>ss;
    }
    
    return 0;
}
	
	
