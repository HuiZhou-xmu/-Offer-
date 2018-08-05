//一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。

#include <vector>
#include <map>
#include <iostream>
#include <math.h>
using namespace std;

//使用map
class Solution{
public:
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2){
		map<int, int> num_count;
		for (int num : data){
			num_count[num]++;
		}
		vector<int> vec;
		for (auto num : num_count){
			if (num.second == 1){
				vec.push_back(num.first);
			}
		}
		*num1 = vec[0];
		*num2 = vec[1];
	}
};

//异或
//异或基本性质：两个相同的数异或结果为0，0与任何数异或的结果等于该数本身。
//基础版：有一个列表，其中的数字都是成对出现的，但有一个数只出现了一次，找出这个数字，不能借助额外空间。
//意思就是要求空间复杂度O(1)。
class Solution_Basic{
public:
	int FindNumsAppearOnce(vector<int> data){
		int res = 0;
		for (int i = 0; i < data.size(); ++i){
			res ^= data[i];
		}
		return res;
	}
};

//升级版：有一个列表，其中的数字都是成对出现的，但有两个数只出现了一次，找出这两个数字，不能借助额外空间。
//思路：先遍历异或，结果肯定不为0，再依据1的位置二分，列表中的数字在该位置处为1或0各置一边，这样就有了两个子列表，
//需要寻找的两个数分别在其中一个子列表中，接着分别在子列表中异或即可得到我们要找的两个数字。
//不要用关键字进行定义，例如xor等，会出错。
class Solution_Plus{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
		int res = 0;
		//异或的结果为两个单次出现的数字异或的值
		for (int i = 0; i < data.size(); ++i){
			res ^= data[i];
		}
		//找出低位第一个1出现的位置
		int pos = 0;
		while (res){
			if (res & 1){
				break;
			}
			pos++;
			res >>= 1;
		}
		//以pos为判断条件进行异或赋值
		for (int i = 0; i < data.size(); ++i){
			if (data[i] & (1<<pos)){
				*num1 ^= data[i];
			}
			else{
				*num2 ^= data[i];
			}
		}
	}
};


int main(int argc, char **argv){
	cout << (int)pow(2, 4) << endl;
	vector<int> vec{ 1, 2, 1, 2, 3, 4, 4, 5 };
	Solution_Plus s;
	int *num1 = 0;
	int *num2 = 0;
	s.FindNumsAppearOnce(vec, num1, num2);

	//cout << *num1 << " " << *num2 << endl;
}