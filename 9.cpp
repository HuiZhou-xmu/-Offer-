#include <iostream>
#include <math.h>
using namespace std;

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution{
public:
	int jumpFloorII(int number){
		if (number < 1){
			return 0;
		}
		return pow(2, number - 1);
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.jumpFloorII(4) << endl;
}