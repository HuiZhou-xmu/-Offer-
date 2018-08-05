#include <iostream>
using namespace std;

//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

class Solution{
public:
	int rectCover(int number){
		if (number <= 0){
			return 0;
		}
		int a = 1, b = 2;
		if (number == 1){
			return a;
		}
		if (number == 2){
			return b;
		}
		int result;
		for (int i = 2; i < number; ++i){
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};