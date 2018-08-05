//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
#include <iostream>
using namespace std;

class Solution{
public:
	int Add(int num1, int num2){
		int sum = num1;
		while (num2){
			sum = num1^num2;
			num2 = (num1&num2) << 1;
			num1 = sum;
		}
		return sum;
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.Add(5, 0) << endl;
}