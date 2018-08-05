//һ�����������������������֮�⣬���������ֶ�������ż���Ρ���д�����ҳ�������ֻ����һ�ε����֡�

#include <vector>
#include <map>
#include <iostream>
#include <math.h>
using namespace std;

//ʹ��map
class Solution{
public:
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2){
		map<int, int> num_count;
		for (int num : data){
			num_count[num]++;
		}
		vector<int> vec;
		for (auto num : num_count){
			if (num.second == 1){
				vec.push_back(num.first);
			}
		}
		*num1 = vec[0];
		*num2 = vec[1];
	}
};

//���
//���������ʣ�������ͬ���������Ϊ0��0���κ������Ľ�����ڸ�������
//�����棺��һ���б����е����ֶ��ǳɶԳ��ֵģ�����һ����ֻ������һ�Σ��ҳ�������֣����ܽ�������ռ䡣
//��˼����Ҫ��ռ临�Ӷ�O(1)��
class Solution_Basic{
public:
	int FindNumsAppearOnce(vector<int> data){
		int res = 0;
		for (int i = 0; i < data.size(); ++i){
			res ^= data[i];
		}
		return res;
	}
};

//�����棺��һ���б����е����ֶ��ǳɶԳ��ֵģ�����������ֻ������һ�Σ��ҳ����������֣����ܽ�������ռ䡣
//˼·���ȱ�����򣬽���϶���Ϊ0��������1��λ�ö��֣��б��е������ڸ�λ�ô�Ϊ1��0����һ�ߣ������������������б�
//��ҪѰ�ҵ��������ֱ�������һ�����б��У����ŷֱ������б�����򼴿ɵõ�����Ҫ�ҵ��������֡�
//��Ҫ�ùؼ��ֽ��ж��壬����xor�ȣ������
class Solution_Plus{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
		int res = 0;
		//���Ľ��Ϊ�������γ��ֵ���������ֵ
		for (int i = 0; i < data.size(); ++i){
			res ^= data[i];
		}
		//�ҳ���λ��һ��1���ֵ�λ��
		int pos = 0;
		while (res){
			if (res & 1){
				break;
			}
			pos++;
			res >>= 1;
		}
		//��posΪ�ж������������ֵ
		for (int i = 0; i < data.size(); ++i){
			if (data[i] & (1<<pos)){
				*num1 ^= data[i];
			}
			else{
				*num2 ^= data[i];
			}
		}
	}
};


int main(int argc, char **argv){
	cout << (int)pow(2, 4) << endl;
	vector<int> vec{ 1, 2, 1, 2, 3, 4, 4, 5 };
	Solution_Plus s;
	int *num1 = 0;
	int *num2 = 0;
	s.FindNumsAppearOnce(vec, num1, num2);

	//cout << *num1 << " " << *num2 << endl;
}