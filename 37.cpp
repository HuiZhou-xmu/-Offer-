//统计一个数字在排序数组中出现的次数。

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
	int GetNumberOfK(vector<int> data, int k){
		if (data.size() == 0){
			return 0;
		}
		vector<int>::iterator beg = data.begin();
		while (1){
			if (*beg == k){
				break;
			}
			beg++;
			if (beg == data.end()){
				return 0;
			}
		}
		vector<int>::iterator end = data.end() - 1;
		while (1){
			if (*end == k){
				break;
			}
			if (end == data.begin()){
				break;
			}
			end--;
		}
		return (end - beg + 1) > 0 ? end - beg + 1: 0;
	}
};

int main()
{
	using namespace std;

	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(6);

	Solution s;
	cout << s.GetNumberOfK(vec, 10) << endl;

}
