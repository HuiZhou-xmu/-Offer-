#include <iostream>
#include <math.h>
#include <exception>
using namespace std;

//给定一个double类型的浮点数base和int类型的整数exponent。
//求base的exponent次方。

//直接调math库
class Solution{
public:
	double Power(double base, int exponent){
		return pow(base, exponent);
	}
};

//位运算解法
class Solution{
public:
	double Power(double base, int exponent){
		double res = 1, exp = exponent;
		if (exponent < 0){
			if (base == 0){
				throw exception("分母不能为0");
			}
			exponent = -exponent;
		}
		while (exponent != 0){
			if (exponent & 1){
				res *= base;
			}
			base *= base;
			exponent >>= 1;
		}
		return exp >= 0 ? res:1/res;
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.Power(2, -3) << endl;
}


