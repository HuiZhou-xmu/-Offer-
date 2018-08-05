//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
//针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//max_element里面的参数为迭代器时正确，为数字时错误。
//unsigned int从0开始取值，包括0，判断边界时需注意。
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		if (num.size() <= 0 || size > num.size() || size == 0)return res;
		for (int i = 0; i < (num.size() - size + 1); ++i){
			int max = *max_element(num.begin() + i, num.begin() + size + i);
			res.push_back(max);
		}
		return res;
	}
};

int main(int argc, char **argv){

	/*unsigned int t = 4;
	int i = 5;
	cout << (i < t) << endl;*/

	const vector<int>& num = { 2, 3, 4, 2, 6, 2, 5, 1 };
	unsigned int size = 0;
	Solution s;
	vector<int> res = s.maxInWindows(num, size);
	for (auto r : res){
		cout << r << " ";
	}
	cout << endl;
}