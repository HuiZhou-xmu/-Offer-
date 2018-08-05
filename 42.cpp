//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
//输出描述：对应每个测试案例，输出两个数，小的先输出。

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum){
		vector<int> res;
		//一定要切记判断边界，不加边界貌似也不会运行到array[i+1]这？不加边界牛客网报错。
		if (array.size() < 2){
			return res;
		}
		for (int i = 0; i < array.size() - 1; ++i){
			if (!res.empty())break;
			if (array[i] + array[i + 1]>sum)break;
			for (int j = i + 1; j < array.size(); ++j){
				if (array[i] + array[j] > sum)break;
				if (array[i] + array[j] == sum){
					res.push_back(array[i]);
					res.push_back(array[j]);
					break;
				}
			}
		}
		return res;
	}
};

int main(int argc, char **argv){
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> res;
	Solution s;
	res = s.FindNumbersWithSum(arr, 13);
	for (auto r : res){
		cout << r << " ";
	}
	cout << endl;
}