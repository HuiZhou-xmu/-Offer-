//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

//通过
class Solution{
public:
	bool duplicate(int numbers[], int length, int* duplication){
		if (length < 2)return false;
		map<int, int> num_count;
		for (int i = 0; i < length; ++i){
			if (++num_count[numbers[i]] >= 2){
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

//链接：https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8
//来源：牛客网

//这道题比较巧妙的地方就是这个吧：
//在一个长度为n的数组里的所有数字都在0到n-1的范围内
class Solution
{
public:
	bool duplicate(int numbers[], int length, int* duplication)
	{
		std::vector<int> Vec;
		Vec.resize(length);
		for (int i = 0; i<length; ++i)
		{
			Vec[numbers[i]]++;
			if (Vec[numbers[i]] == 2)
			{
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char **argv){
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	Solution s;
	int a = 3;
	int *b = &a;
	cout << s.duplicate(numbers, 7, b)<< endl;
}