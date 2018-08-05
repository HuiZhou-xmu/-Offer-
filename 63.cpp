//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
//我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		vec.push_back(num);
	}

	double GetMedian()
	{
		int size = vec.size();
		if (size <= 0)return -1;
		sort(vec.begin(), vec.end());
		if (size % 2){
			return vec[size / 2];
		}
		else{
			return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
		}
	}
private:
	vector<int> vec;
};