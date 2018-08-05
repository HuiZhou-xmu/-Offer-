//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#include <iostream>
using namespace std;


//利用短路求值
class Solution{
public:
	int Sum_Solution(int n){
		int sum = n;
		(n > 0) && (sum += Sum_Solution(n - 1));
		return sum;
	}
};