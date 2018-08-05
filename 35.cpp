//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组,求出这个数组中的逆序对的总数P。
//并将P对1000000007取模的结果输出。 即输出P%1000000007。
//题目保证输入的数组中没有的相同的数字
//
//数据范围：
//对于 % 50的数据, size <= 10 ^ 4
//对于 % 75的数据, size <= 10 ^ 5
//对于 % 100的数据, size <= 2 * 10 ^ 5
//
//输入：1,2,3,4,5,6,7,0
//输出：7

//《剑指Offer》，归并排序的思想。

#include <vector>
#include <iostream>
using namespace std;

//暴力搜索，超时。
class Solution{
public:
	int InversePairs(vector<int> data){
		if (data.size() <= 1){
			return 0;
		}
		int count = 0;
		for (int i = 0; i < data.size() - 1; ++i){
			for (int j = i + 1; j < data.size(); ++j){
				if (data[i] > data[j]){
					count++;
				}
			}
		}
		return count % 1000000007;
	}
};

int main(int argc, char **argv){
	vector<int> data{ 1, 2, 3, 4, 5, 6, 7, 0 };
	Solution s;
	cout << s.InversePairs(data) << endl;
}