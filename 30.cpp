//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
//��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
//����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
//��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
	int FindGreatestSumOfSubArray(vector<int> array){
		if (array.empty()){
			return 0;
		}
		int maxSum = array[0];
		int tmpSum = array[0];
		for (int i = 1; i < array.size(); ++i){
			tmpSum = max(tmpSum + array[i], array[i]);
			maxSum = max(tmpSum, maxSum); 
		}
		return maxSum;
	}
};

int main(int argc, char **argv){
	vector<int> vec{ 6, -3, -2, 7, -15, 1, 2, 2};
	Solution s;
	cout << s.FindGreatestSumOfSubArray(vec) << endl;
}