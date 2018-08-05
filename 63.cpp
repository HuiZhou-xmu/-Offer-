//��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
//������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
//����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����

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