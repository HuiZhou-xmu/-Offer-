#include <iostream>
using namespace std;

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n <= 39

class Solution{
public:
	int Fibonacci(int n){
		if (n == 0 ){
			return 0;
		}
		if (n == 1){
			return 1;
		}
		int a = 0;
		int b = 1;
		int c;
		for (int i = 0; i < (n - 1); ++i){
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};