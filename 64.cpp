//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
//���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� 
//�������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//max_element����Ĳ���Ϊ������ʱ��ȷ��Ϊ����ʱ����
//unsigned int��0��ʼȡֵ������0���жϱ߽�ʱ��ע�⡣
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