//����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
//�����������Ӧÿ�����԰����������������С���������

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum){
		vector<int> res;
		//һ��Ҫ�м��жϱ߽磬���ӱ߽�ò��Ҳ�������е�array[i+1]�⣿���ӱ߽�ţ��������
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