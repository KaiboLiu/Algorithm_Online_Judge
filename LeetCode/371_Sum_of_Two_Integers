//371_Sum_of_Two_Integers
//[E]
//0ms

//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

//位操作/Bit Manipulation
//a+b，用亦或^存成新的a，并且用&再<<1处理进位，存成b，循环求a+b，直到&为0

class Solution {
public:
    int getSum(int a, int b) {
        int carry = a & b;
        while (carry != 0){
            a = a ^ b;
            b = carry<<1;
            carry = a & b;
        }
        return a^b;
    }
};
