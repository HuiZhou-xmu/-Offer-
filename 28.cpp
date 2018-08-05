//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		map<int, int> num_count;
		for (int num : numbers){
			num_count[num]++;
			if (num_count[num] > numbers.size() / 2.0){
				return num;
			}
		}
		return 0;
	}
};

int main(int argc, char **argv){
	map<int, int> num;
	num[1] = 1;
	num[2] = 3;
	for (auto n : num){
		cout << n.first << " " << n.second << endl;
	}
}