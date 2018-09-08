#include <iostream>
#include <math.h>
#include <exception>
using namespace std;

//����һ��double���͵ĸ�����base��int���͵�����exponent��
//��base��exponent�η���

//ֱ�ӵ�math��
class Solution{
public:
	double Power(double base, int exponent){
		return pow(base, exponent);
	}
};

//λ����ⷨ
class Solution{
public:
	double Power(double base, int exponent){
		double res = 1, exp = exponent;
		if (exponent < 0){
			if (base == 0){
				throw exception("��ĸ����Ϊ0");
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


