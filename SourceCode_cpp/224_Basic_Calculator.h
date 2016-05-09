//224_Basic_Calculator.h
//20ms 83.85%

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
//有没有2+(3)这样的表达式？无所谓，可以通过
//实现字符串的加减表达式计算操作，包含括号、+、-、空格，题目确保输入合法,无负数

//方法一：32ms  48.00%
//用stack，申请2个栈stack_num和stack_opt，分别存数字和运算符，规则为：
//1、前后加一组括号；
//2.1、遇到(则将下一个数字push到数字栈，注意可能有连续的(；
//2.2、遇到+、-则push到符号栈；
//2.3、遇到)则取出2个数字1个符号并pop，计算后入数字栈,此处需要注意符号栈可能为空(表达式开始很多左括号)；
//2.4、遇到数字(用数字范围判断而不是用符号排除)则取出1个数字1个符号并pop，和当前数字计算后入数字栈；

//方法二：20ms 83.85%
//不碰到括号不用栈，并且用num1+sign*num2来计算，其中sign根据运算符来确定


    int calc3(int a,int b,char c){
        if (c == '+') return a+b;
        else if (c == '-') return a-b;
        else if (c == '*') return a*b;
        else if (c == '/') return a/b;
        return 0;
    }
    
    int calculate1(string s) {//全部都用栈，用1~2.4方法
        stack<int> stack_num;
        stack<int> stack_opt;
//        stack<char> stack_opt;
        while (!stack_num.empty()) stack_num.pop();
        while (!stack_opt.empty()) stack_opt.pop();

        string::size_type p = s.find(" ");
        while (p != string::npos){
            s.erase(p,1);//erase后第二个参数不写的话默认往后全部删除
            p = s.find(" ");
        }
        s = '('+s+')';
        int i=0,a,b,l=s.length();
        while (i < l){
            if (s[i] == '(') {                   //2.1、遇到(则将下一个数字push到数字栈，注意可能有连续的(；
                while (i<l && s[i]=='(') i++;
// 以下2行用库函数将字符串string转换成整数：先用c_str()获取其字符串指针，再用sscanf(char*,"%d",i)/i=atoi(char*)求整数，%f和atof求小数
//                sscanf(s.c_str()+i, "%d", &b); 
//                i = s.find_first_of("+-()",i)-1;
// 以下3行用位操作将字符串string转换成整数：
                b = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){    b = b*10+s[i]-'0';	i++;	}//Debug 还是直接判断是数字比较稳妥
                i--;
                stack_num.push(b);
            }else if (s[i]=='+' || s[i]=='-') stack_opt.push(s[i]);	    //2.2、遇到+、-则push到符号栈；
            else if (s[i] == ')'){               //2.3、遇到)则取出2个数字1个符号并pop，计算后入数字栈,此处需要注意符号栈可能为空(表达式开始很多左括号)；
                if(!stack_opt.empty()){
                    b = stack_num.top();
                    stack_num.pop();
                    a = calc3(stack_num.top(),b,stack_opt.top());
                    stack_num.pop();
                    stack_opt.pop();
                    stack_num.push(a);
                }
            }
            else {      //2.4、遇到数字则取出1个数字1个符号并pop，和当前数字计算后入数字栈；
// 以下2行用库函数将字符串string转换成整数/516ms：先用c_str()获取其字符串指针，再用sscanf(char*,"%d",i)/i=atoi(char*)求整数，%f和atof求小数
//                sscanf(s.substr(i).c_str(), "%d", &b); 
//                i = s.find_first_of("+-()",i)-1;
// 以下3行用位操作将字符串string转换成整数/32ms：
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
    
    int calculate2(string s){
        stack<int> stack_c;
        while (!stack_c.empty()) stack_c.pop();  
        int ans=0,sign=1,a,l=s.length();
        
        for (int i=0;i<l;i++){
            if (s[i]>='0' && s[i]<='9'){//是数字，则开始往后提取数字
                a = 0;
                while (i<l && s[i]>='0' && s[i]<='9'){
                    a = a*10 + s[i++] - '0';                    
                }
                i--;
                ans += sign * a;
            } else if (s[i] == '-'){
                sign = -1;
            } else if (s[i] == '+'){
                sign = 1;
            } else if (s[i] == '('){
                stack_c.push(ans);
                stack_c.push(sign);
                ans = 0;
                sign = 1;
            } else if (s[i] == ')'){
                ans = stack_c.top()*ans;
                stack_c.pop();
                ans += stack_c.top();
                stack_c.pop();
                sign = 1;
            }                 
        }
        return ans;        
    }
    
int main(){
    cout<<"224_Basic_Calculator:Input a string, output it's eval result."<<endl;
    string ss;

    cin>>ss;
    while(ss!= "-1"){
        cout<<calculate2(ss)<<endl;
        cin>>ss;
    }
    
    return 0;
}
