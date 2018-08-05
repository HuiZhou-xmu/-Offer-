//��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
//Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

//ͨ��
class Solution{
public:
	bool duplicate(int numbers[], int length, int* duplication){
		if (length < 2)return false;
		map<int, int> num_count;
		for (int i = 0; i < length; ++i){
			if (++num_count[numbers[i]] >= 2){
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

//���ӣ�https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8
//��Դ��ţ����

//�����Ƚ�����ĵط���������ɣ�
//��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ��
class Solution
{
public:
	bool duplicate(int numbers[], int length, int* duplication)
	{
		std::vector<int> Vec;
		Vec.resize(length);
		for (int i = 0; i<length; ++i)
		{
			Vec[numbers[i]]++;
			if (Vec[numbers[i]] == 2)
			{
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char **argv){
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	Solution s;
	int a = 3;
	int *b = &a;
	cout << s.duplicate(numbers, 7, b)<< endl;
}