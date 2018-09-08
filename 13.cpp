#include <iostream>
#include <vector>
using namespace std;

//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
//����֤������������ż����ż��֮������λ�ò��䡣

//����vector�����ռ䣬ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n)��
class Solution{
public:
	void reOrderArray(vector<int> &array){
		int odd_count = 0;
		for (int i = 0; i < array.size(); ++i){
			if (array[i] % 2){
				++odd_count;
			}
		}
		int odd_idx = 0;
		int eve_idx = odd_count;
		vector<int> arr_temp(array.size());
		for (int i = 0; i < array.size(); ++i){
			if (array[i] % 2){
				arr_temp[odd_idx++] = array[i];
			}
			else{
				arr_temp[eve_idx++] = array[i];
			}
		}
		array = arr_temp;
	}
};

//β�壬ɾ��֮����ʵvector�ڲ��Ĵ���ʵ���ǰѺ�����������ݶ���ǰ�ƶ���ʱ�临�Ӷ�ΪO(n^2)���ռ临�Ӷ�ΪO(1)��
class Solution{
public:
	void reOrderArray(vector<int> &array){
		int temp;
		int size = array.size();
		vector<int>::iterator arr_beg = array.begin();
		while (size){
			if (*arr_beg % 2 == 0){
				temp = *arr_beg;
				arr_beg = array.erase(arr_beg);
				array.push_back(temp);
			}
			else{
				++arr_beg;
			}
			--size;
		}
	}
};

int main(int argc, char **argv){
	Solution s;
	vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	s.reOrderArray(array);
}