//LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
//��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
//������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,
//����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� 
//����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ� ����������˳�Ӿ����true����������false��Ϊ�˷������,�������Ϊ��С����0��

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

//��5�ţ���ϸ���⣬�Ȱ����������ٷ�����
class Solution{
public:
	bool IsContinuous(vector<int> numbers){
		if (numbers.size() != 5)return false;
		int zero_count = 0;
		int interval_count = 0;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size() - 1; ++i){
			if (numbers[i] == 0){
				zero_count++;
				continue;
			}
			if (numbers[i] == numbers[i + 1])return false;
			interval_count += numbers[i + 1] - numbers[i] - 1;
		}
		if (zero_count >= interval_count)return true;
		return false;
	}
};

int main(int argc, char **argv){
	Solution s;
	vector<int> vec1{ 1, 2, 3, 4, 5 };
	vector<int> vec2{ 1, 3, 0, 0, 5 };
	vector<int> vec3{ 1, 2, 4, 6, 7 };
	cout << s.IsContinuous(vec1) << endl;
	cout << s.IsContinuous(vec2) << endl;
}