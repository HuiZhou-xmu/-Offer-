#include <iostream>
using namespace std;

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution{
public:
	int jumpFloor(int number){
		if (number < 1){
			return 0;
		}
		int a = 1;
		int b = 2;
		if (number == 1){
			return a;
		}
		if (number == 2){
			return b;
		}
		int result = 0;
		for(int i = 2; i < number; ++i){
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.jumpFloor(5) << endl;
}

