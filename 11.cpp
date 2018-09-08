#include <iostream>
#include <list>
using namespace std;

//输入一个整数，输出该数二进制表示中1的个数。
//其中负数用补码表示。

class Solution{
public:
	int NumberOf1(int n){
		int num = 0;
		if (n < 0){
			n = n & 0x7FFFFFFF;
			++num;
		}
		while (n != 0){
			if (n & 1 == 1){
				num++;
			}
			n = n >> 1;
		}
		return num;
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.NumberOf1(16) << endl;
	cout << s.NumberOf1(-16) << endl;
	cout << sizeof(int) << endl;
}