#include <iostream>
using namespace std;

//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
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